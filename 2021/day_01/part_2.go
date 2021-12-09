package main

import (
	"io/ioutil"
	"strconv"
	"strings"

	log "github.com/sirupsen/logrus"
)

func toInt(num string) int {
	i, _ := strconv.Atoi(num)
	return i
}

func part2() {
	content, _ := ioutil.ReadFile("data.txt")
	lines := strings.Split(string(content), "\n")

	count := -1
	prev_sum := -1
	for i := 0; i < len(lines)-2; i++ {
		sum := (toInt(lines[i]) + toInt(lines[i+1]) + toInt(lines[i+2]))
		if sum > prev_sum {
			count++
		}
		prev_sum = sum
	}
	log.Info(count)
}
