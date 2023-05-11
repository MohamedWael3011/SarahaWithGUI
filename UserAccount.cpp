#include "UserAccount.h"
#include "Misc.h"

void PrintDate(SYSTEMTIME d)
{
	cout << d.wDay << "-" << d.wMonth << "-" << d.wYear << " " << d.wHour << ":" << d.wMinute << endl;
}

bool compareByTime(const pair<UserMessage, int>& a, const pair<UserMessage, int>& b) {
	::FILETIME aFileTime, bFileTime;
	SystemTimeToFileTime(&a.first.SentDate, &aFileTime);
	SystemTimeToFileTime(&b.first.SentDate, &bFileTime);
	return CompareFileTime(&aFileTime, &bFileTime) < 0;
}

UserAccount::UserAccount(void)
{
}

UserAccount::UserAccount(int id, string username, string pw)
{
	Set(id, username, pw);
}

void UserAccount::Set(int id, string username, string pw)
{
	m_id = id;
	m_username = username;
	m_password = pw;
}

int UserAccount::ID(void) const
{
	return m_id;
}

string UserAccount::Username(void) const
{
	return m_username;
}

string UserAccount::Password(void) const
{
	return m_password;
}

bool UserAccount::AddContact(int User_ID) {

	if (ReceivedMessages.find(User_ID) != ReceivedMessages.end()) {

		if (Contacts.find(User_ID) != Contacts.end()) {

			cout << User_ID << " is already in your contacts list.\n";
		}
		else {

			Contacts.insert(User_ID);
			cout << User_ID << " has been added to your contacts list.\n";

		}
		return true;
	}

	return false;

}

bool UserAccount::RemoveContact(int User_ID) {

	if (Contacts.find(User_ID) != Contacts.end()) {
		Contacts.erase((User_ID));
		cout << User_ID << " has been removed from your contacts list.\n";
		return true;
	}
	return false;
}

bool UserAccount::Block(int User_ID)
{
	if (!IsBlocked(User_ID))
	{
		Blocked.insert(User_ID);
		return true;
	}
	return false;
}

bool UserAccount::Unblock(int User_ID)
{
	return Blocked.erase(User_ID);
}

char UserAccount::SendUserMessage(UserAccount* recipient, string content)
{
	if (!recipient)
		return 1;
	else if (IsBlocked(recipient->m_id))
		return 2;
	else if (recipient->IsBlocked(m_id))
		return 3;

	SYSTEMTIME time;
	GetSystemTime(&time);
	UserMessage msg{ 0, content, time };

	// >> SENDER SIDE <<
	msg.Index = (!SentMessages.empty() ? SentMessages.top().second.Index : 0) + 1;
	SentMessages.push(pair<int, UserMessage>(recipient->m_id, msg));

	// >> RECIPIENT/RECEIVER SIDE <<
	auto it = recipient->ReceivedMessages.find(m_id);

	// if received msgs from this user before
	if (it != recipient->ReceivedMessages.end())
	{
		//msg.Index = (!it->second.empty() ? it->second.top().Index : 0) + 1;
		it->second.push(msg);
	}

	// first time to receive msg from this user
	else
	{
		stack<UserMessage> msgs;
		msgs.push(msg);

		recipient->ReceivedMessages[m_id] = msgs;
	}
	return 0;
}

bool UserAccount::PopUserMessage(UserAccount* user) {

	// Pop from sender side
	if (SentMessages.empty())
		return false;
	SentMessages.pop();

	// Pop from receiver side
	auto it = user->ReceivedMessages.find(m_id);
	if (it == user->ReceivedMessages.end() || it->second.empty()) {
		return false;
	}
	else {
		it->second.pop();
		return true;
	}
}

void UserAccount::SetSentMessageSeen(int Receiver_ID, int Msg_Index, bool seen)
{
	stack<pair<int, UserMessage>> sent;
	pair<int, UserMessage> msg;

	while (!SentMessages.empty())
	{
		msg = SentMessages.top();

		if (msg.first == Receiver_ID && msg.second.Index == Msg_Index)
			msg.second.Seen = true;

		sent.push(msg);
		SentMessages.pop();
	}

	while (!sent.empty())
	{
		SentMessages.push(sent.top());
		sent.pop();
	}
}

void UserAccount::ViewContacts() {
	set<int>::iterator itr;
	vector<pair<int, int>>ContactTotalUserMessages;

	for (itr = Contacts.begin(); itr != Contacts.end(); itr++) // Retrieving Contact's Sent UserMessages
	{
		int ContactID = *itr;
		int ContactUserMessages = ReceivedMessages[ContactID].size();
		ContactTotalUserMessages.push_back(make_pair(ContactUserMessages, ContactID)); // Storing as (UserMessages,ID) for easier sort lol :')
	}
	if (ContactTotalUserMessages.empty()) {
		cout << "Oh no, you don't have any contacts. :(" << endl;
	}
	else {
		sort(ContactTotalUserMessages.begin(), ContactTotalUserMessages.end(), greater<>());
		for (auto i : ContactTotalUserMessages) {
			cout << "Contact with ID " << i.second << ": " << i.first << "  UserMessage" << endl;
		}
	}
}

Panel^ CreateMessageBox(String^ message)
{
	Panel^ messageContainer = gcnew Panel();
	RichTextBox^ messageBox = gcnew RichTextBox();

	int wordCount = 0;

	String^ messageContent = message;

	//Limiting the number of words per line to 15
	cli::array<String^>^ words = messageContent->Split();
	String^ processedText = "";
	for each (String ^ word in words)
	{
		if (wordCount > 15)
		{
			processedText += "\n";
			wordCount = 0;
		}
		processedText += word + " ";
		wordCount++;
	}

	messageBox->Text = processedText->Trim();

	//Measure size of text in textbox
	Drawing::Size size = TextRenderer::MeasureText(messageBox->Text, messageBox->Font);

	// Adjust the size of the textbox to fit the text
	messageBox->Width = size.Width;
	messageBox->Height = size.Height;

	//Adjust the size of the panel to fit the textbox
	messageContainer->Width = messageBox->Width + 20;
	messageContainer->Height = messageBox->Height + 20;

	//Properties for Panel
	messageContainer->BorderStyle = BorderStyle::None;
	messageContainer->BackColor = Color::DarkSlateGray;
	messageContainer->Padding = System::Windows::Forms::Padding(10);

	//Properties for Textbox
	messageBox->BorderStyle = BorderStyle::None;
	messageBox->BackColor = Color::DarkSlateGray;
	messageBox->Dock = DockStyle::Fill;
	messageBox->ForeColor = Color::White;
	messageBox->Multiline = true;
	messageBox->ReadOnly = true;
	messageBox->WordWrap = true;

	//Add the textbox inside panel
	messageContainer->Controls->Add(messageBox);

	return messageContainer;
}

Panel^ CreateUIDPanel(String^ ID, String^ date, bool seen)
{
	Panel^ uIDContainer = gcnew Panel();
	Label^ uIDLabel = gcnew Label();
	Label^ uDateLabel = gcnew Label();

	//Label for UID
	uIDLabel->Text = "By UID: " + ID;
	uIDLabel->ForeColor = seen ? Color::FromArgb(83, 189, 235) : Color::White;
	uIDLabel->AutoSize = true;

	//Label for date
	uDateLabel->Text = date;
	uDateLabel->ForeColor = seen ? Color::FromArgb(83, 189, 235) : Color::White;
	uDateLabel->Location = Point(uIDLabel->Width, 0);
	uDateLabel->AutoSize = true;

	//Properties for Panel
	uIDContainer->Width = uIDLabel->Width + uDateLabel->Width;
	uIDContainer->Height = uIDLabel->Height;
	uIDContainer->BorderStyle = BorderStyle::None;
	uIDContainer->BackColor = Color::FromArgb(12, 12, 12);
	uIDContainer->AutoSize = true;

	//Adding the label inside panel
	uIDContainer->Controls->Add(uIDLabel);
	uIDContainer->Controls->Add(uDateLabel);

	Button^ ContactButton = gcnew Button();
	Button^ FavoriteButton = gcnew Button();

	ContactButton->Text = "add contact";
	ContactButton->Size = Size(100, 25);
	ContactButton->BackColor = Color::Transparent;
	ContactButton->Location = Point(uDateLabel->Location.X + uDateLabel->Width + 25, -5);

	FavoriteButton->Text = "add favorite";
	FavoriteButton->Size = Size(100, 25);
	FavoriteButton->BackColor = Color::Transparent;
	FavoriteButton->Location = Point(ContactButton->Location.X + ContactButton->Width + 2, -5);

	uIDContainer->Controls->Add(ContactButton);
	uIDContainer->Controls->Add(FavoriteButton);

	return uIDContainer;
}

Panel^ CreateMainMessagePanel(String^ message, String^ ID, String^ date, bool seen)
{
	Panel^ MainPanel = gcnew Panel();
	Panel^ MessageBoxPanel = CreateMessageBox(message);
	Panel^ UIDPanel = CreateUIDPanel(ID, date, seen);

	//Properties of Main Panel
	MainPanel->Width = MessageBoxPanel->Width;
	UIDPanel->Location = Point(0, MessageBoxPanel->Height + 5);
	MainPanel->AutoSize = true;

	//Add Panels into Main Panel
	MainPanel->Controls->Add(MessageBoxPanel);
	MainPanel->Controls->Add(UIDPanel);

	return MainPanel;
}

void CreateMessageLayout(FlowLayoutPanel^ container, vector<pair<UserMessage, int>>& messages)
{
	//Flow Layout Properties
	//container->Location = Point(110, 135);
	container->FlowDirection = FlowDirection::TopDown;
	container->AutoScroll = true;
	container->WrapContents = false;

	//Add the Messages
	for (int i = 0; i < messages.size(); i++)
	{
		container->Controls->Add(CreateMainMessagePanel(CPPSTR2SYSTEM(messages[i].first.Content.c_str()), CPPSTR2SYSTEM(to_string(messages[i].second).c_str()), CPPSTR2SYSTEM(GetMessageDate(messages[i].first.SentDate).c_str()), messages[i].first.Seen));
	}
}

void CreateMessageLayout(FlowLayoutPanel^ container, stack<UserMessage>& messages, int User_ID)
{
	//Flow Layout Properties
	//container->Location = Point(110, 135);
	container->FlowDirection = FlowDirection::TopDown;
	container->AutoScroll = true;
	container->WrapContents = false;

	UserMessage message;

	//Add the Messages
	while (!messages.empty())
	{
		message = messages.top();
		container->Controls->Add(CreateMainMessagePanel(CPPSTR2SYSTEM(message.Content.c_str()), CPPSTR2SYSTEM(to_string(User_ID).c_str()), CPPSTR2SYSTEM(GetMessageDate(message.SentDate).c_str()), message.Seen));
		messages.pop();
	}
}

void CreateMessageLayout(FlowLayoutPanel^ container, stack<pair<int, UserMessage>>& messages)
{
	//Flow Layout Properties
	//container->Location = Point(110, 135);
	container->FlowDirection = FlowDirection::TopDown;
	container->AutoScroll = true;
	container->WrapContents = false;

	pair<int, UserMessage> message;

	//Add the Messages
	while (!messages.empty())
	{
		message = messages.top();
		container->Controls->Add(CreateMainMessagePanel(CPPSTR2SYSTEM(message.second.Content.c_str()), CPPSTR2SYSTEM(to_string(message.first).c_str()), CPPSTR2SYSTEM(GetMessageDate(message.second.SentDate).c_str()), message.second.Seen));
		messages.pop();
	}
}

void CreateMessageLayout(FlowLayoutPanel^ container, queue<pair<int, UserMessage>>& messages, UserAccount* acc)
{
	//Flow Layout Properties
	//container->Location = Point(110, 135);
	container->FlowDirection = FlowDirection::TopDown;
	container->AutoScroll = true;
	container->WrapContents = false;

	pair<int, UserMessage> message;

	//Add the Messages
	while (!messages.empty())
	{
		message = messages.front();
		container->Controls->Add(CreateMainMessagePanel(CPPSTR2SYSTEM(message.second.Content.c_str()), CPPSTR2SYSTEM((acc->GetContact(message.first) ? (to_string(message.first) + " (contact)").c_str() : to_string(message.first).c_str())), CPPSTR2SYSTEM(GetMessageDate(message.second.SentDate).c_str()), message.second.Seen));
		messages.pop();
	}
}

vector<pair<UserMessage, int>> UserAccount::ViewReceivedMessages(FlowLayoutPanel^ container, bool full)
{
	vector <pair<UserMessage, int>> AllUserMessages;

	if (ReceivedMessages.empty() == false)
	{
		UserMessage Message;
		unordered_map<int, stack<UserMessage>>::iterator it;

		for (it = ReceivedMessages.begin(); it != ReceivedMessages.end(); it++)
		{
			stack<UserMessage> UserMessages;

			while (!it->second.empty())
			{
				Message = it->second.top();

				if (full == true || Message.Seen == false)
					AllUserMessages.emplace_back(Message, it->first);

				//set messages as seen for receiver
				Message.Seen = true;
				UserMessages.push(Message);

				it->second.pop();
			}

			//re-set received messages (to update IsSeen)
			while (!UserMessages.empty())
			{
				it->second.push(UserMessages.top());
				UserMessages.pop();
			}
		}

		std::sort(AllUserMessages.begin(), AllUserMessages.end(), compareByTime);
		CreateMessageLayout(container, AllUserMessages);
	}

	return AllUserMessages;
}

void UserAccount::ViewSentMessages(FlowLayoutPanel^ container)
{
	if (!SentMessages.empty())
	{
		stack<pair<int, UserMessage>> msgs = SentMessages;
		CreateMessageLayout(container, msgs);
	}
}

bool UserAccount::ViewUserMessages(FlowLayoutPanel^ container, int User_ID)
{
	//Flow Layout Properties
	container->Location = Point(110, 135);
	container->FlowDirection = FlowDirection::TopDown;
	container->AutoScroll = true;
	container->WrapContents = false;

	stack<UserMessage> UserMessages;

	if (ReceivedMessages.find(User_ID) == ReceivedMessages.end())
	{
		return false;
	}
	else
	{
		UserMessages = ReceivedMessages[User_ID];
		CreateMessageLayout(container, UserMessages, User_ID);
		return true;
	}

}
bool UserAccount::PutFavorite(int User_ID, int Msg_Index) {
	if (ReceivedMessages.find(User_ID) == ReceivedMessages.end())
	{
		return false;
	}
	else
	{
		stack<UserMessage> chat = ReceivedMessages[User_ID];
		while (!chat.empty())
		{
			if (chat.top().Index != Msg_Index)
			{
				chat.pop();
			}
			else
			{
				if (chat.top().IsFavorite == true)
				{
					cout << "This message is already a favourite";
					return false;
				}
				else
				{
					chat.top().IsFavorite = true;
					Favorites.emplace(User_ID, chat.top());
					return true;
				}
			}
		}
	}
}
bool UserAccount::RemoveOldestFavorite() {
	if (Favorites.empty())
		return false;
	Favorites.pop();
	return true;

}

bool UserAccount::ViewFavorites(FlowLayoutPanel^ container)
{
	if (Favorites.empty())
	{
		return false;
	}

	queue<pair<int, UserMessage>> msgs = Favorites;
	CreateMessageLayout(container, msgs, this);
	return true;
}

bool UserAccount::DeleteSpecificFavorite(int senderID, int Msg_Index)
{
	//Checking if index is in bounds
	if (Msg_Index < 0)
		return false;

	//Adding elements before location into temp q
	queue<pair<int, UserMessage>> temp;

	for (int i = 0; i < Favorites.size(); i++)
	{
		if (Favorites.front().first != senderID || Favorites.front().second.Index != Msg_Index)
		{
			temp.push(Favorites.front());
		}
		Favorites.pop();
	}

	//Pushing all elements from temp into main queue
	while (!temp.empty())
	{
		Favorites.push(temp.front());
		temp.pop();
	}
	return true;
}

int UserAccount::GetUserMessagesFromUser(UserAccount* user) {
	return ReceivedMessages[user->m_id].size();

}
bool UserAccount::GetContact(int User_ID) {
	auto it = Contacts.find(User_ID);
	if (it != Contacts.end()) {
		return true;
	}
	return NULL;
}

bool UserAccount::IsBlocked(int User_ID)
{
	return Blocked.find(User_ID) != Blocked.end();
}
