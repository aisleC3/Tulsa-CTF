#pragma once

class Core
{
public:

	static char* Xor(const char* str, int len) 
	{
		char* ret = new char[len];
		ZeroMemory(ret, len);
		for (int i = 0; i < len; i++) {
			ret[i] = str[i] ^ 1;
		}
		return ret;
	}
};