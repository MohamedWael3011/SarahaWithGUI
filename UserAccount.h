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
	void ViewContacts(FlowLayoutPanel^ container, Form^ form); //ordered by most UserMessages
	void ViewContacts(FlowLayoutPanel^ container, Form^ form, int User_ID);
	vector<pair<UserMessage, int>> ViewReceivedMessages(FlowLayoutPanel^ container, Form^ form, bool full = false);
	void ViewSentMessages(FlowLayoutPanel^ container, Form^ form);
	bool ViewUserMessages(FlowLayoutPanel^ container, Form^ form, int User_ID);
	bool PutFavorite(int User_ID, int Msg_Index);
	bool RemoveOldestFavorite();
	bool RemoveFavorite(int User_ID, int Msg_Index);
	bool IsFavorite(int User_ID, int Msg_Index);
	bool ViewFavorites(FlowLayoutPanel^ container, Form^ form);
	bool ViewBlocks(FlowLayoutPanel^ container, Form^ form);

private:
	Panel^ CreateMessageBox(String^ message);
	Panel^ CreateUIDPanel(Form^ form, String^ ID, String^ date, UserMessage& msg, string type);
	Panel^ CreateMainMessagePanel(Form^ form, int User_ID, UserMessage& msg, string type);
	void CreateMessageLayout(FlowLayoutPanel^ container, Form^ form, vector<pair<UserMessage, int>>& messages);
	void CreateMessageLayout(FlowLayoutPanel^ container, Form^ form, stack<UserMessage>& messages, int User_ID);
	void CreateMessageLayout(FlowLayoutPanel^ container, Form^ form, stack<pair<int, UserMessage>>& messages);
	void CreateMessageLayout(FlowLayoutPanel^ container, Form^ form, queue<pair<int, UserMessage>>& messages);
	void CreateBlocksLayout(FlowLayoutPanel^ container, Form^ form);
	Panel^ CreateBlockPanel(FlowLayoutPanel^ container, Form^ form, int User_ID);

public:
	int GetUserMessagesFromUser(UserAccount* user);
	bool GetContact(int User_ID);
	int ID() const;
	string Username() const;
	string Password() const;
	bool IsBlocked(int User_ID);
};