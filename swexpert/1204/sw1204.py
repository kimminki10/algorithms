t = int(input())

for _ in range(t):
    casenum = int(input())
    scores = [ int(i) for i in input().split() ]

    result = 0
    score_frequency = [ 0 for _ in range(1000) ]
    for i in scores: 
        score_frequency[i] += 1
    score_frequency.reverse()
    max_score_frequency = max(score_frequency)
    result = 1000 - (score_frequency.index(max_score_frequency) + 1)
    print("#{} {}".format(casenum, result))