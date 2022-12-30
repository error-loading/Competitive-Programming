# https://dmoj.ca/problem/ccc03j1
# CCC '03 J1 - Trident

t = int(input())
s = int(input())
h = int(input())

newString = "*"
newString+= " " * s
newString += newString
newString += "*"

for i in range(t):
    print(newString)

print("*"*(s+s+3))

for i in range(h):
    print(" " * (1+s) + "*")
