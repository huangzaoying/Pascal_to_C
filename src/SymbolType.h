#ifndef SYMBOLTYPE_H
#define SYMBOLTYPE_H

#include <vector>
#include <string>

enum TokenType{
    _IDENTIFIER_, _NUM_, _FUNC_, _ARRAY_, _NOTFOUND_
};

const std::string tokenTypeName[] = {
    "ID", "NUM", "FUNC", "ARR", "NOTFOUND"
};

enum ValueType{
    _INT_, _REAL_, _CHAR_, _BOOL_, _VOID_, _CONSTINT_, _CONSTREAL_, _CONSTCHAR_, _CONSTBOOL_, _NONE_, _ERROR_
};

const std::string valueTypeName[] = {
    "INT", "REAL", "CHAR", "BOOL", "VOID", "INT", "REAL", "CHAR", "BOOL", "NONE", "ERROR"
};

const std::string codeTypeName[] = {
    "int", "float", "char", "int", "void", "int", "float", "char", "BOOL", "NONE", "ERROR"
};

// const std::string strTypeName[] = {
//     "%d", "%f", "%c", "%d", "void", "%d", "%f", "%c", "NONE", "ERROR"
// };

const std::string strTypeName[] = {
    "%d", "%f", "%c", "%d", "%?", "%d", "%f", "%c", "%d", "%?", "%?"
};

struct Period{
    std::string lower, upper;
    Period(std::string _lower, std::string _upper);
};

struct Periods{
    std::vector<std::string> l_list, r_list;
};

struct Const{
    std::string value;
    ValueType value_type;
    bool ref;
    Const(std::string _value, ValueType _value_type,bool _ref);
    Const(std::string _value, ValueType _value_type);
};

class TokenNUM{
protected:
    TokenType token_type;
    std::string value;
    ValueType value_type;
public:
    TokenNUM();
    TokenNUM(TokenType _token_type, std::string _value, ValueType _value_type);
    TokenType get_token_type();
    std::string get_value();
    ValueType get_value_type();
    int set_value(std::string _value);
    int set_value_type(ValueType _value_type);
};

class TokenID: public TokenNUM{
private:
    /*
     * attribute 'refernce' is not used yet,
     * but reserved and initilized by 'false' 
     */
    bool reference;
public:
    TokenID(std::string _value, ValueType _value_type, const bool _reference = false);
    bool get_reference();
    int set_reference(int _reference);
};

class TokenFUNC: public TokenNUM {
private:
    std::vector<int> para_referenced;
    std::vector<ValueType> para_value_type;
public:
    TokenFUNC(std::string _value, ValueType _value_type, std::vector<int> _para_referenced, std::vector<ValueType> _para_value_type);
    // void para_value_push_back(std::string para);
    int get_para_size();
    int get_para_referenced(int index);
    ValueType get_para_value_type(int index);
};

class TokenARRAY: public TokenNUM {
private:
    std::vector<std::string> l_list, r_list;
public:
    TokenARRAY(std::string _value, ValueType _value_type, std::vector<std::string> _l_list, std::vector<std::string> _r_list);
    // void l_list_push_back(std::string l);
    // void r_list_push_back(std::string r);
    int get_list_size();
    std::string get_l_list(int index);
    std::string get_r_list(int index);
};


#endif