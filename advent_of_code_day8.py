from collections import defaultdict, Counter, deque

points = []
with open('in.txt', 'r') as file:
    for line in file:
        x, y, z = line.split(',')
        points.append((int(x), int(y), int(z)))

distance = []

for i in range(len(points)):
    for j in range(i + 1, len(points)):
        p1 = points[i]
        p2 = points[j]
        dist = (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2 + (p1[2] - p2[2])**2
        distance.append((dist, i, j))

distance = sorted(distance)

UF = list(range(len(points)))

def find(x):
    if UF[x] != x:
        UF[x] = find(UF[x])
    return UF[x]

def union(x, y):
    rootX = find(x)
    rootY = find(y)
    if rootX != rootY:
        UF[rootX] = rootY

connections = 0

for dist, i, j in distance:
    if find(i) != find(j):
        connections += 1
        if connections == len(points) - 1:
            print(points[i][0] * points[j][0])
        union(i, j)

SZ = defaultdict(int)
for i in range(len(points)):
    root = find(i)
    SZ[root] += 1
S = sorted(SZ.values())
print(S[-1] * S[-2] * S[-3])

