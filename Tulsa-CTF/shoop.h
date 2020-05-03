#pragma once

static const char* goal = "jmt_j]tm`q`t_j]mpjtf^";
static const char* goal_plus_five = "orydobyreveydobruoykc";

class Shoop
{
private:

	

public:


	static void Execute()
	{
		char* src; // [rsp+10h] [rbp-20h]
		char* s; // [rsp+18h] [rbp-18h]
		signed int k; // [rsp+24h] [rbp-Ch]
		signed int j; // [rsp+28h] [rbp-8h]
		signed int i; 

		src = (char*)malloc(0x15uLL);

		printf("Input: ");
		for (k = 0; k < 21; ++k)
			src[k] = *((BYTE*)goal + (k - 10) % 21);

		printf("%s\n", src);
		s = (char*)malloc(0x16uLL); // allocate memory
		memset(s, 0, 0x16uLL); // zero it

		printf("\nGimme that good stuff: ");
		read(0, s, 0x15uLL);

		

		for (i = 0x14; i >= 0; --i)
			src[0x15 - i - 1] = s[i]; // Reverse the string
		//
		memcpy(s, src, 0x15uLL);

		printf("Step 1: %s\n", s);

		for (j = 0; j < 0x15; ++j)
			s[j] -= 5;

		printf("Step 2: %s\n", s);

		for (k = 0; k < 0x15; ++k)
			src[k] = s[(k + 10) % 0x15];

		// 'j' = base + 10 % 0x15

		memcpy(s, src, 0x15uLL);

		printf("Step 3: %s\n", s);

		printf("\n%s\n%s\n\n", goal, s);
	}
};