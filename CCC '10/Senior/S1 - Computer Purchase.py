# https://dmoj.ca/problem/ccc10s1
# CCC '10 S1 - Computer Purchase

import sys
input = sys.stdin.readline

n = int(input())


arr = [["", 0], ["", 0]]

for i in range(n):
    name, r, s, d = input().split()
    r = int(r); s = int(s); d = int(d)
    price = 2*r + 3*s + d
    if arr[-1][-1] < price or (arr[-1][-1] == price and name < arr[-1][0]):
        arr[0][0] = arr[-1][0]
        arr[0][1] = arr[-1][-1]
        arr[-1][0] = name
        arr[-1][-1] = price

    elif arr[0][-1] < price or (arr[0][-1] == price and name < arr[0][0]):
        arr[0][0] = name
        arr[0][1] = price
if arr[-1][0] == "":
    pass
elif arr[0][0] == "":
    print(arr[-1][0])
else:
    print(arr[-1][0])
    print(arr[0][0])

