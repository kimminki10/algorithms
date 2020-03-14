package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func scanf(s string, a ...interface{})  { fmt.Fscanf(in, s, a...) }
func printf(s string, a ...interface{}) { fmt.Fprintf(out, s, a...) }

func isSameColor(x, y, a, b int, ta [][]int) bool {
	color := ta[x][y]
	for i := x; i < a; i++ {
		for j := y; j < b; j++ {
			if color != ta[i][j] {
				return false
			}
		}
	}
	return true
}

var blue = 0
var white = 0

func solve(x, y, a, b int, ta [][]int) {
	if isSameColor(x, y, a, b, ta) {
		if ta[x][y] == 1 {
			blue++
		} else {
			white++
		}
	} else {
		mx := (x + a) / 2
		my := (y + b) / 2
		solve(x, y, mx, my, ta)
		solve(x, my, mx, b, ta)
		solve(mx, y, a, my, ta)
		solve(mx, my, a, b, ta)
	}
}

func main() {
	var n int
	scanf("%d\n", &n)

	ta := make([][]int, n)
	for i := 0; i < n; i++ {
		ta[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			scanf("%d ", &ta[i][j])
		}
	}

	solve(0, 0, n, n, ta)
	printf("%d\n%d\n", white, blue)
	out.Flush()
}
