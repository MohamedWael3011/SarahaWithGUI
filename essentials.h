#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>

#pragma comment (lib, "user32.lib")

using namespace std;
using namespace System;
using namespace System::Runtime::InteropServices;

#define CPPSTR2SYSTEM(str) gcnew String(str)

string SystemStringToCpp(String^ str);
string ReplaceAll(string& str, string toreplace, string tobereplaced);