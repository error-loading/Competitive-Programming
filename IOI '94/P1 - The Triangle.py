# https://dmoj.ca/problem/ioi94p1
# IOI '94 P1 - The Triangle

import sys
input = sys.stdin.readline

n = int(input())

triangle = [[] for i in range(n)]
dp = [[0 for j in range(i)] for i in range(1,n+1)]

for i in range(n):
    row = [int(i) for i in input().split()]
    triangle[i] = row

suma = []

def rec(x, y, ttl):
    if y+1 >= n:
        suma.append(ttl)
        return 0
    rec(x, y+1, ttl + triangle[y+1][x])
    rec(x+1, y+1, ttl + triangle[y+1][x+1])

rec(0,0,triangle[0][0])

print(max(suma))
