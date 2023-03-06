# https://dmoj.ca/problem/dwite08c3p4
# DWITE '08 R3 #4 - Time for change

for i in range(5):
    m = int(input())
    n = int(input())
    coins = [int(input()) for i in range(n)]
    dp = [100000000 for i in range(m+1)]
    dp[0] = 0
    for i in range(0, m+1):
        for j in coins:
            if i + j <= m:
                dp[i + j] = min(dp[i + j], dp[i] + 1)
    print(dp[-1])