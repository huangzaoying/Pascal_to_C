program test(input,output);
var a, sum: real;
procedure add(x, y: integer);
var result: integer;
begin
  result:=x+y;
  write(result);
end;

begin
a:=3.5;
add(a, 4); // 类型不匹配错误，传递实数参数给接受整数参数的函数
end.