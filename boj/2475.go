package main

import (
	"fmt"
	"math"
)

func main() {
	sum := 0
	temp := 0
	for i := 0; i < 5; i++ {
		fmt.Scan(&temp)
		sum += int(math.Pow(float64(temp), 2))
	}
	fmt.Print(sum % 10)
}
