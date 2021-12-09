package main

import (
	"io/ioutil"
	"strconv"
	"strings"

	log "github.com/sirupsen/logrus"
)

func part1() {
	content, _ := ioutil.ReadFile("data_1.txt")
	lines := strings.Split(string(content), "\n")
	log.Info(lines)

	count := -1
	prev_val := -1
	for _, val := range lines {
		number, _ := strconv.Atoi(val)
		if number > prev_val {
			count++
		}
		prev_val = number
	}
	log.Info(count)
}
