#define _CRT_NONSTDC_NO_DEPRECATE

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <io.h>
#include "faker.h"
#include "sonic.h"
#include "object.h"
#include "core.h"
#include "xorient.h"

int main()
{
	const char* flag = "UTBUGzb1s2^etlq>^O2w2s^i25se^1g^x1t|";
	
	printf("\nTest: %s\n", Core::Xor(flag, strlen(flag)));
}

