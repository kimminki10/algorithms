package main

import (
	"bufio"
	"fmt"
	"os"
)

var writer = bufio.NewWriter(os.Stdout)
var reader = bufio.NewReader(os.Stdin)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func main() {
	defer writer.Flush()

	var n int
	scanf("%d\n", &n)

	var h [51]int
	var w [51]int

	for i := 0; i < n; i++ {
		scanf("%d %d\n", &h[i], &w[i])
	}

	for i := 0; i < n; i++ {
		count := 0
		for j := 0; j < n; j++ {
			if w[i] < w[j] && h[i] < h[j] {
				count++
			}
		}
		printf("%d ", count+1)
	}
}
