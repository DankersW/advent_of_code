package main

import (
	"io/ioutil"
	"strconv"
	"strings"

	log "github.com/sirupsen/logrus"
)

func part2() {
	content, _ := ioutil.ReadFile("data.txt")
	lines := strings.Split(string(content), "\n")
	//log.Info(lines)

	depth, hor, aim := 0, 0, 0
	for _, line := range lines {
		cmd := strings.Split(line, " ")
		force, _ := strconv.Atoi(cmd[1])

		if cmd[0] == "down" {
			aim = aim + force
		} else if cmd[0] == "up" {
			aim = aim - force
		} else if cmd[0] == "forward" {
			hor = hor + force
			depth = depth + (aim * force)
		}
	}
	log.Infof("hor: %d", hor)
	log.Infof("dep: %d", depth)
	log.Infof("result: %d", hor*depth)
}
