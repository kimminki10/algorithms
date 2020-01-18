package main

import (
	"bufio"
	"fmt"
	"os"
)

var apart [15][15]int // 층 호

func solve(k, n int) {
	fmt.Println(apart[k][n])
}
func initinit() {
	for i := 1; i <= 14; i++ {
		apart[0][i] = i
	}
	for i := 1; i <= 14; i++ {
		apart[i][1] = 1
		for j := 2; j <= 14; j++ {
			apart[i][j] = apart[i-1][j] + apart[i][j-1]
		}
	}
}

func main() {
	initinit()
	in := bufio.NewReader(os.Stdin)
	var t, k, n int
	fmt.Fscanf(in, "%d", &t)
	for ; t > 0; t-- {
		fmt.Fscanf(in, "\n%d\n%d", &k, &n)
		solve(k, n)
	}
}
