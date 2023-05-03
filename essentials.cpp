#include "essentials.h"

string SystemStringToCpp(String^ str)
{
	string res;

	char* buffer = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
	res.assign(buffer);

	Marshal::FreeHGlobal((IntPtr)buffer);
	return res;
}
