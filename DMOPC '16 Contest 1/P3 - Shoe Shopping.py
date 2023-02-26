n = int(input())
arr = [int(i) for i in input().split()]
dp = [float('inf') for i in range(n+1)]
dp[0] = 0
dp[1] = arr[0]

for i in range(n+1):
    if i+1 <= n:
        dp[i+1] = min(dp[i+1], dp[i] + arr[i])
    if i + 2 <= n:
        dp[i+2] = min(dp[i+2], dp[i] + min(arr[i], arr[i+1]) / 2 + max(arr[i], arr[i+1]))
    if i + 3 <= n:
        dp[i+3] = min(dp[i+3], dp[i] + arr[i] + arr[i+1] + arr[i+2] - min(arr[i], arr[i+1], arr[i+2]))

print("{price:.1f}".format(price = dp[-1]))