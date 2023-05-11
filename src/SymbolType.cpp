#include "SymbolType.h"
#include <string>
Const::Const(std::string _value, ValueType _value_type,bool _ref)
{
    value = _value;
    value_type = _value_type;
    ref=_ref;
}
Const::Const(std::string _value, ValueType _value_type)
{
    value = _value;
    value_type = _value_type;
    ref=false;
}

Period::Period(std::string _lower, std::string _upper)
{
    lower = _lower;
    upper = _upper;
}

TokenNUM::TokenNUM()
{
    // do nothing
}

TokenNUM::TokenNUM(TokenType _token_type, std::string _value, ValueType _value_type)
{
    token_type = _token_type;
    value = _value;
    value_type = _value_type;
}

TokenType TokenNUM::get_token_type()
{
    return token_type;
}

std::string TokenNUM::get_value()
{
    return value;
}

ValueType TokenNUM::get_value_type()
{
    return value_type;
}

int TokenNUM::set_value(std::string _value)
{
    value = _value;
    return 1;
}

int TokenNUM::set_value_type(ValueType _value_type)
{
    value_type = _value_type;
    return 1;
}

TokenID::TokenID(std::string _value, ValueType _value_type, const bool _reference)
{
    token_type = _IDENTIFIER_;
    value = _value;
    value_type = _value_type;
    reference = _reference;
}

bool TokenID::get_reference()
{
    return reference;
}

int TokenID::set_reference(int _reference)
{
    reference = _reference;
    return 1;
}

TokenFUNC::TokenFUNC(std::string _value, ValueType _value_type, std::vector<int> _para_referenced, std::vector<ValueType> _para_value_type)
{
    token_type = _FUNC_;
    value = _value;
    value_type = _value_type;
    para_referenced = _para_referenced;
    para_value_type = _para_value_type;
}

// void TokenFUNC::para_value_push_back(std::string para)
// {
//     para_value.push_back(para);
// }

int TokenFUNC::get_para_size()
{
    return (int)para_referenced.size();
}

int TokenFUNC::get_para_referenced(int index)
{
    return para_referenced[index];
}

ValueType TokenFUNC::get_para_value_type(int index)
{
    return para_value_type[index];
}

TokenARRAY::TokenARRAY(std::string _value, ValueType _value_type, std::vector<std::string> _l_list, std::vector<std::string> _r_list)
{
    token_type = _ARRAY_;
    value = _value;
    value_type = _value_type;
    l_list = _l_list;
    r_list = _r_list;
}

// void TokenARRAY::l_list_push_back(std::string l)
// {
//     l_list.push_back(l);
// }

// void TokenARRAY::r_list_push_back(std::string r)
// {
//     r_list.push_back(r);
// }

int TokenARRAY::get_list_size()
{
    return (int)l_list.size();
}

std::string TokenARRAY::get_l_list(int index)
{
    return l_list[index];
}

std::string TokenARRAY::get_r_list(int index)
{
    return r_list[index];
}
