# https://dmoj.ca/problem/binary
# Binary

n = int(input())

for i in range(n):
    x = str(format(int(input()), "b"))
    some = 0
    newString = ""
    while len(x) > 0:
        if len(x) % 4 == 0:
            newString+= x[:4]
            x = x[4:]
            newString+= " " 
        else:
            newString+= "0" * (4-len(x) % 4)
            newString+=x[:len(x)%4]
            newString+= " "
            x = x[len(x)%4:]
    print(newString)