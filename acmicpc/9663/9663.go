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

var table [][]int
var n int

func isPossible(x, y int) bool {
	for i := 0; i <= x; i++ {
		if table[i][y] == 1 {
			return false
		}
		if x-i >= 0 && y-i >= 0 && table[x-i][y-i] == 1 {
			return false
		}
		if x-i >= 0 && y+i < n && table[x-i][y+i] == 1 {
			return false
		}
	}
	return true
}

func putput(x, y int) (result int) {
	table[x][y] = 1
	if x == n-1 {
		return 1
	}
	for i := 0; i < n; i++ {
		if isPossible(x+1, i) {
			result += putput(x+1, i)
			table[x+1][i] = 0
		}
	}
	return
}

func main() {
	defer writer.Flush()
	scanf("%d\n", &n)

	table = make([][]int, n)
	for i := 0; i < n; i++ {
		table[i] = make([]int, n)
	}

	result := 0
	for i := 0; i < n; i++ {
		result += putput(0, i) // 첫째줄부터 간다
		table[0][i] = 0
	}
	printf("%d\n", result)
}
