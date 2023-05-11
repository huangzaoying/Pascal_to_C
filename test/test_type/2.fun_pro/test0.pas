program test(input,output);
var sum:integer;
a:real;
diff:real;

function add(x, y: integer): real;
var result: real;
begin
  result := x + y;
end;

function minus(x, y: real): integer;
var result: integer;
begin
  result := x - y;
end;

begin
a := 3.5;
sum := add(a, 4); // 类型不匹配错误，传递实数参数给接受整数参数的函数
diff:=minus(a, 4.5);
end.