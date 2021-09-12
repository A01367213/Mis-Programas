package sin

import "testing"

func benchmarkFactorial(i int, b *testing.B) {
	for n := 0; n < b.N; n++ {
		Factorial(i)
	}
}

func BenchmarkFactorial5(b *testing.B) { benchmarkFactorial(5, b) }
