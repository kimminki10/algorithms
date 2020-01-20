package main

import (
	"bufio"
	"fmt"
	"os"
)

var fibo [21]int

func fillFIbo() {
	fibo[0] = 0
	fibo[1] = 1

	for i := 2; i < 21; i++ {
		fibo[i] = fibo[i-1] + fibo[i-2]
	}
}

func main() {
	fillFIbo()
	in := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanf(in, "%d", &n)
	fmt.Printf("%d\n", fibo[n])
}
