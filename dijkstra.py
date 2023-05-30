from heapq import *


def prims(graph, start, visited, distance, parent):
    bag = []
    heappush(bag, [0, start])
    distance[start] = 0
    parent[start] = -1

    while (bag):
        d, n = heappop(bag)
        if not visited[n]:
            visited[n] = True
            for cd, cn in graph[n]:
                if distance[cn] > cd and not visited[cn]:
                    parent[cn] = n
                    distance[cn] = cd
                    heappush(bag, [cd, cn])


n = 5
ipt = [[0, 1, 2], [0, 3, 6], [1, 0, 2], [1, 2, 3], [1, 3, 8], [1, 4, 5], [2, 1, 3], [2, 4, 7], [
    3, 0, 6], [3, 1, 8], [3, 4, 9], [4, 1, 5], [4, 2, 7], [4, 3, 9]]  # [startnode, endnode, dist]

graph = {}
parent = {}
visited = {}
distance = {}

for i in range(n):
    graph[i] = []
    parent[i] = None
    visited[i] = False
    distance[i] = float('inf')

for s, d, w in ipt:
    graph[s].append([w, d])
    graph[d].append([w, s])

start = int(input("Enter start: "))

prims(graph, start, visited, distance, parent)

for k, v in parent.items():
    if v != -1:
        print(f'{v} - {k}')
tot = 0
for k, v in distance.items():
    tot += v

print(tot)
