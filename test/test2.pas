program test2(input, output);
var m,n,k,l,d:integer;
    t,f:array[1..1000]of integer;
    t1,f1:array[1..1000]of integer;
procedure inp;
var i,j,x1,y1,x2,y2:integer;
begin
    read(m,n,k,l,d);
    for i:=1 to d do
    begin
        read(x1,y1,x2,y2);
    end;
end;

procedure sol;
var i,j:integer;
begin
    for i:=1 to k do
        write(t1[i]);
    for i:=1 to l do
        write(f1[i]);
end;

procedure pai;
var i,j,k1,k2:integer;
begin
    for i:=1 to m-1 do
      for j:=i+1 to m do
          if t[j]>t[j-1] then
            begin
                k1:=t[j]; k2:=t1[j];
                t[j]:=t[j-1]; t1[j]:=t1[j-1];
                t[j-1]:=k1; t1[j-1]:=k2;
            end;
    for i:=1 to n-1 do
      for j:=i+1 to n do
          if f[j]>f[j-1] then
            begin
                k1:=f[j]; k2:=f1[j];
                f[j]:=f[j-1];f1[j]:=f1[j-1];
                f[j-1]:=k1; f1[j-1]:=k2;
            end;
    for i:=1 to k-1 do
      for j:=i+1 to k do
          if (t1[j]<t1[j-1])and(t1[j]<>0) then
            begin
                k1:=t1[j];
                t1[j]:=t1[j-1];
                t1[j-1]:=k1;
            end;
    for i:=1 to l-1 do
      for j:=i+1 to l do
          if (f1[j]<f1[j-1])and(f1[j]<>0) then
            begin
                k1:=f1[j];
                f1[j]:=f1[j-1];
                f1[j-1]:=k1;
            end;

end;
begin
    inp;
    pai;
    sol;
end.