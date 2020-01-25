package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)

	var x, y, z int
	for {
		fmt.Fscanf(in, "%d %d %d\n", &x, &y, &z)

		if x == 0 && y == 0 && z == 0 {
			return
		}

		// y 가 제일 큰 경우
		if x < y && z < y {
			y, z = z, y
		} else if y < x && z < x {
			x, z = z, x
		}

		if x*x+y*y == z*z {
			fmt.Println("right")
		} else {
			fmt.Println("wrong")
		}
	}
}
