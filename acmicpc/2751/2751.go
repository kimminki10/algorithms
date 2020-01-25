package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var writer = bufio.NewWriter(os.Stdout)
var reader = bufio.NewReader(os.Stdin)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func main() {
	defer writer.Flush()
	var n int

	scanf("%d\n", &n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		scanf("%d\n", &arr[i])
	}

	sort.IntSlice(arr).Sort()
	for i := 0; i < n; i++ {
		printf("%d\n", arr[i])
	}
}
