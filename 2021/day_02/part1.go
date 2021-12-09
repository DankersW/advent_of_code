package main

import (
	"io/ioutil"
	"strconv"
	"strings"

	log "github.com/sirupsen/logrus"
)

func parser(cmd string) (int, int) {
	s := strings.Split(cmd, " ")
	force, _ := strconv.Atoi(s[1])
	if s[0] == "forward" {
		return force, 0
	} else if s[0] == "down" {
		return 0, force
	} else if s[0] == "up" {
		return 0, force * -1
	}
	log.Error("failed return")
	return 0, 0
}

func part1() {
	content, _ := ioutil.ReadFile("data.txt")
	lines := strings.Split(string(content), "\n")
	//log.Info(lines)

	depth, hor := 0, 0
	for _, line := range lines {
		//log.Info(line)
		posH, posD := parser(line)
		depth = depth + posD
		hor = hor + posH
	}
	log.Infof("hor: %d", hor)
	log.Infof("dep: %d", depth)
	log.Infof("result: %d", hor*depth)
}
