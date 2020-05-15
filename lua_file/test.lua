print("hello, I am lua!")
function foo( ... )

    local i = 1
    local sum = 1
    while i <= 10 do
        sum = sum * 2
        i = i + 1
    end
    return sum
end

print("sum = ", foo());