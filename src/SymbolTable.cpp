#include <assert.h>
#include "SymbolType.h"
#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
    index_table.push_back(scope_count=1);
    index_name.push_back(std::string());
    index_count.push_back(0);
}

TokenNUM* SymbolTable::query(HashKey hs)
{
    std::map<HashKey, int>::iterator itr = hash_table.find(hs);
    if(itr == hash_table.end())
        return nullptr;
    return symbol_table[itr->second];
}

void SymbolTable::pop_back()
{
    int topScope = *index_table.rbegin();
    TokenNUM* sym = symbol_table.back();
    HashKey q(topScope, sym->get_value().c_str());
    hash_table.erase(q);
    symbol_table.pop_back();
}

int SymbolTable::insert(TokenNUM* sym)
{
    int topScope = *index_table.rbegin();
    std::string value = sym->get_value();
    HashKey q(topScope, value);
    if(query(q))
        return 0;
    hash_table[q] = symbol_table.size();
    TokenNUM *ptr;
    switch(sym->get_token_type())
    {
        case _IDENTIFIER_:
            ptr = new TokenID(*((TokenID*)sym));
            break;
        case _NUM_:
            ptr = new TokenNUM(*((TokenNUM*)sym));
            break;
        case _FUNC_:
            ptr = new TokenFUNC(*((TokenFUNC*)sym));
            break;
        case _ARRAY_:
            ptr = new TokenARRAY(*((TokenARRAY*)sym));
            break;
        default:
            assert(0);
            break;
    }
    symbol_table.push_back(ptr);
    return 1;
}

void SymbolTable::reset_token(std::string value, TokenNUM* sym)
{
    // only for resetting TokenNUM, which is must be called in the same location
    HashKey hs(index_table[(int)index_name.size()-2], value);
    std::map<HashKey, int>::iterator itr = hash_table.find(hs);
    if(itr == hash_table.end())
        return;
    delete symbol_table[itr->second];
    symbol_table[itr->second] = new TokenFUNC(*((TokenFUNC*)sym));
}

void SymbolTable::delete_token(std::string value)
{
    HashKey hs(index_table[(int)index_name.size()-2], value);
    hash_table.erase(hs);
}

ValueType SymbolTable::get_type(std::string value)
{
    for(int top = index_name.size(); top; top--)
    {
        HashKey hs(index_table[top-1], value);
        TokenNUM* res = query(hs);
        if(!res)
            continue;
        if(res->get_value_type() != _ERROR_)
            return res->get_value_type();
    }
    //fprintf(stdout, "ERROR: The designated identifier has not been declared.\n");
    return _ERROR_;
}

TokenType SymbolTable::get_token_type(std::string value)
{
    for(int top = index_name.size(); top; top--)
    {
        HashKey hs(index_table[top-1], value);
        TokenNUM* res = query(hs);
        if(!res)
            continue;
        if(res->get_token_type() != _NOTFOUND_)
            return res->get_token_type();
    }
    return _NOTFOUND_;
}

bool SymbolTable::get_reference(std::string value)
{
    for(int top = index_name.size(); top; top--)
    {
        HashKey hs(index_table[top-1], value);
        TokenNUM* res = query(hs);
        if(!res)
            continue;
        if(res->get_token_type() == _IDENTIFIER_)
            return ((TokenID*)res)->get_reference();
    }
    return false;
}

void SymbolTable::set_reference(std::string value)
{
    for(int top = index_name.size(); top; top--)
    {
        HashKey hs(index_table[top-1], value);
        TokenNUM* res = query(hs);
        if(!res)
            continue;
        if(res->get_token_type() == _IDENTIFIER_)
            ((TokenID*)res)->set_reference(1);
    }
}


int SymbolTable::get_array_size(std::string value)
{
    for(int top = index_name.size(); top; top--)
    {
        HashKey hs(index_table[top-1], value);
        TokenNUM* res = query(hs);
        if(!res)
            continue;
        if(res->get_token_type() != _ARRAY_)
            return -1;
        return ((TokenARRAY*)res)->get_list_size();
    }
    return -1;
}

std::string SymbolTable::get_array_l(std::string value, int index)
{
    for(int top = index_name.size(); top; top--)
    {
        HashKey hs(index_table[top-1], value);
        TokenNUM* res = query(hs);
        if(!res)
            continue;
        // if(res->get_token_type() != ARRAY)
        //     return -1;
        return ((TokenARRAY*)res)->get_l_list(index);
    }
    // assert(0);
}

std::string SymbolTable::get_array_r(std::string value, int index)
{
    for(int top = index_name.size(); top; top--)
    {
        HashKey hs(index_table[top-1], value);
        TokenNUM* res = query(hs);
        if(!res)
            continue;
        // if(res->get_token_type() != ARRAY)
        //     return -1;
        return ((TokenARRAY*)res)->get_r_list(index);
    }
    // assert(0);
}

int SymbolTable::get_func_size(std::string value)
{
    for(int top = index_name.size(); top; top--)
    {
        HashKey hs(index_table[top-1], value);
        TokenNUM* res = query(hs);
        if(!res)
            continue;
        if(res->get_token_type() != _FUNC_)
            return -1;
        return ((TokenFUNC*)res)->get_para_size();
    }
    return -1;
}

int SymbolTable::get_func_ref(std::string value, int index)
{
    for(int top = index_name.size(); top; top--)
    {
        HashKey hs(index_table[top-1], value);
        TokenNUM* res = query(hs);
        if(!res)
            continue;
        // if(res->get_token_type() != FUNC)
        //     return -1;
        return ((TokenFUNC*)res)->get_para_referenced(index);
    }
    // assert(0);
}

ValueType SymbolTable::get_func_type(std::string value, int index)
{
    for(int top = index_name.size(); top; top--)
    {
        HashKey hs(index_table[top-1], value);
        TokenNUM* res = query(hs);
        if(!res)
            continue;
        // if(res->get_token_type() != FUNC)
        //     return -1;
        return ((TokenFUNC*)res)->get_para_value_type(index);
    }
    // assert(0);
}

void SymbolTable::locate(const std::string domain_name)
{
    index_table.push_back(++scope_count);
    index_name.push_back(domain_name);
    index_count.push_back(symbol_table.size());
}

std::string SymbolTable::get_location()
{
    return *index_name.rbegin();
}

void SymbolTable::relocate()
{
    if((int)index_count.size()<=1)
        return ;
    for(int i=symbol_table.size(), ntop=*index_count.rbegin();i>ntop;i--)
        pop_back();
    index_table.pop_back();
    index_name.pop_back();
    index_count.pop_back();
}

void SymbolTable::print()
{
    puts("---------Symbol Table---------");
    for(auto x: symbol_table)
    {
        printf("Token:%s \tValue:%s \tType:%s\n", tokenTypeName[x->get_token_type()].c_str(),
                x->get_value().c_str(), codeTypeName[x->get_value_type()].c_str());
    }
    puts("---------Hash Table-----------");
    for(auto x: hash_table)
    {
        printf("First: (%d, %s) Second: %d\n", x.first.scope, x.first.value.c_str(), x.second);
    }
    puts("------------------------------");
}
