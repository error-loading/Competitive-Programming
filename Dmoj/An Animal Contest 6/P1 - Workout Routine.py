# https://dmoj.ca/problem/aac6p1
# An Animal Contest 6 P1 - Workout Routine

import sys
input = sys.stdin.readline
n, k = map(int, input().split())

arr = [i+1 for i in range(n-1)]

sumA = sum(arr)

i = n

while (i+sumA) % k != 0:
    i+=1

arr.append(i)

print(*arr)