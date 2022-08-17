package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(r *bufio.Reader, n int) int {
	m := make(map[string][]string)
	var s1, s2 string
	for i := 0; i < n; i++ {
		fmt.Fscanf(r, "%s %s", &s1, &s2)
		//		if _, exist := m[s2]; !exist {
		//			m[s2] = make([]string, 1)
		//		}
		//		m[s2] = append(m[s2], s1)
		fmt.Printf("s1:%s, s2:%s\n", s1, s2)
	}
	fmt.Printf("map:%q\n", m)
	return 1
}

func main() {
	var t, n int
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	fmt.Fscanf(r, "%d", &t)
	for ; t > 0; t-- {
		fmt.Fscanf(r, "%d", &n)
		fmt.Fprintf(w, "%d\n", solve(r, n))
	}
	w.Flush()
	fmt.Println("Hello World;")
}
