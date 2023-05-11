#include "essentials.h"

string SystemStringToCpp(String^ str)
{
	string res;

	char* buffer = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
	res.assign(buffer);

	Marshal::FreeHGlobal((IntPtr)buffer);
	return res;
}

string ReplaceAll(string& str, string toreplace, string tobereplaced)
{
	string res(str);
	size_t index = 0;

	while (true)
	{
		/* Locate the substring to replace. */
		index = res.find(toreplace, index);
		if (index == std::string::npos) break;

		/* Make the replacement. */
		res.replace(index, toreplace.length(), tobereplaced);

		/* Advance index forward so the next iteration doesn't pick it up as well. */
		index += tobereplaced.length();
	}

	return res;
}
