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

type Point struct {
	x, y int
}

type SortBy []Point

func (a SortBy) Len() int      { return len(a) }
func (a SortBy) Swap(i, j int) { a[i], a[j] = a[j], a[i] }
func (a SortBy) Less(i, j int) bool {
	if a[i].x == a[j].x {
		return a[i].y < a[j].y
	} else {
		return a[i].x < a[j].x
	}
}

func main() {
	defer writer.Flush()
	var n int
	scanf("%d\n", &n)

	arr := make(SortBy, n)

	for i := 0; i < n; i++ {
		scanf("%d %d\n", &arr[i].x, &arr[i].y)
	}
	sort.Sort(arr)
	for i := 0; i < n; i++ {
		printf("%d %d\n", arr[i].x, arr[i].y)
	}
}
