package main

import (
	"bufio"
	"fmt"
	"os"
)

func PrintQueue(doc, m int) {

}

func main() {
	var n int
	fmt.Scan(&n)

	r := bufio.NewReader(os.Stdin)
	for i := 0; i < n; i++ {
		var doc, m int
		fmt.Fscanf(r, "%d %d", &doc, &m)
		PrintQueue(doc, m)
	}
}
