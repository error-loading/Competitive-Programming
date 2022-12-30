# https://dmoj.ca/problem/bsspc22c1p5
# BSSPC '22 P5 - Derrick and Orz Trees

import sys
input = sys.stdin.readline

n = int(input())
trees = [int(i) for i in input().split()]

MOD = 10**9+7
def factor(num):
    if num % 2 == 1:
        return 1
    return (factor(num//2) ** 2 + 1) % MOD

cut = 1

for tree in trees:
    cut*= factor(tree) 
    cut %= MOD

print(cut % MOD)

