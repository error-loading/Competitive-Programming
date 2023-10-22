N, H = map(int, input().split())
rob = [0] + list(map(int, input().split()))
dp = [float('inf') for i in range(N + 1)]
dp[0] = 0

last = 0

for i in range(1, N + 1):
    for j in range(last, i):
        tmp = dp[j] + H + (rob[i] - rob[j + 1])**2
        if tmp < dp[i]: 
            dp[i] = tmp
            last = j

print(dp[-1])