package main

import (
	"bufio"
	"fmt"
	"os"
)

type Depth struct {
	D int
	V int
}

func calc_bacon(matrix [][]bool, visit []int, next []Depth, n int) {
	if len(next) == 0 {
		return
	}
	cur, next := next[0], next[1:]
	for i := 1; i <= n; i++ {
		if i == cur.V {
			continue
		}
		// matrix[cur][i]랑 친구고 i 방문 안했으면 방문
		// DFS가 아니라 BFS로 풀어야함
		if matrix[cur.V][i] == true {
			if cur.D+1 < visit[i] || visit[i] == 0 {
				visit[i] = cur.D + 1
				next = append(next, Depth{D: cur.D + 1, V: i})

			}
			// 새로 찾은 곳이 더 작은 값이면
		}
	}
	calc_bacon(matrix, visit, next, n)
}

func delicious_bacon(matrix [][]bool, n int) int {

	min_bacon := 200
	result := 0
	// 1~n까지 사람에 대해서 각각의 케빈 베이컨 수를 구해야한다.
	for i := 1; i <= n; i++ {
		visit := make([]int, n+1)
		next := []Depth{
			Depth{
				D: 0,
				V: i,
			},
		}
		sum := 0

		visit[i] = -1
		calc_bacon(matrix, visit, next, n)

		//fmt.Printf("%d: ", i)
		for i := 1; i <= n; i++ {
			if visit[i] == -1 {
				continue
			}
			sum += visit[i]
		}
		//		fmt.Printf("\n%d번쨰 베이컨:%d\n", i, sum)
		if sum < min_bacon {
			min_bacon = sum
			result = i
		}

	}

	return result
}

func print_matrix[T any](matrix [][]T, x, y int) {
	for i := 1; i <= y; i++ {
		for j := 1; j <= x; j++ {
			fmt.Printf("%v ", matrix[i][j])
		}
		fmt.Println("")
	}
}

func main() {
	r := bufio.NewReader(os.Stdin)
	//	w := bufio.NewWriter(os.Stdout)
	var n, m int
	fmt.Fscan(r, &n, &m)

	matrix := make([][]bool, n+1)
	for i := range matrix {
		matrix[i] = make([]bool, n+1)
	}

	for i := 0; i < m; i++ {
		var r1, r2 int
		fmt.Fscan(r, &r1, &r2)
		matrix[r1][r2] = true
		matrix[r2][r1] = true

	}

	fmt.Print(delicious_bacon(matrix, n))
}
