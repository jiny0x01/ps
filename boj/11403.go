package main

import (
	"bufio"
	"fmt"
	"os"
)

func print_matrix[T any](matrix [][]T, x, y int) {
	w := bufio.NewWriter(os.Stdout)
	for i := 1; i <= y; i++ {
		for j := 1; j <= x; j++ {
			fmt.Fprintf(w, "%v ", matrix[i][j])
		}
		fmt.Fprint(w, "\n")
	}
	w.Flush()
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(r, &n)

	matrix := make([][]int, n+1)
	for i := range matrix {
		matrix[i] = make([]int, n+1)
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			fmt.Fscan(r, &matrix[i][j])
		}
	}

	for k := 1; k <= n; k++ {
		for i := 1; i <= n; i++ {
			for j := 1; j <= n; j++ {
				// 출발 지점 i번쨰줄의 j값이 있고
				// 중간지점 j번쨰에 k값이 있으면
				if matrix[i][k] == 1 && matrix[k][j] == 1 {
					// 출발지점 i번쨰는 k지점에 도달할 수 있다.
					matrix[i][j] = 1
				}
			}
		}
	}
	print_matrix[int](matrix, n, n)
}

/*

0 1 0
0 0 1
1 0 0

1->3
2->1
3->2

1 1 1
1 1 1
1 1 1




*/
