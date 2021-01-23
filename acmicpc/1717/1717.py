import sys
input = sys.stdin.readline


def find(v):
    if v == s[v]: 
        return v
    s[v] = find(s[v])
    return s[v]


def union(u, v):
    u = find(u)
    v = find(v)

    if u == v: 
        return
    if rank[u] < rank[v]: 
        u,v = v, u
    s[v] = u
    if rank[u] == rank[v]:
        rank[u] += 1


n, m = map(int, input().split())
s = [ int(i) for i in range(n+1) ]
rank = [1] * (n+1)

for _ in range(m):
    op, a, b = map(int, input().split())
    if op == 0:
        union(a, b)
    else:
        if find(a) == find(b):
            print("yes")
        else:
            print("no")
