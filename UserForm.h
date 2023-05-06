#pragma once
#include "main.h"
#include <array>
#include <string>
namespace SarahaWithGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;


	/// <summary>
	/// Summary for UserForm
	/// </summary>
	public ref class UserForm : public System::Windows::Forms::Form
	{
	private: Control^ m_selectedpanel;


	private: System::Windows::Forms::FlowLayoutPanel^  FavoritesPanel;
	private: System::Windows::Forms::FlowLayoutPanel^  SendPanel;
	private: System::Windows::Forms::Form^ otherform;

	public:

		UserForm(System::Windows::Forms::Form^ o)
		{
			otherform = o;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ Options;

	private: System::Windows::Forms::Button^ LogoutButton;
	private: System::Windows::Forms::Button^ SendButton;
	private: System::Windows::Forms::Button^ ContactsButton;
	private: System::Windows::Forms::Button^ InboxButton;
	private: System::Windows::Forms::Panel^ InboxPanel;


	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ SentButton;

	private: System::Windows::Forms::Button^ ReceivedButton;
	private: System::Windows::Forms::Button^ FavoriteButton;
	private: System::Windows::Forms::FlowLayoutPanel^  MsgsPanel;
	private: System::Windows::Forms::FlowLayoutPanel^  ContactsPanel;







	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserForm::typeid));
			this->Options = (gcnew System::Windows::Forms::Panel());
			this->FavoriteButton = (gcnew System::Windows::Forms::Button());
			this->LogoutButton = (gcnew System::Windows::Forms::Button());
			this->SendButton = (gcnew System::Windows::Forms::Button());
			this->ContactsButton = (gcnew System::Windows::Forms::Button());
			this->InboxButton = (gcnew System::Windows::Forms::Button());
			this->SendPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->InboxPanel = (gcnew System::Windows::Forms::Panel());
			this->MsgsPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SentButton = (gcnew System::Windows::Forms::Button());
			this->ReceivedButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->FavoritesPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ContactsPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->Options->SuspendLayout();
			this->InboxPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// Options
			// 
			this->Options->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->Options->Controls->Add(this->FavoriteButton);
			this->Options->Controls->Add(this->LogoutButton);
			this->Options->Controls->Add(this->SendButton);
			this->Options->Controls->Add(this->ContactsButton);
			this->Options->Controls->Add(this->InboxButton);
			this->Options->Dock = System::Windows::Forms::DockStyle::Left;
			this->Options->Location = System::Drawing::Point(0, 0);
			this->Options->Name = L"Options";
			this->Options->Size = System::Drawing::Size(109, 546);
			this->Options->TabIndex = 0;
			this->Options->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseDown);
			this->Options->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseMove);
			this->Options->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseUp);
			// 
			// FavoriteButton
			// 
			this->FavoriteButton->FlatAppearance->BorderSize = 0;
			this->FavoriteButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FavoriteButton->ForeColor = System::Drawing::Color::Transparent;
			this->FavoriteButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FavoriteButton.Image")));
			this->FavoriteButton->Location = System::Drawing::Point(18, 327);
			this->FavoriteButton->Name = L"FavoriteButton";
			this->FavoriteButton->Size = System::Drawing::Size(72, 72);
			this->FavoriteButton->TabIndex = 4;
			this->FavoriteButton->UseVisualStyleBackColor = true;
			this->FavoriteButton->Click += gcnew System::EventHandler(this, &UserForm::FavoriteButton_Click);
			// 
			// LogoutButton
			// 
			this->LogoutButton->FlatAppearance->BorderSize = 0;
			this->LogoutButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LogoutButton->ForeColor = System::Drawing::Color::Transparent;
			this->LogoutButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LogoutButton.Image")));
			this->LogoutButton->Location = System::Drawing::Point(18, 449);
			this->LogoutButton->Name = L"LogoutButton";
			this->LogoutButton->Size = System::Drawing::Size(72, 72);
			this->LogoutButton->TabIndex = 3;
			this->LogoutButton->UseVisualStyleBackColor = true;
			this->LogoutButton->Click += gcnew System::EventHandler(this, &UserForm::LogoutButton_Click);
			// 
			// SendButton
			// 
			this->SendButton->FlatAppearance->BorderSize = 0;
			this->SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SendButton->ForeColor = System::Drawing::Color::Transparent;
			this->SendButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SendButton.Image")));
			this->SendButton->Location = System::Drawing::Point(18, 237);
			this->SendButton->Name = L"SendButton";
			this->SendButton->Size = System::Drawing::Size(72, 72);
			this->SendButton->TabIndex = 2;
			this->SendButton->UseVisualStyleBackColor = true;
			this->SendButton->Click += gcnew System::EventHandler(this, &UserForm::SendButton_MouseClick);
			// 
			// ContactsButton
			// 
			this->ContactsButton->FlatAppearance->BorderSize = 0;
			this->ContactsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ContactsButton->ForeColor = System::Drawing::Color::Transparent;
			this->ContactsButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ContactsButton.Image")));
			this->ContactsButton->Location = System::Drawing::Point(18, 147);
			this->ContactsButton->Name = L"ContactsButton";
			this->ContactsButton->Size = System::Drawing::Size(72, 72);
			this->ContactsButton->TabIndex = 1;
			this->ContactsButton->UseVisualStyleBackColor = true;
			this->ContactsButton->Click += gcnew System::EventHandler(this, &UserForm::ContactsButton_MouseClick);
			// 
			// InboxButton
			// 
			this->InboxButton->FlatAppearance->BorderSize = 0;
			this->InboxButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->InboxButton->ForeColor = System::Drawing::Color::Transparent;
			this->InboxButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InboxButton.Image")));
			this->InboxButton->Location = System::Drawing::Point(18, 57);
			this->InboxButton->Name = L"InboxButton";
			this->InboxButton->Size = System::Drawing::Size(72, 72);
			this->InboxButton->TabIndex = 0;
			this->InboxButton->UseVisualStyleBackColor = true;
			this->InboxButton->Click += gcnew System::EventHandler(this, &UserForm::InboxButton_MouseClick);
			// 
			// SendPanel
			// 
			this->SendPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->SendPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->SendPanel->Location = System::Drawing::Point(109, 0);
			this->SendPanel->Name = L"SendPanel";
			this->SendPanel->Size = System::Drawing::Size(879, 546);
			this->SendPanel->TabIndex = 106;
			this->SendPanel->Visible = false;
			// 
			// InboxPanel
			// 
			this->InboxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->InboxPanel->Controls->Add(this->MsgsPanel);
			this->InboxPanel->Controls->Add(this->SentButton);
			this->InboxPanel->Controls->Add(this->ReceivedButton);
			this->InboxPanel->Controls->Add(this->button1);
			this->InboxPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->InboxPanel->Location = System::Drawing::Point(109, 0);
			this->InboxPanel->Name = L"InboxPanel";
			this->InboxPanel->Size = System::Drawing::Size(879, 546);
			this->InboxPanel->TabIndex = 1;
			this->InboxPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseDown);
			this->InboxPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseMove);
			this->InboxPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseUp);
			// 
			// MsgsPanel
			// 
			this->MsgsPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->MsgsPanel->Location = System::Drawing::Point(0, 135);
			this->MsgsPanel->Name = L"MsgsPanel";
			this->MsgsPanel->Size = System::Drawing::Size(879, 408);
			this->MsgsPanel->TabIndex = 104;
			CreateMessageLayout(MsgsPanel);
			// 
			// SentButton
			// 
			this->SentButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->SentButton->FlatAppearance->BorderSize = 0;
			this->SentButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SentButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SentButton->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->SentButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SentButton.Image")));
			this->SentButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->SentButton->Location = System::Drawing::Point(451, 57);
			this->SentButton->Name = L"SentButton";
			this->SentButton->Size = System::Drawing::Size(336, 43);
			this->SentButton->TabIndex = 103;
			this->SentButton->Text = L"Sent";
			this->SentButton->UseVisualStyleBackColor = false;
			// 
			// ReceivedButton
			// 
			this->ReceivedButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->ReceivedButton->FlatAppearance->BorderSize = 0;
			this->ReceivedButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ReceivedButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ReceivedButton->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ReceivedButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ReceivedButton.Image")));
			this->ReceivedButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->ReceivedButton->Location = System::Drawing::Point(55, 57);
			this->ReceivedButton->Name = L"ReceivedButton";
			this->ReceivedButton->Size = System::Drawing::Size(336, 43);
			this->ReceivedButton->TabIndex = 102;
			this->ReceivedButton->Text = L"Received";
			this->ReceivedButton->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(847, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(32, 32);
			this->button1->TabIndex = 101;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &UserForm::button1_Click_1);
			// 
			// FavoritesPanel
			// 
			this->FavoritesPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->FavoritesPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->FavoritesPanel->Location = System::Drawing::Point(109, 0);
			this->FavoritesPanel->Name = L"FavoritesPanel";
			this->FavoritesPanel->Size = System::Drawing::Size(879, 546);
			this->FavoritesPanel->TabIndex = 107;
			// 
			// ContactsPanel
			// 
			this->ContactsPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->ContactsPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->ContactsPanel->Location = System::Drawing::Point(109, 0);
			this->ContactsPanel->Name = L"ContactsPanel";
			this->ContactsPanel->Size = System::Drawing::Size(879, 546);
			this->ContactsPanel->TabIndex = 105;
			// 
			// UserForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(988, 546);
			this->Controls->Add(this->InboxPanel);
			this->Controls->Add(this->FavoritesPanel);
			this->Controls->Add(this->ContactsPanel);
			this->Controls->Add(this->SendPanel);
			this->Controls->Add(this->Options);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"UserForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UserForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &UserForm::UserForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &UserForm::UserForm_Load);
			this->Options->ResumeLayout(false);
			this->InboxPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}


#pragma endregion

	private: System::Void UserForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		InboxButton->Image = System::Drawing::Image::FromFile("img/SelectedInbox.png");
		ReceivedButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
			static_cast<System::Int32>(static_cast<System::Byte>(103)));

		//load panels
		ShowPanels(false);
		InboxButton_MouseClick(nullptr, nullptr);
	}

	private: System::Void UserForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		cfg.Save();
	}

private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

	   bool Drag;
	   Point offset;
private: System::Void UserForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Drag = true;
	offset.X = e->X;
	offset.Y = e->Y;

}
private: System::Void UserForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (Drag)
	{
		Point Curr = PointToScreen(Point(e->X, e->Y));
		Location = Point(Curr.X - offset.X, Curr.Y - offset.Y);
	}
}
private: System::Void UserForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Drag = false;
}


void resetButtons() {
	InboxButton->Image = System::Drawing::Image::FromFile("img/Inbox.png");
	ContactsButton->Image = System::Drawing::Image::FromFile("img/Contacts.png");
	SendButton->Image = System::Drawing::Image::FromFile("img/Send.png");
	FavoriteButton->Image = System::Drawing::Image::FromFile("img/Favorite.png");
}

private: System::Void ShowPanels(bool visible)
{
	this->InboxPanel->Visible = visible;
	this->ContactsPanel->Visible = visible;
	this->SendPanel->Visible = visible;
	this->FavoritesPanel->Visible = visible;
}

private: System::Void SelectPanel(Control^ panel)
{
	if (m_selectedpanel != nullptr)
		m_selectedpanel->Hide();

	panel->Show();
	m_selectedpanel = panel;
}

private: System::Void InboxButton_MouseClick(System::Object^ sender, System::EventArgs^ e) {
	resetButtons();
	InboxButton->Image = System::Drawing::Image::FromFile("img/SelectedInbox.png");
	SelectPanel(InboxPanel);
}
private: System::Void ContactsButton_MouseClick(System::Object^ sender, System::EventArgs^ e) {
	resetButtons();
	ContactsButton->Image = System::Drawing::Image::FromFile("img/SelectedContacts.png");
	SelectPanel(ContactsPanel);
}
private: System::Void SendButton_MouseClick(System::Object^ sender, System::EventArgs^ e) {
	resetButtons();
	SendButton->Image = System::Drawing::Image::FromFile("img/SelectedSend.png");
	SelectPanel(SendPanel);
}

private: System::Void FavoriteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	resetButtons();
	FavoriteButton->Image = System::Drawing::Image::FromFile("img/SelectedFavorite.png");
	SelectPanel(FavoritesPanel);
}

private: System::Void LogoutButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	otherform->Show();
}

	   Panel^ CreateMessageBox(String^ message)
	   {
		   Panel^ messageContainer = gcnew Panel();
		   RichTextBox^ messageBox = gcnew RichTextBox();

		   int wordCount = 0;
		 
		   String^ messageContent = message;

		   //Limiting the number of characters per line to 45
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
	   Panel^ CreateUIDPanel(String^ ID)
	   {
		   Panel^ uIDContainer = gcnew Panel();
		   Label^ uIDLabel = gcnew Label();
		   TextBox^ uID = gcnew TextBox();

		   //Label for UID
		   uIDLabel->Text = "By UID: " + ID;
		   uIDLabel->ForeColor = Color::White;

		   //Properties for Panel
		   uIDContainer->Width = uIDLabel->Width;
		   uIDContainer->Height = uIDLabel->Height;
		   uIDContainer->BorderStyle = BorderStyle::None;
		   uIDContainer->BackColor = Color::Black;
		   uIDContainer->AutoSize = true;

		   //Adding the label inside panel
		   uIDContainer->Controls->Add(uIDLabel);

		   return uIDContainer;
	   }
	   Panel^ CreateMainMessagePanel(String^ message, String^ ID)
	   {
		   Panel^ MainPanel = gcnew Panel();
		   Panel^ MessageBoxPanel = CreateMessageBox(message);
		   Panel^ UIDPanel = CreateUIDPanel(ID);

		   //Properties of Main Panel
		   MainPanel->Width = MessageBoxPanel->Width;
		   UIDPanel->Location = Point(0, MessageBoxPanel->Height);
		   MainPanel->AutoSize = true;

		   //Add Panels into Main Panel
		   MainPanel->Controls->Add(MessageBoxPanel);
		   MainPanel->Controls->Add(UIDPanel);

		   return MainPanel;
	   }
	   void CreateMessageLayout(FlowLayoutPanel^ container)
	   {
		   //Flow Layout Properties
		   container->Location = Point(110, 135);
		   container->FlowDirection = FlowDirection::TopDown;
		   container->AutoScroll = true;
		   container->WrapContents = false;

		   //Add the Messages
		   //----This is for Testing---
		   container->Controls->Add(CreateMainMessagePanel("Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum. Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.", "1111"));
		   container->Controls->Add(CreateMainMessagePanel("Hello Karim, Nice to Meet you. I'm Chehab", "2222"));
		   container->Controls->Add(CreateMainMessagePanel(".", "3333"));
		   container->Controls->Add(CreateMainMessagePanel("Je suis Fouad", "4444"));
		   container->Controls->Add(CreateMainMessagePanel("sdfsdfsd", "5555"));
		   //--------------------------
		   this->Controls->Add(container);
	   }
};
}
