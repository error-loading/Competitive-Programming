# https://dmoj.ca/problem/dmopc16c1p3
# DMOPC '16 Contest 1 P3 - Shoe Shopping

n = int(input())
arr = [int(i) for i in input().split()]

dp = arr[:]

for i in range(1,n):
    dp[i]+= dp[i-1]

dp.insert(0,0)

for i in range(1,n+1):
    if i-2>=0:
        dp[i] = min(dp[i], dp[i-3] + arr[i-1] + arr[i-2] + arr[i-3] - min(arr[i-1], arr[i-2], arr[i-3]))
    if i-1>=0:
        dp[i] = min(dp[i], dp[i-2] + arr[i-1]+arr[i-2] - min(arr[i-1]/2, arr[i-2]/2))

print(round(float(dp[-1]),1))