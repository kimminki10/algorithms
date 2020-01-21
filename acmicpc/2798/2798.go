package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader = bufio.NewReader(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

var n, m, result int
var card [102]int

func combi(start, num, sum int) {
	if m < sum || num == 0 || n-start < num {
		return
	}
	if num == 1 && sum > result {
		result = sum
	}

	for i := start + 1; i < n; i++ {
		combi(i, num-1, sum+card[i])
	}
}

func main() {

	scanf("%d %d\n", &n, &m)

	for i := 0; i < n; i++ {
		scanf("%d", &card[i])
	}

	for i := 0; i <= n-3; i++ {
		combi(i, 3, card[i])
	}
	printf("%d\n", result)
	writer.Flush()
}
