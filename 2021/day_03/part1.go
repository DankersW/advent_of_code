package main

import (
	"io/ioutil"
	"strings"

	log "github.com/sirupsen/logrus"
)

func part1() {
	content, _ := ioutil.ReadFile("sample.txt")
	lines := strings.Split(string(content), "\n")

	log.Info(lines)
	for _, data := range lines {
		log.Info(data)
	}
}
