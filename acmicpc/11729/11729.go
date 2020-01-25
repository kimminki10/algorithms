package main

import (
	"bufio"
	"fmt"
	"os"
)

func movemove(a, b, size int) {
	if size == 1 {
		return
	}
	movemove((b+1)%3, (a+1)%3, size-1)

}

func main() {
	in := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscanf(in, "%d\n", &n)
	movemove(1, 3, n)
}
