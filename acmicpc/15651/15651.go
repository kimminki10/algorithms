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

func solve(arr []int, n, m int) {
	if m == 0 {
		for _, v := range arr {
			printf("%d ", v)
		}
		printf("\n")
		return
	}
	for i := 1; i <= n; i++ {
		arr = append(arr, i)
		solve(arr, n, m-1)
		arr = arr[:len(arr)-1]
	}
}

func main() {
	defer writer.Flush()
	var n, m int
	scanf("%d %d\n", &n, &m)
	arr := []int{}
	solve(arr, n, m)
}
