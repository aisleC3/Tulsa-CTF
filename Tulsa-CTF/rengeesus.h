#pragma once

static unsigned long next = 0;

class RNGeesus
{
public:
	static int do_rand(unsigned long* ctx)
	{
#ifdef  USE_WEAK_SEEDING
		/*
		 * Historic implementation compatibility.
		 * The random sequences do not vary much with the seed,
		 * even with overflowing.
		 */
		return ((*ctx = *ctx * 1103515245 + 12345) % ((u_long)RAND_MAX + 1));
#else   /* !USE_WEAK_SEEDING */
		/*
		 * Compute x = (7^5 * x) mod (2^31 - 1)
		 * without overflowing 31 bits:
		 *      (2^31 - 1) = 127773 * (7^5) + 2836
		 * From "Random number generators: good ones are hard to find",
		 * Park and Miller, Communications of the ACM, vol. 31, no. 10,
		 * October 1988, p. 1195.
		 */
		long hi, lo, x;

		/* Can't be initialized with 0, so use another value. */
		if (*ctx == 0)
			*ctx = 123459876;
		hi = *ctx / 127773;
		lo = *ctx % 127773;
		x = 16807 * lo - 2836 * hi;
		if (x < 0)
			x += 0x7fffffff;
		return ((*ctx = x) % ((unsigned long)RAND_MAX + 1));
#endif  /* !USE_WEAK_SEEDING */
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