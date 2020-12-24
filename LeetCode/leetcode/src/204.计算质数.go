package src

// countPrimes 素数筛
func countPrimes(n int) int {
	isNotPrime := make([]bool, n)
	cnt := 0

	for i := 2; i < n; i++ {
		if !isNotPrime[i] {
			cnt++
			for j := i * i; j < n; j += i {
				isNotPrime[j] = true
			}
		}
	}

	return cnt
}
