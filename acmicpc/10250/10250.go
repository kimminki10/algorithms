package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(h, w, n int) {
	if n%h == 0 {
		fmt.Printf("%d%02d\n", h, n/h)
	} else {
		fmt.Printf("%d%02d\n", n%h, n/h+1)
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	var t, h, w, n int
	fmt.Fscanf(in, "%d", &t)
	for ; t > 0; t-- {
		fmt.Fscanf(in, "\n%d %d %d", &h, &w, &n)

		solve(h, w, n)
	}
}
