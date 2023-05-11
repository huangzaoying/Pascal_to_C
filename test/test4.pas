program test4(input, output);
var a : array[0..10] of integer;
i, j : integer;

function gcd(a, b: integer): integer;
begin
    if b=0 then gcd:=a
    else gcd:=gcd(b, a mod b);
end;

begin
    gcd(i, j);
end.