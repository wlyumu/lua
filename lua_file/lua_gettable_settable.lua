-- 定义一个table 

information = {

    name = "tom",
    age  = 18,
    sex  = "man"
}


local mt = {

    __index = function (table, key )
        print("lua --> get value ---> I haven't this field: " .. key)
    end
    ,

    __newindex = function ( table, key, value)
       print("lua --> set value --> I haven't this field : " .. key)
       print("lua --> but I do this : " ..key.. "=".. key)
-- 设置table[index]的实际值
       rawset(table, key, value)
    end
}

--设置元表
setmetatable(information, mt);

function func_print_addr(  )
    -- body
    print("\n lua --> information.address:")
    print(information.address)
end