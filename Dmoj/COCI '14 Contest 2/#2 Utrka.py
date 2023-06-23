import sys
input = sys.stdin.readline

N = int(input())

names = {}
for i in range(N):
    name = input().strip()
    if name not in names:
        names[name] = 1
    else:
        names[name] += 1

for i in range(N-1):
    name = input().strip()
    names[name] -= 1

for key, val in names.items():
    if val:
        print(key)
        sys.exit()