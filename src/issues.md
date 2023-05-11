# 这里用来提出一些我们遇到的问题

## 0. 面向测试数据（这个部分是@Guanzhou 在维护）

1. input1
   + write字符常量不支持
   + true 和 false 关键字识别为 NUM fixed
   + boolean 变量改为了 int，但插入的时候却仍然是 boolean 而不是 int
   + boolean 变量不能赋值 （添加了 _CONSTBOOL_ 类型，但需要做类型检查）fixed
   + char 变量不能赋值
   + boolean 变量不能做运算生成 expression fixed
   + REAL 和 INT 之间应该可以互相比大小
2. input2：skipped，不支持records
3. input3
   + var_declaration 的错误处理有问题，会死循环
   + 不能支持 a['b' - 'a']，因为里面是一个 expression，但看了看pascal好像也不太支持，就算了吧
   + arr3 = arr2，感觉可能也没必要支持
   + @Yifei，目前是访问arr的语句直接不输出
4. input4: ok
   + write() 也不支持，但感觉不支持也行
   + case 我们不支持
   + 多行注释词法无法匹配 fixed
   + repeat until 这个条件语句，需要取反 fixed
5. input5
   + 如果定义 function testfunc: integer; 然后 a := testfunc; 翻译出来的没有括号
   + 正确的翻译应该是 a = testfunc()
   + 但这样我们有冲突，因为我们为了避免RR冲突，强制要求 function_call 必须带有括号
   + 但这个地方也没有报错。。怎么办？
   + yacc.y 1105行 需要判断 variable 是否为 FUNC 类型 @Yifei
   + 目前报错变成了 变量名未定义，我估摸着是copy的时候忘记改报错信息了
6. input6：他们还匹配了自带函数？skipped
7. input7：是在测试自定义类型，skipped
8. input8：是在测试字符串，skipped
   + 修改了一下测试样例，char 数组似乎被当做int来插了
9. input9：快排，ok

## 1. 词法分析部分（@Guanzhou fix一下）

1. LETTER 记号会和 IDENTIFIER 冲突
    + 把 'a' 整体识别为 CONSTCHAR 记号
2. write字符常量
3. 若char为空的情况下，这种情况下应该给出报错信息 fixed
4. 若char为多个字符的情况下，这种情况下应该给出报错信息 fixed
   
## 11. 语法分析部分（@Zaoyin fix一下）

1. var_declartion 有左递归，消了一下
2. procedure_call function_call 不能一起处理，procedure 没有返回值，不能作为 factor
3. begin end中必须有一个语句
4. program_head报错信息，如缺括号、分号、程序名以及程序头不全
5. 常量定义，还未处理：缺少结尾的分号、缺少常量值、缺少赋值号
6. 变量定义，还未处理：缺少分号、类型
7. 数组定义，还未处理：缺少左括号，右括号，以及of，还有类型错误的问题

## 2. 符号表部分

1. locate的时候需要注意顺序，先插入FUNC，再locate，再插入参数列表

## 3. 类型检查部分（@Yifei fix一下）
(5.8)
1. 在给数组赋值时出现问题: *ok*
	- arr1[3] := 7; 该操作理应正确，但是产生了ERROR: Incompatible types : gotINT expected INT *ok*
	- arr1[0] := 5; 越界问题没有正确处理 *neglect*
2. for循环的问题，没有检查开始值、结束值、控制变量的类型是否一致 *ok,只能是int*
3. 数组维度不匹配问题
	- src/test_type/3.array/test3.pas
4. 数组不带下标的错误检查
	- src/test_type/3.array/test2.pas
---
+ factor 里面的 ID() 可以没有参数，改为 procedure call
1. 左值不带下标引用数组和右值不带下标引用数组错误检查
2. 数组的引用时，维数不匹配，以及下标检查为整数，和越界的问题
3. 对于for的循环判断问题，希望输出更详细一点对于start和end的类型检查
6. 需要确认一下，类型检查是否已经完成了对变量未定义情况的识别和错误信息的输出？请确认错误信息输出的格式。
目前返回的错误信息有问题，Error:Incompatible types : got  ERROR  expected INT，但应该报错Error: Identifier not found (TODO)
7. 请确认是否处理了变量重复定义部分的错误处理
目前重复定义没处理，需要在insert时候判断返回值是否为0 (fixed)
8. 暂时不支持 write('a')，然后pascal本身不支持 write ('a' < 'b')，如果想要把 simple_expression 增加 LETTER 的产生式不知道会不会出问题（实际是支持的）
9. read 的参数类型只能是 char, int, real; write 只能是 char, int, real, boolen OK
10. Boolen 类型不能参与算术运算 OK
11. div 和 mod 的操作数只能是 int, not and or 的操作数只能是 Boolen OK
12. 例如 a[] 这种, a 必须是一个数组
13. 数组定义时需判断：（先不解决，negelected）
    - 下界不能超过上界
    - 数字范围不能超过 2^17
    - 这里建议写一个字符串比较
14. 数组名（没有索引）不能作为逻辑或算术操作数 OK
15. 需要检查 if 语句中的条件表达式，是否为 boolean 类型，如果否，需要按照 error_handle 中的格式输出错误信息 （TODO）
16. 需要检查 for 循环中，循环控制变量的类型，必须是 integer, char 或 boolean，如果否，请按照 error_handle 中的格式输出错误信息 18 (TODO)
17. 需要检查 for 循环中，循环控制变量的类型与循环上下界的类型是否匹配，若不匹配，请输出对应的错误信息 19 (TODO)


## 4. 错误处理部分（@Ziwei fix一下）

1. 129: ERROR 25 无法获取类型，我把翻译动作直接删掉了（是没有问题的，确实不需要额外的翻译动作）
2. 139: ERROR 25 无法获取类型，我把翻译动作直接删掉了
3. 148: ERROR 25 无法获取类型，我把翻译动作直接删掉了
4. 158: ERROR 25/16, 无法获取类型，我把翻译动作直接删掉了，把 error_16 的位置挪了一下
5. 186: ERROR 29, 无法获取类型，我把翻译动作直接删掉了
	- @Guanzhou：另外需要注意的是，我觉得error10应该是针对自定义类型的错误，应该直接negelect，我已经删除了有关 error_10 的处理。
6. 197: ERROR 29, 无法获取类型，我把翻译动作直接删掉了（没有问题，确实可以直接删去翻译动作）
7. yacc_error_handling.y:362.39-92: warning: type clash on default action: <text> != <>
	- 大概意思是，subprogram_head 本来应该返回这个 procedure/function 的 ID，但如果缺少 ID，那么将导致没有返回值
	- 这可以恢复吗，要怎么恢复
	- @Ziwei: 目前我加了一点处理，如果没有定义 ID 的话，会返回一个 \*\*UNKNOWN_PROCEDURE_NAME\*\* 作为返回值，并且不会插入符号表避免出现别的问题。我觉得这种情况不需要恢复。 
8. 如果 read(pro); 而 pro 是一个未定义的变量，由于yacc里会查询两次符号表，所以会导致符号表输出两次错误信息
	- 所以我觉得可能不能由符号表输出 Error 24
	- @Ziwei: 感觉好像报错两次也没关系？

9. 对于语句分号缺失没什么问题使用error，但是好像error不能放在中间
10. FUNCTION ID formal_parameter ':' error { error_15(); yyerrok; }。这句话有 RR 冲突，具体表现为正常处理的语句为 FUNCTION ID • {...} formal_parameter ':' basic_type。当此时读到 ':' 的时候，它不知道应该不应该执行 {...}。
    - 此时yacc不知道后面到底是 error 还是 basic_type，因此它不知道要不要执行 {...}

## 5. 代码生成（@Ziwei fix一下）
* read部分遇到有如下问题,但也有可能是别的地方的锅，比如这里的ERROR _pro：
	- 样例与输出详见src/test_3/test0，测试方式见src/test_3/ReadMe
	- 具体问题在下面注释部分说明了
	- 数组名没有被%?掉
	- 变量输入的顺序可能会有误()
	- 
```
# 样例
procedure pro(var d:integer;h:char);
 var i:real;
 j:boolean;
 begin
 read(d,h,i,j); //正确
 read(a,c,e,f[1]); //正确
 read(f); //错误，数组名不能作为read的参数
 read(test); //错误，主程序名不能作为read的参数
 read(input); //错误，主程序参数不能作为read的参数
 read(pro); //错误，过程名不能作为read的参数
 read(fun); //错误，函数名不能作为read的参数
end;
# 对应的代码生成的问题：
void pro(int* d, char h)
{
	ERROR _pro;
	int j;
	float i;
	scanf("%c%?%?%f", &d, &h, &i, &j);  // 不应该%?，且顺序有误
	scanf("%d%c%f%d", &a, &c, &e, &f[1-1]);
	scanf("%d", &f);  // 没有被ban掉（类型检查查出来了）
	scanf("%?", &test);
	scanf("%?", &input);
	scanf("%d", &_pro);
	scanf("%d", &fun);
	return _pro;
}
```
- @Ziwei: 这个原始输入是什么？ 
- @Ziyang: 已经补上测试样例路径了~不过更新后的重新测试后还是有问题,
- @Guanzhou: 符号表的问题应该已经解决了，原始输入test0.pas。有一个问题在于read(d)的时候，d是一个var int，会翻译成 scanf("%d%c%f%d", &*d, &h, &i, &j);


## 6. UI 界面或前端

## 7. 扩展功能

## 8. 未归类问题（@Xinpeng fix一下）
1. 多个fun、procedure（不重名）时，第一个fun或pro不会有问题，其余都会翻译出类似如下内容：
```
void pro(int* d, char h)
{
	ERROR _pro;
```
典型测试用例，快排
2. 同上，fun下面有procedure，比如快排程序输出空白
3. relocate 函数可能有问题
+ 自动化测试

## 9. 测试需求
+ 希望可以给 yacc_error_handling.y 做一个阶段测试，回报一下新产生的编译错误之类的问题 (TODO)



### 10. DEBUG

1. 语句分号的处理 
statement_list                      : statement ';' { $$ = $1; }
                                    /* | statement error ';' { error_14(); yyerrok; $$ = $1; } */
                                    | statement { error_14(); yyerrok; $$ = $1; }
                                    | statement_list statement ';' {$$ = $1; *$$ = *$$ + "+" + *$2; }
                                    /* | statement_list statement error ';' { error_14(); yyerrok; $$ = $1; *$$ = *$$ + "+" + *$2; } */
                                    | statement_list statement { error_14(); yyerrok; $$ = $1; *$$ = *$$ + "+" + *$2; }
