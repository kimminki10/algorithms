package main

import (
	"bufio"
	"fmt"
	"os"
)

var erache [300005]int

func findPrime() {
	for i := 2; i < 300005; i++ {
		if erache[i] == 0 {
			erache[i] = 1
			for j := 2; i*j < 300005; j++ {
				erache[i*j] = -1
			}
		}
	}
}

func findNum(num int) int {
	d := 2 * num
	var result int
	for i := num + 1; i <= d; i++ {
		if erache[i] == 1 {
			result++
		}
	}
	return result
}

func main() {
	findPrime()
	in := bufio.NewReader(os.Stdin)

	var num = -1

	for {
		fmt.Fscanf(in, "%d\n", &num)
		if num == 0 {
			return
		}
		fmt.Printf("%d\n", findNum(num))
	}

}
