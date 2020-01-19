package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	var n float64
	fmt.Fscanf(in, "%f\n", &n)

	fmt.Printf("%f\n%f", n*n*math.Pi, n*n*2)
}
