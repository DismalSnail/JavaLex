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

//词法分析器类
class Scanner
{
private:
	Position pos;    //当前的token的起始位置
	Position endPos; //当前的token的结束位置
	Position tmpPos;    //临时记录用位置

	char name[MAX_LINE];    //标识符的名称
	int radix;  //数值类型token的基数

	char sbuf[MAX_FILE];   //字符缓冲区
	int sp; //字符缓冲区指针

	char buf[MAX_FILE]; //输入缓冲区
	int bp; //输入缓冲区指针
	int buflen; //输入缓冲区长

	char ch;    //当前字符
	int line;   //当前行
	int col;    //当前列

	ifstream inFile;    //输入文件
	ofstream outFile, errFile, lexFile;  //输出文件与错误文件

	void ScanChar();    //扫描下一个字符
	void ScanIdent();   //扫描标识符
	void ScanNumber(int radix);    //扫描一个数值
	void ScanFraction();    //扫描指数
	void ScanFractionAndSuffix();   //扫描浮点数后缀
	void ScanCommentChar(); //扫描注释标志
	void ScanLitChar(); //扫描字符串
	void ScanOperator();    //扫描运算符
	int Digit(int base);    //将ASCII字符转化为数值
	void PutChar(char ch);  //向字符缓冲区追加一个字符
	void SkipComment(); //跳过注释内容
	bool IsJavaIdentifierStart(const char & ch);   //是否为Java标识符的首字符
	bool IsJavaIdentifierPart(const char & ch); //判定指定字符是否为Java标识符中除首字符外的字符
	bool IsSpecial(const char & ch);    //是否为特殊字符
	void LexError(const Position & pos, const char * msg, const char * arg); //错误输出
	void LexError(const Position & pos, const char * msg); //错误输出
	void LexError(const char * msg); //错误输出
	void LexError(const char * msg, const char * arg); //错误输出

public:
	int token;  //当前的token
	int count_line; //本行单词个数
	int count_file; //整个源文件单词个数

	Scanner(char * fn_in, char * fn_out, char * fn_err, char * fn_lex);  //构造函数
	~Scanner(); //析构函数
	void NextToken();    //扫描下一个token
	void OutputToken(); //输出当前的token
	static int NameToKey(char * msg); //从名称得到详细属性
	static int DetailToType(int detail); //从详细属性得到类型属性
	static int GetPriority(int type); //得到运算符优先级
};

#endif
