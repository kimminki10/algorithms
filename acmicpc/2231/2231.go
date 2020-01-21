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

func concon(n int) int {
	result := n
	for ; n > 0; n /= 10 {
		result = result + n%10
	}
	return result
}
func main() {
	defer writer.Flush()
	var n int

	scanf("%d", &n)
	for i := 1; i < n; i++ {
		if n == concon(i) {
			printf("%d", i)
			return
		}
	}
	printf("0")
}
