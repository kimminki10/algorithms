<<<<<<< HEAD

def my_union(a, b):
    f_a = find(a)
    f_b = find(b)
    if f_a == f_b: return
    s[f_a] = f_b


def find(x):
    if s[x] == x:
        return x
    s[x] = find(s[x])
    return s[x] 


n, m = [ int(i) for i in input().split()]
s = [ i for i in range(n+1) ]

for _ in range(m):
    op, a, b = [ int(i) for i in input().split() ]
    if op == 0:
        my_union(a, b)
    elif op == 1:
        r_a = find(a)
        r_b = find(b)
        if r_a == r_b:
            print("yes")
        else:
            print("no")

=======
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
>>>>>>> f1cf216417319c747ddbceb329aa159a426a1b90
