#ifndef CONSTANT_H
#define CONSTANT_H

//类型属性设计
static const int T_ERROR = 0x100;    //错误的单词
static const int T_COMMENT = 0x101;    //注释
static const int T_SPACE = 0x102;    //空格
static const int T_KEYWORD = 0x103;    //关键字
static const int T_IDENTIFIER = 0x104;    //标识符
static const int T_BOOL = 0x105;    //布尔型
static const int T_CHAR = 0x106;    //字符型
static const int T_INT = 0x107;    //整型
static const int T_FLOAT = 0x108;    //浮点型
static const int T_STRING = 0x109;    //字符串
static const int T_ASSIGN = 0x110;    //=  +=  -=  *=  /=  %=  &=  ^=  |=  >>=  <<=  >>>=
static const int T_TERNARY = 0x111;    //?:
static const int T_OR = 0x112;    //||
static const int T_AND = 0x113;    //&&
static const int T_BITOR = 0x114;    //|
static const int T_BITXOR = 0x115;    //^
static const int T_BITAND = 0x116;    //&
static const int T_EQUALITY = 0x117;    //==  !=
static const int T_COMPARE = 0x118;    //<  >  <=  >=
static const int T_SHIFT = 0x119;    //<<  >>  >>>
static const int T_ADDSUB = 0x11A;    //+  -
static const int T_MULDIV = 0x11B;    //*  /  %
static const int T_UNIFY = 0x11C;    //++  --  +(正)  –(负)  !  ~
static const int T_BOUND = 0x11D;    //[]  ()  .
static const int T_COMMA = 0x120;    //,
static const int T_BRACKET = 0x121;    //{}
static const int T_SEMICOLON = 0x122;    //;

										 //详细属性设计
static const int P_EOF = 0;    //0
static const int P_ERROR = P_EOF + 1;    //1
static const int P_IDENTIFIER = P_ERROR + 1;    //2
static const int P_ABSTRACT = P_IDENTIFIER + 1;    //3
static const int P_ASSERT = P_ABSTRACT + 1;    //4
static const int P_BOOLEAN = P_ASSERT + 1;    //5
static const int P_BREAK = P_BOOLEAN + 1;    //6
static const int P_BYTE = P_BREAK + 1;    //7
static const int P_CASE = P_BYTE + 1;    //8
static const int P_CATCH = P_CASE + 1;    //9
static const int P_CHAR = P_CATCH + 1;    //10
static const int P_CLASS = P_CHAR + 1;    //11
static const int P_CONST = P_CLASS + 1;    //12
static const int P_CONTINUE = P_CONST + 1;    //13
static const int P_DEFAULT = P_CONTINUE + 1;    //14
static const int P_DO = P_DEFAULT + 1;    //15
static const int P_DOUBLE = P_DO + 1;    //16
static const int P_ELSE = P_DOUBLE + 1;    //17
static const int P_EXTENDS = P_ELSE + 1;    //18
static const int P_FINAL = P_EXTENDS + 1;    //19
static const int P_FINALLY = P_FINAL + 1;    //20
static const int P_FLOAT = P_FINALLY + 1;    //21
static const int P_FOR = P_FLOAT + 1;    //22
static const int P_GOTO = P_FOR + 1;    //23
static const int P_IF = P_GOTO + 1;    //24
static const int P_IMPLEMENTS = P_IF + 1;    //25
static const int P_IMPORT = P_IMPLEMENTS + 1;    //26
static const int P_INSTANCEOF = P_IMPORT + 1;    //27
static const int P_INT = P_INSTANCEOF + 1;    //28
static const int P_INTERFACE = P_INT + 1;    //29
static const int P_LONG = P_INTERFACE + 1;    //30
static const int P_NATIVE = P_LONG + 1;    //31
static const int P_NEW = P_NATIVE + 1;    //32
static const int P_PACKAGE = P_NEW + 1;    //33
static const int P_PRIVATE = P_PACKAGE + 1;    //34
static const int P_PROTECTED = P_PRIVATE + 1;    //35
static const int P_PUBLIC = P_PROTECTED + 1;    //36
static const int P_RETURN = P_PUBLIC + 1;    //37
static const int P_SHORT = P_RETURN + 1;    //38
static const int P_STATIC = P_SHORT + 1;    //39
static const int P_STRICTFP = P_STATIC + 1;    //40
static const int P_SUPER = P_STRICTFP + 1;    //41
static const int P_SWITCH = P_SUPER + 1;    //42
static const int P_SYNCHRONIZED = P_SWITCH + 1;    //43
static const int P_THIS = P_SYNCHRONIZED + 1;    //44
static const int P_THROW = P_THIS + 1;    //45
static const int P_THROWS = P_THROW + 1;    //46
static const int P_TRANSIENT = P_THROWS + 1;    //47
static const int P_TRY = P_TRANSIENT + 1;    //48
static const int P_VOID = P_TRY + 1;    //49
static const int P_VOLATILE = P_VOID + 1;    //50
static const int P_WHILE = P_VOLATILE + 1;    //51
static const int P_INTLITERAL = P_WHILE + 1;    //52
static const int P_LONGLITERAL = P_INTLITERAL + 1;    //53
static const int P_FLOATLITERAL = P_LONGLITERAL + 1;    //54
static const int P_DOUBLELITERAL = P_FLOATLITERAL + 1;    //55
static const int P_CHARLITERAL = P_DOUBLELITERAL + 1;    //56
static const int P_STRINGLITERAL = P_CHARLITERAL + 1;    //57
static const int P_TRUE = P_STRINGLITERAL + 1;    //58
static const int P_FALSE = P_TRUE + 1;    //59
static const int P_NULL = P_FALSE + 1;    //60
static const int P_LPAREN = P_NULL + 1;    //61
static const int P_RPAREN = P_LPAREN + 1;    //62
static const int P_LBRACE = P_RPAREN + 1;    //63
static const int P_RBRACE = P_LBRACE + 1;    //64
static const int P_LBRACKET = P_RBRACE + 1;    //65
static const int P_RBRACKET = P_LBRACKET + 1;    //66
static const int P_SEMI = P_RBRACKET + 1;    //67
static const int P_COMMA = P_SEMI + 1;    //68
static const int P_DOT = P_COMMA + 1;    //69
static const int P_EQ = P_DOT + 1;    //70
static const int P_GT = P_EQ + 1;    //71
static const int P_LT = P_GT + 1;    //72
static const int P_BANG = P_LT + 1;    //73
static const int P_TILDE = P_BANG + 1;    //74
static const int P_QUES = P_TILDE + 1;    //75
static const int P_COLON = P_QUES + 1;    //76
static const int P_EQEQ = P_COLON + 1;    //77
static const int P_LTEQ = P_EQEQ + 1;    //78
static const int P_GTEQ = P_LTEQ + 1;    //79
static const int P_BANGEQ = P_GTEQ + 1;    //80
static const int P_AMPAMP = P_BANGEQ + 1;    //81
static const int P_BARBAR = P_AMPAMP + 1;    //82
static const int P_PLUSPLUS = P_BARBAR + 1;    //83
static const int P_SUBSUB = P_PLUSPLUS + 1;    //84
static const int P_PLUS = P_SUBSUB + 1;    //85
static const int P_SUB = P_PLUS + 1;    //86
static const int P_STAR = P_SUB + 1;    //87
static const int P_SLASH = P_STAR + 1;    //88
static const int P_AMP = P_SLASH + 1;    //89
static const int P_BAR = P_AMP + 1;    //90
static const int P_CARET = P_BAR + 1;    //91
static const int P_PERCENT = P_CARET + 1;    //92
static const int P_LTLT = P_PERCENT + 1;    //93
static const int P_GTGT = P_LTLT + 1;    //94
static const int P_GTGTGT = P_GTGT + 1;    //95
static const int P_PLUSEQ = P_GTGTGT + 1;    //96
static const int P_SUBEQ = P_PLUSEQ + 1;    //97
static const int P_STAREQ = P_SUBEQ + 1;    //98
static const int P_SLASHEQ = P_STAREQ + 1;    //99
static const int P_AMPEQ = P_SLASHEQ + 1;    //100
static const int P_BAREQ = P_AMPEQ + 1;    //101
static const int P_CARETEQ = P_BAREQ + 1;    //102
static const int P_PERCENTEQ = P_CARETEQ + 1;    //103
static const int P_LTLTEQ = P_PERCENTEQ + 1;    //104
static const int P_GTGTEQ = P_LTLTEQ + 1;    //105
static const int P_GTGTGTEQ = P_GTGTEQ + 1;    //106
static const int TokenCount = P_GTGTGTEQ + 1;    //107

												 //程序控制常量
static const int MAX_WORD = 16;
static const int MAX_LINE = 256;
static const int MAX_FILE = 65536;
static const int TABLE_LENGTH = TokenCount + 1;
static const int PRIORITY_LENGTH = 14;

//格式控制字符
static const int TabInc = 8;
static const char C_TAB = 8;
static const char C_LF = 10;
static const char C_FF = 12;
static const char C_CR = 13;
static const char C_EOI = 26;

//属性对照表结构
struct attrmap
{
	int type;
	int detail;
	char keyword[MAX_WORD];
};

//属性对照表
static const struct attrmap ATTR_MAP[TABLE_LENGTH] =
{
	{ T_ADDSUB, P_PLUS, "+" },
{ T_ADDSUB, P_SUB, "-" },
{ T_UNIFY, P_BANG, "!" },
{ T_MULDIV, P_PERCENT, "%" },
{ T_BITXOR, P_CARET, "^" },
{ T_BITAND, P_AMP, "&" },
{ T_MULDIV, P_STAR, "*" },
{ T_BITOR, P_BAR, "|" },
{ T_UNIFY, P_TILDE, "~" },
{ T_MULDIV, P_SLASH, "/" },
{ T_COMPARE, P_GT, ">" },
{ T_COMPARE, P_LT, "<" },
{ T_TERNARY, P_QUES, "?" },
{ T_TERNARY, P_COLON, ":" },
{ T_ASSIGN, P_EQ, "=" },
{ T_UNIFY, P_PLUSPLUS, "++" },
{ T_UNIFY, P_SUBSUB, "--" },
{ T_EQUALITY, P_EQEQ, "==" },
{ T_COMPARE, P_LTEQ, "<=" },
{ T_COMPARE, P_GTEQ, ">=" },
{ T_EQUALITY, P_BANGEQ, "!=" },
{ T_SHIFT, P_LTLT, "<<" },
{ T_SHIFT, P_GTGT, ">>" },
{ T_SHIFT, P_GTGTGT, ">>>" },
{ T_ASSIGN, P_PLUSEQ, "+=" },
{ T_ASSIGN, P_SUBEQ, "-=" },
{ T_ASSIGN, P_STAREQ, "*=" },
{ T_ASSIGN, P_SLASHEQ, "/=" },
{ T_ASSIGN, P_AMPEQ, "&=" },
{ T_ASSIGN, P_BAREQ, "|=" },
{ T_ASSIGN, P_CARETEQ, "^=" },
{ T_ASSIGN, P_PERCENTEQ, "%=" },
{ T_ASSIGN, P_LTLTEQ, "<<=" },
{ T_ASSIGN, P_GTGTEQ, ">>=" },
{ T_ASSIGN, P_GTGTGTEQ, ">>>=" },
{ T_OR, P_BARBAR, "||" },
{ T_AND, P_AMPAMP, "&&" },
{ T_KEYWORD, P_ABSTRACT, "abstract" },
{ T_KEYWORD, P_ASSERT, "assert" },
{ T_KEYWORD, P_BOOLEAN, "boolean" },
{ T_KEYWORD, P_BREAK, "break" },
{ T_KEYWORD, P_BYTE, "byte" },
{ T_KEYWORD, P_CASE, "case" },
{ T_KEYWORD, P_CATCH, "catch" },
{ T_KEYWORD, P_CHAR, "char" },
{ T_KEYWORD, P_CLASS, "class" },
{ T_KEYWORD, P_CONST, "const" },
{ T_KEYWORD, P_CONTINUE, "continue" },
{ T_KEYWORD, P_DEFAULT, "default" },
{ T_KEYWORD, P_DO, "do" },
{ T_KEYWORD, P_DOUBLE, "double" },
{ T_KEYWORD, P_ELSE, "else" },
{ T_KEYWORD, P_EXTENDS, "extends" },
{ T_KEYWORD, P_FINAL, "final" },
{ T_KEYWORD, P_FINALLY, "finally" },
{ T_KEYWORD, P_FLOAT, "float" },
{ T_KEYWORD, P_FOR, "for" },
{ T_KEYWORD, P_GOTO, "goto" },
{ T_KEYWORD, P_IF, "if" },
{ T_KEYWORD, P_IMPLEMENTS, "implements" },
{ T_KEYWORD, P_IMPORT, "import" },
{ T_KEYWORD, P_INSTANCEOF, "instanceof" },
{ T_KEYWORD, P_INT, "int" },
{ T_KEYWORD, P_INTERFACE, "interface" },
{ T_KEYWORD, P_LONG, "long" },
{ T_KEYWORD, P_NATIVE, "native" },
{ T_KEYWORD, P_NEW, "new" },
{ T_KEYWORD, P_PACKAGE, "package" },
{ T_KEYWORD, P_PRIVATE, "private" },
{ T_KEYWORD, P_PROTECTED, "protected" },
{ T_KEYWORD, P_PUBLIC, "public" },
{ T_KEYWORD, P_RETURN, "return" },
{ T_KEYWORD, P_SHORT, "short" },
{ T_KEYWORD, P_STATIC, "static" },
{ T_KEYWORD, P_STRICTFP, "strictfp" },
{ T_KEYWORD, P_SUPER, "super" },
{ T_KEYWORD, P_SWITCH, "switch" },
{ T_KEYWORD, P_SYNCHRONIZED, "synchronized" },
{ T_KEYWORD, P_THIS, "this" },
{ T_KEYWORD, P_THROW, "throw" },
{ T_KEYWORD, P_THROWS, "throws" },
{ T_KEYWORD, P_TRANSIENT, "transient" },
{ T_KEYWORD, P_TRY, "try" },
{ T_KEYWORD, P_VOID, "void" },
{ T_KEYWORD, P_VOLATILE, "volatile" },
{ T_KEYWORD, P_WHILE, "while" },
{ T_BOOL, P_TRUE, "true" },
{ T_BOOL, P_FALSE, "false" },
{ T_KEYWORD, P_NULL, "null" },
{ T_ERROR, P_ERROR, "" },
{ T_COMMENT, -1, "" },
{ T_SPACE, -1, "" },
{ T_IDENTIFIER, P_IDENTIFIER, "" },
{ T_CHAR, P_CHARLITERAL, "" },
{ T_INT, P_INTLITERAL, "" },
{ T_INT, P_LONGLITERAL, "" },
{ T_FLOAT, P_FLOATLITERAL, "" },
{ T_FLOAT, P_DOUBLELITERAL, "" },
{ T_STRING, P_STRINGLITERAL, "" },
{ T_BOUND, P_LPAREN, "(" },
{ T_BOUND, P_RPAREN, ")" },
{ T_BOUND, P_LBRACKET, "[" },
{ T_BOUND, P_RBRACKET, "]" },
{ T_BOUND, P_DOT, "." },
{ T_COMMA, P_COMMA, "," },
{ T_BRACKET, P_LBRACE, "{" },
{ T_BRACKET, P_RBRACE, "}" },
{ T_SEMICOLON, P_SEMI, ";" }
};

//优先级对照表结构
struct primap
{
	int type;
	int priority;
};

//优先级对照表
static const struct primap PRI_MAP[PRIORITY_LENGTH] =
{
{ T_ASSIGN, 1 },
{ T_TERNARY, 2 },
{ T_OR, 3 },
{ T_AND, 4 },
{ T_BITOR, 5 },
{ T_BITXOR, 6 },
{ T_BITAND, 7 },
{ T_EQUALITY, 8 },
{ T_COMPARE, 9 },
{ T_SHIFT, 10 },
{ T_ADDSUB, 11 },
{ T_MULDIV, 12 },
{ T_UNIFY, 13 },
{ T_BOUND, 14 }
};

#endif

