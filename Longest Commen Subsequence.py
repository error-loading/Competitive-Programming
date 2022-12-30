# https://dmoj.ca/problem/lcs
# Longest Common Subsequence

import sys
input = sys.stdin.readline
n, m = map(int, input().split())
x = [int(i) for i in input().split()]
y = [int(i) for i in input().split()]
dp = [[0 for i in range(m+1)] for j in range(n+1)]

for i in range(n-1, -1, -1):
    for j in range(m-1, -1, -1):
        if x[i] == y[j]:
            dp[i][j] = 1 + dp[i+1][j+1]
        else:
            dp[i][j] = max(dp[i][j+1],dp[i+1][j])
print(dp[0][0])