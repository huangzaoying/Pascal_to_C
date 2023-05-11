program test3(input, output);
var x,y: integer;

procedure swap(var a,b:integer);
var tmp:integer;
begin
    tmp:=a;
    a:=b;
    b:=tmp;
end;

begin
    read(x,y);
    swap(x,y);
    write(x,y);
end.