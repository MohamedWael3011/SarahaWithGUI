#pragma once
#include "essentials.h"

struct UserMessage
{
	int Index;
	string Content;
	SYSTEMTIME SentDate;
	bool IsFavorite;
	bool Seen;
};