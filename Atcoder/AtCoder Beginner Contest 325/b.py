N = int(input())
a = []

for i in range(N):
    w, x = map(int, input().split())
    a.append([x, w])

big = 0

for i in range(0, 24):
    ttl = 0

    for x, w in a:
        if 9 <= (x + i) % 24 < 18:
            ttl += w
    
    big = max(big, ttl)

print(big)