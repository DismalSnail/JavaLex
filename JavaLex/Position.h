#ifndef POSITION_H
#define POSITION_H

#include "constant.h"

//λ�ü�¼��
class Position
{
public:
	int line;   //�к�
	int col; //�к�
	void Reset();   //����
	void Set(int l, int c); //��ֵ
};

#endif
