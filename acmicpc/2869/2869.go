package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)

	var a, b, v int64
	fmt.Fscanf(in, "%d %d %d", &a, &b, &v)

	if v-a < 0 {
		fmt.Println(1)
	} else {
		fmt.Println((v-b-1)/(a-b) + 1)
	}
}
