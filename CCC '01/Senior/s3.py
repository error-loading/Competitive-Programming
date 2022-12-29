# https://dmoj.ca/problem/ccc01s3
# CCC '01 S3 - Strategic Bombing

import sys, copy
from collections import deque
input = sys.stdin.readline

roads = []
graph = {}

while True:
    road = input().strip()
    if road == "**":
        break
    roads.append(road)

    if road[0] not in graph:
        graph[road[0]] = [road[1]]
    else:
        graph[road[0]].append(road[1])

    if road[1] not in graph:
        graph[road[1]] = [road[0]]
    else:
        graph[road[1]].append(road[0])
def graphTheory(newgraph, road):
    newgraph = copy.deepcopy(newgraph)
    newgraph[road[0]].remove(road[1])
    newgraph[road[1]].remove(road[0])


    visited = []

    dq = deque()
    dq.append("A")
    visited.append("A")

    while len(dq) > 0:
        node = dq.pop()
        if node == "B":
            return False
        for i in newgraph[node]:
            if i not in visited:
                visited.append(i)
                dq.append(i)
    return True

ttl = 0

for i in roads:
    if graphTheory(graph, i):
        ttl+=1
        print(i)
print(f"There are {ttl} disconnecting roads.")
