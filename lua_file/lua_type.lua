-- 定义一个全局table

information = {
    name = "wl",
    age  = 18,
    married = false
}



--定义一个打印函数

function func_prt()
    print("lua -->table element:\r\n")
    for index, value in pairs(information)do
        print("information."..index.." = ".. tostring(value));
    end
end