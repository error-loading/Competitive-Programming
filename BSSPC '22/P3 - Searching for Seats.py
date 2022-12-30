# https://dmoj.ca/problem/bsspc22c1p3
# BSSPC '22 P3 - Searching for Seats

n , m, k = map(int, input().split())

grid = [["." for i in range(m)] for j in range(n)]

for i in range(k):
    x, y = map(int, input().split())
    grid[x-1][y-1] = "#"

ppl = 0


for i in range(n):
    for j in range(m):
        ttl = 0
        if grid[i][j] == "#":
            continue

        if n == 1:
            continue

        if i > 0 and i < n-1:
            if j > 0 and j < m-1:
                if grid[i+1][j] == "#":
                    ttl+=1
                if grid[i-1][j] == "#":
                    ttl+=1
                if grid[i][j+1] == "#":
                    ttl+=1
                if grid[i][j-1] == "#":
                    ttl+=1
                if grid[i-1][j-1] == "#":
                    ttl+=1
                if grid[i+1][j-1] == "#":
                    ttl+=1
                if grid[i+1][j+1] == "#":
                    ttl+=1
                if grid[i-1][j+1] == "#":
                    ttl+=1
            else:
                if grid[i+1][j] == "#":
                    ttl+=1
                if grid[i-1][j] == "#":
                    ttl+=1
                if j == 0 and grid[i][j+1] == "#":
                    ttl+=1
                if j == m-1 and grid[i][j-1] == "#":
                    ttl+=1
                if j == m-1 and grid[i-1][j-1] == "#":
                    ttl+=1
                if j == m-1 and grid[i+1][j-1] == "#":
                    ttl+=1
                if j == 0 and grid[i+1][j+1] == "#":
                    ttl+=1
                if j == 0 and grid[i-1][j+1] == "#":
                    ttl+=1
        else:
            if i == 0 and grid[i+1][j] == "#":
                ttl+=1
            if i == n-1 and grid[i-1][j] == "#":
                ttl+=1
            if j != m-1 and grid[i][j+1] == "#":
                ttl+=1
            if j != 0 and grid[i][j-1] == "#": 
                ttl+=1
            if i == n-1 and j != 0 and grid[i-1][j-1] == "#":
                ttl+=1
            if i == 0 and j != 0 and grid[i+1][j-1] == "#":
                ttl+=1
            if i == 0 and j != m-1 and grid[i+1][j+1] == "#":
                ttl+=1
            if i == n-1 and j != m-1 and grid[i-1][j+1] == "#":
                ttl+=1
        if ttl >= 3:
            ppl+=1
print(ppl)