package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)


func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	seq := []int{}
	for i := 0; i < n; i++ {
		sc.Scan()
		num, _ := strconv.Atoi(sc.Text())
		seq = append(seq, num)
	}
	fmt.Println("input ok. seq:", seq)
	stack := []int{}
	visit := make([]int, n)
	result := []rune{}
	head := 1
	for i:=0; i<len(seq); i++{
		if head < seq[i] {
			// head을 seq[i]랑 같아져야함
			for ;head<=seq[i]; head++ {
				if visit[head] != 0 { // 방문 했으면 쫑
					fmt.Println("NO")
					fmt.Println("head:",head)
					fmt.Println("stack head:", stack[len(stack)-1])
					fmt.Println("result:", result)
					return
				}
				visit[head] = 1
				stack = append(stack, head)
				result = append(result, '+')
			}
		} else if stack[len(stack)-1] > seq[i] { // stack에서 빼기만 하면 됨
			for j:=len(stack)-1; stack[j]>seq[i]; j-- {
				stack = stack[:j-1]
				result = append(result, '-')
			}
		}
		if stack[len(stack)-1] == seq[i] {
			stack = stack[:len(stack)-1]
			result = append(result, '-')
		}
	}

	w := bufio.NewWriter(os.Stdout)
	for _, r := range result {
		w.WriteRune(r)
		w.WriteRune('\n')
	}
	w.Flush()
}

/*
*/
