import sys

N, X = map(int, input().split())
arr = [int(i) for i in input().split()]


for i in range(101):
    arr.append(i)

    arr.sort()

    if sum(arr[1:-1]) >= X:
        print(i)
        sys.exit()

    arr.remove(i)

print(-1)
