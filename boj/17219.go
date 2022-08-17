package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var n int
	var m int
	user := make(map[string]string)
	fmt.Scanf("%d %d", &n, &m)
	r := bufio.NewScanner(os.Stdin)
	for i := 0; i < n; i++ {
		r.Scan()
		result := strings.Split(r.Text(), " ")
		user[result[0]] = result[1]
	}
	w := bufio.NewWriter(os.Stdout)
	for i := 0; i < m; i++ {
		r.Scan()
		if pw, ok := user[r.Text()]; ok {
			w.WriteString(pw)
			w.WriteString("\n")
		}
	}
	w.Flush()
}
