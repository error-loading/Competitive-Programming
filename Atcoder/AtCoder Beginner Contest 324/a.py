import sys
input = sys.stdin.readline

N = int(input())
a = [int(i) for i in input().split()]

for i in a:
    if i != a[0]:
        print("No")
        sys.exit()

print("Yes")