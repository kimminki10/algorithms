import queue

def bfs(graph, check, start):
    q = queue.Queue()
    q.put(start)
    check[start] = 1
    
    while not q.empty():
        v = q.get()
        for i in graph[v]:
            if check[i] is 0:
                q.put(i)
                check[i] -= check[v]
            elif check[i] is check [v]:
                return False
    return True

def solve(v, e):
    graph = [ [] for _ in range(v) ]
    check = [ 0 for _ in range(v) ]
    
    for _ in range(e):
        v1, v2 = [ int(i) for i in input().split() ]
        graph[v1 - 1].append(v2 - 1)
        graph[v2 - 1].append(v1 - 1)

    for i in range(v):
        if check[i] is 0:
            result = bfs(graph, check, i) 
        if result is False:
            print("NO")
            return
    print("YES")

k = int(input())

for i in range(k):
    v, e = [ int(i) for i in input().split() ]
    solve(v, e)
