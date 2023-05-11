program TestForLoop(input, output);
var
  i, start, endInt: integer;
  startReal, endReal: real;
arr3: array [1..5] of real;
begin
  start := 1;
  endInt := 5;

  // 正确的for循环
  for i := start to endInt do
  begin
    write(i);
  end;

  // 错误的for循环：开始值为实数类型
  startReal := 1.5;
  for arr3 := startReal to endInt do // 类型错误：开始值为实数类型
  begin
    write(i);
  end;
  // 错误的for循环：结束值为实数类型
  endReal := 5.5;
  for i := start to endReal do // 类型错误：结束值为实数类型
  begin
    write(i);
  end;
  // 错误的for循环：开始值和结束值都是实数类型
  for i := startReal to endReal do // 类型错误：开始值和结束值都是实数类型
  begin
    write(i);
  end;
end.