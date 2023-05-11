program test();
// 一维数组声明和初始化
var arr1, arr2: array [1..5] of integer;
    arr3: array [1..5] of real;
    multiArr: array [1..3, 1..4] of integer;
begin
// 下标处理
arr1[3] := 7;
arr1[3.5] := 6;

// 维数匹配
arr1[3, 2] := 4; // 这个操作应该引发类型错误，因为维数不匹配
end.