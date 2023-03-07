n = int(input())
graph = [[i for i in input()] for i in range(n)]


day = [0]
big = [0]

for i in range(5):
    ttl = 0
    for j in range(n):
        if graph[j][i] == "Y": ttl += 1
    if big[0] == ttl:
        day.append(i+1)
    elif big[0] < ttl:
        day = [i+1]
        big = [ttl]

string = ""
for i in day:
    string += f",{i}"

print(string[1:])