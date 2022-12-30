# https://dmoj.ca/problem/cchange
# Coin Change

x = int(input())
n = int(input())

dp = [-1 for i in range(x+1)]

coins = [int(input()) for i in range(n)]

dp[0] = 0

for i in range(x+1):
    for coin in coins:
        if i+coin <= x:
            if dp[i+coin] != -1:
                dp[i+coin] = min(dp[i+coin], dp[i]+1)
            else:
                dp[i+coin] = dp[i] + 1
        
print(dp[-1])