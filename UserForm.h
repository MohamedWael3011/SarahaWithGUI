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
	private: System::Windows::Forms::Form^ otherform;
	private: Control^ m_selectedpanel;
	private: Control^ m_selectedinbox;
	private: bool m_lastrecvmsgfull;


	private: System::Windows::Forms::FlowLayoutPanel^ FavoritesPanel;
	private: System::Windows::Forms::Panel^ SendPanel;
	private: System::Windows::Forms::TextBox^ UserIdSendMessage;
	private: System::Windows::Forms::Button^ SendMessageButton;

	private: System::Windows::Forms::RichTextBox^ SendMessageText;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^  ReceivedInboxBtn;


	private: System::Windows::Forms::Button^ InboxButton;
	private: System::Windows::Forms::Button^ ContactsButton;
	private: System::Windows::Forms::Button^ SendButton;
	private: System::Windows::Forms::Button^ LogoutButton;
	private: System::Windows::Forms::Button^ FavoriteButton;
	private: System::Windows::Forms::Panel^ Options;
	private: System::Windows::Forms::Panel^ MainContactPanel;
	private: System::Windows::Forms::FlowLayoutPanel^ ContactsPanel;
	private: System::Windows::Forms::FlowLayoutPanel^ MessagesFromContactsPanel;
	private: System::Windows::Forms::Button^  BlockedButton;
	private: System::Windows::Forms::FlowLayoutPanel^ BlocksPanel;
	private: System::Windows::Forms::Panel^  ContactSidePanel;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::TextBox^  Contact_SearchBox;





























	private: System::Windows::Forms::FlowLayoutPanel^  MsgsPanel;

	public:

		UserForm(System::Windows::Forms::Form^ o)
		{
			otherform = o;
			m_lastrecvmsgfull = false;

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






	private: System::Windows::Forms::Panel^ InboxPanel;
	private: System::Windows::Forms::Button^  ExitButton;




	private: System::Windows::Forms::Button^ SentButton;

	private: System::Windows::Forms::Button^ ReceivedButton;










	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UserForm::typeid));
			this->SendPanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SendMessageButton = (gcnew System::Windows::Forms::Button());
			this->SendMessageText = (gcnew System::Windows::Forms::RichTextBox());
			this->UserIdSendMessage = (gcnew System::Windows::Forms::TextBox());
			this->InboxPanel = (gcnew System::Windows::Forms::Panel());
			this->ReceivedInboxBtn = (gcnew System::Windows::Forms::Button());
			this->MsgsPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SentButton = (gcnew System::Windows::Forms::Button());
			this->ReceivedButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->FavoritesPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->InboxButton = (gcnew System::Windows::Forms::Button());
			this->ContactsButton = (gcnew System::Windows::Forms::Button());
			this->SendButton = (gcnew System::Windows::Forms::Button());
			this->LogoutButton = (gcnew System::Windows::Forms::Button());
			this->FavoriteButton = (gcnew System::Windows::Forms::Button());
			this->Options = (gcnew System::Windows::Forms::Panel());
			this->BlockedButton = (gcnew System::Windows::Forms::Button());
			this->MainContactPanel = (gcnew System::Windows::Forms::Panel());
			this->ContactSidePanel = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->Contact_SearchBox = (gcnew System::Windows::Forms::TextBox());
			this->MessagesFromContactsPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ContactsPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->BlocksPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SendPanel->SuspendLayout();
			this->InboxPanel->SuspendLayout();
			this->Options->SuspendLayout();
			this->MainContactPanel->SuspendLayout();
			this->ContactSidePanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// SendPanel
			// 
			this->SendPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->SendPanel->Controls->Add(this->label2);
			this->SendPanel->Controls->Add(this->label1);
			this->SendPanel->Controls->Add(this->SendMessageButton);
			this->SendPanel->Controls->Add(this->SendMessageText);
			this->SendPanel->Controls->Add(this->UserIdSendMessage);
			this->SendPanel->Location = System::Drawing::Point(109, 0);
			this->SendPanel->Name = L"SendPanel";
			this->SendPanel->Size = System::Drawing::Size(879, 546);
			this->SendPanel->TabIndex = 106;
			this->SendPanel->Visible = false;
			this->SendPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseDown);
			this->SendPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseMove);
			this->SendPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseUp);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->label2->Location = System::Drawing::Point(27, 135);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Message:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->label1->Location = System::Drawing::Point(27, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"User ID:";
			// 
			// SendMessageButton
			// 
			this->SendMessageButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->SendMessageButton->FlatAppearance->BorderSize = 0;
			this->SendMessageButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SendMessageButton->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->SendMessageButton->Location = System::Drawing::Point(662, 449);
			this->SendMessageButton->Name = L"SendMessageButton";
			this->SendMessageButton->Size = System::Drawing::Size(108, 23);
			this->SendMessageButton->TabIndex = 2;
			this->SendMessageButton->Text = L"Send";
			this->SendMessageButton->UseVisualStyleBackColor = false;
			this->SendMessageButton->Click += gcnew System::EventHandler(this, &UserForm::SendMessageButton_Click);
			// 
			// SendMessageText
			// 
			this->SendMessageText->BackColor = System::Drawing::Color::WhiteSmoke;
			this->SendMessageText->Location = System::Drawing::Point(151, 135);
			this->SendMessageText->Name = L"SendMessageText";
			this->SendMessageText->Size = System::Drawing::Size(619, 271);
			this->SendMessageText->TabIndex = 1;
			this->SendMessageText->Text = L"";
			// 
			// UserIdSendMessage
			// 
			this->UserIdSendMessage->BackColor = System::Drawing::Color::WhiteSmoke;
			this->UserIdSendMessage->Location = System::Drawing::Point(151, 57);
			this->UserIdSendMessage->Name = L"UserIdSendMessage";
			this->UserIdSendMessage->Size = System::Drawing::Size(100, 20);
			this->UserIdSendMessage->TabIndex = 0;
			// 
			// InboxPanel
			// 
			this->InboxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->InboxPanel->Controls->Add(this->ReceivedInboxBtn);
			this->InboxPanel->Controls->Add(this->MsgsPanel);
			this->InboxPanel->Controls->Add(this->SentButton);
			this->InboxPanel->Controls->Add(this->ReceivedButton);
			this->InboxPanel->Controls->Add(this->ExitButton);
			this->InboxPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->InboxPanel->Location = System::Drawing::Point(0, 0);
			this->InboxPanel->Name = L"InboxPanel";
			this->InboxPanel->Size = System::Drawing::Size(988, 546);
			this->InboxPanel->TabIndex = 1;
			this->InboxPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseDown);
			this->InboxPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseMove);
			this->InboxPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseUp);
			// 
			// ReceivedInboxBtn
			// 
			this->ReceivedInboxBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->ReceivedInboxBtn->FlatAppearance->BorderSize = 0;
			this->ReceivedInboxBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ReceivedInboxBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ReceivedInboxBtn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->ReceivedInboxBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ReceivedInboxBtn.Image")));
			this->ReceivedInboxBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->ReceivedInboxBtn->Location = System::Drawing::Point(371, 486);
			this->ReceivedInboxBtn->Name = L"ReceivedInboxBtn";
			this->ReceivedInboxBtn->Size = System::Drawing::Size(336, 43);
			this->ReceivedInboxBtn->TabIndex = 105;
			this->ReceivedInboxBtn->Text = L"Inbox";
			this->ReceivedInboxBtn->UseVisualStyleBackColor = false;
			this->ReceivedInboxBtn->Click += gcnew System::EventHandler(this, &UserForm::ReceivedInboxBtn_Click);
			// 
			// MsgsPanel
			// 
			this->MsgsPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->MsgsPanel->Location = System::Drawing::Point(126, 80);
			this->MsgsPanel->Name = L"MsgsPanel";
			this->MsgsPanel->Size = System::Drawing::Size(843, 392);
			this->MsgsPanel->TabIndex = 104;
			this->MsgsPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseDown);
			this->MsgsPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseMove);
			this->MsgsPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseUp);
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
			this->SentButton->Location = System::Drawing::Point(584, 19);
			this->SentButton->Name = L"SentButton";
			this->SentButton->Size = System::Drawing::Size(336, 43);
			this->SentButton->TabIndex = 103;
			this->SentButton->Text = L"Sent";
			this->SentButton->UseVisualStyleBackColor = false;
			this->SentButton->Click += gcnew System::EventHandler(this, &UserForm::SentButton_Click);
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
			this->ReceivedButton->Location = System::Drawing::Point(163, 18);
			this->ReceivedButton->Name = L"ReceivedButton";
			this->ReceivedButton->Size = System::Drawing::Size(336, 43);
			this->ReceivedButton->TabIndex = 102;
			this->ReceivedButton->Text = L"Received";
			this->ReceivedButton->UseVisualStyleBackColor = false;
			this->ReceivedButton->Click += gcnew System::EventHandler(this, &UserForm::ReceivedButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->ExitButton->FlatAppearance->BorderSize = 0;
			this->ExitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ExitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ExitButton->ForeColor = System::Drawing::Color::White;
			this->ExitButton->Location = System::Drawing::Point(956, 3);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(32, 32);
			this->ExitButton->TabIndex = 101;
			this->ExitButton->Text = L"X";
			this->ExitButton->UseVisualStyleBackColor = false;
			this->ExitButton->Click += gcnew System::EventHandler(this, &UserForm::button1_Click_1);
			// 
			// FavoritesPanel
			// 
			this->FavoritesPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->FavoritesPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->FavoritesPanel->Location = System::Drawing::Point(126, 20);
			this->FavoritesPanel->Name = L"FavoritesPanel";
			this->FavoritesPanel->Size = System::Drawing::Size(845, 506);
			this->FavoritesPanel->TabIndex = 107;
			this->FavoritesPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseDown);
			this->FavoritesPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseMove);
			this->FavoritesPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseUp);
			// 
			// InboxButton
			// 
			this->InboxButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->InboxButton->FlatAppearance->BorderSize = 0;
			this->InboxButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->InboxButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->InboxButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->InboxButton->ForeColor = System::Drawing::Color::Transparent;
			this->InboxButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"InboxButton.Image")));
			this->InboxButton->Location = System::Drawing::Point(18, 6);
			this->InboxButton->Name = L"InboxButton";
			this->InboxButton->Size = System::Drawing::Size(72, 72);
			this->InboxButton->TabIndex = 0;
			this->InboxButton->UseVisualStyleBackColor = true;
			this->InboxButton->Click += gcnew System::EventHandler(this, &UserForm::InboxButton_MouseClick);
			// 
			// ContactsButton
			// 
			this->ContactsButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->ContactsButton->FlatAppearance->BorderSize = 0;
			this->ContactsButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->ContactsButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->ContactsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ContactsButton->ForeColor = System::Drawing::Color::Transparent;
			this->ContactsButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ContactsButton.Image")));
			this->ContactsButton->Location = System::Drawing::Point(18, 96);
			this->ContactsButton->Name = L"ContactsButton";
			this->ContactsButton->Size = System::Drawing::Size(72, 72);
			this->ContactsButton->TabIndex = 1;
			this->ContactsButton->UseVisualStyleBackColor = true;
			this->ContactsButton->Click += gcnew System::EventHandler(this, &UserForm::ContactsButton_MouseClick);
			// 
			// SendButton
			// 
			this->SendButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->SendButton->FlatAppearance->BorderSize = 0;
			this->SendButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->SendButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->SendButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SendButton->ForeColor = System::Drawing::Color::Transparent;
			this->SendButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SendButton.Image")));
			this->SendButton->Location = System::Drawing::Point(18, 186);
			this->SendButton->Name = L"SendButton";
			this->SendButton->Size = System::Drawing::Size(72, 72);
			this->SendButton->TabIndex = 2;
			this->SendButton->UseVisualStyleBackColor = true;
			this->SendButton->Click += gcnew System::EventHandler(this, &UserForm::SendButton_MouseClick);
			// 
			// LogoutButton
			// 
			this->LogoutButton->FlatAppearance->BorderSize = 0;
			this->LogoutButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LogoutButton->ForeColor = System::Drawing::Color::Transparent;
			this->LogoutButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LogoutButton.Image")));
			this->LogoutButton->Location = System::Drawing::Point(18, 456);
			this->LogoutButton->Name = L"LogoutButton";
			this->LogoutButton->Size = System::Drawing::Size(72, 72);
			this->LogoutButton->TabIndex = 3;
			this->LogoutButton->UseVisualStyleBackColor = true;
			this->LogoutButton->Click += gcnew System::EventHandler(this, &UserForm::LogoutButton_Click);
			// 
			// FavoriteButton
			// 
			this->FavoriteButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->FavoriteButton->FlatAppearance->BorderSize = 0;
			this->FavoriteButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->FavoriteButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->FavoriteButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FavoriteButton->ForeColor = System::Drawing::Color::Transparent;
			this->FavoriteButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FavoriteButton.Image")));
			this->FavoriteButton->Location = System::Drawing::Point(18, 276);
			this->FavoriteButton->Name = L"FavoriteButton";
			this->FavoriteButton->Size = System::Drawing::Size(72, 72);
			this->FavoriteButton->TabIndex = 4;
			this->FavoriteButton->UseVisualStyleBackColor = true;
			this->FavoriteButton->Click += gcnew System::EventHandler(this, &UserForm::FavoriteButton_Click);
			// 
			// Options
			// 
			this->Options->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->Options->Controls->Add(this->BlockedButton);
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
			// BlockedButton
			// 
			this->BlockedButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->BlockedButton->FlatAppearance->BorderSize = 0;
			this->BlockedButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->BlockedButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->BlockedButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BlockedButton->ForeColor = System::Drawing::Color::Transparent;
			this->BlockedButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BlockedButton.Image")));
			this->BlockedButton->Location = System::Drawing::Point(18, 366);
			this->BlockedButton->Name = L"BlockedButton";
			this->BlockedButton->Size = System::Drawing::Size(72, 72);
			this->BlockedButton->TabIndex = 5;
			this->BlockedButton->UseVisualStyleBackColor = true;
			this->BlockedButton->Click += gcnew System::EventHandler(this, &UserForm::BlockedButton_Click);
			// 
			// MainContactPanel
			// 
			this->MainContactPanel->Controls->Add(this->ContactSidePanel);
			this->MainContactPanel->Controls->Add(this->MessagesFromContactsPanel);
			this->MainContactPanel->Controls->Add(this->ContactsPanel);
			this->MainContactPanel->Location = System::Drawing::Point(109, 0);
			this->MainContactPanel->Name = L"MainContactPanel";
			this->MainContactPanel->Size = System::Drawing::Size(879, 546);
			this->MainContactPanel->TabIndex = 107;
			this->MainContactPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseDown);
			this->MainContactPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseMove);
			this->MainContactPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseUp);
			// 
			// ContactSidePanel
			// 
			this->ContactSidePanel->Controls->Add(this->panel5);
			this->ContactSidePanel->Controls->Add(this->Contact_SearchBox);
			this->ContactSidePanel->Location = System::Drawing::Point(603, 6);
			this->ContactSidePanel->Name = L"ContactSidePanel";
			this->ContactSidePanel->Size = System::Drawing::Size(270, 45);
			this->ContactSidePanel->TabIndex = 0;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->panel5->Location = System::Drawing::Point(7, 34);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(254, 3);
			this->panel5->TabIndex = 20;
			// 
			// Contact_SearchBox
			// 
			this->Contact_SearchBox->AccessibleName = L"";
			this->Contact_SearchBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->Contact_SearchBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Contact_SearchBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Contact_SearchBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Contact_SearchBox->Location = System::Drawing::Point(7, 11);
			this->Contact_SearchBox->Name = L"Contact_SearchBox";
			this->Contact_SearchBox->Size = System::Drawing::Size(254, 19);
			this->Contact_SearchBox->TabIndex = 19;
			this->Contact_SearchBox->Text = L"User ID";
			this->Contact_SearchBox->TextChanged += gcnew System::EventHandler(this, &UserForm::Contact_SearchBox_TextChanged);
			// 
			// MessagesFromContactsPanel
			// 
			this->MessagesFromContactsPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->MessagesFromContactsPanel->Location = System::Drawing::Point(603, 57);
			this->MessagesFromContactsPanel->Name = L"MessagesFromContactsPanel";
			this->MessagesFromContactsPanel->Padding = System::Windows::Forms::Padding(10);
			this->MessagesFromContactsPanel->Size = System::Drawing::Size(270, 486);
			this->MessagesFromContactsPanel->TabIndex = 108;
			this->MessagesFromContactsPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseDown);
			this->MessagesFromContactsPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseMove);
			this->MessagesFromContactsPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseUp);
			// 
			// ContactsPanel
			// 
			this->ContactsPanel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ContactsPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->ContactsPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->ContactsPanel->Location = System::Drawing::Point(3, 0);
			this->ContactsPanel->Margin = System::Windows::Forms::Padding(0);
			this->ContactsPanel->Name = L"ContactsPanel";
			this->ContactsPanel->Padding = System::Windows::Forms::Padding(10);
			this->ContactsPanel->Size = System::Drawing::Size(595, 546);
			this->ContactsPanel->TabIndex = 108;
			this->ContactsPanel->WrapContents = false;
			this->ContactsPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseDown);
			this->ContactsPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseMove);
			this->ContactsPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseUp);
			// 
			// BlocksPanel
			// 
			this->BlocksPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->BlocksPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->BlocksPanel->Location = System::Drawing::Point(109, 12);
			this->BlocksPanel->Name = L"BlocksPanel";
			this->BlocksPanel->Size = System::Drawing::Size(879, 522);
			this->BlocksPanel->TabIndex = 109;
			this->BlocksPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseDown);
			this->BlocksPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseMove);
			this->BlocksPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &UserForm::UserForm_MouseUp);
			// 
			// UserForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->ClientSize = System::Drawing::Size(988, 546);
			this->Controls->Add(this->Options);
			this->Controls->Add(this->MainContactPanel);
			this->Controls->Add(this->BlocksPanel);
			this->Controls->Add(this->InboxPanel);
			this->Controls->Add(this->SendPanel);
			this->Controls->Add(this->FavoritesPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"UserForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Saraha";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &UserForm::UserForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &UserForm::UserForm_Load);
			this->SendPanel->ResumeLayout(false);
			this->SendPanel->PerformLayout();
			this->InboxPanel->ResumeLayout(false);
			this->Options->ResumeLayout(false);
			this->MainContactPanel->ResumeLayout(false);
			this->ContactSidePanel->ResumeLayout(false);
			this->ContactSidePanel->PerformLayout();
			this->ResumeLayout(false);

		}


#pragma endregion

	private: System::Void UserForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		InboxButton->Image = System::Drawing::Image::FromFile("img/SelectedInbox.png");

		//load panels
		ShowPanels(false);
		InboxButton_MouseClick(nullptr, nullptr);

		//load messages
		ReceivedButton_Click(nullptr, nullptr);
	}

	private: System::Void UserForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
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
			   BlockedButton->Image = System::Drawing::Image::FromFile("img/Blocked.png");
		   }

	private: System::Void ShowPanels(bool visible)
	{
		this->InboxPanel->Visible = visible;
		this->MainContactPanel->Visible = visible;
		this->SendPanel->Visible = visible;
		this->FavoritesPanel->Visible = visible;
		this->BlocksPanel->Visible = visible;
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
		SelectPanel(MainContactPanel);

		LoadContacts();
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

		//reload favorites
		FavoritesPanel->Controls->Clear();
		current_user->ViewFavorites(FavoritesPanel, this);
	}

	private: System::Void BlockedButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		resetButtons();
		BlockedButton->Image = System::Drawing::Image::FromFile("img/SelectedBlocked.png");
		SelectPanel(BlocksPanel);

		LoadBlocks();
	}

	private: System::Void LogoutButton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		otherform->Show();
	}

	vector<pair<UserMessage, int>> LoadReceivedMessages(bool full)
	{
		m_lastrecvmsgfull = full;
		MsgsPanel->Controls->Clear();
		
		return current_user->ViewReceivedMessages(MsgsPanel, this, full);
	}

	private: System::Void LoadBlocks()
	{
		//reload blocks
		BlocksPanel->Controls->Clear();
		current_user->ViewBlocks(BlocksPanel, this);
	}

	private: System::Void LoadContacts()
	{
		//reload contacts
		ContactsPanel->Controls->Clear();
		current_user->ViewContacts(ContactsPanel, this);
	}

	private: System::Void ReceivedButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		m_selectedinbox = ReceivedButton;

		ReceivedButton->BackColor = System::Drawing::Color::FromArgb(67, 106, 103);
		SentButton->BackColor = System::Drawing::Color::FromArgb(64, 165, 140);

		ReceivedInboxBtn->Text = "Inbox";

		//reload msgs
		vector <pair<UserMessage, int>> AllUserMessages = LoadReceivedMessages(false);

		//update seen for sender
		cfg.SetSentMsgsSeen(current_user->ID(), AllUserMessages, true);
	}

	private: System::Void SentButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		m_selectedinbox = SentButton;

		ReceivedButton->BackColor = System::Drawing::Color::FromArgb(64, 165, 140);
		SentButton->BackColor = System::Drawing::Color::FromArgb(67, 106, 103);

		ReceivedInboxBtn->Text = "Unsend last message";

		//reload msgs
		MsgsPanel->Controls->Clear();
		current_user->ViewSentMessages(MsgsPanel, this);
	}
	private: System::Void SendMessageButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrEmpty(UserIdSendMessage->Text) || String::IsNullOrEmpty(SendMessageText->Text))
		{
			MessageBox::Show("Please fill all fields first.", "Fill Fields", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;
		}

		int ID = stoi(SystemStringToCpp(UserIdSendMessage->Text));
		char check = current_user->SendUserMessage(cfg.GetUserAccount(ID), SystemStringToCpp(SendMessageText->Text));
		if (check == 1)
		{
			MessageBox::Show("This user does not exist", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;

		}
		else if (check == 2)
		{
			MessageBox::Show("This contact is in your block list; you can't send him a message", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else if (check == 3) {
			MessageBox::Show("This user has you on his block list; you can't send him a message", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;

		}
		MessageBox::Show("Message has been sent", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
	private: System::Void ReceivedInboxBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ReceivedInboxBtn->Text == "Inbox")
			LoadReceivedMessages(true);
		else {
			MsgsPanel->Controls->Clear();

			if (!current_user->SentMessages.empty())
			{
				UserAccount* user = cfg.GetUserAccount(current_user->SentMessages.top().first);
				current_user->PopUserMessage(user);
				current_user->ViewSentMessages(MsgsPanel, this);
			}
			else
				MessageBox::Show("There is no sent message to be removed", "Fail", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
	}

	public: System::Void MessageContact_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ btn = static_cast<Button^>(sender);
		int User_ID = atoi(SystemStringToCpp(btn->Name).c_str());
		
		if (!current_user->GetContact(User_ID))
		{
			if (current_user->AddContact(User_ID))
				btn->Image = System::Drawing::Image::FromFile("img/IsContact.png");
		}
		else if (current_user->RemoveContact(User_ID))
			btn->Image = System::Drawing::Image::FromFile("img/NotContact.png");

		LoadReceivedMessages(m_lastrecvmsgfull);
	}

	public: System::Void MessageFavorite_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ btn = static_cast<Button^>(sender);
		auto splitter = btn->Name->Split(',');

		if (splitter->Length == 2)
		{
			int User_ID = atoi(SystemStringToCpp(splitter[0]).c_str());
			int Msg_Index = atoi(SystemStringToCpp(splitter[1]).c_str());

			if (!current_user->IsFavorite(User_ID, Msg_Index))
			{
				current_user->PutFavorite(User_ID, Msg_Index);
				btn->Image = System::Drawing::Image::FromFile("img/IsFavorite.png");
			}
			else
			{
				current_user->RemoveFavorite(User_ID, Msg_Index);
				btn->Image = System::Drawing::Image::FromFile("img/NotFavorite.png");
			}

			LoadReceivedMessages(m_lastrecvmsgfull);
		}
	}

	public: System::Void MessageBlock_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ btn = static_cast<Button^>(sender);
		int User_ID = atoi(SystemStringToCpp(btn->Name).c_str());

		if (!current_user->IsBlocked(User_ID))
		{
			if (current_user->Block(User_ID))
			{
				MessageBox::Show(String::Format("{0} has been blocked.", User_ID), "Block list", MessageBoxButtons::OK, MessageBoxIcon::Information);
				btn->Image = System::Drawing::Image::FromFile("img/IsBlocked.png");
			}
			else
				MessageBox::Show(String::Format("{0} is already blocked.", User_ID), "Block list", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
		else if (current_user->Unblock(User_ID))
		{
			MessageBox::Show(String::Format("{0} has been unblocked.", User_ID), "Block list", MessageBoxButtons::OK, MessageBoxIcon::Information);
			btn->Image = System::Drawing::Image::FromFile("img/NotBlocked.png");
		}

		LoadReceivedMessages(m_lastrecvmsgfull);
	}
	public: System::Void SeeMessages_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MessagesFromContactsPanel->Controls->Clear();
		//Named the button in CreatPanelFunction as userID
		Button^ btn = static_cast<Button^>(sender);
		int id = atoi(SystemStringToCpp(btn->Name).c_str());
		
		current_user->ViewUserMessages(MessagesFromContactsPanel,this,id);

	}

	public: System::Void BlockContact_btn_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ btn = static_cast<Button^>(sender);
		int id = atoi(SystemStringToCpp(btn->Name).c_str());

		if (current_user->Block(id))
		
			MessageBox::Show("Contact has been blocked", "Block list", MessageBoxButtons::OK, MessageBoxIcon::Information);
		else
			MessageBox::Show("Contact already blocked", "Block list", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	public: System::Void BlockPanel_Unblock_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ btn = static_cast<Button^>(sender);
		int userid = atoi(SystemStringToCpp(btn->Name).c_str());

		if (current_user->Unblock(userid))

			MessageBox::Show("Contact has been unblocked", "Block list", MessageBoxButtons::OK, MessageBoxIcon::Information);
		else
			MessageBox::Show("Contact is not blocked!", "Block list", MessageBoxButtons::OK, MessageBoxIcon::Information);

		LoadBlocks();
	}

private: System::Void Contact_SearchBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (String::IsNullOrEmpty(Contact_SearchBox->Text))
		LoadContacts();
	else
	{
		int userid = atoi(SystemStringToCpp(Contact_SearchBox->Text).c_str());

		ContactsPanel->Controls->Clear();
		current_user->ViewContacts(ContactsPanel, this, userid);
	}
}
};
}
