# ERROR HANDLING

*此文档用于整理所有的错误情况，和当前错误处理的进度*

+ ID 0: ERROR: The designated identifier has not been declared. (output error string as stderr info)
    - STATE: Guanzhou solved (todo / detected / handled)
    - HANDLING PERIOD: solved in SymbolTable
    - NOTE: 

+ ID 1: The indicated identifer is declared more than once in the same scope.
    - STATE: Yifei solved
    - HANDLING PERIOD: solved in TYPE CHECK PHASE
    - NOTE:

+ ID 2: An identifier is expected. 
    - STATE: Guanzhou solved in yacc rule
    - HANDLING PERIOD: yacc rule. Missing ID would call on this error.
    - NOTE: 优先判37号错误，其他判2号错误

+ ID 3: Every program must begin with the symbol program.
    - STATE: Xinpeng solved
    - HANDLING PERIOD: yacc rule. At the beginning of the whole program.
    - NOTE:

+ ID 4: A closing parenthesis is expected.
    - STATE: Ziwei solved.
    - HANDLING PERIOD: yacc rule. Lose right parenthesis.
    - NOTE:

+ ID 5: A colon is expected. In declarations, the colon is followed by a type.
    - STATE: Guanzhou solved in yacc rule
    - HANDLING PERIOD: yacc rule. After the declaration statement signals like var and const, but don't find a colon.
    - NOTE:

+ ID 6: At this point, the indicated symbol is incorrectly used. The compiler skips this and possibly several following symbols.
    - STATE: Pending
    - HANDLING PERIOD: yacc rule. Happened in the wrong usage of reserved words.
    - NOTE:

+ ID 7: In a formal parameter list each section must begin with an identifier or the symbol var, depending whether the parameter is a value or a variable parameter.
    - STATE: Ziwei solved.
    - HANDLING PERIOD: yacc rule. Happened in parameter list which lose identifier.
    - NOTE:

+ ID 8: The symbol 'of' is expected.
    - STATE: Xinpeng done.
    - HANDLING PERIOD: yacc rule. In the declaration of an array.
    - NOTE:

+ ID 9: An opening parenthes is is expected.
    - STATE: Ziwei solved.
    - HANDLING PERIOD: yacc rule. Lost of left parenthesis.
    - NOTE:

+ ID 10: A type definition must begin with an identifier, the symbol array, or the symbol record.
    - STATE: negelected
    - HANDLING PERIOD: yacc rule. After in definition parts, need a identifier after var or const.
    - NOTE: 应该是针对用户自定义类型的

+ ID 11: An opening bracket is expected ([).
    - STATE: Xinpeng down
    - HANDLING PERIOD: yacc rule. To judge after every call on an array or call on ID which is an array actually.
    - NOTE:

+ ID 12: A closing bracket is expected (]).
    - STATE: Ziwei solved.
    - HANDLING PERIOD: yacc rule. Every appearance of left bracket must be followed with a right one.
    - NOTE:

+ ID 13: The symbol .. is expected (no blank between the dots).
    - STATE: Guanzhou solved in lex
    - HANDLING PERIOD: lex. To specially check the situation x. .y
    - NOTE:

+ ID 14: A semicolon is expected.
    - STATE: Ziwei solved.
    - HANDLING PERIOD: yacc rule. To fixed the deletion of semicolon.
    - NOTE:he result of a function must be of type integer, real, Boolean, or char.

+ ID 15: The result of a function must be of type integer, real, Boolean, or char.
    - STATE: Xinpeng solved.
    - HANDLING PERIOD: yacc rule. Change the yacc rule to match the other kind of types in the production of function.
    - NOTE:

+ ID 16: An equal sign is expected. The symbol := is used in assignment statements only, but not in declarations.
    - STATE: Ziwei solved.
    - HANDLING PERIOD: yacc rule. In statements of decalaritions, add a new production which replace the = with :=.
    - NOTE:

+ ID 17: The expression following the symbol 'if', 'while', or 'until' must be of type Boolean.
    - STATE: down
    - HANDLING PERIOD: error detect phase. Please check whether we have judged the return value of expressions in 'if' statement.
    - NOTE: down in type check

+ ID 18: The control variable following the symbol 'for' must be of type integer, char or Boolean.
    - STATE: down
    - HANDLING PERIOD: error detect. Please check whether we have checked the type of control variable in 'for' statements.
    - NOTE: down in type check

+ ID 19: The expression which specify the initial and final values of the control variable in a for statement must be of the same type as the control variable.
    - STATE: down
    - HANDLING PERIOD: error detect. Please check the type in for statements.
    - NOTE: down in type check

+ ID 20: The parameter 'output' must  be included in the program heading.
    - STATE: neglected

+ ID 21: The indicated is too large. The maximum number of number digits is 14.
    - STATE: Guanzhou solved in lex (CONSTINT and CONSTREAL)
    - HANDLING PERIOD: error detect. Please check the length of NUM
    - NOTE: check in lex

+ ID 22: A dot is expected at end of the corresponding begin and end symbols!
    - STATE: Xinpeng down
    - HANDLING PERIOD: yacc rule

+ ID 23: The expression following the symbol case must be of type integer, char, or Boolean. (In the latter case, an if statement is recommended.)
    - STATE: neglected.
    - HANDLING PERIOD: type check

+ ID 24: The designated character is not acceptable.
    - STATE: Guanzhou solved in lex (What is this?)
    - HANDLING PERIOD: lex
    - NOTE: 除了可以识别的字符之外都报这个错，invalid character

+ ID 25: In a constant definition, the equal sign must be followed constant.
    - STATE: Ziwei solved.
    - HANDLING PERIOD: yacc rule

+ ID 26: The type of an index expression must be identical to the index type specified in the array declaration.
    - STATE: neglected

+ ID 27: In array declaration, the lower bound must not exceed an the upper bound. They must be with in a permissible range of values (2^17).
    - STATE: todo
    - HANDLING PERIOD: error detected
    - NOTE: suggest write a func to check string

+ ID 28: Every indexed variable must be declared as an array.
    - STATE: todo
    - HANDLING PERIOD: type check
    - NOTE: 

+ ID 29: A type identifier is expected here.
    - STATE: Ziwei solved. But may conflict with error 10.
    - HANDLING PERIOD: yacc rule
    - NOTE: MAY HAVE CONFLICT!!!!

+ ID 30: This type is not defined (Recursive type definitions are not not allowed.)
    - STATE: TODO: we don't have user defined data type
    - HANDLING PERIOD: yacc rule
    - NOTE: in variable declaration

+ ID 31: Every variable with a field selector must be declared as a record.
    - STATE: neglected

+ ID 32: The operands of the operators not, and, and or must be of type Boolean.
    - STATE: down
    - HANDLING PERIOD: type check
    - NOTE: in expression, do in type check

+ ID 33: The specified type of this arithmetic expression is illegal.
    - STATE: down
    - HANDLING PERIOD: type check
    - NOTE:
        - like Boolen cannot use + -
        - entire arrays cannot occur as operands to arithmetic or logical operators.

+ ID 34: Operands of div and mod must be of type integer.
    - STATE: todo
    - HANDLING PERIOD: type check
    - NOTE: in type check

+ ID 35: The types of the comparands are incompatible.
    - STATE: down
    - HANDLING PERIOD: type check
    - NOTE: in type check

+ ID 36: The types of corresponding actual and formal parameters must be identical.
    - STATE: down
    - HANDLING PERIOD: type check
    - NOTE: in type check

+ ID 37: A variable is expected.
    - STATE: Guanzhou solved in yacc rule
    - HANDLING PERIOD: yacc rule
    - NOTE: like a:=b, if a is not a varible, put this error. 

+ ID 38: A string must contain at least one character.
    - STATE: neglected
    - HANDLING PERIOD: lex
    - NOTE:

+ ID 39: The number of actual parameters must be equal to the number specified formal parameters.
    - STATE: down

+ ID 40: The parameters of the ofprocedure read must be of type char, integer, or real.
    - STATE: down

+ ID 41: The parameters of the procedure write must be of type char, integer, real, or Boolean.
    - STATE: down

+ ID 42: If a statement has the form write(x:m; n), then x must be anexpression of type real.
    - STATE: neglected

+ ID 43: If statement has the form write(x:n) or write(x:m:n) then m and n must be expressions of type integer.
    - STATE: neglected

+ ID 44: No type procedure identifiers may occur as part of anorexpression.
    - STATE: down

+ ID 45: A statement cannot begin with a type or a function identifier. An exception is the assignment of a result value to a function. In this case, it must be part of the function body.
    - STATE: solved
    - HANDLING PERIOD: 类型检查
    - NOTE:
+ ID 46: In assignment x :=y, the types of the variable x andanthebe identical.An exception is theexpressiony mustcass when xis real. Then, y may also be of type integer.
    - STATE: solved
    - HANDLING PERIOD: 类型检查
    - NOTE: the types near := do not match
+ ID 47: Every case label must be a constant of the same type as theexpression in the case clause.
    - STATE: negelected
    - HANDLING PERIOD: yacc rule 
    - NOTE: swithch 语句，暂时不支持
+ ID 48: The indicated argument of the standard function is of an illegal type.
    - STATE: solved
    - HANDLING PERIOD: 类型检查 
    - NOTE: 可能需要再测试一下
+ ID 49: The program requires too much storage.
    - STATE: negelected
    - HANDLING PERIOD: 
    - NOTE: 
+ ID 50: A constant cannot begin with the indicated symbol.
    - STATE: TODO
    - HANDLING PERIOD:
    - NOTE: 
+ ID 51: The symbol := is expected. (No space between : and =)
    - STATE: Guanzhou sloved in lex
    - HANDLING PERIOD: lex
    - NOTE: 
+ ID 52: The symbol then is expected.
    - STATE: done
    - HANDLING PERIOD: yacc rule
    - NOTE:
+ ID 53: The symbol until is expected.
    - STATE: negelected
    - HANDLING PERIOD: yacc rule
    - NOTE:
+ ID 54: The symbol do is expected.
    - STATE: negelected
    - HANDLING PERIOD: yacc rule
    - NOTE:
+ ID 55: The symbol to (or downto) is expected.
    - STATE: hzy-done 不支持downto
    - HANDLING PERIOD: yacc rule
    - NOTE: downto 关键字 yacc rule 里暂时还不支持
+ ID 56: The symbol begin is expected.
    - STATE: hzy-done
    - HANDLING PERIOD: yacc rule
    - NOTE:
+ ID 57: The symbol end is expected.
    - STATE: hzy-done
    - HANDLING PERIOD: yacc rule
    - NOTE:
+ ID 58: A factor must begin with an identifier, a constant, the symbol not, or with a left parenthesis.
    - STATE: hzy-done
    - HANDLING PERIOD: yacc rule
    - NOTE: yacc 的 factor 翻译规则第一个成分错误