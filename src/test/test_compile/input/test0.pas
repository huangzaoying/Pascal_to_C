
program fib(input, output);
var
  a, i: integer;
function fib(y: integer): integer;
begin
if y = 0 then
    fib := 0
  else
  begin
    if y = 1 then
      fib := 1
    else
      fib := fib(y - 1) + fib(y - 2);
  end;
end;

begin
  for i:= 1 to 10 do
    write(fib(i),' ');
end.
