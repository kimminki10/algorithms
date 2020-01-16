package main

import "fmt"

func sum(a []int) int {
	var r int
	for _, n := range a {
		r += n
	}
	return r
}
func main() {

	fmt.Println(sum([]int{1, 2, 3, 4, 5}))
}
