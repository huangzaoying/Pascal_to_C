
program gcd(input, output);
var
  x, y: integer;
function gcd(a, b: integer): integer;
begin
  if b = 0 then gcd := a
  else gcd := gcd(b, a mod b);
end;
begin
  read(x, y);
  write(gcd(x, y));
end.