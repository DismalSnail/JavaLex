#define _CRT_SECURE_NO_WARNINGS
#include "Scanner.h"

Scanner::Scanner(char * fn_in, char * fn_out, char * fn_err, char * fn_lex)
{
	token = -1;
	count_line = 0;
	count_file = 0;

	//将源文件读入缓冲区
	int ptr = 0;
	inFile.open(fn_in);
	if (!inFile.is_open())
	{
		return;
	}
	while (inFile.get(buf[ptr]))
	{
		ptr++;
	}
	inFile.close();

	//创建输出和错误文件
	FILE * fp;
	fp = fopen(fn_out, "w");
	fclose(fp);
	fp = fopen(fn_err, "w");
	fclose(fp);
	fp = fopen(fn_lex, "w");
	fclose(fp);
	outFile.open(fn_out, ios::out | ios::app);
	errFile.open(fn_err, ios::out | ios::app);
	lexFile.open(fn_lex, ios::out | ios::app);

	buf[ptr] = C_EOI;
	buflen = ptr;
	line = 1;
	col = 0;
	bp = -1;
	endPos.Reset();

	ScanChar();
	NextToken();
}

Scanner::~Scanner()
{
	if (!outFile.is_open())
	{
		outFile.close();
	}
	if (!errFile.is_open())
	{
		errFile.close();
	}
	if (!lexFile.is_open())
	{
		lexFile.close();
	}
}

void Scanner::ScanChar()
{
	int oldcol;
	bp++;
	ch = buf[bp];
	switch (ch)
	{
	case C_CR:
		oldcol = col;
		col = 0;
		line++;
		break;
	case C_LF:
		if (bp == 0 || buf[bp - 1] != C_CR)
		{
			oldcol = col;
			col = 0;
			line++;
		}
		break;
	case C_TAB:
		col = (col / TabInc * TabInc) + TabInc;
		break;
	default:
		col++;
		break;
	}
	endPos.Set(line, col - 1);
	if (endPos.col == -1)
	{
		endPos.Set(line - 1, oldcol);
	}
}

void Scanner::ScanNumber(int radix)
{
	this->radix = radix;
	int digitRadix = (radix <= 10) ? 10 : 16;
	while (Digit(digitRadix) >= 0)
	{
		PutChar(ch);
		ScanChar();
	}
	if (radix <= 10 && ch == '.')
	{
		PutChar(ch);
		ScanChar();
		ScanFractionAndSuffix();
	}
	else if
		(
			radix <= 10 &&
			(
				ch == 'e' || ch == 'E' ||
				ch == 'f' || ch == 'F' ||
				ch == 'd' || ch == 'D'
				)
			)
	{
		ScanFractionAndSuffix();
	}
	else
	{
		if (ch == 'l' || ch == 'L')
		{
			ScanChar();
			token = P_LONGLITERAL;
		}
		else
		{
			token = P_INTLITERAL;
		}
	}
}

void Scanner::PutChar(char ch)
{
	sbuf[sp++] = ch;
}

void Scanner::NextToken()
{
	int start;
	memset(sbuf, '\0', MAX_FILE);
	sp = 0;
	count_line++;
	count_file++;

	while (true)
	{
		int oldline = pos.line;
		pos.Set(line, col);
		if (pos.line > oldline)
		{
			count_line = 1;
		}
		start = bp;
		switch (ch)
		{
		case ' ':

		case C_TAB:

		case C_FF:

		case C_CR:

		case C_LF:
			ScanChar();
			break;

		case 'A':

		case 'B':

		case 'C':

		case 'D':

		case 'E':

		case 'F':

		case 'G':

		case 'H':

		case 'I':

		case 'J':

		case 'K':

		case 'L':

		case 'M':

		case 'N':

		case 'O':

		case 'P':

		case 'Q':

		case 'R':

		case 'S':

		case 'T':

		case 'U':

		case 'V':

		case 'W':

		case 'X':

		case 'Y':

		case 'Z':

		case 'a':

		case 'b':

		case 'c':

		case 'd':

		case 'e':

		case 'f':

		case 'g':

		case 'h':

		case 'i':

		case 'j':

		case 'k':

		case 'l':

		case 'm':

		case 'n':

		case 'o':

		case 'p':

		case 'q':

		case 'r':

		case 's':

		case 't':

		case 'u':

		case 'v':

		case 'w':

		case 'x':

		case 'y':

		case 'z':

		case '$':

		case '_':
			ScanIdent();
			return;

		case '0':
			ScanChar();
			if (ch == 'x' || ch == 'X')
			{
				ScanChar();
				if (Digit(16) < 0)
				{
					LexError("Invalid hexadecimal number");
				}
				ScanNumber(16);
			}
			else
			{
				PutChar('0');
				ScanNumber(8);
			}
			return;

		case '1':

		case '2':

		case '3':

		case '4':

		case '5':

		case '6':

		case '7':

		case '8':

		case '9':
			ScanNumber(10);
			return;

		case '.':
			ScanChar();
			if ('0' <= ch && ch <= '9')
			{
				PutChar('.');
				ScanFractionAndSuffix();
			}
			else
			{
				token = P_DOT;
			}
			return;

		case ',':
			ScanChar();
			token = P_COMMA;
			return;

		case ';':
			ScanChar();
			token = P_SEMI;
			return;

		case '(':
			ScanChar();
			token = P_LPAREN;
			return;

		case ')':
			ScanChar();
			token = P_RPAREN;
			return;

		case '[':
			ScanChar();
			token = P_LBRACKET;
			return;

		case ']':
			ScanChar();
			token = P_RBRACKET;
			return;

		case '{':
			ScanChar();
			token = P_LBRACE;
			return;

		case '}':
			ScanChar();
			token = P_RBRACE;
			return;

		case '/':
			ScanChar();
			if (ch == '/')
			{
				do
				{
					ScanCommentChar();
				} while (ch != C_CR && ch != C_LF && bp < buflen);
				break;
			}
			else if (ch == '*')
			{
				ScanChar();
				SkipComment();
				if (ch == '/')
				{
					ScanChar();
					break;
				}
				else
				{
					LexError("Unclosed comment");
					return;
				}
			}
			else if (ch == '=')
			{
				strcpy(name, "/=");
				token = P_SLASHEQ;
				ScanChar();
			}
			else
			{
				strcpy(name, "/");
				token = P_SLASH;
			}
			return;

		case '\'':
			ScanChar();
			if (ch == '\'')
			{
				LexError("Empty character");
			}
			else
			{
				if (ch == C_CR || ch == C_LF)
				{
					LexError(pos, "Illegal line end in character");
				}
				ScanLitChar();
				if (ch == '\'')
				{
					ScanChar();
					token = P_CHARLITERAL;
				}
				else
				{
					LexError(pos, "Unclosed character quote mark");
				}
			}
			return;

		case '\"':
			ScanChar();
			while (ch != '\"' && ch != C_CR && ch != C_LF && bp < buflen)
			{
				ScanLitChar();
			}
			if (ch == '\"')
			{
				token = P_STRINGLITERAL;
				ScanChar();
			}
			else
			{
				LexError(pos, "Unclosed string quote mark");
			}
			return;

		default:
			if (IsSpecial(ch))
			{
				ScanOperator();
			}
			else if (IsJavaIdentifierStart(ch))
			{
				ScanIdent();
			}
			else if (bp == buflen || ch == C_EOI && bp + 1 == buflen)
			{
				token = P_EOF;
			}
			else
			{
				LexError("Illegal character");
				ScanChar();
			}
			return;
		}
	}
}

void Scanner::ScanLitChar()
{
	if (ch == '\\')
	{
		if (buf[bp + 1] == '\\')
		{
			bp++;
			col++;
			PutChar('\\');
			ScanChar();
		}
		else
		{
			ScanChar();
			char leadch = ch;
			int oct = Digit(8);
			int hex = 0;
			switch (ch)
			{
			case '0':

			case '1':

			case '2':

			case '3':

			case '4':

			case '5':

			case '6':

			case '7':
				leadch = ch;
				oct = Digit(8);
				ScanChar();
				if ('0' <= ch && ch <= '7')
				{
					oct = oct * 8 + Digit(8);
					ScanChar();
					if (leadch <= '3' && '0' <= ch && ch <= '7')
					{
						oct = oct * 8 + Digit(8);
						ScanChar();
					}
				}
				PutChar((char)oct);
				break;

			case 'u':
				ScanChar();
				if (('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F'))
				{
					hex = hex * 16 + Digit(16);
					ScanChar();
					if (('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F'))
					{
						hex = hex * 16 + Digit(16);
						ScanChar();
						if (('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F'))
						{
							hex = hex * 16 + Digit(16);
							ScanChar();
							if (('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F'))
							{
								hex = hex * 16 + Digit(16);
								ScanChar();
							}
						}
					}
				}
				else
				{
					tmpPos.Set(line, col);
					LexError(tmpPos, "Illegal unicode character");
					break;
				}
				PutChar((char)hex);
				break;

			case 'b':
				PutChar('\b');
				ScanChar();
				break;

			case 't':
				PutChar('\t');
				ScanChar();
				break;

			case 'n':
				PutChar('\n');
				ScanChar();
				break;

			case 'f':
				PutChar('\f');
				ScanChar();
				break;

			case 'r':
				PutChar('\r');
				ScanChar();
				break;

			case '\'':
				PutChar('\'');
				ScanChar();
				break;

			case '\"':
				PutChar('\"');
				ScanChar();
				break;

			case '\\':
				PutChar('\\');
				ScanChar();
				break;

			default:
				tmpPos.Set(line, col);
				LexError(tmpPos, "Illegal esc character");
				break;
			}
		}
	}
	else if (bp != buflen)
	{
		PutChar(ch);
		ScanChar();
	}
}

void Scanner::ScanOperator()
{
	while (true)
	{
		PutChar(ch);

		strncpy(name, sbuf, sp);
		name[sp] = '\0';

		if (NameToKey(name) == P_IDENTIFIER)
		{
			sp--;
			break;
		}
		token = NameToKey(name);

		ScanChar();
		if (!IsSpecial(ch))
		{
			break;
		}
	}
}

void Scanner::ScanFraction()
{
	while (Digit(10) >= 0)
	{
		PutChar(ch);
		ScanChar();
	}
	int sp1 = sp;
	if (ch == 'e' || ch == 'E')
	{
		PutChar(ch);
		ScanChar();
		if (ch == '+' || ch == '-')
		{
			PutChar(ch);
			ScanChar();
		}
		if ('0' <= ch && ch <= '9')
		{
			do
			{
				PutChar(ch);
				ScanChar();
			} while ('0' <= ch && ch <= '9');
			return;
		}
		LexError("Illegal float number");
		sp = sp1;
	}
}

void Scanner::ScanFractionAndSuffix() {
	ScanFraction();
	if (ch == 'f' || ch == 'F')
	{
		PutChar(ch);
		ScanChar();
		token = P_FLOATLITERAL;
	}
	else
	{
		if (ch == 'd' || ch == 'D')
		{
			PutChar(ch);
			ScanChar();
		}
		token = P_DOUBLELITERAL;
	}
}

void Scanner::ScanCommentChar()
{
	ScanChar();
	if (ch == '\\')
	{
		if (buf[bp + 1] == '\\')
		{
			bp++;
			col++;
		}
	}
}

void Scanner::ScanIdent()
{
	do
	{
		if (sp == MAX_FILE)
		{
			PutChar(ch);
		}
		else
		{
			sbuf[sp++] = ch;
		}
		ScanChar();
		switch (ch)
		{
		case 'A':

		case 'B':

		case 'C':

		case 'D':

		case 'E':

		case 'F':

		case 'G':

		case 'H':

		case 'I':

		case 'J':

		case 'K':

		case 'L':

		case 'M':

		case 'N':

		case 'O':

		case 'P':

		case 'Q':

		case 'R':

		case 'S':

		case 'T':

		case 'U':

		case 'V':

		case 'W':

		case 'X':

		case 'Y':

		case 'Z':

		case 'a':

		case 'b':

		case 'c':

		case 'd':

		case 'e':

		case 'f':

		case 'g':

		case 'h':

		case 'i':

		case 'j':

		case 'k':

		case 'l':

		case 'm':

		case 'n':

		case 'o':

		case 'p':

		case 'q':

		case 'r':

		case 's':

		case 't':

		case 'u':

		case 'v':

		case 'w':

		case 'x':

		case 'y':

		case 'z':

		case '$':

		case '_':

		case '0':

		case '1':

		case '2':

		case '3':

		case '4':

		case '5':

		case '6':

		case '7':

		case '8':

		case '9':
			break;

		default:
			if (!IsJavaIdentifierPart(ch) || bp >= buflen)
			{
				strncpy(name, sbuf, sp);
				name[sp] = '\0';
				token = NameToKey(name);
				return;
			}

		}
	} while (true);
}

void Scanner::SkipComment()
{
	while (bp < buflen)
	{
		switch (ch)
		{
		case '*':
			ScanChar();
			if (ch == '/')
			{
				return;
			}
			break;

		default:
			ScanCommentChar();
			break;
		}
	}
}

int Scanner::Digit(int base)
{
	char c = ch;
	int result;

	if (c >= '0' && c <= '7')
	{
		result = (int)(c - '0');
	}
	else if (c >= '8' && c <= '9')
	{
		if (base > 8)
		{
			result = (int)(c - '0');
		}
		else
		{
			result = -1;
		}
	}
	else if (c >= 'a' && c <= 'f')
	{
		if (base > 10)
		{
			result = (int)(c - 'a' + 10);
		}
		else
		{
			result = -1;
		}
	}
	else if (c >= 'A' && c <= 'F')
	{
		if (base > 10)
		{
			result = (int)(c - 'A' + 10);
		}
		else
		{
			result = -1;
		}
	}
	else
	{
		result = -1;
	}

	if (result >= 0 && c < 0)
	{
		tmpPos.Set(pos.line, pos.col + 1);
		LexError(tmpPos, "Non-ASCII digit");
	}
	return result;
}

bool Scanner::IsJavaIdentifierPart(const char & ch)
{
	return
		(
		(ch >= '0' && ch <= '9') ||
			(ch >= 'A' && ch <= 'Z') ||
			(ch >= 'a' && ch <= 'z') ||
			ch == '_' ||
			ch == '$'
			);
}

bool Scanner::IsJavaIdentifierStart(const char & ch)
{
	return
		(
		(ch >= 'A' && ch <= 'Z') ||
			(ch >= 'a' && ch <= 'z') ||
			ch == '_' ||
			ch == '$'
			);
}

bool Scanner::IsSpecial(const char & ch)
{
	switch (ch)
	{
	case '!':

	case '%':

	case '&':

	case '*':

	case '?':

	case '+':

	case '-':

	case ':':

	case '<':

	case '=':

	case '>':

	case '^':

	case '|':

	case '~':
		return true;

	default:
		return false;
	}
}

void Scanner::LexError(const Position & pos, const char * msg, const char * arg)
{
	token = P_ERROR;
	errFile << "Error: " << msg << endl;
	if (arg != NULL)
	{
		errFile << "    Content: " << arg << endl;
	}
	if (pos.line > 0 && pos.col > 0)
	{
		errFile << "    At line " << pos.line << ", column " << pos.col << endl;
	}
}

void Scanner::LexError(const Position & pos, const char * msg)
{
	LexError(pos, msg, NULL);
}

void Scanner::LexError(const char * msg)
{
	LexError(this->pos, msg, NULL);
}

void Scanner::LexError(const char * msg, const char * arg)
{
	LexError(this->pos, msg, arg);
}

void Scanner::OutputToken()
{
	int type = DetailToType(token);
	if (type == 0)
	{
		count_line--;
		count_file--;
		return;
	}
	outFile << setw(2) << dec << count_line << ": ";
	outFile << "(" << setw(3) << dec << pos.line << "," << setw(3) << dec << pos.col << ")-";
	outFile << "(" << setw(3) << dec << endPos.line << "," << setw(3) << dec << endPos.col << ") ";
	outFile << "(0x" << setw(3) << hex << type << ") ";
	outFile << "(" << setw(3) << dec << token << ") ";
	outFile << "[";
	int len = endPos.col - pos.col + 1;
	int start = bp - len;
	for (int j = start; j < start + len; j++)
	{
		outFile << buf[j];
	}
	outFile << "]";
	if (type >= T_ASSIGN && type <= T_BOUND)
	{
		outFile << "-[Priority:" << setw(2) << dec << GetPriority(type) << "]";
	}
	outFile << endl;
	//仅对一个子集进行语法、语义分析，给出语法、语义分析器所需的输入属性字文件
	if
		(
			token == P_WHILE ||
			token == P_IDENTIFIER ||
			token == P_INTLITERAL ||
			token == P_LPAREN ||
			token == P_RPAREN ||
			token == P_EQ ||
			token == P_GT ||
			token == P_LT ||
			token == P_PLUS ||
			token == P_SUB ||
			token == P_STAR ||
			token == P_SLASH ||
			token == P_SEMI
			)
	{
		lexFile << token << "\t" << pos.line << "\t" << pos.col << "\t";
		for (int j = start; j < start + len; j++)
		{
			lexFile << buf[j];
		}
		lexFile << endl;
	}
}

int Scanner::NameToKey(char * msg)
{
	for (int i = 0; i < TABLE_LENGTH; i++)
	{
		if (!strcmp(msg, ATTR_MAP[i].keyword))
		{
			return ATTR_MAP[i].detail;
		}
	}
	return P_IDENTIFIER;
}

int Scanner::DetailToType(int detail)
{
	for (int i = 0; i < TABLE_LENGTH; i++)
	{
		if (detail == ATTR_MAP[i].detail)
		{
			return ATTR_MAP[i].type;
		}
	}
	return 0;
}

int Scanner::GetPriority(int type)
{
	for (int i = 0; i < PRIORITY_LENGTH; i++)
	{
		if (type == PRI_MAP[i].type)
		{
			return PRI_MAP[i].priority;
		}
	}
	return 0;
}
