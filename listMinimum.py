# https://dmoj.ca/problem/bf1
# List Minimum

x = int(input())
arr = [int(input()) for i in range(x)]
arr.sort()
for i in arr:
    print(i)