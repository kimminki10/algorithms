package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var a, b, c, r int64

	in := bufio.NewReader(os.Stdin)

	fmt.Fscanf(in, "%d %d %d", &a, &b, &c)
	r = -1
	if c-b > 0 {
		r = a/(c-b) + 1
	}
	fmt.Println(r)
}
