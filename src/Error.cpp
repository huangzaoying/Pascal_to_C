




#include "Error.h"
#include <cstring>
#include <string>
#include <cstdlib>
#define outfile stderr

extern int yylineno;
extern int num_column;

void truncate()
{
    error_0("an unrecoverable error has occurred, the compilation is aborted.");
    exit(0);
}

void error_0(const char* error_msg)
{
    if(strcmp(error_msg,"syntax error")==0) return;
    fprintf(outfile, "At (%d, %d), %s\n", yylineno, num_column, error_msg);
}

void error_2()
{
    error_0("ERROR: An identifier is expected.\n");
}

void error_3()
{
    error_0("ERROR: Program must begin with the symbol 'program'.\n");
}

void error_4()
{
    error_0("ERROR: A closing parenthesis(')') is expected.\n");
}

void error_5()
{
    error_0("ERROR: A colon(':') is expected. In declarations, the colon(':') is followed by a type.\n");
}

void error_7()
{
    error_0("ERROR: In a formal parameter list each section must begin with an identifier or the symbol var, depending whether the parameter is a value or a variable parameter.\n");
}

void error_8()
{
    error_0("ERROR: The symbol 'of' is expected.\n");
}

void error_9()
{
    error_0("ERROR: An opening parenthesis('(') is expected.\n");
    truncate();
}

void error_10()
{
    error_0("Error: A type definition must begin with an identifier, the symbol array, or the symbol record.\n");
}

void error_11()
{
    error_0("ERROR: An opening bracket('[') is expected.\n");
    truncate();
}

void error_12()
{
    error_0("ERROR: A closing bracket(']') is expected.\n");
}

void error_13()
{
    error_0("ERROR: The symbol .. is expected (no blank between the dots).\n");
}

void error_14()
{
    error_0("ERROR: A semicolon(';') is expected.\n");
}

void error_15()
{
    error_0("ERROR: The result of a function must be of type integer, real, Boolean, or char.\n");
}

void error_16()
{
    error_0("ERROR: An equal sign('=') is expected. The symbol := is used in assignment statements only, but not in declarations.\n");
}

void error_21()
{
    error_0("ERROR: The indicated is too large. The maximum number of number digits is 14.\n");
}

void error_22()
{
    error_0("ERROR: A dot('.') is expected at end of the corresponding begin and end symbols.\n");
}

void error_24()
{
    error_0("ERROR: The designated character is not acceptable.\n");
}

void error_25()
{
    error_0("ERROR: In a constant definition, the equal sign must be followed constant.\n");
}

void error_29()
{
    error_0("ERROR: A type identifier is expected here.\n");
}

void error_37()
{
    error_0("ERROR: A variable is expected.\n");
}

void error_51()
{
    error_0("ERROR: The symbol ':=' is expected. (No space between : and =).\n");
}

void error_52()
{
    error_0("ERROR: The symbol 'then' is expected.\n");
}
void error_53()
{
    error_0("ERROR: The symbol until is expected.\n");
}
void error_54()
{
    error_0("ERROR: The symbol do is expected.\n");
}
void error_55()
{
    error_0("ERROR: The symbol to (or downto) is expected.\n");
}
void error_56()
{
    error_0("ERROR: The symbol begin is expected.\n");
}
void error_57()
{
    error_0("ERROR: The symbol end is expected.\n");
}

void error_58()
{
    error_0("ERROR: A factor must begin with an identifier, a constant, the symbol not, or with a left parenthesis.\n");
}