package main

import (
	"bufio"
	"fmt"
	"os"
)

var dpPrime [10000002]bool

func IsNotPrime(n int) bool {
	if dpPrime[n] == true {
		return false
	}

	var i int
	for i = 2; i*i <= n; i++ {
		if n%i == 0 {
			return true
		}
	}
	dpPrime[n] = true
	return false
}

func Prime(w *bufio.Writer, n int) {
	if n < 2 {
		return
	}
	for i := 2; i*i <= n; i++ {
		if IsNotPrime(i) {
			continue
		}
		if n%i == 0 {
			n /= i
			w.WriteString(string(i))
			w.WriteByte('\n')
			Prime(w, n)
			w.Flush()
			break
		}
	}
}

func main() {
	var n int
	r := bufio.NewReader(os.Stdin)
	fmt.Fscan(r, &n)
	w := bufio.NewWriter(os.Stdout)
	Prime(w, n)
}
