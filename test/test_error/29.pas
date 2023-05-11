//Error 29 - Missing type identifier in type definition
program TestError29(input, output);
var
  x, y: ; // 这里缺少类型，将触发 error_29
begin
write(1);
end.