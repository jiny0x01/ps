package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

type pair struct {
	value int
	count int
}

func avg(nums []int) float64 {
	sum := 0
	for _, num := range nums {
		sum += num
	}
	return math.Round(float64(sum) / float64(len(nums)))
}

func mid(nums []int) int {
	copied_nums := make([]int, len(nums))
	copy(copied_nums, nums)
	idx := len(copied_nums) / 2
	sort.Sort(sort.IntSlice(copied_nums))
	return copied_nums[idx]
}

func most(nums []int) int {
	m := make(map[int]int)
	max := 0
	for _, num := range nums {
		m[num]++
		if max < m[num] {
			max = m[num]
		}
	}

	max_slice := []int{}
	//	fmt.Println("max:", max)
	for k, v := range m {
		if v != max {
			continue
		}
		max_slice = append(max_slice, k)
	}
	//fmt.Println(m)
	sort.Sort(sort.IntSlice(max_slice))
	//	fmt.Println(max_slice)
	if len(max_slice) == 1 {
		return max_slice[0]
	}
	return max_slice[1]
}

func num_range(nums []int) int {
	copied_nums := make([]int, len(nums))
	copy(copied_nums, nums)
	sort.Sort(sort.IntSlice(copied_nums))
	return int(math.Abs(float64(copied_nums[0]) - float64(copied_nums[len(copied_nums)-1])))
}

func main() {
	var n int
	fmt.Scanf("%d", &n)

	nums := []int{}
	s := bufio.NewScanner(os.Stdin)
	for i := 0; i < n; i++ {
		s.Scan()
		temp, err := strconv.Atoi(s.Text())
		if err != nil {
			panic(err)
		}
		nums = append(nums, temp)
	}

	average := avg(nums)
	if average == -0 {
		average = 0
	}
	fmt.Println(average)
	fmt.Println(mid(nums))
	fmt.Println(most(nums))
	fmt.Println(num_range(nums))
}
