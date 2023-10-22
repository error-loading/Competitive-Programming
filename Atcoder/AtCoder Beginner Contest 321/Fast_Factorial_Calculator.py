N = int(input())
arr = [0] + [int(i) for i in input().split()]
dp = [0 for i in range(N + 1)]

for i in range(1, N + 1):
    if i == 1: dp[i] = max(arr[0], 0)
    else: dp[i] = max(dp[i - 1], dp[i - 2] + arr[i])

print(dp[-1])