N, M = map(int, input().split())
S = input().strip()
T = input().strip()

if T.find(S) == 0 and T[M - N:] == S:
    print(0)

elif T.find(S) == 0:
    print(1)

elif T[M - N:] == S:
    print(2)

else: print(3)