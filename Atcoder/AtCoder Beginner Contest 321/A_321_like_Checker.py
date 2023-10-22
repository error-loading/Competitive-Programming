import sys

arr = [int(i) for i in input()]

newArr = sorted(arr, reverse=True)

for i in range(10):
    if arr.count(i) > 1:
        print("No")
        sys.exit()

if newArr == arr:
    print("Yes")

else:
    print("No")

