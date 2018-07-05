#define _CRT_SECURE_NO_WARNINGS
#include "Position.h"

void Position::Reset()
{
	Set(0, 0);
}

void Position::Set(int l, int c)
{
	line = l;
	col = c;
}
