package src

import (
	"strings"
)

func firstUniqChar(s string) int {
	chSlice := [26]int{}

	for _, c := range s {
		chSlice[c-'a']++
	}

	for k, c := range s {
		if chSlice[c-'a'] == 1 {
			return k
		}
	}

	return -1
}

func firstUniqCharV2(s string) int {
	for k, c := range s {
		if strings.IndexRune(s, c) == strings.LastIndex(s, string(c)) {
			return k
		}
	}

	return -1
}
