package src

import "fmt"

func singleNumber(nums []int) int {
	nMap := map[int]int{}

	for _, v := range nums {
		nMap[v]++
	}

	for k, v := range nMap {
		if v == 1 {
			return k
		}
	}

	return 0
}

func singleNumberV2(nums []int) int {
	counts := [32]int{}

	for i := 0; i < len(nums); i++ {
		for j := 0; j < 32; j++ {
			counts[j] += nums[i] & 1
			nums[i] >>= 1
		}
	}

	fmt.Println(counts)

	res, m := 0, 3

	for i := 0; i < 32; i++ {
		res <<= 1
		res |= counts[31-i] % m
	}

	return res
}

func singleNumberV3(nums []int) int {
	ones, twos := 0, 0
	for _, v := range nums {
		ones = ones ^ v & ^twos
		twos = twos ^ v & ^ones
	}
	return ones
}
