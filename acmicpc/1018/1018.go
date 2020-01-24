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

var table [51]string
var n, m int

func toggleC(c *byte) {
	if *c == 'W' {
		*c = 'B'
	} else {
		*c = 'W'
	}
}

func check(i, j, m int, start byte) (result int) {
	c := start
	for k := i; k < i+8; k++ {
		for l := j; l < j+8; l++ {
			if table[k][l] == c {
				result++
			}
			if result >= m {
				return
			}
			toggleC(&c)
		}
		toggleC(&c)
	}
	return
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	defer writer.Flush()

	scanf("%d %d\n", &n, &m)

	for i := 0; i < n; i++ {
		scanf("%s\n", &table[i])
	}

	var minmin = 2500
	for i := 0; i <= n-8; i++ {
		for j := 0; j <= m-8; j++ {
			r := min(check(i, j, minmin, 'W'),
				check(i, j, minmin, 'B'))
			if minmin > r {
				minmin = r
			}
		}
	}
	printf("%d\n", minmin)
}
