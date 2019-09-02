import copy

def matmul(a1, a2, r):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                r[i][j] = (r[i][j]+(a1[i][k] * a2[k][j])%1000)%1000

def solve(d, b):
    if b in d.keys(): 
        return
    d[b] = copy.deepcopy(zeros)
    if b % 2 == 1:
        solve(d, b-1)
        matmul(d[b-1], d[1], d[b])
    else:
        tmp = int(b/2)
        solve(d, tmp)
        matmul(d[tmp], d[tmp], d[b])

n, b = [ int(i) for i in input().split() ]
d = {}
zeros = [[0 for _ in range(n)] for _ in range(n) ]
d[1] = [[int(i) for i in input().split() ] for i in range(n) ]
solve(d, b)
for i in d[b]:
    for j in i:
        print(j, end=' ')
    print()