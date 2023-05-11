//Error 55 - Missing "to" (or "downto") keyword in "for" loop
program Error55;
var
  a: integer;
begin
  for a:=1 to 10 do
  begin
    writeln(a);
  end;
end.