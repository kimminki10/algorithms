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

type Person struct {
	age   int
	order int
	name  string
}

type SortBy []Person

func (a SortBy) Len() int      { return len(a) }
func (a SortBy) Swap(i, j int) { a[i], a[j] = a[j], a[i] }
func (a SortBy) Less(i, j int) bool {
	if a[i].age == a[j].age {
		return a[i].order < a[j].order
	}
	return a[i].age < a[j].age
}

func main() {
	defer writer.Flush()
	var n int
	scanf("%d\n", &n)
	arr := make(SortBy, n)

	for i := 0; i < n; i++ {
		scanf("%d %s\n", &arr[i].age, &arr[i].name)
		arr[i].order = i
	}
	sort.Sort(arr)

	for _, i := range arr {
		printf("%d %s\n", i.age, i.name)
	}
}
