package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var s [20]int
	var n int
	fmt.Scan(&n)

	w := bufio.NewWriter(os.Stdout)
	r := bufio.NewScanner(os.Stdin)
	for i := 0; i < n; i++ {
		r.Scan()
		result := strings.Split(r.Text(), " ")
		if result[0] == "empty" {
			for j := 0; j < 20; j++ {
				s[j] = 0
			}
		} else if result[0] != "all" {
			num, _ := strconv.Atoi(result[1])
			if result[0] == "add" {
				s[num-1] = 1
			} else if result[0] == "remove" {
				s[num-1] = 0
			} else if result[0] == "check" {
				if s[num-1] > 0 {
					w.WriteString("1\n")
				} else {
					w.WriteString("0\n")
				}
			} else if result[0] == "toggle" {
				if s[num-1] > 0 {
					s[num-1] = 0
				} else {
					s[num-1] = 1
				}
			}
		} else {
			for j := 0; j < 20; j++ {
				s[j] = 1
			}
		}
	}
	w.Flush()
}
