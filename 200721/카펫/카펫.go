package 카펫

import "math"

func solution(brown int, yellow int) []int {
	answer := make([]int, 2)
	by := brown + yellow
	sb := int(math.Sqrt(float64(by)))
	for i := 3; i <= sb; i++ {
		if by%i == 0 {
			j := by / i
			ii := i - 2
			ij := j - 2
			if yellow == ii*ij && brown == by-yellow {
				answer[0] = j
				answer[1] = i
				return answer
			}
		}
	}

	return []int{}
}
