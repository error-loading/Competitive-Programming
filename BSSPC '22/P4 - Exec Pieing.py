# https://dmoj.ca/problem/bsspc22c1p4
# https://dmoj.ca/problem/bsspc22c1p4

n, t = map(int, input().split())

arr = [int(i) for i in input().split()]
pref = arr[:]
maxArr = [arr[0]]

for i in range(1, n):
    pref[i]+=pref[i-1]
    if arr[i] > maxArr[i-1]:
        maxArr.append(arr[i])
    else:
        maxArr.append(maxArr[i-1])

ind = 0
maxSum = 0

for i in range(n):
    if pref[i] - maxArr[i] <= t and pref[i] - maxArr[i] > maxSum:
        maxSum = pref[i] - maxArr[i]
        ind = i
print(ind)