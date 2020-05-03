#pragma once

static unsigned long next = 0;

class RNGeesus
{
public:
	static int do_rand(unsigned long* ctx)
	{
		long hi, lo, x;
		if (*ctx == 0)
			*ctx = 123459876;
		hi = *ctx / 127773;
		lo = *ctx % 127773;
		x = 16807 * lo - 2836 * hi;
		if (x < 0)
			x += 0x7fffffff;
		return ((*ctx = x) % ((unsigned long)RAND_MAX + 1));
	}

	static int rand_r(unsigned int* ctx)
	{
		u_long val = (u_long)*ctx;
		int r = do_rand(&val);

		*ctx = (unsigned int)val;
		return (r);
	}



	static int rand()
	{
		return (do_rand(&next));
	}
};