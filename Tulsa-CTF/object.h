#pragma once

class Object
{
private:
	static const int password_length = 0x2C;
public:
	static char* FindPassword()
	{
		int8_t password[] = { 0xFD,0xFF,0xD3,0xFD,0xD9,0xA3,0x93,0x35,0x89,0x39,0xB1 };
		char* ret = new char[password_length];
		ZeroMemory(ret, password_length);

		for (int i = 0; i < password_length; ++i)
		{
			while (((int8_t)(~(2 * ret[i]) ^ 0xAA)) != password[i])
			{
				if (((unsigned __int8)(~(2 * ret[i]) ^ 0xAA)) == password[i]) /* wtf ?*/
				{
					continue;
				}
				ret[i]++;
			}
		}
		return ret;
	}
};