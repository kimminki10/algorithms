
def combi(n, picked, to_pick, teams):
    if to_pick == 0: 
        teams.append(picked.copy())
        return

    if len(picked) is 0:
        start = 0
    else:
        start = picked[-1] + 1
    
    for i in range(start, n):
        picked.append(i)
        combi(n, picked, to_pick-1, teams)
        picked.pop()

def calcTeam(s, team):
    l = len(team)
    result = 0
    for i in range(l):
        for j in range(l):
            if i == j: continue
            result += s[team[i]][team[j]]
    return result
            
if __name__ == "__main__":
    n = int(input())
    s = [[int(i) for i in input().split(" ")] for _ in range(n)]
    teams = []
    combi(n, [], n/2, teams)

    l = len(teams)
    minmin = 987654321
    for i in range(l):
        start_team = teams[i]
        link_team = teams[l-i-1]
        sub = abs(calcTeam(s, start_team) - calcTeam(s, link_team))
        if sub < minmin: minmin = sub

    print(minmin)

