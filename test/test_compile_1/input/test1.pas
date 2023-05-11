
program sort(input, output);
var a: array[1..101] of integer;
  k,
  m,tempOut: integer;
function partition(low,high: integer): integer;
var i, j, temp: integer;
begin
  i := low - 1;
  for j:=low to (high - 1) do
    begin
      if a[j] <= a[high] then
        begin
          i := i + 1;
          temp := a[i];
          a[i] := a[j];
          a[j] := temp;
        end;
    end ;
  i := i + 1;
  temp := a[i];
  a[i] := a[high];
  a[high] := temp;
  partition := i;
end;
procedure qs(low,high: integer);
var pivot: integer;
begin
  pivot := 0;
  if low <= high then
    begin
      pivot := partition(low, high);
      qs(low, pivot - 1);
      qs(pivot + 1, high);
    end;
end;
begin
  read(m);
  for k:=1 to m do
    begin
      read(tempOut);
      a[k] := tempOut;
    end;
  qs(1, m);
  for k:=1 to m do
    begin
      write(a[k],' ');
    end;
end.
