
black = white = 0

def is_same_color(ta):
    c = ta[0][0]
    for vv in ta:
        for i in vv:
            if c != i:
                return False
    return True

def solve(ta, size):
    if is_same_color(ta):
        global black, white
        if ta[0][0] == 1:
            black += 1
        else:
            white += 1
    else:
        m = int(size/2)
        solve([v[:m] for v in ta[:m]], m)
        solve([v[m:] for v in ta[:m]], m)
        solve([v[:m] for v in ta[m:]], m)
        solve([v[m:] for v in ta[m:]], m)
        
        
n = int(input())
ta = [[ int(v) for v in input().split() ] for _ in range(n)]

solve(ta, n)

print(white, black, sep='\n')