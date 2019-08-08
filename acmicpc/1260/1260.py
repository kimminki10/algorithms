import queue

n, m, v = [ int(i) for i in input().split() ]
if n == m == v == 1:
    print(1)
    print(1)
    exit(0)
g = [ [] for _ in range(n) ]
for _ in range(m):
    a, b = [ int(i) for i in input().split() ]
    g[a-1].append(b-1) 
    g[b-1].append(a-1)

for i in g:
    i.sort()

def bfs(g, v):
    result = []
    q = queue.Queue()
    result.append(v-1)
    q.put(v-1)

    while not q.empty() :
        item = q.get()
        for j in g[item]:
            if j not in result:
                result.append(j)
                q.put(j)
    
    return result


def dfs(g, v, result):
    result.append(v)

    for i in g[v]:
        if i not in result:
            dfs(g, i, result)
    
result = []
dfs(g,v-1,result)
print([ i+1 for i in result ])
print([ i+1 for i in bfs(g,v) ])
