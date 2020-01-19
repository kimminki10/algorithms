package main

import (
	"bufio"
	"fmt"
	"os"
)

var erache [10004]int

func findPrime() {
	for i := 2; i <= 10000; i++ {
		if erache[i] == 0 {
			erache[i] = 1
			for j := 2; j*i <= 10000; j++ {
				erache[i*j] = -1
			}
		}
	}
}

func solve(n int) (int, int) {
	m := n / 2
	for i := m; i >= 2; i-- {
		if erache[i] == 1 && erache[n-i] == 1 {
			return i, n - i
		}
	}
	return -1, -1
}

func main() {
	findPrime()
	in := bufio.NewReader(os.Stdin)

	var t, n int
	fmt.Fscanf(in, "%d\n", &t)

	for ; t > 0; t-- {
		fmt.Fscanf(in, "%d\n", &n)
		fmt.Println(solve(n))
	}
}
