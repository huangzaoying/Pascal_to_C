#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <map>

#include "SymbolType.h"

struct HashKey{
    int scope;
    std::string value;
    HashKey(int _scope, std::string _value){
        scope = _scope;
        value = _value;
    }
    // bool operator == (HashKey& t) {
    //     return scope == t.scope && value == t.value;
    // }
    bool operator < (const HashKey& t)const{
        return scope == t.scope ? value < t.value : scope < t.scope;
    }
};

class SymbolTable{
private:
    int scope_count;
    std::map<HashKey, int> hash_table;
    std::vector<TokenNUM*> symbol_table;
    std::vector<int> index_table, index_count;
    std::vector<std::string> index_name;
    TokenNUM* query(HashKey hs);
    void pop_back();
public:
    SymbolTable();
    int insert(TokenNUM* sym);
    void reset_token(std::string value, TokenNUM* sym);
    void delete_token(std::string value);
    ValueType get_type(std::string value);
    TokenType get_token_type(std::string value);
    bool get_reference(std::string value);
    void set_reference(std::string value);
    int get_array_size(std::string value);
    std::string get_array_l(std::string value, int index);
    std::string get_array_r(std::string value, int index);
    int get_func_size(std::string value);
    int get_func_ref(std::string value, int index);
    ValueType get_func_type(std::string value, int index);
    void locate(const std::string domain_name = std::string(""));
    std::string get_location();
    void relocate();
    void print();
};

#endif
