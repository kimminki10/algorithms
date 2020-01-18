package main

import "bufio"
import "os"
import "fmt"

var erache [10004]int

func findPrime() {
	for i := 2; i <= 10000; i++ {
		if erache[i] == 0 {
			erache[i] = 1
			for j := 2; j*i <= 10000; j++ {
				erache[i*j] = -1
			}
		}
	}
}
func main() {
	findPrime()
	var m, n int
	in := bufio.NewReader(os.Stdin)

	fmt.Fscanf(in, "%d\n%d", &m, &n)
	var s, minimum = 0, n
	for i := m; i <= n; i++ {
		if erache[i] == 1 {
			s += i

			if minimum > i {
				minimum = i
			}
		}
	}

	if s == 0 {
		fmt.Println(-1)
	} else {
		fmt.Printf("%d\n%d", s, minimum)
	}
}
