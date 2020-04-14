#pragma once

class Faker
{
public:

	static char* DeobfuscateString(const char* str)
	{
		int len = strlen(str); // Get our original string length
		char* ret = new char[len]; // Initialize new string with correct length, assuming we don't add characters
		strcpy(ret, str); // copy original string into new
		for (int i = 0; i < len; ++i) // run the crypto on it
			ret[i] = 8 * ((ret[i] ^ 0xF) - 29) % 95 + 32;
		return ret; // return new string
	}
};