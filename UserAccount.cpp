#include "UserAccount.h"
#include "Misc.h"
#include "UserForm.h"

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


		if (Contacts.find(User_ID) == Contacts.end()) {

			Contacts.insert(User_ID);
			return true;
		}
	}

	return false;
}

bool UserAccount::RemoveContact(int User_ID) {

	if (Contacts.find(User_ID) != Contacts.end()) {
		Contacts.erase((User_ID));
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
	UserMessage tempMsg= SentMessages.top().second;
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
	// Remove if in favorite
	user->RemoveFavorite(user->m_id, tempMsg.Index);
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



Panel^ UserAccount::CreateMessageBox(String^ message)
{
	const int MaxWidthPerLine = 2600;

	Panel^ messageContainer = gcnew Panel();
	RichTextBox^ messageBox = gcnew RichTextBox();

	int count = 0;

	String^ messageContent = message;

	// Single character size
	int charsize = TextRenderer::MeasureText("W", messageBox->Font).Width;

	// Maximum characters per line
	charsize = MaxWidthPerLine / charsize;

	//Limiting the number of characters per line
	String^ processedText = "";
	for each (char word in messageContent)
	{
		processedText += Char::ToString(word);

		if (count > 0 && !(count % charsize))
			processedText += "\n";

		count++;
	}

	messageBox->Text = processedText;

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
	messageBox->MaxLength = 25;

	//Add the textbox inside panel
	messageContainer->Controls->Add(messageBox);

	return messageContainer;
}

Panel^ UserAccount::CreateUIDPanel(Form^ form, String^ ID, String^ date, UserMessage& msg, string type)
{
	int User_ID = atoi(SystemStringToCpp(ID).c_str());

	Panel^ uIDContainer = gcnew Panel();
	Label^ uIDLabel = gcnew Label();
	Label^ uDateLabel = gcnew Label();

	//Label for UID
	uIDLabel->Text = "By UID: " + ID;
	uIDLabel->ForeColor = msg.Seen ? Color::FromArgb(83, 189, 235) : Color::White;
	uIDLabel->AutoSize = true;

	//Label for date
	uDateLabel->Text = date;
	uDateLabel->ForeColor = msg.Seen ? Color::FromArgb(83, 189, 235) : Color::White;
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
	Button^ BlockButton = gcnew Button();

	///
	ContactButton->Text = "";
	ContactButton->BackColor = Color::Transparent;
	ContactButton->Location = Point(uDateLabel->Location.X + uDateLabel->Width + 25, -5);
	ContactButton->FlatAppearance->BorderSize = 0;
	ContactButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
		static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)));
	ContactButton->FlatAppearance->BorderSize = 0;
	ContactButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
		static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)));
	ContactButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
		static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)));
	ContactButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	ContactButton->ForeColor = System::Drawing::Color::Transparent;
	ContactButton->Image = System::Drawing::Image::FromFile(GetContact(User_ID) ? "img/IsContact.png" : "img/NotContact.png");
	ContactButton->Name = ID;
	ContactButton->Size = System::Drawing::Size(28, 28);
	ContactButton->TabIndex = 4;

	///
	FavoriteButton->Text = "";
	FavoriteButton->BackColor = Color::Transparent;
	FavoriteButton->Location = Point(ContactButton->Location.X + ContactButton->Width + 2, -5);
	FavoriteButton->FlatAppearance->BorderSize = 0;
	FavoriteButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
		static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)));
	FavoriteButton->FlatAppearance->BorderSize = 0;
	FavoriteButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
		static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)));
	FavoriteButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
		static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)));
	FavoriteButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	FavoriteButton->ForeColor = System::Drawing::Color::Transparent;
	FavoriteButton->Image = System::Drawing::Image::FromFile(msg.IsFavorite ? "img/IsFavorite.png" : "img/NotFavorite.png");
	FavoriteButton->Name = String::Format("{0},{1}", ID, CPPSTR2SYSTEM(to_string(msg.Index).c_str()));
	FavoriteButton->Size = System::Drawing::Size(28, 28);
	FavoriteButton->TabIndex = 4;

	///
	BlockButton->Text = "";
	BlockButton->BackColor = Color::Transparent;
	BlockButton->Location = Point(FavoriteButton->Location.X + FavoriteButton->Width + 2, -5);
	BlockButton->FlatAppearance->BorderSize = 0;
	BlockButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
		static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)));
	BlockButton->FlatAppearance->BorderSize = 0;
	BlockButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
		static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)));
	BlockButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
		static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)));
	BlockButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	BlockButton->ForeColor = System::Drawing::Color::Transparent;
	BlockButton->Image = System::Drawing::Image::FromFile(IsBlocked(User_ID) ? "img/IsBlocked.png" : "img/NotBlocked.png");
	BlockButton->Name = ID;
	BlockButton->Size = System::Drawing::Size(28, 28);
	BlockButton->TabIndex = 4;

	ContactButton->Click += gcnew System::EventHandler(static_cast<SarahaWithGUI::UserForm^>(form), &SarahaWithGUI::UserForm::MessageContact_Click);
	FavoriteButton->Click += gcnew System::EventHandler(static_cast<SarahaWithGUI::UserForm^>(form), &SarahaWithGUI::UserForm::MessageFavorite_Click);
	BlockButton->Click += gcnew System::EventHandler(static_cast<SarahaWithGUI::UserForm^>(form), &SarahaWithGUI::UserForm::MessageBlock_Click);

	if (type == "Received") {
		uIDContainer->Controls->Add(ContactButton);
		uIDContainer->Controls->Add(FavoriteButton);
		uIDContainer->Controls->Add(BlockButton);

	}
	return uIDContainer;
}

Panel^ UserAccount::CreateMainMessagePanel(Form^ form, int User_ID, UserMessage& msg, string type)
{
	Panel^ MainPanel = gcnew Panel();
	Panel^ MessageBoxPanel = CreateMessageBox(CPPSTR2SYSTEM(msg.Content.c_str()));
	Panel^ UIDPanel = CreateUIDPanel(form, CPPSTR2SYSTEM(to_string(User_ID).c_str()), CPPSTR2SYSTEM(GetMessageDate(msg.SentDate).c_str()), msg, type);

	//Properties of Main Panel
	MainPanel->Width = MessageBoxPanel->Width;
	UIDPanel->Location = Point(0, MessageBoxPanel->Height + 5);
	MainPanel->AutoSize = true;

	//Add Panels into Main Panel
	MainPanel->Controls->Add(MessageBoxPanel);
	MainPanel->Controls->Add(UIDPanel);

	return MainPanel;
}

void UserAccount::CreateMessageLayout(FlowLayoutPanel^ container, Form^ form, vector<pair<UserMessage, int>>& messages)
{
	//Flow Layout Properties
	container->FlowDirection = FlowDirection::TopDown;
	container->AutoScroll = true;
	container->WrapContents = false;

	//Add the Messages
	for (int i = 0; i < messages.size(); i++)
	{
		container->Controls->Add(CreateMainMessagePanel(form, messages[i].second, messages[i].first, "Received"));
	}
}

void UserAccount::CreateMessageLayout(FlowLayoutPanel^ container, Form^ form, stack<UserMessage>& messages, int User_ID)
{
	//Flow Layout Properties
	container->FlowDirection = FlowDirection::TopDown;
	container->AutoScroll = true;
	container->WrapContents = false;

	UserMessage message;

	//Add the Messages
	while (!messages.empty())
	{
		message = messages.top();
		container->Controls->Add(CreateMainMessagePanel(form, User_ID, message, "Recieved"));
		messages.pop();
	}
}

void UserAccount::CreateMessageLayout(FlowLayoutPanel^ container, Form^ form, stack<pair<int, UserMessage>>& messages)
{
	//Flow Layout Properties
	container->FlowDirection = FlowDirection::TopDown;
	container->AutoScroll = true;
	container->WrapContents = false;

	pair<int, UserMessage> message;

	//Add the Messages
	while (!messages.empty())
	{
		message = messages.top();
		container->Controls->Add(CreateMainMessagePanel(form, message.first, message.second, "Sent"));
		messages.pop();
	}
}

void UserAccount::CreateMessageLayout(FlowLayoutPanel^ container, Form^ form, queue<pair<int, UserMessage>>& messages)
{
	//Flow Layout Properties
	container->FlowDirection = FlowDirection::TopDown;
	container->AutoScroll = true;
	container->WrapContents = false;

	pair<int, UserMessage> message;

	//Add the Messages
	while (!messages.empty())
	{
		message = messages.front();
		container->Controls->Add(CreateMainMessagePanel(form, message.first, message.second, "Favorite"));
		messages.pop();
	}
}

void UserAccount::CreateBlocksLayout(FlowLayoutPanel^ container, Form^ form)
{
	//Properties of FlowLayoutPanels
	container->FlowDirection = FlowDirection::TopDown;
	container->AutoScroll = true;
	container->WrapContents = false;

	for (auto it = Blocked.begin(); it != Blocked.end(); ++it)
		container->Controls->Add(CreateBlockPanel(container, form, *it));
}

Panel^ UserAccount::CreateBlockPanel(FlowLayoutPanel^ container, Form^ form, int User_ID)
{
	String^ userid = Convert::ToString(User_ID);

	Panel^ BlockPanel = gcnew Panel();
	PictureBox^ BlockIcon = gcnew PictureBox();
	Label^ uIDLabel = gcnew Label();
	Label^ placeHolder = gcnew Label();
	Button^ UnblockButton = gcnew Button();


	//Properties for Panel
	BlockPanel->Size = Drawing::Size(480, 61);
	BlockPanel->BorderStyle = BorderStyle::FixedSingle;
	BlockPanel->Location = System::Drawing::Point(204, 10);
	BlockPanel->Margin = System::Windows::Forms::Padding(204, 10, 3, 3);
	BlockPanel->Name = L"BlockPanel";

	//Properties of PictureBox
	BlockIcon->Size = Drawing::Size(32, 32);
	BlockIcon->Location = Point(15, 14);
	BlockIcon->Image = System::Drawing::Image::FromFile("img/ProfileIcon.png");

	//Properties of Labels
	uIDLabel->ForeColor = Color::White;
	uIDLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	uIDLabel->Size = Drawing::Size(34, 20);
	uIDLabel->Location = Drawing::Point(66, 20);
	uIDLabel->AutoSize = true;
	placeHolder->Text = userid;
	placeHolder->Name = L"placeHolder";
	uIDLabel->Text = "Blocked user: " + placeHolder->Text;

	placeHolder->ForeColor = Color::White;
	placeHolder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	placeHolder->AutoSize = true;

	//Properties of Button (Unblock)
	UnblockButton->AutoSize = true;
	UnblockButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	UnblockButton->ForeColor = System::Drawing::Color::White;
	UnblockButton->Location = System::Drawing::Point(375, 19);
	UnblockButton->Size = System::Drawing::Size(89, 25);
	UnblockButton->Text = "Unblock";
	UnblockButton->Name = userid;
	UnblockButton->Click += gcnew System::EventHandler(static_cast<SarahaWithGUI::UserForm^>(form), &SarahaWithGUI::UserForm::BlockPanel_Unblock_Click);

	BlockPanel->Controls->Add(BlockIcon);
	BlockPanel->Controls->Add(uIDLabel);
	BlockPanel->Controls->Add(UnblockButton);

	return BlockPanel;
}

Panel^ CreateContactPanel(String^ user_ID, String^ numMsgs, Form^ form)
{
	Panel^ ContactPanel = gcnew Panel();
	PictureBox^ ContactIcon = gcnew PictureBox();
	Label^ uIDLabel = gcnew Label();
	Label^ uIDNumberLabel = gcnew Label();
	Label^ placeHolder = gcnew Label();
	Button^ SeeMessages = gcnew Button();
	Button^ BlockContact = gcnew Button();
	

	//Properties for Panel
	ContactPanel->Size = Drawing::Size(569, 61);
	ContactPanel->BorderStyle = BorderStyle::FixedSingle;
	ContactPanel->Padding = System::Windows::Forms::Padding(5);
	ContactPanel->Name = L"something";
	
	//Properties of PictureBox
	ContactIcon->Size = Drawing::Size(32, 32);
	ContactIcon->Location = Point(15, 14);
	ContactIcon->Image = System::Drawing::Image::FromFile("img/ProfileIcon.png");

	//Properties of Labels
	uIDLabel->ForeColor = Color::White;
	uIDLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	uIDLabel->Size = Drawing::Size(34, 20);
	uIDLabel->Location = Drawing::Point(66, 20);
	uIDLabel->AutoSize = true;
	placeHolder->Text = user_ID;
	placeHolder->Name = L"placeHolder";
	uIDLabel->Text = "Contact with ID " + placeHolder->Text + ": ";

	placeHolder->ForeColor = Color::White;
	placeHolder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	placeHolder->AutoSize = true;

	uIDNumberLabel->AutoSize = true;
	uIDNumberLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	uIDNumberLabel->ForeColor = Drawing::Color::White;
	uIDNumberLabel->Location = Drawing::Point(240, 20);
	uIDNumberLabel->Size = Drawing::Size(203, 20);
	uIDNumberLabel->Text = numMsgs + " Messages";

	//Properties of Button (See Messages)
	SeeMessages->AutoSize = true;
	SeeMessages->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	SeeMessages->ForeColor = System::Drawing::Color::White;
	SeeMessages->Location = System::Drawing::Point(470, 19);
	SeeMessages->Size = System::Drawing::Size(89, 25);
	SeeMessages->Text = "See Messages";
	SeeMessages->Name = user_ID;
	SeeMessages->Click += gcnew System::EventHandler(static_cast<SarahaWithGUI::UserForm^>(form), &SarahaWithGUI::UserForm::SeeMessages_btn_Click);
	
	//Properties of Button (Block Contact)
	BlockContact->AutoSize = true;
	BlockContact->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	BlockContact->ForeColor = System::Drawing::Color::White;
	BlockContact->Location = System::Drawing::Point(375, 19);
	BlockContact->Size = System::Drawing::Size(89, 25);
	BlockContact->Text = "Block Contact";
	BlockContact->Name = user_ID;
	BlockContact->Click += gcnew System::EventHandler(static_cast<SarahaWithGUI::UserForm^>(form), &SarahaWithGUI::UserForm::BlockContact_btn_Click);
	

	ContactPanel->Controls->Add(ContactIcon);
	ContactPanel->Controls->Add(uIDLabel);
	ContactPanel->Controls->Add(uIDNumberLabel);
	ContactPanel->Controls->Add(SeeMessages);
	ContactPanel->Controls->Add(BlockContact);

	return ContactPanel;
}

void CreateContactLayout(FlowLayoutPanel^ container, String^ user_ID, String^ numMsgs,Form^ form)
{
	//Properties of FlowLayoutPanels
	container->Size = System::Drawing::Size(879, 546);
	container->FlowDirection = FlowDirection::TopDown;
	container->AutoScroll = true;
	container->WrapContents = false;

	//Testing
	container->Controls->Add(CreateContactPanel(user_ID,numMsgs,form));

}

vector<pair<UserMessage, int>> UserAccount::ViewReceivedMessages(FlowLayoutPanel^ container, Form^ form, bool full)
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
		CreateMessageLayout(container, form, AllUserMessages);
	}

	return AllUserMessages;
}

void UserAccount::ViewSentMessages(FlowLayoutPanel^ container, Form^ form)
{
	if (!SentMessages.empty())
	{
		stack<pair<int, UserMessage>> msgs = SentMessages;
		CreateMessageLayout(container, form, msgs);
	}
}

bool UserAccount::ViewUserMessages(FlowLayoutPanel^ container, Form^ form, int User_ID)
{
	//Flow Layout Properties
	/*container->Location = Point(110, 135);
	container->FlowDirection = FlowDirection::TopDown;
	container->AutoScroll = true;
	container->WrapContents = false;*/

	stack<UserMessage> UserMessages;

	if (ReceivedMessages.find(User_ID) == ReceivedMessages.end())
	{
		return false;
	}
	else
	{
		UserMessages = ReceivedMessages[User_ID];
		CreateMessageLayout(container, form, UserMessages, User_ID);
		return true;
	}

}
bool UserAccount::PutFavorite(int User_ID, int Msg_Index) {
	auto it = ReceivedMessages.find(User_ID);
	if (it == ReceivedMessages.end())
	{
		return false;
	}
	else
	{
		bool found = false;
		stack<UserMessage> chat;
		UserMessage msg;

		while (!it->second.empty())
		{
			msg = it->second.top();

			if (!found && msg.Index == Msg_Index)
			{
				found = true;
				msg.IsFavorite = true;
				Favorites.emplace(User_ID, msg);
			}

			chat.push(msg);
			it->second.pop();
		}

		while (!chat.empty())
		{
			it->second.push(chat.top());
			chat.pop();
		}
		return found;
	}
}

bool UserAccount::RemoveOldestFavorite(void)
{
	return RemoveFavorite(Favorites.back().first, Favorites.back().second.Index);

}

bool UserAccount::RemoveFavorite(int User_ID, int Msg_Index)
{
	auto it = ReceivedMessages.find(User_ID);
	if (it == ReceivedMessages.end())
	{
		return false;
	}
	else
	{
		bool found = false;
		stack<UserMessage> chat;
		UserMessage msg;
		queue<pair<int, UserMessage>> favs;
		pair<int, UserMessage> favmsg;

		//set messages flag
		while (!it->second.empty())
		{
			msg = it->second.top();

			if (!found && msg.Index == Msg_Index)
			{
				found = true;
				msg.IsFavorite = false;
			}

			chat.push(msg);
			it->second.pop();
		}

		while (!chat.empty())
		{
			it->second.push(chat.top());
			chat.pop();
		}

		//removing from Favorites queue
		while (!Favorites.empty())
		{
			favmsg = Favorites.front();

			if (favmsg.first != User_ID || favmsg.second.Index != Msg_Index)
				favs.push(favmsg);

			Favorites.pop();
		}

		Favorites = favs;
		return found;
	}
}

bool UserAccount::IsFavorite(int User_ID, int Msg_Index)
{
	auto it = ReceivedMessages.find(User_ID);
	if (it != ReceivedMessages.end())
	{
		stack<UserMessage> chat = it->second;

		//set messages flag
		while (!chat.empty())
		{
			if (chat.top().Index == Msg_Index)
				return chat.top().IsFavorite;
			chat.pop();
		}
	}
	return false;
}

bool UserAccount::ViewFavorites(FlowLayoutPanel^ container, Form^ form)
{
	if (Favorites.empty())
	{
		return false;
	}

	queue<pair<int, UserMessage>> msgs = Favorites;
	CreateMessageLayout(container, form, msgs);
	return true;
}



bool UserAccount::ViewBlocks(FlowLayoutPanel^ container, Form^ form)
{
	if (Blocked.empty())
		return false;

	CreateBlocksLayout(container, form);
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

void UserAccount::ViewContacts(FlowLayoutPanel^ container,Form^ form)
{
	set<int>::iterator itr;
	vector<pair<int, int>>ContactTotalUserMessages;
	Label^ noContactMessage = gcnew Label();
	
	for (itr = Contacts.begin(); itr != Contacts.end(); itr++) // Retrieving Contact's Sent UserMessages
	{
		int ContactID = *itr;
		if (!IsBlocked(ContactID))
		{
			int ContactUserMessages = ReceivedMessages[ContactID].size();
			ContactTotalUserMessages.push_back(make_pair(ContactUserMessages, ContactID)); // Storing as (UserMessages,ID) for easier sort lol :')
		}
	}
	if (ContactTotalUserMessages.empty()) {

		//Properties for Label
		noContactMessage->Text = "Oh no, you don't have any contacts. :(";
		noContactMessage->ForeColor = Color::White;
		noContactMessage->AutoSize = true;
		noContactMessage->Margin = Padding(20);
		noContactMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));

		container->Controls->Add(noContactMessage);
	}
	else {
		sort(ContactTotalUserMessages.begin(), ContactTotalUserMessages.end(), greater<>());
		for (auto i : ContactTotalUserMessages) {
			CreateContactLayout(container, Convert::ToString(i.second),Convert::ToString(i.first),form);
		}
	}
}

void UserAccount::ViewContacts(FlowLayoutPanel^ container, Form^ form, int User_ID)
{
	if (GetContact(User_ID) && !IsBlocked(User_ID))
		CreateContactLayout(container, Convert::ToString(User_ID), Convert::ToString(ReceivedMessages[User_ID].size()), form);
	else
	{
		Label^ noContactMessage = gcnew Label();

		//Properties for Label
		noContactMessage->Text = "Couldn't find this contact. :(";
		noContactMessage->ForeColor = Color::White;
		noContactMessage->AutoSize = true;
		noContactMessage->Margin = Padding(20);
		noContactMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));

		container->Controls->Add(noContactMessage);
	}
}

