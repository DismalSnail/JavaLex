#ifndef POSITION_H
#define POSITION_H

#include "constant.h"

//位置记录类
class Position
{
public:
	int line;   //行号
	int col; //列号
	void Reset();   //清零
	void Set(int l, int c); //赋值
};

#endif
