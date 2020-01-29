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

var n int
var opName = [4]string{"+", "-", "*", "/"}
var opList [4]int
var numList []int
var minmin, maxmax int

func calc(a, b int, op string) int {
	switch op {
	case "+":
		return a + b
	case "-":
		return a - b
	case "*":
		return a * b
	case "/":
		return a / b
	default:
		return 0
	}
}

func solve(num, result int) {
	if num == n {
		if result > maxmax {
			maxmax = result
		}
		if result < minmin {
			minmin = result
		}
		return
	}
	for i := 0; i < 4; i++ {
		if opList[i] > 0 {
			opList[i]--
			r := calc(result, numList[num], opName[i])
			solve(num+1, r)
			opList[i]++
		}
	}
	return
}

func main() {
	defer writer.Flush()
	scanf("%d\n", &n)
	numList = make([]int, n)

	for i := 0; i < n; i++ {
		scanf("%d ", &numList[i])
	}

	scanf("%d %d %d %d\n", &opList[0], &opList[1], &opList[2], &opList[3])

	maxmax = -10e9
	minmin = 10e9
	solve(1, numList[0])
	printf("%d\n%d\n", maxmax, minmin)
}
