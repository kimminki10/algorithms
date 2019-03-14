def combination(n, k):
    result = 1
    for i in range(k):
        result *= (n-i) / (k-i)
    return result

t = int(input())

for _ in range(t):
    [w, e] = [ int(i) for i in input().split() ]
    print("{:.0f}".format(combination(e, w)))