program test1(input , output);
var a,b,c,i: integer;
begin
    c:=a+a*(b+c);
    read(a,b);
    for i := a to a+b do
        if i mod 2 = 0 then
            c := c + i
        else
            c := c - i;
    write(a*b,c);
end.
