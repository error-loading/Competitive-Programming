import sys
input = sys.stdin.readline

N = int(input())

dp = {}

def solve(num):
    cnt = 0
    j = 1
    while j*j<=num:
        if num % j == 0:
            cnt += j * j

            if num // j != j:
                cnt += (num//j) ** 2
        
        j+= 1

    dp[num] = j

    return cnt

for i in range(N):
    num = int(input())
    if num in dp:
        print(dp[num])
    else: print(solve(num))