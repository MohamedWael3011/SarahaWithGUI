#pragma once
#include "main.h"
#include "UserForm.h"

namespace SarahaWithGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Zusammenfassung für MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ LoginScreen_LeftPart;
	protected:
	private: System::Windows::Forms::Panel^ LoginScreen_RightPart;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ Login_Username;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ Login_Password;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ ProfileIcon;
	private: System::Windows::Forms::Button^ LoginButton;
	private: System::Windows::Forms::Button^ CloseButton;
	private: System::Windows::Forms::Panel^ Register_Left;
	private: System::Windows::Forms::Button^ Register_Login;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ Login_Register;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ Register_Right;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::TextBox^ Register_PasswordC;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ Register;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ Register_Password;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ Register_Username;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->LoginScreen_LeftPart = (gcnew System::Windows::Forms::Panel());
			this->Register_Left = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Register_Login = (gcnew System::Windows::Forms::Button());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Login_Register = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->LoginScreen_RightPart = (gcnew System::Windows::Forms::Panel());
			this->Register_Right = (gcnew System::Windows::Forms::Panel());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->Register_PasswordC = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Register = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->Register_Password = (gcnew System::Windows::Forms::TextBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->Register_Username = (gcnew System::Windows::Forms::TextBox());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->LoginButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->ProfileIcon = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->Login_Password = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Login_Username = (gcnew System::Windows::Forms::TextBox());
			this->LoginScreen_LeftPart->SuspendLayout();
			this->Register_Left->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->LoginScreen_RightPart->SuspendLayout();
			this->Register_Right->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProfileIcon))->BeginInit();
			this->SuspendLayout();
			// 
			// LoginScreen_LeftPart
			// 
			this->LoginScreen_LeftPart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->LoginScreen_LeftPart->Controls->Add(this->Register_Left);
			this->LoginScreen_LeftPart->Controls->Add(this->label4);
			this->LoginScreen_LeftPart->Controls->Add(this->Login_Register);
			this->LoginScreen_LeftPart->Controls->Add(this->pictureBox2);
			this->LoginScreen_LeftPart->Dock = System::Windows::Forms::DockStyle::Left;
			this->LoginScreen_LeftPart->Location = System::Drawing::Point(0, 0);
			this->LoginScreen_LeftPart->Name = L"LoginScreen_LeftPart";
			this->LoginScreen_LeftPart->Size = System::Drawing::Size(443, 593);
			this->LoginScreen_LeftPart->TabIndex = 5;
			this->LoginScreen_LeftPart->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->LoginScreen_LeftPart->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->LoginScreen_LeftPart->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			// 
			// Register_Left
			// 
			this->Register_Left->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->Register_Left->Controls->Add(this->label3);
			this->Register_Left->Controls->Add(this->Register_Login);
			this->Register_Left->Controls->Add(this->pictureBox6);
			this->Register_Left->Controls->Add(this->label1);
			this->Register_Left->Controls->Add(this->label2);
			this->Register_Left->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Register_Left->Location = System::Drawing::Point(0, 0);
			this->Register_Left->Name = L"Register_Left";
			this->Register_Left->Size = System::Drawing::Size(443, 593);
			this->Register_Left->TabIndex = 6;
			this->Register_Left->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->Register_Left->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->Register_Left->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label3->Location = System::Drawing::Point(120, 137);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(233, 46);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Welcome to";
			// 
			// Register_Login
			// 
			this->Register_Login->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->Register_Login->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Register_Login->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Register_Login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Register_Login->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Register_Login->Location = System::Drawing::Point(128, 374);
			this->Register_Login->Name = L"Register_Login";
			this->Register_Login->Size = System::Drawing::Size(186, 38);
			this->Register_Login->TabIndex = 4;
			this->Register_Login->Text = L"Log in";
			this->Register_Login->UseVisualStyleBackColor = false;
			this->Register_Login->Click += gcnew System::EventHandler(this, &MainForm::Register_Login_Click);
			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(73, 215);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(300, 118);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox6->TabIndex = 7;
			this->pictureBox6->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label1->Location = System::Drawing::Point(120, 137);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(233, 46);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Welcome to";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label2->Location = System::Drawing::Point(120, 137);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(233, 46);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Welcome to";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->label4->Location = System::Drawing::Point(120, 137);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(233, 46);
			this->label4->TabIndex = 27;
			this->label4->Text = L"Welcome to";
			// 
			// Login_Register
			// 
			this->Login_Register->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(12)));
			this->Login_Register->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Login_Register->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Login_Register->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Login_Register->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Login_Register->Location = System::Drawing::Point(128, 374);
			this->Login_Register->Name = L"Login_Register";
			this->Login_Register->Size = System::Drawing::Size(186, 38);
			this->Login_Register->TabIndex = 26;
			this->Login_Register->Text = L"Register";
			this->Login_Register->UseVisualStyleBackColor = false;
			this->Login_Register->Click += gcnew System::EventHandler(this, &MainForm::Login_Register_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(73, 215);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(300, 118);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// LoginScreen_RightPart
			// 
			this->LoginScreen_RightPart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->LoginScreen_RightPart->Controls->Add(this->Register_Right);
			this->LoginScreen_RightPart->Controls->Add(this->CloseButton);
			this->LoginScreen_RightPart->Controls->Add(this->LoginButton);
			this->LoginScreen_RightPart->Controls->Add(this->pictureBox1);
			this->LoginScreen_RightPart->Controls->Add(this->ProfileIcon);
			this->LoginScreen_RightPart->Controls->Add(this->panel2);
			this->LoginScreen_RightPart->Controls->Add(this->Login_Password);
			this->LoginScreen_RightPart->Controls->Add(this->panel1);
			this->LoginScreen_RightPart->Controls->Add(this->Login_Username);
			this->LoginScreen_RightPart->Location = System::Drawing::Point(443, 0);
			this->LoginScreen_RightPart->Name = L"LoginScreen_RightPart";
			this->LoginScreen_RightPart->Size = System::Drawing::Size(563, 593);
			this->LoginScreen_RightPart->TabIndex = 11;
			this->LoginScreen_RightPart->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::LoginScreen_RightPart_Paint);
			this->LoginScreen_RightPart->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->LoginScreen_RightPart->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->LoginScreen_RightPart->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			// 
			// Register_Right
			// 
			this->Register_Right->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->Register_Right->Controls->Add(this->pictureBox5);
			this->Register_Right->Controls->Add(this->panel6);
			this->Register_Right->Controls->Add(this->Register_PasswordC);
			this->Register_Right->Controls->Add(this->button1);
			this->Register_Right->Controls->Add(this->Register);
			this->Register_Right->Controls->Add(this->pictureBox3);
			this->Register_Right->Controls->Add(this->pictureBox4);
			this->Register_Right->Controls->Add(this->panel4);
			this->Register_Right->Controls->Add(this->Register_Password);
			this->Register_Right->Controls->Add(this->panel5);
			this->Register_Right->Controls->Add(this->Register_Username);
			this->Register_Right->Location = System::Drawing::Point(0, 0);
			this->Register_Right->Name = L"Register_Right";
			this->Register_Right->Size = System::Drawing::Size(563, 593);
			this->Register_Right->TabIndex = 12;
			this->Register_Right->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->Register_Right->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->Register_Right->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(95, 302);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(32, 32);
			this->pictureBox5->TabIndex = 13;
			this->pictureBox5->TabStop = false;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->panel6->Location = System::Drawing::Point(133, 327);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(304, 3);
			this->panel6->TabIndex = 14;
			// 
			// Register_PasswordC
			// 
			this->Register_PasswordC->AccessibleName = L"";
			this->Register_PasswordC->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->Register_PasswordC->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Register_PasswordC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Register_PasswordC->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Register_PasswordC->Location = System::Drawing::Point(133, 302);
			this->Register_PasswordC->Name = L"Register_PasswordC";
			this->Register_PasswordC->Size = System::Drawing::Size(304, 23);
			this->Register_PasswordC->TabIndex = 2;
			this->Register_PasswordC->Text = L"Confirm Password";
			this->Register_PasswordC->GotFocus += gcnew System::EventHandler(this, &MainForm::Register_PasswordC_Enter);
			this->Register_PasswordC->Leave += gcnew System::EventHandler(this, &MainForm::Register_PasswordC_Leave);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(528, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(32, 32);
			this->button1->TabIndex = 100;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// Register
			// 
			this->Register->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				static_cast<System::Int32>(static_cast<System::Byte>(103)));
			this->Register->FlatAppearance->BorderSize = 0;
			this->Register->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Register->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Register->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Register->Location = System::Drawing::Point(156, 374);
			this->Register->Name = L"Register";
			this->Register->Size = System::Drawing::Size(229, 38);
			this->Register->TabIndex = 3;
			this->Register->Text = L"Register";
			this->Register->UseVisualStyleBackColor = false;
			this->Register->Click += gcnew System::EventHandler(this, &MainForm::Register_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(95, 248);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(32, 32);
			this->pictureBox3->TabIndex = 15;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(95, 194);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(32, 32);
			this->pictureBox4->TabIndex = 16;
			this->pictureBox4->TabStop = false;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->panel4->Location = System::Drawing::Point(133, 273);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(304, 3);
			this->panel4->TabIndex = 17;
			// 
			// Register_Password
			// 
			this->Register_Password->AccessibleName = L"";
			this->Register_Password->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->Register_Password->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Register_Password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Register_Password->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Register_Password->Location = System::Drawing::Point(133, 248);
			this->Register_Password->Name = L"Register_Password";
			this->Register_Password->Size = System::Drawing::Size(304, 23);
			this->Register_Password->TabIndex = 1;
			this->Register_Password->Text = L"Password";
			this->Register_Password->GotFocus += gcnew System::EventHandler(this, &MainForm::Register_Password_Enter);
			this->Register_Password->Leave += gcnew System::EventHandler(this, &MainForm::Register_Password_Leave);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->panel5->Location = System::Drawing::Point(133, 219);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(304, 3);
			this->panel5->TabIndex = 18;
			// 
			// Register_Username
			// 
			this->Register_Username->AccessibleName = L"";
			this->Register_Username->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->Register_Username->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Register_Username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Register_Username->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Register_Username->Location = System::Drawing::Point(133, 194);
			this->Register_Username->Name = L"Register_Username";
			this->Register_Username->Size = System::Drawing::Size(304, 23);
			this->Register_Username->TabIndex = 0;
			this->Register_Username->Text = L"Username";
			this->Register_Username->GotFocus += gcnew System::EventHandler(this, &MainForm::Register_Username_Enter);
			this->Register_Username->Leave += gcnew System::EventHandler(this, &MainForm::Register_Username_Leave);
			// 
			// CloseButton
			// 
			this->CloseButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->CloseButton->FlatAppearance->BorderSize = 0;
			this->CloseButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CloseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CloseButton->ForeColor = System::Drawing::Color::White;
			this->CloseButton->Location = System::Drawing::Point(528, 3);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(32, 32);
			this->CloseButton->TabIndex = 101;
			this->CloseButton->Text = L"X";
			this->CloseButton->UseVisualStyleBackColor = false;
			this->CloseButton->Click += gcnew System::EventHandler(this, &MainForm::CloseButton_Click);
			// 
			// LoginButton
			// 
			this->LoginButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(67)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				static_cast<System::Int32>(static_cast<System::Byte>(103)));
			this->LoginButton->FlatAppearance->BorderSize = 0;
			this->LoginButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LoginButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoginButton->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->LoginButton->Location = System::Drawing::Point(156, 374);
			this->LoginButton->Name = L"LoginButton";
			this->LoginButton->Size = System::Drawing::Size(229, 38);
			this->LoginButton->TabIndex = 25;
			this->LoginButton->Text = L"Log in";
			this->LoginButton->UseVisualStyleBackColor = false;
			this->LoginButton->Click += gcnew System::EventHandler(this, &MainForm::Login_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(95, 308);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(32, 32);
			this->pictureBox1->TabIndex = 19;
			this->pictureBox1->TabStop = false;
			// 
			// ProfileIcon
			// 
			this->ProfileIcon->Location = System::Drawing::Point(95, 264);
			this->ProfileIcon->Name = L"ProfileIcon";
			this->ProfileIcon->Size = System::Drawing::Size(32, 32);
			this->ProfileIcon->TabIndex = 20;
			this->ProfileIcon->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->panel2->Location = System::Drawing::Point(133, 333);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(304, 3);
			this->panel2->TabIndex = 21;
			// 
			// Login_Password
			// 
			this->Login_Password->AccessibleName = L"";
			this->Login_Password->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->Login_Password->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Login_Password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Login_Password->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Login_Password->Location = System::Drawing::Point(133, 308);
			this->Login_Password->Name = L"Login_Password";
			this->Login_Password->Size = System::Drawing::Size(304, 23);
			this->Login_Password->TabIndex = 24;
			this->Login_Password->Text = L"Password";
			this->Login_Password->GotFocus += gcnew System::EventHandler(this, &MainForm::Login_Password_Enter);
			this->Login_Password->Leave += gcnew System::EventHandler(this, &MainForm::Login_Password_Leave);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->panel1->Location = System::Drawing::Point(133, 289);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(304, 3);
			this->panel1->TabIndex = 22;
			// 
			// Login_Username
			// 
			this->Login_Username->AccessibleName = L"";
			this->Login_Username->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)));
			this->Login_Username->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Login_Username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Login_Username->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->Login_Username->Location = System::Drawing::Point(133, 264);
			this->Login_Username->Name = L"Login_Username";
			this->Login_Username->Size = System::Drawing::Size(304, 23);
			this->Login_Username->TabIndex = 23;
			this->Login_Username->Text = L"Username";
			this->Login_Username->GotFocus += gcnew System::EventHandler(this, &MainForm::Login_Username_Enter);
			this->Login_Username->Leave += gcnew System::EventHandler(this, &MainForm::Login_Username_Leave);
			// 
			// MainForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1006, 593);
			this->Controls->Add(this->LoginScreen_RightPart);
			this->Controls->Add(this->LoginScreen_LeftPart);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(8);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Saraha";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			this->LoginScreen_LeftPart->ResumeLayout(false);
			this->LoginScreen_LeftPart->PerformLayout();
			this->Register_Left->ResumeLayout(false);
			this->Register_Left->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->LoginScreen_RightPart->ResumeLayout(false);
			this->LoginScreen_RightPart->PerformLayout();
			this->Register_Right->ResumeLayout(false);
			this->Register_Right->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProfileIcon))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		cfg.Load();

		this->pictureBox4->Image = System::Drawing::Image::FromFile("img/ProfileIcon.png");
		this->pictureBox5->Image = System::Drawing::Image::FromFile("img/PassIcon.png");
		this->pictureBox3->Image = System::Drawing::Image::FromFile("img/PassIcon.png");
		this->pictureBox6->Image = System::Drawing::Image::FromFile("img/AppLogo.png");
		this->pictureBox2->Image = System::Drawing::Image::FromFile("img/AppLogo.png");
		this->pictureBox1->Image = System::Drawing::Image::FromFile("img/PassIcon.png");
		this->ProfileIcon->Image = System::Drawing::Image::FromFile("img/ProfileIcon.png");

	}

	private: System::Void MainForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		cfg.Save();
	}

	private: System::Void LoginScreen_RightPart_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}


private: System::Void Login_Username_Enter(System::Object^ sender, System::EventArgs^ e) {
	if (Login_Username->Text == "Username")
		Login_Username->Text = "";
}

private: System::Void Login_Username_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if(Login_Username->Text =="Username")
		Login_Username->Text = "";
}

private: System::Void Login_Username_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (Login_Username->Text == "")
		Login_Username->Text = "Username";
}

	private: System::Void Login_Password_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (Login_Password->Text == "Password")
		{
			Login_Password->UseSystemPasswordChar = true;
			Login_Password->Text = "";
		}
	}

private: System::Void Login_Password_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (Login_Password->Text == "Password")
	{
		Login_Password->UseSystemPasswordChar = true;
		Login_Password->Text = "";
	}
}

private: System::Void Login_Password_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (Login_Password->Text == "")
	{
		Login_Password->Text = "Password";
		Login_Password->UseSystemPasswordChar = false;
	}

}

private: System::Void CloseButton_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

private: System::Void Register_Username_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (Register_Username->Text == "Username")
		Register_Username->Text = "";
}

private: System::Void Register_Username_Enter(System::Object^ sender, System::EventArgs^ e) {
	if (Register_Username->Text == "Username")
		Register_Username->Text = "";
}

private: System::Void Register_Username_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (Register_Username->Text == "")
		Register_Username->Text = "Username";
}

private: System::Void Register_Password_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (Register_Password->Text == "")
	{
		Register_Password->Text = "Password";
		Register_Password->UseSystemPasswordChar = false;
	}
}

private: System::Void Register_Password_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (Register_Password->Text == "Password")
	{
		Register_Password->UseSystemPasswordChar = true;
		Register_Password->Text = "";
	}
}

private: System::Void Register_Password_Enter(System::Object^ sender, System::EventArgs^ e) {
	if (Register_Password->Text == "Password")
	{
		Register_Password->UseSystemPasswordChar = true;
		Register_Password->Text = "";
	}
}

private: System::Void Register_PasswordC_Enter(System::Object^ sender, System::EventArgs^ e) {
	if (Register_PasswordC->Text == "Confirm Password")
	{
		Register_PasswordC->UseSystemPasswordChar = true;
		Register_PasswordC->Text = "";
	}
}

private: System::Void Register_PasswordC_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (Register_PasswordC->Text == "Confirm Password")
	{
		Register_PasswordC->UseSystemPasswordChar = true;
		Register_PasswordC->Text = "";
	}	
}

private: System::Void Register_PasswordC_Leave(System::Object^ sender, System::EventArgs^ e)
{
	if (Register_PasswordC->Text == "")
	{
		Register_PasswordC->Text = "Confirm Password";
		Register_PasswordC->UseSystemPasswordChar = false;
	}
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

private: System::Void Register_Login_Click(System::Object^ sender, System::EventArgs^ e)
{
	Register_Right->Hide();
	Register_Left->Hide();
	Register_Username->Text = "Username";
	Register_Password->Text = "Password";
	Register_PasswordC->Text = "Confirm Password";
	Register_Password->UseSystemPasswordChar = false;
	Register_PasswordC->UseSystemPasswordChar = false;
}

private: System::Void Login_Register_Click(System::Object^ sender, System::EventArgs^ e)
{
	Register_Right->Show();
	Register_Left->Show();
	Login_Username->Text = "Username";
	Login_Password->Text = "Password";
	Login_Password->UseSystemPasswordChar = false;
}

private: System::Void Register_Click(System::Object^  sender, System::EventArgs^  e)
{
	const char* errormsg = NULL;

	if (Register_Username->Text == "Username" || Register_Username->Text->Length < 4 || Register_Username->Text->Length > 16)
		errormsg = "Username must be between 4 and 16 characters.";
	else if (Register_Password->Text == "Password" || Register_Password->Text->Length < 4 || Register_Password->Text->Length > 24)
		errormsg = "Password must be between 4 and 24 characters.";
 	else if (Register_PasswordC->Text == "Confirm Password" || Register_PasswordC->Text != Register_Password->Text)
		errormsg = "Password and confirmation must be the same.";
	else
	{
		string username = SystemStringToCpp(Register_Username->Text), pw = SystemStringToCpp(Register_Password->Text);

		if (!cfg.AccountExists(username))
		{
			UserAccount acc(cfg.PopNextAccountID(), username, pw);
			cfg.UserAccounts[acc.ID()] = acc;
		}
		else
			errormsg = "Username is already in use, please choose another one.";
	}

	if (errormsg)
		MessageBox::Show(CPPSTR2SYSTEM(errormsg), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else
	{
		MessageBox::Show("Your account has been registered successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		Register_Login_Click(nullptr, nullptr);
	}
}

private: System::Void Login_Click(System::Object^  sender, System::EventArgs^  e)
{
	const char* errormsg = NULL;

	if (Login_Username->Text == "Username" || Login_Password->Text == "Password")
		errormsg = "Please fill missing fields.";
	else
	{
		string username = SystemStringToCpp(Login_Username->Text), pw = SystemStringToCpp(Login_Password->Text);

		if (UserAccount* user = cfg.AccountExists(username, pw))
			current_user = user;
		else
			errormsg = "Could not login, incorrect username or password.";
	}

	if (errormsg)
		MessageBox::Show(CPPSTR2SYSTEM(errormsg), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else
	{
		MessageBox::Show("You have logged in successfully.", "Logged in", MessageBoxButtons::OK, MessageBoxIcon::Information);
		Hide();

		Login_Username->Text = "Username";
		Login_Password->Text = "Password";
		Login_Password->UseSystemPasswordChar = false;

		UserForm^ form = gcnew UserForm(this);
		form->Show();
	}
}
	   bool Drag;
	   Point offset;
private: System::Void MainForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Drag = true;
	offset.X = e->X;
	offset.Y = e->Y;

}
private: System::Void MainForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (Drag)
	{
		Point Curr = PointToScreen(Point(e->X, e->Y));
		Location = Point(Curr.X - offset.X, Curr.Y - offset.Y);
	}
}
private: System::Void MainForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Drag = false;
}

};
}
