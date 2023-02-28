# https://codeforces.com/contest/1796/problem/A
# A. Typical Interview Problem

alpha = "FBFFBFFBFBFFBFFBFBF"

n = int(input())

for i in range(n):
    input()
    string = input()
    if string in alpha:
        print("YES")
    else:
        print("NO")
