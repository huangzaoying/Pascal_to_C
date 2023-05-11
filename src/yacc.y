%{
    #include <fstream>
    #include <cstdio>
    #include <vector>
    #include <string> 
    #include <assert.h>
    #include <string.h>

    #include "SymbolTable.h"
    #include "SymbolType.h"
    #include "List.h"
    #include "Error.h"

    extern "C"
    {
        int yyparse(void);
        int yyerror(const char *s);
    };
        
    extern int yylex(void);
    int yyerror(std::string s);

    bool parseError = false;
    const std::string c_equal = "=";
    const std::string c_lmid = "[";
    const std::string c_rmid = "]";
    const std::string c_minus = "-";
    
    int tab_count = 0;

    SymbolTable symbol_table;
    void list_symbol_insert(List *head, TokenNUM* type);
    void make_ref_seq(std::vector<int> &seq, List* head);
    void make_type_seq(std::vector<ValueType> &seq, List* head);
    // void get_ref_seq(std::vector<int> &seq, ExpList* head, text fun);
    void print_tab();

%}

%union{
    std::string* text;
    Period *period;
    Periods *period_list;
    Const* num;
    TokenNUM* token;
    List* list;
    ExpList* explist;
}


%token ARRAY BEGINNING BOOLEAN CASE CHAR CONST DO DOWNTO ELSE END
%token FOR FUNCTION IF INTEGER NOT OF PROCEDURE PROGRAM
%token REAL RECORD REPEAT THEN TO TYPE UNTIL VAR WHILE READ WRITE WRITELN
%token ASSIGNOP OROP

%token<text> RELOP ADDOP MULOP EQUAL
%token<text> ID CONSTCHAR
%token<num> NUM
%token<period> PERIOD

%type<list> idlist parameter_list formal_parameter parameter var_parameter value_parameter
%type<explist> expression_list variable_list id_varpart
%type<token> type basic_type
%type<period_list> periods
%type<num> const_value factor variable term simple_expression expression procedure_call function_call
%type<text> subprogram_head statement compound_statement statement_list

%%


programstruct                       : program_head { printf("#include <stdio.h>\n\n"); symbol_table.locate("__global__");} program_body1
                                    ;
program_body1                       : ';' program_body2
                                    | {error_14();} program_body2
                                    | error {error_14(); ;yyclearin; yyerrok;} program_body2
                                    ;
program_body2                       : program_body program_body3
                                    ;
program_body3                       :  '.'
                                    |  error { error_22();yyclearin;  yyerrok; }
                                    |  { error_22();  yyerrok; }
                                    ;

program_head                        : PROGRAM ID '(' idlist ')'
                                    | PROGRAM ID
                                    | PROGRAM ID  '(' ')'
                                    | PROGRAM {error_2(); yyerrok;}
                                    /* | PROGRAM error {error_2(); yyerrok;} '(' idlist ')'  */
                                    | PROGRAM ID '(' idlist error {error_4(); yyerrok;} // 也许可以恢复右括号
                                    | PROGRAM ID error {error_9(); yyerrok;} idlist ')'
                                    | { error_3(); yyerrok;}
                                    /* | PROGRAM error {error_2(); yyerrok;} '(' idlist error {error_4(); yyerrok;}
                                    | PROGRAM error {error_2(); yyerrok;} error {error_9(); yyerrok;} idlist error {error_4(); yyerrok;}
                                    | PROGRAM ID error {error_9(); yyerrok;} idlist error {error_4(); yyerrok;}
                                    | PROGRAM error {error_2(); error_9(); yyerrok;} idlist error {error_4(); yyerrok;}
                                    | PROGRAM error {error_2(); yyerrok;}
                                    | error { error_3(); yyerrok;} */
                                    ;
program_body                        : const_declarations
                                      var_declarations { printf("\n");}
                                      subprogram_declarations { printf("int main()\n{\n"); symbol_table.locate("__main__"); tab_count ++;}
                                        compound_statement { print_tab(); tab_count --; printf("return 0;\n}"); symbol_table.relocate(); symbol_table.relocate();}
                                    ;
idlist              		        : ID {
                                        if (symbol_table.get_location() == *$1)
                                            $$ = new List(new TokenID(std::string("_") + *$1, _NONE_));
                                        else if (symbol_table.get_reference(*$1))
                                            $$ = new List(new TokenID(std::string("*") + *$1, _NONE_));
                                        else
                                            $$ = new List(new TokenID(*$1, _NONE_));
                                    }
								    | idlist ',' ID {
                                        $$ = $1;
                                        if (symbol_table.get_location() == *$3)
                                            list_append($$, new TokenID(std::string("_") + *$3, _NONE_));
                                        else if (symbol_table.get_reference(*$3))
                                            list_append($$, new TokenID(std::string("*") + *$3, _NONE_));
                                        else
                                            list_append($$, new TokenID(*$3, _NONE_));
                                    }
                                    | idlist ',' error {error_37();yyerrok;}
                                    /* | error {error_37();yyerrok;} */
                                    ;
const_declarations                  :
                                    | CONST const_declaration { printf("\n");} 
                                    ;
const_declaration                   :
                                    | ID EQUAL expression ';' {
                                        if ($3==nullptr)
                                            yyerror("ERROR: Illegal expression");
                                        else {
                                            auto type = $3->value_type;
                                            if (type == _INT_)
                                                type = _CONSTINT_;
                                            if (type == _REAL_)
                                                type = _CONSTREAL_;
                                            if (type == _BOOL_)
                                                type = _CONSTBOOL_;
                                            if (type == _CHAR_)
                                                type = _CONSTCHAR_;
                                            if(symbol_table.insert(new TokenNUM(_NUM_, *$1, type))==0){
                                                yyerror(std::string() + "ERROR: Duplicate identifier");	
                                            }
                                            print_tab();
                                            printf("const %s %s = %s;\n", codeTypeName[$3->value_type].c_str(),
                                                $1 -> c_str(), $3 -> value.c_str());
                                        }
                                    } const_declaration
                                    | ID {error_25(); yyerrok;} expression ';' {
                                        if(symbol_table.insert(new TokenNUM(_NUM_, *$1, $3->value_type))==0){
                                        	yyerror(std::string() + "ERROR: Duplicate identifier");	
										}
                                        print_tab();
                                        printf("const %s %s = %s;\n", codeTypeName[$3->value_type].c_str(),
                                            $1 -> c_str(), $3 -> value.c_str());
                                        
                                    } const_declaration
                                    | ID ASSIGNOP {error_25(); yyerrok;} expression ';' {
                                        if(symbol_table.insert(new TokenNUM(_NUM_, *$1, $4->value_type))==0){
                                        	yyerror(std::string() + "ERROR: Duplicate identifier");	
										}
                                        print_tab();
                                        printf("const %s %s = %s;\n", codeTypeName[$4->value_type].c_str(),
                                            $1 -> c_str(), $4 -> value.c_str());
                                        
                                    } const_declaration
                                    /* | ID EQUAL error {error_25(); yyerrok;} ';' const_declaration
                                    | ID ASSIGNOP const_value ';' const_declaration {
                                        error_16();
                                        if(symbol_table.insert(new TokenNUM(_NUM_, *$1, $3->value_type))==0){
                                        	yyerror(std::string() + "ERROR: Duplicate identifier");	
										}
                                        print_tab();
                                        printf("const %s %s = %s;\n", codeTypeName[$3->value_type].c_str(),
                                            $1 -> c_str(), $3 -> value.c_str());
                                    }
                                    | ID ASSIGNOP error {error_25(); yyerrok;} ';' const_declaration 
                                    | ID EQUAL const_value error {error_14(); yyerrok;} const_declaration {
                                        if(symbol_table.insert(new TokenNUM(_NUM_, *$1, $3->value_type))==0){
                                        	yyerror(std::string() + "ERROR: Duplicate identifier");	
										}
                                        print_tab();
                                        printf("const %s %s = %s;\n", codeTypeName[$3->value_type].c_str(),
                                            $1 -> c_str(), $3 -> value.c_str());
                                    } 
                                    | ID EQUAL error { error_25(); error_14(); yyerrok;} const_declaration
                                    | ID ASSIGNOP const_value error {error_14(); yyerrok;} const_declaration {
                                        error_16();
                                        if(symbol_table.insert(new TokenNUM(_NUM_, *$1, $3->value_type))==0){
                                        	yyerror(std::string() + "ERROR: Duplicate identifier");	
										}
                                        print_tab();
                                        printf("const %s %s = %s;\n", codeTypeName[$3->value_type].c_str(),
                                            $1 -> c_str(), $3 -> value.c_str());
                                    }  */
                                    /* | ID ASSIGNOP error { error_25(); error_14(); error_16(); yyerrok;} const_declaration */
                                    // | error {error_37(); yyerrok;} EQUAL const_value ';' const_declaration
                                    // | error {error_37(); yyerrok;} EQUAL error {error_25(); yyerrok;} ';' const_declaration
                                    // | error {error_37(); yyerrok;} ASSIGNOP {error_16();} const_value ';' const_declaration
                                    // | error {error_37(); yyerrok;} ASSIGNOP {error_16();} error {error_25(); yyerrok;} ';' const_declaration
                                    // | error {error_37(); yyerrok;} EQUAL const_value error {error_14(); yyerrok;} const_declaration
                                    // | error {error_37(); yyerrok;} EQUAL error { error_25(); error_14(); yyerrok;} const_declaration
                                    // | error {error_37(); yyerrok;} ASSIGNOP {error_16();} const_value error {error_14(); yyerrok;} const_declaration
                                    // | error {error_37(); yyerrok;} ASSIGNOP {error_16();} error { error_25(); error_14(); yyerrok;} const_declaration
                                    ;
const_value                         : ADDOP NUM { $$ = $2; $$->value = *$1 + $2->value; }
                                    | NUM { $$ = $1; }
                                    | CONSTCHAR { $$ = new Const(*$1, _CHAR_); }
                                    ;
var_declarations                    :
                                    | VAR var_declaration
                                    ;
var_declaration                     : 
     					            | idlist ':' type ';' var_declaration  {
                                        list_symbol_insert($1, $3);
                                        print_tab();
                                        printf("%s ", codeTypeName[$3->get_value_type()].c_str());
                                        if ($3->get_token_type() == _ARRAY_)
                                            list_print($1, (TokenARRAY*)$3);
                                        else
                                            list_print($1);
                                        printf(";\n");
                                    }
                                    | idlist ':' error {error_29(); yyclearin; yyerrok;} ';' var_declaration 
                                    | idlist ':' {error_29(); yyerrok;} ';' var_declaration 
                                    | idlist ':' type error {error_14();yyclearin; yyerrok;} var_declaration  {
                                        list_symbol_insert($1, $3);
                                        print_tab();
                                        printf("%s ", codeTypeName[$3->get_value_type()].c_str());
                                        if ($3->get_token_type() == _ARRAY_)
                                            list_print($1, (TokenARRAY*)$3);
                                        else
                                            list_print($1);
                                        printf(";\n");
                                    }
                                    | idlist ':' type {error_14(); yyerrok;} var_declaration  {
                                        list_symbol_insert($1, $3);
                                        print_tab();
                                        printf("%s ", codeTypeName[$3->get_value_type()].c_str());
                                        if ($3->get_token_type() == _ARRAY_)
                                            list_print($1, (TokenARRAY*)$3);
                                        else
                                            list_print($1);
                                        printf(";\n");
                                    }
                                    | idlist ':' error { error_29(); error_14();yyclearin; yyerrok;} var_declaration
                                    | idlist ':' { error_29(); error_14(); yyerrok;} var_declaration
                                    | idlist error {error_5(); yyerrok;} type ';' var_declaration
                                    | idlist {error_5(); yyerrok;} type ';' var_declaration
                                    | idlist error {error_5(); error_29();yyclearin; yyerrok;} ';' var_declaration
                                    | idlist {error_5(); error_29(); yyerrok;} ';' var_declaration
                                    | idlist error {error_5(); error_29(); error_14();yyclearin; yyerrok;} var_declaration
                                    | idlist {error_5(); error_29(); error_14(); yyerrok;} var_declaration
                                    ; // 需要统一 type 在是数组和非数组两种情况下的类型，并且，留一个供判断是否是数组的接口
type                     		    : basic_type { $$ = $1; }
                                    | ARRAY '[' periods ']' OF basic_type {
                                        $$ = new TokenARRAY("", $6->get_value_type(), $3->l_list, $3->r_list);
                                    }
                                    // 
                                    /* | ARRAY '[' periods error {error_12();} OF basic_type {
                                        $$ = new TokenARRAY("", $7->get_value_type(), $3->l_list, $3->r_list);
                                    }
                                    | ARRAY '[' periods ']' error {
                                        error_8();
                                        $$ = nullptr;
                                        yyerrok;
                                    }
                                    | ARRAY '[' periods error {
                                        error_12();
                                        error_8();
                                        $$ = nullptr;
                                        yyerrok;
                                    }
                                    | ARRAY error {
                                        error_11();
                                        $$ = nullptr;
                                        yyerrok;
                                    }  */
                                    // 左括号缺失
                                    | ARRAY {error_11();yyerrok;} periods ']' OF basic_type {
                                        $$ = new TokenARRAY("", $6->get_value_type(), $3->l_list, $3->r_list);
                                    }
                                    // 有括号缺失
                                    | ARRAY '[' periods {error_12();yyerrok;} OF basic_type {
                                        $$ = new TokenARRAY("", $6->get_value_type(), $3->l_list, $3->r_list);
                                    }
                                    // of的缺失
                                    | ARRAY '[' periods ']' {error_8();yyerrok;} basic_type {
                                        $$ = new TokenARRAY("", $6->get_value_type(), $3->l_list, $3->r_list);
                                    }
                                    ;
basic_type                          : INTEGER { $$ = new TokenID("", _INT_); }
                                    | REAL { $$ = new TokenID("", _REAL_); }
                                    | BOOLEAN { $$ = new TokenID("", _BOOL_); }
                                    | CHAR { $$ = new TokenID("", _CHAR_); }
                                    ;
periods							    : periods ',' PERIOD {
                                        $$ = $1;
                                        $$->l_list.push_back($3->lower);
                                        $$->r_list.push_back($3->upper);
                                    }

                                    
								    | PERIOD {
                                        $$ = new Periods();
                                        $$->l_list.push_back($1->lower);
                                        $$->r_list.push_back($1->upper);
                                    }
								    ;
//period                          	   : DIGITS '.' '.' DIGITS {$$.l_list.push_back($1),$$.r_list.push_back($4);}
//                                    | period {$$.l_list=$1.l_list,$$.r_list=$1.r_list;} ',' DIGITS '.' '.' DIGITS {$$.l_list.push_back($1),$$.r_list.push_back($4);}
//                                    ;
subprogram_declarations			    :
                                    | subprogram_declarations subprogram ';'
                                    | subprogram_declarations subprogram error {error_14(); yyerrok;}
                                    ;
subprogram                          : subprogram_head { print_tab(); printf("%s\n{\n", $1->c_str()); tab_count ++; } ';' {
                                        std::string temp = symbol_table.get_location();
                                        if (symbol_table.get_type(temp) != _VOID_) {
                                            auto type = symbol_table.get_type(temp);
                                            if(symbol_table.insert(new TokenID(std::string("_") + temp, type))==0){
                                            	yyerror(std::string() + "ERROR: Duplicate identifier");	
											}
                                            print_tab();
                                            printf("%s _%s;\n", codeTypeName[type].c_str(), temp.c_str());
                                        }
                                    } subprogram_body {
                                        std::string temp = symbol_table.get_location();
                                        if (symbol_table.get_type(temp) != _VOID_) {
                                            print_tab();
                                            printf("return _%s;\n", temp.c_str());
                                        }
                                        tab_count --;
                                        print_tab();
                                        printf("}\n\n");
                                        symbol_table.relocate();
                                    }
                                    | subprogram_head {print_tab(); printf("%s\n{\n", $1->c_str()); tab_count ++; } error {error_14(); yyerrok;} {
                                        std::string temp = symbol_table.get_location();
                                        if (symbol_table.get_type(temp) != _VOID_) {
                                            auto type = symbol_table.get_type(temp);
                                            if(symbol_table.insert(new TokenID(std::string("_") + temp, type))==0){
                                            	yyerror(std::string() + "ERROR: Duplicate identifier");	
											}
                                            print_tab();
                                            printf("%s _%s;\n", codeTypeName[type].c_str(), temp.c_str());
                                        }
                                    } subprogram_body {
                                        std::string temp = symbol_table.get_location();
                                        if (symbol_table.get_type(temp) != _VOID_) {
                                            print_tab();
                                            printf("return _%s;\n", temp.c_str());
                                        }
                                        tab_count --;
                                        print_tab();
                                        printf("}\n\n");
                                        symbol_table.relocate();
                                    }
                                    ;
subprogram_head       			    : PROCEDURE ID {
                                        std::vector<int> v1;
                                        std::vector<ValueType> v2;
                                        TokenFUNC *t = new TokenFUNC(*$2, _VOID_, v1, v2);
                                        if(symbol_table.insert((TokenNUM*)t)==0){
                                        	yyerror(std::string() + "ERROR: Duplicate identifier");	
										}
                                        symbol_table.locate(*$2);
                                    } 
                                    formal_parameter {
                                        std::vector<int> v1;
                                        std::vector<ValueType> v2;
                                        make_ref_seq(v1, $4);
                                        make_type_seq(v2, $4);
                                        TokenFUNC *t = new TokenFUNC(*$2, _VOID_, v1, v2);
                                        symbol_table.reset_token(*$2, (TokenNUM*)t);
                                        $$ = new std::string;
                                        *$$ = *$$ + "void " + *$2 + "(";
                                        int cnt = 0;
                                        auto i = $4;
                                        while (i && i->next) {
                                            *$$ += codeTypeName[i->x->get_value_type()];
                                            if (v1[cnt])
                                                *$$ += "* ";
                                            else
                                                *$$ +=  " ";
                                            *$$ +=  i->x->get_value() + ", ";
                                            i = i->next;
                                            ++cnt;
                                        }
                                        if (i) {
                                            *$$ += codeTypeName[i->x->get_value_type()];
                                            if (v1[cnt])
                                                *$$ += "* ";
                                            else
                                                *$$ +=  " ";
                                            *$$ +=  i->x->get_value();
                                        }
                                        *$$ +=  ")";
                                    }
                                    | FUNCTION ID 
                                    {
                                        std::vector<int> v1;
                                        std::vector<ValueType> v2;
                                        TokenFUNC *t = new TokenFUNC(*$2, _VOID_, v1, v2);
                                        if(symbol_table.insert((TokenNUM*)t)==0){
                                        	yyerror(std::string() + "ERROR: Duplicate identifier");	
										}
                                        symbol_table.locate(*$2);
                                    } 
                                    formal_parameter ':' basic_type {
                                        std::vector<int> v1;
                                        std::vector<ValueType> v2;
                                        make_ref_seq(v1, $4);
                                        make_type_seq(v2, $4);
                                        TokenFUNC *t = new TokenFUNC(*$2, $6->get_value_type(), v1, v2);
                                        symbol_table.reset_token(*$2, (TokenNUM*)t);
                                        $$ = new std::string;
                                        *$$ = codeTypeName[$6->get_value_type()] + " " + *$2 + "(";
                                        int cnt = 0;
                                        auto i = $4;
                                        while (i && i->next) {
                                            *$$ += codeTypeName[i->x->get_value_type()];
                                            if (v1[cnt])
                                                *$$ += "* ";
                                            else
                                                *$$ +=  " ";
                                            *$$ +=  i->x->get_value() + ", ";
                                            i = i->next;
                                            ++cnt;
                                        }
                                        if (i) {
                                            *$$ += codeTypeName[i->x->get_value_type()];
                                            if (v1[cnt])
                                                *$$ += "* ";
                                            else
                                                *$$ +=  " ";
                                            *$$ +=  i->x->get_value();
                                        }
                                        *$$ +=  ")";
                                    } 
                                    /* | FUNCTION ID {
                                        std::vector<int> v1;
                                        std::vector<ValueType> v2;
                                        TokenFUNC *t = new TokenFUNC(*$2, _VOID_, v1, v2);
                                        if(symbol_table.insert((TokenNUM*)t)==0) {
                                        	yyerror(std::string() + "ERROR: Duplicate identifier");	
										}
                                        symbol_table.locate(*$2);
                                    } formal_parameter ':' error { 
                                        symbol_table.delete_token(*$2);
                                        error_15(); yyerrok;
                                    } // This cycles
                                    | PROCEDURE error {error_2(); yyerrok;} formal_parameter {
                                        $$ = new std::string;
                                        *$$ = "**UNKNOWN_PROCEDURE_NAME**"
                                    }
                                    | FUNCTION error {error_2(); yyerrok;} formal_parameter ':' basic_type {
                                        $$ = new std::string;
                                        *$$ = "**UNKNOWN_FUNCTION_NAME**"
                                    }
                                    | FUNCTION ID {
                                        std::vector<int> v1;
                                        std::vector<ValueType> v2;
                                        TokenFUNC *t = new TokenFUNC(*$2, _VOID_, v1, v2);
                                        if(symbol_table.insert((TokenNUM*)t)==0) {
                                        	yyerror(std::string() + "ERROR: Duplicate identifier");	
										}
                                        symbol_table.locate(*$2);
                                    } formal_parameter error {error_5(); yyerrok;} basic_type {
                                        std::vector<int> v1;
                                        std::vector<ValueType> v2;
                                        make_ref_seq(v1, $4);
                                        make_type_seq(v2, $4);
                                        TokenFUNC *t = new TokenFUNC(*$2, $7->get_value_type(), v1, v2);
                                        symbol_table.reset_token(*$2, (TokenNUM*)t);
                                        $$ = new std::string;
                                        *$$ = codeTypeName[$7->get_value_type()] + " " + *$2 + "(";
                                        int cnt = 0;
                                        auto i = $4;
                                        while (i && i->next) {
                                            *$$ += codeTypeName[i->x->get_value_type()];
                                            if (v1[cnt])
                                                *$$ += "* ";
                                            else
                                                *$$ +=  " ";
                                            *$$ +=  i->x->get_value() + ", ";
                                            i = i->next;
                                            ++cnt;
                                        }
                                        if (i) {
                                            *$$ += codeTypeName[i->x->get_value_type()];
                                            if (v1[cnt])
                                                *$$ += "* ";
                                            else
                                                *$$ +=  " ";
                                            *$$ +=  i->x->get_value();
                                        }
                                        *$$ +=  ")";
                                    }
                                    | FUNCTION error {error_2(); yyerrok;} formal_parameter error {error_5(); yyerrok;} basic_type */
                                    ;
formal_parameter                    : { $$ = nullptr; }
                                    | '(' parameter_list ')' { $$ = $2; }
                                    /* | error {error_9(); yyerrok;} parameter_list ')' { $$ = $3; }
                                    | {error_9(); yyerrok;} parameter_list ')' { $$ = $2; }
                                    | '(' parameter_list error {error_4(); $$ = $2; yyerrok;}
                                    | error {error_9(); yyerrok;} parameter_list error {error_4(); $$ = $3; yyerrok;} */
                                    ;
parameter_list                      : parameter { $$ = $1; }
                                    | parameter_list ';' parameter {
                                        $$ = $1;
                                        list_add($$, $3);
                                    }
                                    /* | parameter_list error {error_14(); yyerrok;} parameter {
                                        $$ = $1;
                                        list_add($$, $4);
                                    } */
                                    ;
parameter                           : var_parameter { $$ = $1; }
                                    | value_parameter { $$ = $1; }
                                    ;
var_parameter                       : VAR value_parameter {
                                        $$ = $2;
                                        for (auto i = $$; i; i = i->next) {
                                            symbol_table.set_reference(i->x->get_value());
                                            ((TokenID*)(i->x))->set_reference(1);
                                        }
                                    }
                                    ;
value_parameter                     : idlist ':' basic_type {
                                        list_symbol_insert($1, $3);
                                        $$ = $1;
                                    }
                                    /* | idlist error {error_5();} basic_type {
                                        list_symbol_insert($1, $4);
                                        $$ = $1;
                                    } */
                                    /* | error {error_7();} */
                                    ;
subprogram_body                     : const_declarations var_declarations compound_statement
                                    ;
compound_statement                  : BEGINNING statement_list END { $$ = $2; }
                                    |{
                                        error_56();
                                        yyerrok;
                                        truncate();
                                    } statement_list END { 
                                        $$ = $2; 
                                    }
                                    | BEGINNING statement_list  {
                                        error_57();
                                        $$ = $2; 
                                        yyerrok;
                                    }
                                    ;

statement_list                      : statement ';' { $$ = $1; }
                                    /* | statement error ';' { error_14(); yyerrok; $$ = $1; } */
                                    | statement_list statement ';' {$$ = $1; *$$ = *$$ + "+" + *$2; }
                                    | statement { error_14(); yyerrok; $$ = $1; }
                                    /* | statement_list statement error ';' { error_14(); yyerrok; $$ = $1; *$$ = *$$ + "+" + *$2; } */
                                    | statement_list statement { error_14(); yyerrok; $$ = $1; *$$ = *$$ + "+" + *$2; }
                                    ;
statement                           : variable ASSIGNOP expression {
										if($1->value_type==_CONSTCHAR_ || $1->value_type==_CONSTREAL_ || $1->value_type==_CONSTINT_ || $1->value_type==_CONSTBOOL_)
                                            yyerror(std::string() + "Variable identifier expected");
                                        else if(($3->value_type==_INT_ || $3->value_type==_CONSTINT_) && $1->value_type!=_INT_ && $1->value_type!=_REAL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$3->value_type] + " expected "+ valueTypeName[$1->value_type]); 
                                        else if(($3->value_type==_REAL_ || $3->value_type==_CONSTREAL_) && $1->value_type!=_REAL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$3->value_type] + " expected "+ valueTypeName[$1->value_type]);
                                        else if(($3->value_type==_CHAR_ || $3->value_type==_CONSTCHAR_) && $1->value_type!=_CHAR_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$3->value_type] + " expected "+ valueTypeName[$1->value_type]);
                                        else if(($3->value_type==_BOOL_ || $3->value_type==_CONSTBOOL_) && $1->value_type!=_BOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$3->value_type] + " expected "+ valueTypeName[$1->value_type]);
                                        else if($1->value_type!=_BOOL_ && $1->value_type!=_CHAR_ && $1->value_type!=_REAL_ && $1->value_type!=_INT_&& symbol_table.get_token_type($1->value)!=_FUNC_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$3->value_type] + " expected "+ valueTypeName[$1->value_type]);
										else if(symbol_table.get_token_type($1->value)==_ARRAY_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$3->value_type] + " expected Array");
                                        else if(symbol_table.get_token_type($1->value)==_FUNC_ && $1->value != symbol_table.get_location())
                                            yyerror(std::string() + "Argument cannot be assigned to");
										$$ = new std::string;
                                        *$$ = $1->value + " = " + $3->value;
                                        print_tab();
                                        printf("%s;\n", $$->c_str());
                                    }
                                    | procedure_call { $$ = new std::string($1->value); print_tab(); printf("%s;\n", $$->c_str()); }
                                    | function_call { $$ = new std::string($1->value); print_tab(); printf("%s;\n", $$->c_str()); }
                                    | { tab_count --; print_tab(); printf("{\n"); tab_count ++; } compound_statement { $$ = $2; tab_count --; print_tab(); printf("}\n"); tab_count ++;}
                                    | IF expression {
                                        if($2->value_type!=_BOOL_&&$2->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$2->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("if (%s)\n", $2->value.c_str());
                                    } THEN {tab_count ++;} statement {tab_count --;} else_part {
                                        $$ = new std::string($2->value);
                                    }
                                    | IF expression {
                                        if($2->value_type!=_BOOL_&&$2->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$2->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("if (%s)\n", $2->value.c_str());
                                    }  { error_52(); yyerrok; tab_count ++;} statement {tab_count --;} else_part {
                                        $$ = new std::string($2->value);
                                    }
                                    | WHILE expression {
                                        if($2->value_type!=_BOOL_&&$2->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$2->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("while (%s)\n", $2->value.c_str());
                                    } DO {tab_count ++; } statement {
                                        tab_count --; 
                                        $$ = new std::string($2->value);
                                    }
                                    | WHILE expression {
                                        if($2->value_type!=_BOOL_&&$2->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$2->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("while (%s)\n", $2->value.c_str());
                                        error_54(); yyerrok; tab_count ++; } statement {
                                        tab_count --; 
                                        $$ = new std::string($2->value);
                                    }
                                    | REPEAT {
                                        print_tab();
                                        printf("do\n");
                                        print_tab();
                                        printf("{\n");
                                        tab_count ++;
                                    } statement_list { tab_count --; print_tab(); printf("}\n");} UNTIL expression {
                                        if ($6->value_type!=_BOOL_&&$6->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$6->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("while (!(%s));\n", $6->value.c_str());
                                        $$ = new std::string($6->value);
                                    }
                                    | FOR ID {
                                        if (*$2 == symbol_table.get_location())
                                            *$2 = std::string("_") + *$2;
                                        if(symbol_table.get_type(*$2)==_ERROR_)
                                            yyerror(std::string() + "ERROR: The designated identifier has not been declared.("+ *$2 + ")");
                                        else if(symbol_table.get_token_type(*$2)==_ARRAY_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + "Array" + " expected INT");
                                        else if(symbol_table.get_type(*$2)!=_INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[symbol_table.get_type(*$2)] + " expected INT");
                                        auto type = symbol_table.get_type(*$2);
                                        if(type==_CONSTCHAR_ || type==_CONSTREAL_ || type==_CONSTINT_ || type==_CONSTBOOL_)
                                            yyerror(std::string() + "Variable identifier expected");
                                        if (symbol_table.get_reference(*$2))
                                            *$2 = std::string("*") + *$2;
                                    } ASSIGNOP expression {
                                        if($5->value_type != _INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$5->value_type] + " expected INT");
                                    } TO expression {
                                        if($8->value_type != _INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$8->value_type] + " expected INT");
                                        print_tab();
                                        printf("for(%s = %s; %s <= %s; %s ++)\n", $2->c_str(), $5->value.c_str(), $2->c_str(), $8->value.c_str(), $2->c_str());
                                        tab_count ++;
                                    } DO statement {
                                        $$ = $11;
                                        tab_count --;
                                    }
                                    | FOR ID {
                                        if (*$2 == symbol_table.get_location())
                                            *$2 = std::string("_") + *$2;
                                        if(symbol_table.get_type(*$2)==_ERROR_)
                                            yyerror(std::string() + "ERROR: The designated identifier has not been declared.("+ *$2 + ")");
                                        else if(symbol_table.get_token_type(*$2)==_ARRAY_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + "Array" + " expected INT");
                                        else if(symbol_table.get_type(*$2)!=_INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[symbol_table.get_type(*$2)] + " expected INT");
                                        auto type = symbol_table.get_type(*$2);
                                        if(type==_CONSTCHAR_ || type==_CONSTREAL_ || type==_CONSTINT_ || type==_CONSTBOOL_)
                                            yyerror(std::string() + "Variable identifier expected");
                                        if (symbol_table.get_reference(*$2))
                                            *$2 = std::string("*") + *$2;
                                    } ASSIGNOP expression {
                                        if($5->value_type != _INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$5->value_type] + " expected BOOL");
                                        printf("sdadas");
                                        error_55();
                                        yyerrok;
                                    } expression {
                                        if($7->value_type != _INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$7->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("for(%s = %s; %s <= %s; %s ++)\n", $2->c_str(), $5->value.c_str(), $2->c_str(), $7->value.c_str(), $2->c_str());
                                        tab_count ++;
                                    } DO statement {
                                        $$ = $10;
                                        tab_count --;
                                    }
                                    | FOR ID {
                                        if (*$2 == symbol_table.get_location())
                                            *$2 = std::string("_") + *$2;
                                        if(symbol_table.get_type(*$2)==_ERROR_)
                                            yyerror(std::string() + "ERROR: The designated identifier has not been declared.("+ *$2 + ")");
                                        else if(symbol_table.get_token_type(*$2)==_ARRAY_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + "Array" + " expected INT");
                                        else if(symbol_table.get_type(*$2)!=_INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[symbol_table.get_type(*$2)] + " expected INT");
                                        auto type = symbol_table.get_type(*$2);
                                        if(type==_CONSTCHAR_ || type==_CONSTREAL_ || type==_CONSTINT_ || type==_CONSTBOOL_)
                                            yyerror(std::string() + "Variable identifier expected");
                                        if (symbol_table.get_reference(*$2))
                                            *$2 = std::string("*") + *$2;
                                    } ASSIGNOP expression {
                                        if($5->value_type != _INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$5->value_type] + " expected BOOL");
                                    } TO expression {
                                        if($8->value_type != _INT_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$8->value_type] + " expected BOOL");
                                        print_tab();
                                        printf("for(%s = %s; %s <= %s; %s ++)\n", $2->c_str(), $5->value.c_str(), $2->c_str(), $8->value.c_str(), $2->c_str());
                                        tab_count ++;
                                        error_54();
                                        yyerrok;
                                    } statement {
                                        $$ = $10;
                                        tab_count --;
                                    }
                                    | READ '(' variable_list ')' {
                                        int flag=0;
                                        for (auto i = $3; i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ ||\
                                                i->x->value_type==_REAL_ ||\
                                                i->x->value_type==_CHAR_
                                                )
                                                continue;
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "ERROR: Can't read or write variables of this type");
                                        else{
                                            std::string s1, s2;
                                            for (auto i = $3; i; i = i->next) {
                                                s1 += strTypeName[i->x->value_type];
                                                s2 = s2 + "&" + i->x->value;
                                                if (i->next)
                                                    s2 += ", ";
                                            }
                                            $$ = new std::string("scanf(\"");
                                            *$$ += s1 + "\", " + s2 + ")";
                                            print_tab();
                                            printf("%s;\n", $$->c_str());
                                        }
                                    }
                                    | READ  {error_9(); yyerrok;} variable_list ')' {
                                        int flag=0;
                                        for (auto i = $3; i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ ||\
                                                i->x->value_type==_REAL_ ||\
                                                i->x->value_type==_CHAR_
                                                )
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "E: Can't read or write variables of this type");
                                        std::string s1, s2;
                                        for (auto i = $3; i; i = i->next) {
                                            s1 += strTypeName[i->x->value_type];
                                            s2 = s2 + "&" + i->x->value;
                                            if (i->next)
                                                s2 += ", ";
                                        }
                                        $$ = new std::string("scanf(\"");
                                        *$$ += s1 + "\", " + s2 + ")";
                                        print_tab();
                                        printf("%s;\n", $$->c_str());
                                    }
                                    | READ '(' variable_list error {
                                        error_4(); yyerrok;
                                        int flag=0;
                                        for (auto i = $3; i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ ||\
                                                i->x->value_type==_REAL_ ||\
                                                i->x->value_type==_CHAR_
                                                )
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "E: Can't read or write variables of this type");
                                        std::string s1, s2;
                                        for (auto i = $3; i; i = i->next) {
                                            s1 += strTypeName[i->x->value_type];
                                            s2 = s2 + "&" + i->x->value;
                                            if (i->next)
                                                s2 += ", ";
                                        }
                                        $$ = new std::string("scanf(\"");
                                        *$$ += s1 + "\", " + s2 + ")";
                                        print_tab();
                                        printf("%s;\n", $$->c_str());
                                    }
                                    | WRITE '(' expression_list ')' {
                                        int flag=0;
                                        for (auto i = $3; i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ || i->x->value_type==_CONSTINT_ ||\
                                                i->x->value_type==_REAL_ || i->x->value_type==_CONSTREAL_ ||\
                                                i->x->value_type==_CHAR_ || i->x->value_type==_CONSTCHAR_ ||\
                                                i->x->value_type==_BOOL_ || i->x->value_type==_CONSTBOOL_
                                                )
                                                continue;
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "ERROR: Can't read or write variables of this type");
                                        else{
                                            std::string s1, s2;
                                            for (auto i = $3; i; i = i->next) {
                                                s1 += strTypeName[i->x->value_type];
                                                s2 += i->x->value;
                                                if (i->next)
                                                    s2 += ", ";
                                            }
                                            $$ = new std::string("printf(\"");
                                            *$$ += s1 + "\", " + s2 + ")";
                                            print_tab();
                                            printf("%s;\n", $$->c_str());
                                        }
                                    } 
                                    | WRITE {error_9(); yyerrok;} expression_list ')' {
                                        int flag=0;
                                        for (auto i = $3; i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ || i->x->value_type==_CONSTINT_ ||\
                                                i->x->value_type==_REAL_ || i->x->value_type==_CONSTREAL_ ||\
                                                i->x->value_type==_CHAR_ || i->x->value_type==_CONSTCHAR_ ||\
                                                i->x->value_type==_BOOL_ || i->x->value_type==_CONSTBOOL_
                                                )
                                                continue;
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "ERROR: Can't read or write variables of this type");
                                        std::string s1, s2;
                                        for (auto i = $3; i; i = i->next) {
                                            s1 += strTypeName[i->x->value_type];
                                            s2 += i->x->value;
                                            if (i->next)
                                                s2 += ", ";
                                        }
                                        $$ = new std::string("printf(\"");
                                        *$$ += s1 + "\", " + s2 + ")";
                                        print_tab();
                                        printf("%s;\n", $$->c_str());
                                    }
                                    | WRITE '(' expression_list {
                                        error_4(); yyerrok;
                                        int flag=0;
                                        for (auto i = $3; i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ || i->x->value_type==_CONSTINT_ ||\
                                                i->x->value_type==_REAL_ || i->x->value_type==_CONSTREAL_ ||\
                                                i->x->value_type==_CHAR_ || i->x->value_type==_CONSTCHAR_ ||\
                                                i->x->value_type==_BOOL_ || i->x->value_type==_CONSTBOOL_
                                                )
                                                continue;
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "ERROR: Can't read or write variables of this type");
                                        std::string s1, s2;
                                        for (auto i = $3; i; i = i->next) {
                                            s1 += strTypeName[i->x->value_type];
                                            s2 += i->x->value;
                                            if (i->next)
                                                s2 += ", ";
                                        }
                                        $$ = new std::string("printf(\"");
                                        *$$ += s1 + "\", " + s2 + ")";
                                        print_tab();
                                        printf("%s;\n", $$->c_str());
                                    } 
                                    | FOR error {error_37(); yyerrok;} ASSIGNOP expression TO expression DO statement
                                    | WRITELN '(' expression_list ')' {
                                        int flag=0;
                                        for (auto i = $3; i; i = i->next){
                                            if(symbol_table.get_token_type(i->x->value)==_ARRAY_)
                                                flag=1;
                                            if( i->x->value_type==_INT_ || i->x->value_type==_CONSTINT_ ||\
                                                i->x->value_type==_REAL_ || i->x->value_type==_CONSTREAL_ ||\
                                                i->x->value_type==_CHAR_ || i->x->value_type==_CONSTCHAR_ ||\
                                                i->x->value_type==_BOOL_ || i->x->value_type==_CONSTBOOL_
                                                )
                                                continue;
                                            flag=1;
                                        }
                                        if(flag==1)
                                            yyerror(std::string() + "ERROR: Can't read or write variables of this type");
                                        else{
                                            std::string s1, s2;
                                            for (auto i = $3; i; i = i->next) {
                                                s1 += strTypeName[i->x->value_type];
                                                s2 += i->x->value;
                                                if (i->next)
                                                    s2 += ", ";
                                            }
                                            $$ = new std::string("printf(\"");
                                            *$$ += s1 + "\\n\", " + s2 + ")";
                                            print_tab();
                                            printf("%s;\n", $$->c_str());
                                        }
                                    } 
                                    | {$$ = new std::string; print_tab(); printf("%s;\n", $$->c_str());}
                                    ;
procedure_call                      : ID {
                                        if(symbol_table.get_type(*$1)==_ERROR_)
                                            yyerror(std::string() + "ERROR: The designated identifier has not been declared "+ *$1);
                                        else if(symbol_table.get_func_size(*$1)==-1)
                                            yyerror(std::string() + "ERROR: Illegal expression");
                                        else if(symbol_table.get_func_size(*$1)!=0)
                                            yyerror(std::string() + "ERROR: Wrong number of parameters specified for call to " + *$1);
                                        $$ = new Const(*$1 + "()", _VOID_);
                                    }
                                    /* | error {error_2(); yyerrok;} */
                                    ;
function_call                       : ID '(' expression_list ')' {
                                        auto id_type = symbol_table.get_type(*$1);
                                        if(id_type==_ERROR_)
                                            yyerror(std::string() + "ERROR: Identifier not found "+ *$1);
                                        else if(symbol_table.get_func_size(*$1)==-1)
                                            yyerror(std::string() + "ERROR: Illegal expression");
                                        else if(($3==nullptr&&symbol_table.get_func_size(*$1)!=0) || ($3&&symbol_table.get_func_size(*$1)!=$3->size))
                                            yyerror(std::string() + "ERROR: Wrong number of parameters specified for call to " + *$1);
                                        else{
                                            int cnt = 0;
                                            for(auto i = $3; i; i = i->next){
                                                auto type1 = i->x->value_type;
                                                auto type2 = symbol_table.get_func_type(*$1, cnt);
                                                if(symbol_table.get_func_ref(*$1, cnt)==1 && i->x->ref==false)
                                                	yyerror(std::string() + "ERROR: Variable identifier expected");
                                                ++cnt;
                                                if( type1==_INT_&&type2==_INT_ || type1==_CONSTINT_&&type2==_INT_ ||\
                                                    type1==_REAL_&&type2==_REAL_ || type1==_CONSTREAL_&&type2==_REAL_ ||\
                                                    type1==_CHAR_&&type2==_CHAR_ || type1==_CONSTCHAR_&&type2==_CHAR_ ||\
                                                    type1==_BOOL_&&type2==_BOOL_ || type1==_CONSTBOOL_&&type2==_BOOL_ ||\
                                                    type1==_INT_&&type2==_REAL_ && symbol_table.get_func_ref(*$1, cnt)==0||\
                                                    type1==_CONSTINT_&&type2==_REAL_ && symbol_table.get_func_ref(*$1, cnt)==0)
                                                    continue;
                                                yyerror(std::string() + "ERROR: Incompatible type for arg no. " + std::to_string(cnt) +\
                                                    ": Got " + valueTypeName[type1] + " , expected "+valueTypeName[type2]);
                                            }
                                        }
                                        std::string* temp = new std::string(*$1);
                                        *temp = *temp + "(";
                                        auto i = $3;
                                        int cnt = 0;
                                        while (i && i->next) {
                                            // printf("\n----------\n%s %d %d\n----------\n", $1->c_str(), cnt, symbol_table.get_func_ref(*$1, cnt));
                                            if (symbol_table.get_func_ref(*$1, cnt))
                                                *temp = *temp + "&" + i->x->value + ", ";
                                            else
                                                *temp = *temp + i->x->value + ", ";
                                            cnt ++;
                                            i = i->next;
                                        }
                                        if (i) {
                                            if (symbol_table.get_func_ref(*$1, cnt))
                                                *temp = *temp + "&" + i->x->value + ")";
                                            else
                                                *temp = *temp + i->x->value + ")";
                                        } else {
                                            *temp = *temp + ")";
                                        }
                                        $$ = new Const(*temp, symbol_table.get_type(*$1));
                                    }
                                    /* | ID '(' expression_list {
                                        error_4(); yyerrok;
                                        auto id_type = symbol_table.get_type(*$1);
                                        if(id_type==_ERROR_)
                                            yyerror(std::string() + "ERROR: Identifier not found "+ *$1);
                                        else if(symbol_table.get_func_size(*$1)==-1)
                                            yyerror(std::string() + "ERROR: Illegal expression");
                                        else if(symbol_table.get_func_size(*$1)!=$3->size)
                                            yyerror(std::string() + "ERROR: Wrong number of parameters specified for call to " + *$1);
                                        else{
                                            int cnt = 0;
                                            for(auto i = $3; i; i = i->next){
                                                auto type1 = i->x->value_type;
                                                auto type2 = symbol_table.get_func_type(*$1, cnt);
                                                if(symbol_table.get_func_ref(*$1, cnt)==1 && i->x->ref==false)
                                                	yyerror(std::string() + "ERROR: Variable identifier expected");
                                                ++cnt;
                                                if( type1==_INT_&&type2==_INT_ || type1==_CONSTINT_&&type2==_INT_ ||\
                                                    type1==_REAL_&&type2==_REAL_ || type1==_CONSTREAL_&&type2==_REAL_ ||\
                                                    type1==_CHAR_&&type2==_CHAR_ || type1==_CONSTCHAR_&&type2==_CHAR_ ||\
                                                    type1==_BOOL_&&type2==_BOOL_ || type1==_BOOL_&&type2==_BOOL_ ||\
                                                    type1==_INT_&&type2==_REAL_ && symbol_table.get_func_ref(*$1, cnt)==0||\
                                                    type1==_CONSTINT_&&type2==_REAL_ && symbol_table.get_func_ref(*$1, cnt)==0)
                                                    continue;
                                                yyerror(std::string() + "ERROR: Incompatible type for arg no. " + std::to_string(cnt) +\
                                                    ": Got " + valueTypeName[type1] + " , expected "+valueTypeName[type2]);
                                            }
                                        }
                                        std::string* temp = new std::string(*$1);
                                        *temp = *temp + "(";
                                        auto i = $3;
                                        int cnt = 0;
                                        while (i && i->next) {
                                            // printf("\n----------\n%s %d %d\n----------\n", $1->c_str(), cnt, symbol_table.get_func_ref(*$1, cnt));
                                            if (symbol_table.get_func_ref(*$1, cnt))
                                                *temp = *temp + "&" + i->x->value + ", ";
                                            else
                                                *temp = *temp + i->x->value + ", ";
                                            cnt ++;
                                            i = i->next;
                                        }
                                        if (symbol_table.get_func_ref(*$1, cnt))
                                            *temp = *temp + "&" + i->x->value + ")";
                                        else
                                            *temp = *temp + i->x->value + ")"; 
                                        $$ = new Const(*temp, symbol_table.get_type(*$1));
                                    }  */
                                    /* | error {error_2();yyerrok;} '(' expression_list ')'
                                    | error {error_2();yyerrok;} error {error_9();yyerrok;} expression_list ')'
                                    | error {error_2();yyerrok;} '(' expression_list error {error_4();yyerrok;}
                                    | error {error_2();yyerrok;} error {error_9();yyerrok;} expression_list error {error_4();yyerrok;} */
                                    ;
variable_list          			    : variable {
                                        $$ = new ExpList($1);
                                    }
                                    | variable_list ',' variable {
                                        $$ = $1;
                                        list_append($$, $3);
                                    } 
                                    ;
variable                            : ID id_varpart {
                                        if (*$1 == symbol_table.get_location())
                                            *$1 = std::string("_") + *$1;
                                        if (symbol_table.get_type(*$1)==_ERROR_)
                                            yyerror(std::string() + "ERROR: The designated identifier has not been declared.("+ *$1 + ")");
                                        else if(symbol_table.get_token_type(*$1)==_FUNC_) // 需要判断是否为函数
                                            yyerror(std::string() + "ERROR: The designated identifier has not been declared.("+ *$1 + ")");
                                        if ($2 == nullptr) {
                                            $$ = new Const(*$1, symbol_table.get_type(*$1));
                                            if (symbol_table.get_reference(*$1))
                                                $$->value = std::string("*") + *$1;
                                        } else {
                                            std::string str = *$1;
                                            int len = symbol_table.get_array_size(*$1);
                                            if(symbol_table.get_array_size(*$1)!=$2->size)
                                                yyerror(std::string() + "ERROR: Illegal qualifier");
                                            // 类型检查，ID 是不是数组
                                            auto h = $2;
                                            auto j = $2;
                                            for (int i = 0; i < len; i++) { 
                                                if(j->x->value_type!=_INT_)
                                                    yyerror(std::string() + "ERROR: Illegal qualifier");
                                                j=j->next;
                                                std::string l = symbol_table.get_array_l(*$1, i);
                                                if (l[0] == '-') {
                                                    l[0] = '+';
                                                    str = str + "[" + h->x->value + l + "]";
                                                } else {
                                                    str = str + "[" + h->x->value + "-" + l + "]";
                                                }
                                                h=h->next;
                                            }
                                            $$ = new Const(str, symbol_table.get_type(*$1));
                                        }
                                    }
                                    /* | error {error_37();yyerrok;} id_varpart */
                                    ;
id_varpart                    	    : { $$ = nullptr; }
                                    | '[' expression_list ']' { $$ = $2; }
                                    /* | '[' expression_list error { error_12(); yyerrok;$$ = $2; }
                                    | error expression_list ']' {
                                        $$ = $2;
                                        error_11();
                                        yyerrok;
                                    }
                                    | expression_list ']' {
                                        $$ = $1;
                                        error_11();
                                        yyerrok;
                                    } */
                                    /* | error expression_list error {
                                        error_12();
                                        $$ = $2;
                                        error_11();
                                        yyerrok;
                                    } */
                                    ;
else_part              			    :
                                    | ELSE { print_tab(); printf("else\n"); tab_count ++;} statement {tab_count --;}
                                    ;
expression_list             	    : expression {
                                        if($1==nullptr)
                                            $$=nullptr;
                                        else
                                            $$ = new ExpList($1);
                                    }
                                    | expression_list ',' expression {
                                        if ($1==nullptr)
                                            $$ = new ExpList($3);
                                        else {
                                            $$ = $1;
                                            list_append($$, $3);
                                        }
                                    }
                                    ;
expression                          : simple_expression {
                                        $$ = $1;
                                        if($1->value_type==_INT_||$1->value_type==_CONSTINT_)
                                            $$->value_type=_INT_;
                                        else if($1->value_type==_REAL_||$1->value_type==_CONSTREAL_)
                                            $$->value_type=_REAL_;
                                        else if($1->value_type==_CHAR_||$1->value_type==_CONSTCHAR_)
                                            $$->value_type=_CHAR_;
                                        else if($1->value_type==_BOOL_||$1->value_type==_CONSTBOOL_)
                                            $$->value_type=_BOOL_;
                                        //else
                                        //    yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$1->value_type] + " expected INT or REAL or CHAR or BOOL");
									}
                                    | simple_expression RELOP simple_expression {
                                        $$ = $1; 
                                        if (($1->value_type==_BOOL_||$1->value_type==_CONSTBOOL_) && ($3->value_type==_BOOL_||$3->value_type==_CONSTBOOL_))
                                            $$->value_type==_BOOL_;
                                        else if(($1->value_type==_INT_||$1->value_type==_CONSTINT_) && ($3->value_type==_INT_||$3->value_type==_CONSTINT_))
                                            $$->value_type=_BOOL_;
                                        else if(($1->value_type==_INT_||$1->value_type==_CONSTINT_) && ($3->value_type==_REAL_||$3->value_type==_CONSTREAL_))
                                            $$->value_type=_BOOL_;
                                        else if(($1->value_type==_REAL_||$1->value_type==_CONSTREAL_) && ($3->value_type==_INT_||$3->value_type==_CONSTINT_))
                                            $$->value_type=_BOOL_;
                                        else if(($1->value_type==_REAL_||$1->value_type==_CONSTREAL_) && ($3->value_type==_REAL_||$3->value_type==_CONSTREAL_))
                                            $$->value_type=_BOOL_;
                                        else if(($1->value_type==_CHAR_||$1->value_type==_CONSTCHAR_) && ($3->value_type==_CHAR_||$3->value_type==_CONSTCHAR_))
                                            $$->value_type=_BOOL_;
                                        else if(($1->value_type==_BOOL_||$1->value_type==_CONSTBOOL_) && ($3->value_type==_BOOL_||$3->value_type==_CONSTBOOL_))
                                            $$->value_type=_BOOL_;
                                        else if($1->value_type!=_INT_ && $1->value_type!=_REAL_ && $1->value_type!=_CONSTINT_ && $1->value_type!=_CONSTREAL_ && $1->value_type!=_CHAR_ && $1->value_type!=_CONSTCHAR_) 
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$1->value_type] + " expected INT or REAL or CHAR or BOOL");
                                        else
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$3->value_type] + " expected " + valueTypeName[$1->value_type]);
                                        $$->value = $$->value + *$2 + $3->value;
                                        $$->ref=false;
                                    }
                                    | simple_expression EQUAL simple_expression {
                                        $$ = $1; 
                                        if (($1->value_type==_BOOL_||$1->value_type==_CONSTBOOL_) && ($3->value_type==_BOOL_||$3->value_type==_CONSTBOOL_))
                                            $$->value_type==_BOOL_;
                                        else if(($1->value_type==_INT_||$1->value_type==_CONSTINT_) && ($3->value_type==_INT_||$3->value_type==_CONSTINT_))
                                            $$->value_type=_BOOL_;
                                        else if(($1->value_type==_INT_||$1->value_type==_CONSTINT_) && ($3->value_type==_REAL_||$3->value_type==_CONSTREAL_))
                                            $$->value_type=_BOOL_;
                                        else if(($1->value_type==_REAL_||$1->value_type==_CONSTREAL_) && ($3->value_type==_INT_||$3->value_type==_CONSTINT_))
                                            $$->value_type=_BOOL_;
                                        else if(($1->value_type==_REAL_||$1->value_type==_CONSTREAL_) && ($3->value_type==_REAL_||$3->value_type==_CONSTREAL_))
                                            $$->value_type=_BOOL_;
                                        else if(($1->value_type==_CHAR_||$1->value_type==_CONSTCHAR_) && ($3->value_type==_CHAR_||$3->value_type==_CONSTCHAR_))
                                            $$->value_type=_BOOL_;
                                        else if(($1->value_type==_BOOL_||$1->value_type==_CONSTBOOL_) && ($3->value_type==_BOOL_||$3->value_type==_CONSTBOOL_))
                                            $$->value_type=_BOOL_;
                                        else if($1->value_type!=_INT_ && $1->value_type!=_REAL_ && $1->value_type!=_CONSTINT_ && $1->value_type!=_CONSTREAL_ && $1->value_type!=_CHAR_ && $1->value_type!=_CONSTCHAR_) 
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$1->value_type] + " expected INT or REAL or CHAR or BOOL");
                                        else
                                            yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$3->value_type] + " expected " + valueTypeName[$1->value_type]);
                                        $$->value = $$->value + "==" + $3->value;
                                        $$->ref=false;
                                    }
                                    | {$$=nullptr;}
                                    ;
simple_expression                   : term {
                                        $$ = $1;
                                        if($1->value_type==_INT_||$1->value_type==_CONSTINT_)
                                            $$->value_type=_INT_;
                                        else if($1->value_type==_REAL_||$1->value_type==_CONSTREAL_)
                                            $$->value_type=_REAL_;
                                        else if($1->value_type==_CHAR_||$1->value_type==_CONSTCHAR_)
                                            $$->value_type=_CHAR_;
                                        else if($1->value_type==_BOOL_||$1->value_type==_CONSTBOOL_)
                                            $$->value_type=_BOOL_;
                                        //else
                                        //    yyerror(std::string() + "ERROR: Incompatible types : got " +\
                                        //        valueTypeName[$1->value_type] + " expected INT or REAL or CHAR or BOOL");
                                    }
                                    | ADDOP term {
                                        $$ = $2; 
                                        if($2->value_type==_INT_||$2->value_type==_CONSTINT_)
                                            $$->value_type=_INT_;
                                        else if($2->value_type==_REAL_||$2->value_type==_CONSTREAL_)
                                            $$->value_type=_REAL_;
                                        else
                                            yyerror(std::string() + "ERROR: Incompatible types : got " +\
                                                valueTypeName[$2->value_type] + " expected INT or REAL");
                                        $$->value = *$1 + $2->value;
                                        $$->ref=false;
                                    }
                                    | simple_expression ADDOP term {
                                        $$ = $1;
                                        auto typel = $1->value_type;
                                        auto typer = $3->value_type;
                                        if((typel == _INT_ || typel == _CONSTINT_) && (typer == _INT_ || typer == _CONSTINT_))
                                            $$->value_type = _INT_;
                                        else if((typel == _REAL_ || typel == _CONSTREAL_) && (typer == _REAL_ || typer == _CONSTREAL_))
                                            $$->value_type = _REAL_;
                                        else if((typel == _INT_ || typel == _CONSTINT_) && (typer == _REAL_ || typer == _CONSTREAL_))
                                            $$->value_type = _REAL_;
                                        else if((typel == _REAL_ || typel == _CONSTREAL_) && (typer == _INT_ || typer == _CONSTINT_))
                                            $$->value_type = _REAL_;
                                        else if(typel != _REAL_ && typel != _INT_ && typel != _CONSTINT_ && typel != _CONSTREAL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " +\
                                                valueTypeName[typel] + " expected _INT_ or REAL");
                                        else
                                            yyerror(std::string() + "ERROR: Incompatible types : got " +\
                                                valueTypeName[typer] + " expected _INT_ or REAL");
                                        $$->value = $$->value + *$2 + $3->value;
                                        $$->ref=false;
                                    }
                                    | simple_expression OROP term {
                                        $$ = $1;
                                        if(($1->value_type==_BOOL_||$1->value_type==_CONSTBOOL_) && ($3->value_type==_BOOL_||$3->value_type==_CONSTBOOL_))
                                            $$->value_type=_BOOL_;
                                        else if($1->value_type!=_BOOL_&&$1->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got " +\
                                                valueTypeName[$1->value_type] + " expected BOOLEAN");
                                        else
                                            yyerror(std::string() + "ERROR: Incompatible types : got " +\
                                                valueTypeName[$3->value_type] + " expected BOOLEAN");
                                        $$->value = $$->value + "|" + $3->value;
                                        $$->ref=false;
                                    }
                                    ;
term                                : factor {
                                        $$ = $1;
                                        if($1->value_type==_INT_||$1->value_type==_CONSTINT_)
											$$->value_type=_INT_;
										else if($1->value_type==_REAL_||$1->value_type==_CONSTREAL_)
											$$->value_type=_REAL_;
										else if($1->value_type==_CHAR_||$1->value_type==_CONSTCHAR_)
											$$->value_type=_CHAR_;
										else if($1->value_type==_BOOL_||$1->value_type==_CONSTBOOL_)
											$$->value_type=_BOOL_;
										//else
										//	yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$1->value_type] + " expected INT or REAL or CHAR or BOOL");
                                    	
									}
                                    | term MULOP factor {
                                        $$ = $1;
                                        if(*$2=="and"){
											if(($1->value_type==_BOOL_||$1->value_type==_CONSTBOOL_) && ($3->value_type==_BOOL_||$3->value_type==_CONSTBOOL_))
											    $$->value_type=_BOOL_;
										    else if($1->value_type!=_BOOL_&&$1->value_type!=_CONSTBOOL_)
											    yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$1->value_type] + " expected BOOL");
											else
												yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$3->value_type] + " expected BOOL");
										}
										else if(*$2=="div" || *$2=="mod"){
											if(($1->value_type==_INT_||$1->value_type==_CONSTINT_) && ($3->value_type==_INT_||$3->value_type==_CONSTINT_))
												$$->value_type=_INT_;
											else if($1->value_type!=_INT_ && $1->value_type!=_CONSTINT_)
												yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$1->value_type] + " expected INT");
											else
												yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$3->value_type] + " expected INT");
										}
										else{
                                            if(($1->value_type==_INT_||$1->value_type==_CONSTINT_) && ($3->value_type==_INT_||$3->value_type==_CONSTINT_))
                                                $$->value_type=_INT_;
                                            else if(($1->value_type==_REAL_||$1->value_type==_CONSTREAL_) && ($3->value_type==_INT_||$3->value_type==_CONSTINT_))
                                                $$->value_type=_REAL_;
                                            else if(($1->value_type==_INT_||$1->value_type==_CONSTINT_) && ($3->value_type==_REAL_||$3->value_type==_CONSTREAL_))
                                                $$->value_type=_REAL_;
                                            else if(($1->value_type==_REAL_||$1->value_type==_CONSTREAL_) && ($3->value_type==_REAL_||$3->value_type==_CONSTREAL_))
                                                $$->value_type=_REAL_;
                                            else if($1->value_type!=_INT_ && $1->value_type!=_REAL_ && $1->value_type!=_CONSTINT_ && $1->value_type!=_CONSTREAL_) 
                                                yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$1->value_type] + " expected INT or REAL");
                                            else
                                                yyerror(std::string() + "ERROR: Incompatible types : got " + valueTypeName[$3->value_type] + " expected INT or REAL");
                                        }
                                        std::string op = "*";
                                        if (*$2 == "and")
                                            op = " & ";
                                        else if (*$2 == "div")
                                            op = " / ";
                                        else if (*$2 == "mod")
                                            op = " % ";
                                        else
                                            op = "*";
                                        $$->value = $$->value + op + $3->value;
                                        $$->ref=false;
                                    }
                                    ;
factor                              : NUM {
                                        symbol_table.insert(new TokenNUM(_NUM_, $1->value, $1->value_type));
                                        $$ = $1;
                                        $$->ref=false;
                                    }
                                    | CONSTCHAR {
                                        $$ = new Const(*$1, _CONSTCHAR_);
                                        symbol_table.insert(new TokenNUM(_NUM_, $$->value, $$->value_type));
                                        $$->ref=false;
                                    }
                                    | function_call {
                                        $$ = $1;
                                        $$->ref=false;
                                    }
                                    | variable {
                                        $$ = $1;
                                        $$->ref=true;
                                        if(symbol_table.get_token_type($1->value)==_ARRAY_)
                                            yyerror(std::string() + "ERROR: Incompatible types(Array)");
                                    }
                                    | NOT factor {
                                        if($2->value_type!=_BOOL_ && $2->value_type!=_CONSTBOOL_)
                                            yyerror(std::string() + "ERROR: Incompatible types : got "
                                                + valueTypeName[$2->value_type] + " expected BOOL");
                                        $$ = $2;
                                        $$->value = "!" + $$->value;
                                        $$->ref=false;
                                    }
                                    | '(' expression ')' {
                                        $$ = $2;
                                        $$->value = "(" + $$->value + ")";
                                    }
                                    | '(' expression  {
                                        error_4();
                                        yyerrok;
                                        $$ = $2;
                                        $$->value = "(" + $$->value + ")";
                                    }
                                    /* | error {
                                        error_9(); yyerrok;
                                    }';' */
                                    ;

%%

void make_ref_seq(std::vector<int> &seq, List* head) {
    seq.clear();
    while(head != nullptr)
    {
        assert(head->x->get_token_type() == _IDENTIFIER_);
        TokenID *t = (TokenID*) head->x;
        seq.push_back(t->get_reference());
        head = head->next;
    }
}

void make_type_seq(std::vector<ValueType> &seq, List* head) {
    seq.clear();
    while(head != nullptr)
    {
        seq.push_back(symbol_table.get_type(head->x->get_value()));
        head = head->next;
    }
}

/* void get_ref_seq(std::vector<int> &seq, text func) {
    seq.clear();
    int siz = symbol_table.get_func_size(*func);
    for (int i = 0; i < siz; i ++) {
        seq.push_back(symbol_table.get_func_ref(*func, i));
    }
} */

void list_symbol_insert(List *head, TokenNUM* type) {
    for (auto i = head; i; i = i->next) {
        /* fprintf(stderr,"id:%s\n",i->x->get_value().c_str()); */
        if (type->get_token_type() == _ARRAY_) {
            TokenARRAY* tmp = new TokenARRAY(*(TokenARRAY*)type);
            tmp->set_value(i->x->get_value());
            if(symbol_table.insert(tmp)==0){
                yyerror(std::string() + "ERROR: Duplicate identifier");
			}
        } else
            if(symbol_table.insert(new TokenID(i->x->get_value(), type->get_value_type(), false))==0){
                yyerror(std::string() + "ERROR: Duplicate identifier");
			}
        i->x->set_value_type(type->get_value_type());
        /* fprintf(stderr,"id:%s\n",i->x->get_value().c_str()); */
    }
}

void print_tab() {
    for (int i = 0; i < tab_count; i ++)
        printf("\t");
}

int yyerror(const char *msg) {
    error_0(msg);
    return 0;
}

int yyerror(std::string x) {
    x+='\n';
    return yyerror(x.c_str());
}

int main(int argc, char **argv) {
#ifndef Debug
    for (int i = 1; i < argc; i += 2) {
        if (strcmp(argv[i], "-o")==0)
            freopen(argv[i + 1], "w", stdout);
        else if (strcmp(argv[i], "-f")==0)
            freopen(argv[i + 1], "r", stdin);
        else if (strcmp(argv[i], "-d")==0)
            freopen(argv[i + 1], "w", stderr);
    }
#endif
    yyparse();
    fprintf(stderr, "\nfinished.");
    return 0;
}
