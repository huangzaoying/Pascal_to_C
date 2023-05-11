program TestArray;
var  
  arr1: array[1..3] of integer;  
  arr2, arr3: array [1..3, 1..4] of integer;
begin
  { 一维数组赋值 }
  arr1[1] := 1;
  arr1[2] := 2;
  arr1[3] := 3;
  writeln(arr1[3]);
  
  { 二维数组赋值 }
  arr2[1, 1] := 1;
  arr2[1, 2] := 'a';
  arr2[2, 1] := 2;
  arr3[1, 2] := arr2[1, 1];
  writeln(arr3[1, 1]);
end.