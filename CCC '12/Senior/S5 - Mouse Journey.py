# https://dmoj.ca/problem/ccc12s5
# CCC '12 S5 - Mouse Journey

import sys
input = sys.stdin.readline
r, c = map(int, input().split())
k = int(input())
dp = [[0 for i in range(c+1)] for j in range(r+1)]

dp[0][1] = 1

cages = []

for i in range(k):
    x, y = map(int, input().split())
    cages.append((x, y))

for i in range(1,r+1):
    for j in range(1,c+1):
        if (i, j) in cages:
            continue
        dp[i][j] = dp[i-1][j]+dp[i][j-1]

print(dp[-1][-1])