package sin

func Factorial(number int) uint64 {
	var result uint64 = 1
	for i := 1; i <= number; i++ {
		result *= uint64(i)
	}
	return result
}
