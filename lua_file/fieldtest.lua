
c = 100;
-- 变量系数
param =
{
    a = 2;
    b = 1;
}

-- 全局变量，满足c=2a+b，在c语言中实现

-- f(x) = ax + b
function lua_func(x)
    
    print(param.a * x * x + param.b * x + c)
end