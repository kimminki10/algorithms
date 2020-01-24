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

var endOfWorldNums = make([]int, 10004)

func checkThreepleSix(n int) bool {
	for i := n; i > 0; i /= 10 {
		if i%1000 == 666 {
			return true
		}
	}
	return false
}
func fillNums() {
	count := 1
	for i := 666; count <= 10000; i++ {
		if checkThreepleSix(i) {
			endOfWorldNums[count] = i
			count++
		}
	}
}

func main() {
	defer writer.Flush()
	fillNums()

	var n int
	scanf("%d\n", &n)
	printf("%d\n", endOfWorldNums[n])
}
