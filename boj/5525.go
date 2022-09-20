package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n, m int
	r := bufio.NewReader(os.Stdin)
	fmt.Fscan(r, &n)
	fmt.Fscan(r, &m)
	var ioi string
	fmt.Fscan(r, &ioi)

	cnt := 0
	for i := 0; i < len(ioi); i++ {
		k := 0
		if ioi[i] == 'O' {
			continue
		}
		// ioi[i] == 'I'일떄
		for i < len(ioi)-2 && ioi[i+1] == 'O' && ioi[i+2] == 'I' {
			k++
			if k == n {
				cnt++
				k--
			}
			i += 2
		}
	}
	fmt.Println(cnt)
}
