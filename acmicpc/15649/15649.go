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

var n, m int
var arr [][]int

func isChecked(checked []int, num int) bool {
	for _, i := range checked {
		if i == num {
			return true
		}
	}
	return false
}

func printArr(a []int) {
	for _, v := range a {
		printf("%d ", v)
	}
	printf("\n")
}

func permutation(checked []int, n, m int) {
	if m == 0 {
		printArr(checked)
		return
	}
	for i := 1; i <= n; i++ {
		if !isChecked(checked, i) {
			checked = append(checked, i)
			permutation(checked, n, m-1)
			checked = checked[:len(checked)-1]
		}
	}
}

func sizesize(n, m int) (result int) {
	result = 1
	for i := 0; i < m; i++ {
		result *= n - i
	}
	return
}

func main() {
	defer writer.Flush()
	scanf("%d %d\n", &n, &m)

	arrSize := sizesize(n, m)
	arr := make([][]int, arrSize)
	for i := 0; i < arrSize; i++ {
		arr[i] = make([]int, m)
	}

	checked := []int{}
	permutation(checked, n, m)

}
