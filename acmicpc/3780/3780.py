import sys
input = sys.stdin.readline


def find(v):
    if s[v] == v: 
        return v
    tmp = find(s[v])
    d[v] += d[s[v]]
    s[v] = tmp
    return s[v]


def union(a, b):
    s[a] = b
    d[a] = abs(a-b) % 1000


T = int(input())
for _ in range(T):
    n = int(input())
    s = list(range(n+1))
    d = [0] * (n + 1)
    while True:
        i = input().split()
        if i[0] == 'O':
            break
        elif i[0] == 'E':
            v = int(i[1])
            find(v)
            print(d[v])
        elif i[0] == 'I':
            a, b = map(int, i[1:])
            union(a, b)
