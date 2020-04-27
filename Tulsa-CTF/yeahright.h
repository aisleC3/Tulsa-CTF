#pragma once

static const char* pass = "7h3_m057_53cr37357_p455w0rd_y0u_3v3r_54";
static const char* format = "*Ahem*... password? ";
static const char* s = "yeahright!";
static const char* command = "Got the flag!\n";

class YeahRight
{
public:
	static void Run()
	{
		printf("Pass: 0x%p\n", &pass);
		void* buf = malloc(0x40uLL);
		printf(format, 0LL);
		read(0, buf, 0x40uLL);
		printf("Buff: 0x%p\n", &buf);

		if (memcmp(buf, pass, 40uLL))
		{
			puts(s);
			return;
		}
		printf(command);
	//	system("/bin/cat ./flag");
	}
};