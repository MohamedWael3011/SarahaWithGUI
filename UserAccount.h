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
	void SetSentMessageSeen(int Receiver_ID, int Msg_Index, bool seen);
	void ViewContacts(FlowLayoutPanel^ container); //ordered by most UserMessages
	vector<pair<UserMessage, int>> ViewReceivedMessages(FlowLayoutPanel^ container, bool full = false);
	void ViewSentMessages(FlowLayoutPanel^ container);
	bool ViewUserMessages(FlowLayoutPanel^ container, int User_ID);
	bool PutFavorite(int User_ID, int Msg_Index);
	bool RemoveOldestFavorite();
	bool ViewFavorites(FlowLayoutPanel^ container);
	bool DeleteSpecificFavorite(int senderID,int Msg_Index);
	

	int GetUserMessagesFromUser(UserAccount* user);
	bool GetContact(int User_ID);
	int ID() const;
	string Username() const;
	string Password() const;
	bool IsBlocked(int User_ID);
};