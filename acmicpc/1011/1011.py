def go(x, y):
    l = y - x

    s = 0
    i = 0
    while True:
        i+=1
        s += i * 2
        if s >= l:
            break
    
    if s-i < l <= s:
        print(i * 2)
    else:
        print(i * 2 - 1)
    


t = int(input())

for _ in range(t):
    [x, y] = [ int(i) for i in input().split() ]
    go(x, y)