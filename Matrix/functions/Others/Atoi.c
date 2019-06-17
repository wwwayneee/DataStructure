#include "header.h"
#include "function.h"

int Atoi(char c)
{
	if (c >= 0x30 && c <= 0x39)
		return ((int)c - 0x30);
	else
		return -1;
}
