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

type person struct {
	height int
	weight int
}

type personSlice []person

func (p personSlice) Len() int { return len(p) }
func (p personSlice) Less(i, j int) bool {
	return (p[i].height < p[j].height && p[i].weight <= p[j].weight) ||
		(p[i].height <= p[j].height && p[i].weight < p[j].weight)
}
func (p personSlice) Swap(i, j int) { p[i], p[j] = p[j], p[i] }

func main() {
	var n int
	var people [51]person

	scanf("%d\n", &n)
	for i := 0; i < n; i++ {
		scanf("%d %d\n", &(people[i].height), &(people[i].weight))
	}

	sort.Sort(personSlice(people[:n]))
	fmt.Println(people)
}
