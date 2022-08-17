package main

import (
	"bufio"
	"fmt"
	"os"
)

func PrintMaze(maze [][]int, n, m int) {
	w := bufio.NewWriter(os.Stdout)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			fmt.Fprintf(w, "%d", maze[i][j])
		}
		fmt.Fprint(w, "\n")
	}
	w.Flush()
}

func InitMaze(n, m int) [][]int {
	maze := make([][]int, n)
	for i := 0; i < n; i++ {
		maze[i] = make([]int, m)
	}
	return maze
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Fscanf(r, "%d", &n)
	fmt.Fscanf(r, "%d", &m)

	maze := InitMaze(n, m)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			fmt.Fscanf(r, "%d", &maze[i][j])
		}
	}
	fmt.Println("result\n")
	PrintMaze(maze, n, m)
}
