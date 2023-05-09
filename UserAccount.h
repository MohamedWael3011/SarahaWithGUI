#pragma once
#include "essentials.h"
#include "UserMessage.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class UserAccount
{
private:
	int m_id;
	string m_username;
	string m_password;
public:
	set<int> Contacts;
	set<int> Blocked;
	stack<pair<int, UserMessage>> SentMessages;
	unordered_map<int, stack<UserMessage>> ReceivedMessages;
	queue<pair<int, UserMessage>> Favorites;

public:
	UserAccount();
	UserAccount(int id, string username, string pw);

	void Set(int id, string username, string pw);

	bool AddContact(int User_ID);
	bool RemoveContact(int User_ID);
	bool Block(int User_ID);
	bool Unblock(int User_ID);
	char SendUserMessage(UserAccount* recipient, string content);
	bool PopUserMessage(UserAccount* user);
	void ViewContacts(); //ordered by most UserMessages
	void ViewReceivedMessages(FlowLayoutPanel^ container);
	void ViewSentMessages(FlowLayoutPanel^ container);
	bool ViewUserMessages(FlowLayoutPanel^ container, int User_ID);
	bool PutFavorite(int User_ID, int Msg_Index);
	bool RemoveOldestFavorite();
	bool ViewFavorites(FlowLayoutPanel^ container);

	int GetUserMessagesFromUser(UserAccount* user);
	bool GetContact(int User_ID);
	int ID() const;
	string Username() const;
	string Password() const;
	bool IsBlocked(int User_ID);
};