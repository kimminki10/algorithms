package main

import (
	"bufio"
	"fmt"
	"os"
)

var table [3000][3000]int

func solve(y, x, size int) {
	if size == 1 {
		table[y][x] = 1
		return
	}

	l := size / 3

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if i == 1 && j == 1 {
				continue
			}
			solve(y+l*i, x+l*j, l)
		}
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	var n int
	fmt.Fscanf(in, "%d\n", &n)
	solve(0, 0, n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if table[i][j] == 1 {
				fmt.Fprintf(out, "*")
			} else {
				fmt.Fprintf(out, " ")
			}

		}
		fmt.Fprintf(out, "\n")
	}
	out.Flush()
}
