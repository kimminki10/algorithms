package main

import (
	"bufio"
	"fmt"

	"math"
	"os"
)

var out = bufio.NewWriter(os.Stdout)

func hanoi(s, d int, n float64) {
	if n == 1 {
		fmt.Fprintf(out, "%d %d\n", s, d)
		return
	}
	m := 6 - s - d
	hanoi(s, m, n-1)
	hanoi(s, d, 1)
	hanoi(m, d, n-1)
}

func main() {
	in := bufio.NewReader(os.Stdin)

	var n float64
	fmt.Fscanf(in, "%f\n", &n)
	fmt.Fprintf(out, "%.0f\n", math.Pow(2.0, n)-1)
	hanoi(1, 3, n)
	out.Flush()
}
