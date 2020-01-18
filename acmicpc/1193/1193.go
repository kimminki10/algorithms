package main

import (
	"bufio"
	"fmt"
	"os"
)

func evaluate(y, x int) int {
	if (y+x)%2 == 0 {
		y, x = x, y
	}
	return (y*(y-1)+(2*y+x)*(x-1))/2 + 1
}
func printAnswer(x, ans int) {
	for i := 1; i < ans; i++ {
		if x == evaluate(1+i, ans-i) {
			fmt.Printf("%d/%d", ans-i, 1+i)
			return
		}
	}
}
func main() {
	var x int

	io := bufio.NewReader(os.Stdin)
	fmt.Fscanf(io, "%d", &x)

	var l, r, m, ans, ansV, v int
	l = 1
	r = 4472
	for l <= r {
		m = (r + l) / 2
		v = evaluate(1, m)
		if x <= v {
			ans = m
			ansV = v
			r = m - 1
		} else {
			l = m + 1
		}
	}

	if ansV == x {
		fmt.Printf("%d/1\n", ans)
		return
	}
	m = evaluate(ans, 1)
	if x < m {
		ans = ans - 1
	} else if x == m {
		fmt.Printf("%d/%d", 1, ans)
	}
	printAnswer(x, ans)
}
