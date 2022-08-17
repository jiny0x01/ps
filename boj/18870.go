package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)

	var n int
	pos := make(map[int]int)

	fmt.Fscanf(r, "%d", &n)
	for i := 0; i < n; i++ {
		var num int
		fmt.Fscanf(r, "%d", &num)
		pos[i] = num
	}

	for i := range pos {
		fmt.Printf("%d %d\n", i, pos[i])
	}
}
