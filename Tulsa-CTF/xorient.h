#pragma once

class Xorient
{
public:
	static void ExecuteOrder66(const char* file_name, int key)
	{
		std::ifstream file(file_name, std::ios::binary | std::ios::ate);
		std::streamsize size = file.tellg();
		file.seekg(0, std::ios::beg);
		printf("File size: %i\n", size);
		std::vector<char> buffer(size);
		if (file.read(buffer.data(), size))
		{
			/* worked! */
			for (int i = 0; i < buffer.size(); i++)
			{
				buffer[i] = buffer[i] ^ key;
				printf("%2X ", buffer[i]);
			}
		}
		
	}
};