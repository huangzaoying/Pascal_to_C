%{
    #include <cstdio>
    #include <cstring>

    #include "SymbolType.h"
    #include "SymbolTable.h"
    #include "List.h"
    #include "Error.h"

    #include "yacc.tab.h"

    void countNotes();
    std::string* new_text(char*);
    void stk_push(char);
    void stk_pop(char);
    void stk_clear();

    int num_lines = 1, num_column = 0;
    int tp = 0;
    char stk[1010];
%}

%option noyywrap
%option yylineno

LETTER      [a-zA-Z]
DIGIT       [0-9]
ID          {LETTER}({LETTER}|{DIGIT})*
DIGITS      {DIGIT}+
FRACTION    (\.{DIGITS})

CONSTINT    {DIGITS}
CONSTREAL   {DIGITS}{FRACTION}

PERIOD      [+-]?{DIGITS}[ \t]*".."[ \t]*[+-]?{DIGITS}
PERIODERR13 [+-]?{DIGITS}[ \t]*". ."[ \t]*[+-]?{DIGITS}

NOTES       (\{[^}]*\})|"//"(.+)?

%%

[aA][rR][rR][aA][yY]                    {num_column += yyleng; return ARRAY;}
[bB][eE][gG][iI][nN]                    {num_column += yyleng; return BEGINNING;}
[bB][oO][oO][lL][eE][aA][nN]            {num_column += yyleng; return BOOLEAN;}
[cC][aA][sS][eE]                        {num_column += yyleng; return CASE;}
[cC][hH][aA][rR]                        {num_column += yyleng; return CHAR;}
[cC][oO][nN][sS][tT]                    {num_column += yyleng; return CONST;}
[dD][oO]                                {num_column += yyleng; return DO;}
[dD][oO][wW][nN][tT][oO]                {num_column += yyleng; return DOWNTO;}
[eE][lL][sS][eE]                        {num_column += yyleng; return ELSE;}
[eE][nN][dD]                            {num_column += yyleng; return END;}
[fF][oO][rR]                            {num_column += yyleng; return FOR;}
[fF][uU][nN][cC][tT][iI][oO][nN]        {num_column += yyleng; return FUNCTION;}
[iI][fF]                                {num_column += yyleng; return IF;}
[iI][nN][tT][eE][gG][eE][rR]            {num_column += yyleng; return INTEGER;}
[nN][oO][tT]                            {num_column += yyleng; return NOT;}
[oO][fF]                                {num_column += yyleng; return OF;}
[pP][rR][oO][cC][eE][dD][uU][rR][eE]    {num_column += yyleng; return PROCEDURE;}
[pP][rR][oO][gG][rR][aA][mM]            {num_column += yyleng; return PROGRAM;}
[rR][eE][aA][lL]                        {num_column += yyleng; return REAL;}
[rR][eE][cC][oO][rR][dD]                {num_column += yyleng; return RECORD;}
[rR][eE][pP][eE][aA][tT]                {num_column += yyleng; return REPEAT;}
[tT][hH][eE][nN]                        {num_column += yyleng; return THEN;}
[tT][oO]                                {num_column += yyleng; return TO;}
[tT][yY][pP][eE]                        {num_column += yyleng; return TYPE;}
[uU][nN][tT][iI][lL]                    {num_column += yyleng; return UNTIL;}
[vV][aA][rR]                            {num_column += yyleng; return VAR;}
[wW][hH][iI][lL][eE]                    {num_column += yyleng; return WHILE;}

[rR][eE][aA][dD]                        {num_column += yyleng; return READ;}
[wW][rR][iI][tT][eE]                    {num_column += yyleng; return WRITE;}
[wW][rR][iI][tT][eE][lL][nN]            {num_column += yyleng; return WRITELN;}

[tT][rR][uU][eE]                        {num_column += yyleng; yylval.num = new Const(std::string("1"), _CONSTBOOL_); return NUM;}
[fF][aA][lL][sS][eE]                    {num_column += yyleng; yylval.num = new Const(std::string("0"), _CONSTBOOL_); return NUM;}

"="                 {num_column += yyleng; yylval.text = new_text(yytext); return EQUAL;}
"<>"                {num_column += yyleng; yylval.text = new std::string("!="); return RELOP;}
"<"                 {num_column += yyleng; yylval.text = new_text(yytext); return RELOP;}
">"                 {num_column += yyleng; yylval.text = new_text(yytext); return RELOP;}
"<="                {num_column += yyleng; yylval.text = new_text(yytext); return RELOP;}
">="                {num_column += yyleng; yylval.text = new_text(yytext); return RELOP;}
"+"                 {num_column += yyleng; yylval.text = new_text(yytext); return ADDOP;}
"-"                 {num_column += yyleng; yylval.text = new_text(yytext); return ADDOP;}
"*"                 {num_column += yyleng; yylval.text = new_text(yytext); return MULOP;}
"/"                 {num_column += yyleng; yylval.text = new_text(yytext); return MULOP;}
[dD][iI][vV]        {num_column += yyleng; yylval.text = new_text(yytext); return MULOP;}
[mM][oO][dD]        {num_column += yyleng; yylval.text = new_text(yytext); return MULOP;}
[aA][nN][dD]        {num_column += yyleng; yylval.text = new_text(yytext); return MULOP;}
":="                {num_column += yyleng; return ASSIGNOP;}
": ="               {error_51(); num_column += yyleng; return ASSIGNOP;}
[oO][rR]            {num_column += yyleng; return OROP;}

"."         {num_column += yyleng; return '.';}
","         {num_column += yyleng; return ',';}
";"         {num_column += yyleng; return ';';}
":"         {num_column += yyleng; return ':';}
"("         {num_column += yyleng; stk_push('('); return '(';}
")"         {num_column += yyleng; stk_pop('('); return ')';}
"["         {num_column += yyleng; stk_push('['); return '[';}
"]"         {num_column += yyleng; stk_pop('['); return ']';}
"'"         {num_column += yyleng; return '\'';}
" "         {num_column += 1;}
[\t]        {num_column += 4;}
[\n]        {stk_clear(); num_lines++; num_column = 0;}
[ \t]*\n    {stk_clear(); num_lines++; num_column = 0;}

{CONSTINT}  {
    if(yyleng>14)
        error_21();
    num_column += yyleng;
    yylval.num = new Const(std::string(yytext), _CONSTINT_);
    return NUM;
}

{CONSTREAL} {
    if(yyleng>14)
        error_21();
    num_column += yyleng;
    yylval.num = new Const(std::string(yytext), _CONSTREAL_);
    return NUM;
}

"'"[^']*"'" {
    num_column += yyleng;
    yylval.text = new std::string(yytext);
    if(yyleng!=3)
        error_24();
    return CONSTCHAR;
}

{ID} {
    num_column += yyleng;
    yylval.text = new_text(yytext);
    return ID;
}

{PERIOD}    {
    num_column += yyleng;
    int l, r, len = strlen(yytext);
    std::string str = yytext;
    for(l=0; yytext[l+1] == '-' || ('0' <= yytext[l+1] && yytext[l+1] <= '9') ; l++) ;
    for(r=len-1; yytext[r-1] == '-' || ('0' <= yytext[r-1] && yytext[r-1] <= '9'); r--) ;
    yylval.period = new Period(str.substr(0, l+1), str.substr(r, len-r));
    return PERIOD;
}

{PERIODERR13}   {
    error_13();
    num_column += yyleng;
    int l, r, len = strlen(yytext);
    std::string str = yytext;
    for(l=0; yytext[l+1] == '-' || ('0' <= yytext[l+1] && yytext[l+1] <= '9') ; l++) ;
    for(r=len-1; yytext[r-1] == '-' || ('0' <= yytext[r-1] && yytext[r-1] <= '9'); r--) ;
    yylval.period = new Period(str.substr(0, l+1), str.substr(r, len-r));
    return PERIOD;
}

{NOTES}     {countNotes();}

.           {
    num_column += yyleng;
    error_24();
    //fprintf(stderr,"Invalid character at line %d: %c\n", num_lines, yytext[0]);
}

%%

void countNotes()
{
    for(int i = 0; yytext[i]; i++)
        switch(yytext[i])
        {
            case '\n': num_lines++; num_column=0; break;
            case '\t': num_column+=4;break;
            default: num_column++;break;
        }
}

std::string* new_text(char* str)
{
    std::string* res = new std::string(str);
    for(int i = res->length() - 1; ~i; i--)
        if('A' <= (*res)[i] && (*res)[i] <= 'Z')
            (*res)[i] = 'a' + ((*res)[i] - 'A');
    return res;
}

void stk_push(char ch)
{
    stk[++tp] = ch;
}

void stk_pop(char ch)
{
    while((tp > 0) && (stk[tp] != ch))
    {
        if(ch == '(')
        {
            error_9();
        }
        else // ch == '['
        {
            error_11();
        }
        tp--;
    }
    if(tp == 0)
    {
        if(ch == '(')
        {
            error_9();
        }
        else // ch == '['
        {
            error_11();
        }
    }
    else
        tp--;
}

void stk_clear()
{
    tp=0;
}