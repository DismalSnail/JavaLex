#ifndef SCANNER_H
#define SCANNER_H

#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "constant.h"
#include "position.h"

using namespace std;

//�ʷ���������
class Scanner
{
private:
	Position pos;    //��ǰ��token����ʼλ��
	Position endPos; //��ǰ��token�Ľ���λ��
	Position tmpPos;    //��ʱ��¼��λ��

	char name[MAX_LINE];    //��ʶ��������
	int radix;  //��ֵ����token�Ļ���

	char sbuf[MAX_FILE];   //�ַ�������
	int sp; //�ַ�������ָ��

	char buf[MAX_FILE]; //���뻺����
	int bp; //���뻺����ָ��
	int buflen; //���뻺������

	char ch;    //��ǰ�ַ�
	int line;   //��ǰ��
	int col;    //��ǰ��

	ifstream inFile;    //�����ļ�
	ofstream outFile, errFile, lexFile;  //����ļ�������ļ�

	void ScanChar();    //ɨ����һ���ַ�
	void ScanIdent();   //ɨ���ʶ��
	void ScanNumber(int radix);    //ɨ��һ����ֵ
	void ScanFraction();    //ɨ��ָ��
	void ScanFractionAndSuffix();   //ɨ�踡������׺
	void ScanCommentChar(); //ɨ��ע�ͱ�־
	void ScanLitChar(); //ɨ���ַ���
	void ScanOperator();    //ɨ�������
	int Digit(int base);    //��ASCII�ַ�ת��Ϊ��ֵ
	void PutChar(char ch);  //���ַ�������׷��һ���ַ�
	void SkipComment(); //����ע������
	bool IsJavaIdentifierStart(const char & ch);   //�Ƿ�ΪJava��ʶ�������ַ�
	bool IsJavaIdentifierPart(const char & ch); //�ж�ָ���ַ��Ƿ�ΪJava��ʶ���г����ַ�����ַ�
	bool IsSpecial(const char & ch);    //�Ƿ�Ϊ�����ַ�
	void LexError(const Position & pos, const char * msg, const char * arg); //�������
	void LexError(const Position & pos, const char * msg); //�������
	void LexError(const char * msg); //�������
	void LexError(const char * msg, const char * arg); //�������

public:
	int token;  //��ǰ��token
	int count_line; //���е��ʸ���
	int count_file; //����Դ�ļ����ʸ���

	Scanner(char * fn_in, char * fn_out, char * fn_err, char * fn_lex);  //���캯��
	~Scanner(); //��������
	void NextToken();    //ɨ����һ��token
	void OutputToken(); //�����ǰ��token
	static int NameToKey(char * msg); //�����Ƶõ���ϸ����
	static int DetailToType(int detail); //����ϸ���Եõ���������
	static int GetPriority(int type); //�õ���������ȼ�
};

#endif
