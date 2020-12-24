package main

import "fmt"

func main() {
	counts := [32]int{}
	for k,v := range counts{
		k = 11
		fmt.Println(v)
		fmt.Println(k)
	}
	fmt.Println(counts)
}
