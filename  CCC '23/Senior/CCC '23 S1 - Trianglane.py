# https://dmoj.ca/problem/ccc23s1
# CCC '23 S1 - Trianglane

x = int(input())
arr1 = [int(i) for i in input().split()]
arr2 = [int(i) for i in input().split()]

ttl = 0

if arr1[0] == 1:
    if arr2[0] == 1:
        ttl -=2
    ttl+=3

if arr2[0] == 1:
    ttl +=3

for i in range(1, x):
    if arr1[i] == 1:
        ttl+=3
        if arr1[i-1] == 1:
            ttl -=2
        if i % 2 == 0 and arr2[i] == 1:
            ttl -= 2
    if arr2[i] == 1:
        ttl+=3
        if arr2[i-1] == 1:
            ttl-=2
print(ttl)