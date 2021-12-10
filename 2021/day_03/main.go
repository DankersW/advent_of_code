package main

import (
	"io/ioutil"
	"strings"

	log "github.com/sirupsen/logrus"
)

func main() {
	content, _ := ioutil.ReadFile("test.txt")
	lines := strings.Split(string(content), "\n")

	grid := make([][]bool, len(lines))
	log.Info(grid)
	grid[0][1] = true
	log.Info(grid)

	log.Info(lines)
	for y, data := range lines {
		log.Info(y, data)
		for x, val := range []byte(data) {
			log.Info(x, val)
		}
	}

}
