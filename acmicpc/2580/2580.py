
def checkRow(l):
    x, y = l
    for i in range(9):
        d[i][y]

        
d = [[ int(i) for i in input().split() ] for i in split() ]

zero_list = []
for i in range(9):
    for j in range(9):
        if d[i][j] == 0:
            zero_list.append([i,j])

