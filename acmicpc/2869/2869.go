package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)

	var a, b, v int
	fmt.Fscanf(in, "%d %d %d", &a, &b, &v)
	fmt.Println((v-b-1)/(a-b) + 1)

}
