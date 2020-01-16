package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n, max, index int

	in := bufio.NewReader(os.Stdin)

	for i := 1; ; i++ {
		if _, err := fmt.Fscan(in, &n); err != nil {
			break
		}

		if max < n {
			index = i
			max = n
		}
	}
	fmt.Println(max)
	fmt.Println(index)
}
