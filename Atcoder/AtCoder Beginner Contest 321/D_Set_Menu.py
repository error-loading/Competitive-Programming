N, M, P = map(int, input().split())
caf1 = [int(i) for i in input().split()]
caf2 = [int(i) for i in input().split()]

cum = 0

for i in caf1:
    if i >= P:
        cum += P * len(caf2)
    
        caf1.remove(i)

for i in caf2:
    if i >= P:
        cum += P * len(caf1)
        caf2.remove(i)

for i in range(len(caf1)):
    for j in range(len(caf2)):
        cum += min(caf1[i] + caf2[j], P)

print(cum)