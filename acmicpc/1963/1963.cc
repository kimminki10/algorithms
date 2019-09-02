#include <stdio.h>
#include <queue>

using namespace std;

int pNum[2000]= {0,};
int pidx = 0;
int check[10001];

void findPrime() {
	int isPrime[10001] = {0,};
	for (int i = 2; i <= 10000; i++){
		if (isPrime[i] == 0) {
			isPrime[i] = 1;
			
			if (i > 1000) {
				pNum[pidx] = i;
				pidx += 1;
			}
			
			for (int j = 2; j * i < 10001; j++)
				isPrime[i*j] = -1;
		}
	}
}

int isConnected(int a, int b) {
	int result = 0;
	
	int count = 0;
	for (int i = 0; i < 4; i++, a /= 10, b /= 10) {
		if (a % 10 == b % 10) { count += 1; }
	}
	if (count == 3) {
		result = 1;
	}
	return result;
}

int bfs(int start, int end) {
	int depth = -1;
	
    queue<int> qu;
    qu.push(start);
	check[start] = 1;
	
	while (!qu.empty()) {
		depth += 1;
		int size = qu.size();
		for (int i = 0; i < size; i++) {
			int v = qu.front(); qu.pop();
			check[v] = 1;

			if (v == end) {
				return depth;
			}

			for (int i = 0; i < pidx; i++){
				int next = pNum[i];
				if ( isConnected(v, next) && !check[next] ) {
                    qu.push(next);
				}
			}
		}
	}
	
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	
	findPrime();
	
	while(T--) {
		int start, end;
		scanf("%d %d", &start, &end);
		
		int result = bfs(start, end);
		if (result == -1){
			printf("Impossible\n");
		} else {
			printf("%d\n", result);
		}

        for (int i = 0; i < 10001; i++) {
            check[i] = 0;
        }
	}
}
