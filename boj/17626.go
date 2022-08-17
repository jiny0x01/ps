package main

import (
	"fmt"
	"math"
)

func nearSquare(num int) int {
	n := int(math.Round(math.Sqrt(float64(num))))
	for n*n < num {
		n++
	}
	if n*n > num {
		n--
	}
	fmt.Printf("input:%d, n:%d, result:%d\n", num, n, n*n)
	return n * n
}

func main() {
	var num int
	fmt.Scanf("%d", &num)
	cnt := 0

	for num > 0 {
		num -= nearSquare(num)
		fmt.Println(num)
		cnt++
	}
	fmt.Println(cnt)
}
