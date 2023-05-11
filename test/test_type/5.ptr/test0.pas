program test(input, output);
var x,y: integer;

procedure swap(var a:integer; var b: real);
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