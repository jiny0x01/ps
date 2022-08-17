package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scanf("%d", &a)
	fmt.Scanf("%d", &b)
	var pos int
	if a > 0 {
		if b > 0 {
			pos = 1
		} else {
			pos = 4
		}
	} else {
		if b > 0 {
			pos = 2
		} else {
			pos = 3
		}
	}
	fmt.Print(pos)
}
