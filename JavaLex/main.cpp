#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Constant.h"
#include "scanner.h"

using namespace std;

int main(int argc, char * argv[])
{
	char fn_in[MAX_LINE];   //输入文件名
	char fn_out[MAX_LINE];  //输出文件名
	char fn_err[MAX_LINE];  //错误文件名
	char fn_lex[MAX_LINE];  //输出给语法分析器的文件名
	Scanner * scan;

	cout << "JavaLex by Lin Jian" << endl;
	if (argc == 1)
	{
		cout << "Input file name: ";
		cin >> fn_in;
	}
	else
	{
		strcpy(fn_in, argv[1]);
		cout << "File name: " << fn_in << endl;
	}
	strcpy(fn_out, fn_in);
	strcat(fn_out, "_out.txt");
	strcpy(fn_err, fn_in);
	strcat(fn_err, "_err.txt");
	strcpy(fn_lex, fn_in);
	strcat(fn_lex, "_lex.txt");

	scan = new Scanner(fn_in, fn_out, fn_err, fn_lex);
	if (scan->token > 0 && scan->token < TokenCount)
	{
		cout << "Scanning..." << endl;
		scan->OutputToken();
		while (scan->token > 0 && scan->token < TokenCount)
		{
			scan->NextToken();
			scan->OutputToken();
		}
		cout << "Scan is done." << endl;
		cout << "Token number: " << scan->count_file << endl;
	}
	else
	{
		cout << "File not found or that is an empty file." << endl;
	}
	delete scan;

	return 0;
}
