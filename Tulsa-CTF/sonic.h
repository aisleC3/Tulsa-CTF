#pragma once

class Sonic
{
public:
	/* Sonic uses a Caesar Cipher with a random shift on runtime */

	static char* CipherText(const char* str, int shift)
	{
		int len = strlen(str); // Get our original string length
		char* ret = new char[len]; // Initialize new string with correct length, assuming we don't add characters
		strcpy(ret, str); // copy original string into new
		for (int i = 0; i < len; ++i) // run the crypto on it
		{
			char ch = ret[i];
			if (ch >= 'A' && ch <= 'Z') /* The test cases are always capitalized */
			{
				ch = ch - shift;
				if (ch < 'A')
				{
					ch = ch + 'Z' - 'A' + 1;
				}
			}
			ret[i] = ch;
		}
		return ret; // return new string
	}
};