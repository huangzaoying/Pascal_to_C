program test(input,output);
const
  MAX = 100;
  PI = 3.14159;
var
  i, j, k: integer;
  x, y, z: real;
  c: char;
  b: boolean;
{ Functions and procedures }
function factorial(n: integer): integer;
begin
if n <= 1 then
    factorial := 1
else
    factorial := n * factorial(n-1);
end;
procedure printpi;
begin
    write(PI,' ');
end;
begin
  { Assignment statements }
  i := 5;
  j := i + 3;
  k := j * 2;
  x := 2.5;
  y := x div 2.0;
  z := x + y;
  { Conditional statements }
  if i > j then
    write(0,' ')
  else
    write(1,' ');
  { Loop statements }
  for i := 1 to 10 do
    write(i,' ');
  
  { Call functions and procedures }
  write(factorial(5),' ');
  printpi;

  { Use constants }
  write(MAX,' ');
  write(PI,' ');
end.