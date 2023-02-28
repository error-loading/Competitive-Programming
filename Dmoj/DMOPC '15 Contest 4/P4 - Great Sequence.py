# https://dmoj.ca/problem/dmopc15c4p4
# DMOPC '15 Contest 4 P4 - Great Sequence

n, k, q = map(int, input().split())
arr = [int(i) for i in input().split()]
pref= arr[:]

for i in range(1, n):
    pref[i]+=pref[i-1]

pref.insert(0, 0)

freq = {}

for i in range(n):
    node = arr[i]
    if node in freq:
        freq[node].append(i)
    else:
        freq[node] = [i]


for i in range(q):
    a, b, x, y = map(int, input().split())
    if pref[y] - pref[x-1] <= k:
        print("No")
    else:
        if a not in freq or b not in freq:
            print("No")
            continue
        newArrA = freq[a]
        newArrB = freq[b]

        founda = False
        foundb = False


        low = 0; high = len(newArrA) - 1

        while low <= high:
            mid = (low+high) // 2
            if newArrA[mid] >= x-1 and newArrA[mid] <= y-1:
                founda = True
                break
            elif newArrA[mid] > y-1:
                high = mid-1
            else:
                low = mid+1
        if not founda:
            print("No")
            continue
        low = 0; high = len(newArrB) - 1
        while low <= high:
            mid = (low+high) // 2
            if newArrB[mid] >= x-1 and newArrB[mid] <= y-1:
                foundb = True
                break
            elif newArrB[mid] > y-1:
                high = mid-1
            else:
                low = mid+1
        if not foundb:
            print("No")
            continue
        else:
            print("Yes")