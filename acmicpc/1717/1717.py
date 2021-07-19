
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

