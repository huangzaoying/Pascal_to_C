program test(input,output);
var x: integer;
x: real; // 重复定义
y: real;
i: integer;

begin
x := 5;
x := 5.5;
z := 3;
y := 2.5;
x := x + y; // 类型不匹配错误，整数与实数相加

i := 3;
x := x and i; // 类型不匹配错误，整数与布尔值的逻辑与操作
end.