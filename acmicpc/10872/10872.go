package main

import (
	"bufio"
	"fmt"
	"os"
)

func recursiveFactorial(n int) int {
	if n == 1 || n == 0 {
		return 1
	}
	return n * recursiveFactorial(n-1)
}
func main() {
	var n int

	in := bufio.NewReader(os.Stdin)

	fmt.Fscanf(in, "%d\n", &n)

	fmt.Printf("%d", recursiveFactorial(n))
}
