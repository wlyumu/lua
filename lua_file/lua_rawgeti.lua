-- 定义一个全局table

languagesTable = {

    "c",
    "c ++",
    "java",
    "python"
}

-- 定义一个打印函数
function func_prt( )
    print("\n")
    for index, value in pairs(languagesTable)do
        print("["..index.."]"..value);
    end
end