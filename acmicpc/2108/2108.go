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

func sumsum(arr []int) (result int) {
	for _, i := range arr {
		result += i
	}
	return
}

func frequency(arr []int, n int) int {
	// arr must be sorted
	frequent1 := make([]int, 2)
	frequent2 := make([]int, 2)
	c := make([]int, 2)
	c[0] = arr[0]
	for i := 0; i < n; i++ {
		if c[0] == arr[i] {
			c[1]++
		} else {
			c[0] = arr[i]
			c[1] = 1
		}

		if frequent1[1] < c[1] {
			frequent1[0] = c[0]
			frequent1[1] = c[1]
		} else if frequent2[1] < c[1] {
			frequent2[0] = c[0]
			frequent2[1] = c[1]
		}
	}

	if frequent1[1] == frequent2[1] {
		if frequent1[0] < frequent2[0] {
			return frequent2[0]
		}
		return frequent1[0]
	}
	if frequent1[1] < frequent2[1] {
		return frequent2[0]
	}
	return frequent1[0]
}

func main() {
	defer writer.Flush()

	var n int
	scanf("%d\n", &n)

	arr := make([]int, n)

	for i := 0; i < n; i++ {
		scanf("%d\n", &arr[i])
	}
	sort.IntSlice(arr).Sort()

	printf("%.f\n", float64(sumsum(arr))/float64(n))
	printf("%d\n", arr[n/2])
	printf("%d\n", frequency(arr, n))
	printf("%d\n", arr[n-1]-arr[0])
}
