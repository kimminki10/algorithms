package main

import (
	"bufio"
	"fmt"
	"os"
)

var xNum [1003]int
var yNum [1003]int

func main() {
	in := bufio.NewReader(os.Stdin)
	var x, y int
	for i := 0; i < 3; i++ {
		fmt.Fscanf(in, "%d %d\n", &x, &y)
		xNum[x]++
		yNum[y]++
	}

	for i := 0; i <= 1000; i++ {
		if xNum[i]%2 == 1 {
			x = i
		}
		if yNum[i]%2 == 1 {
			y = i
		}
	}
	fmt.Println(x, y)
}
