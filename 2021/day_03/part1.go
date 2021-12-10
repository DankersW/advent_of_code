package main

import (
	"io/ioutil"
	"strconv"
	"strings"

	log "github.com/sirupsen/logrus"
)

func findMostCommonBit(i int, data []string) string {
	c0, c1 := 0, 0
	for _, v := range data {
		b := []byte(v)
		if b[i] == 48 {
			c0++
		} else {
			c1++
		}
	}
	if c0 < c1 {
		return "1"
	} else {
		return "0"
	}
}

func invert(s string) string {
	r := ""
	for _, v := range []byte(s) {
		if v == 48 {
			r = r + "1"
		} else {
			r = r + "0"
		}
	}
	return r
}

func part1() {
	content, _ := ioutil.ReadFile("data.txt")
	lines := strings.Split(string(content), "\n")

	gamma := ""
	for i := 0; i < len(lines[0]); i++ {
		gamma = gamma + findMostCommonBit(i, lines)
	}
	episo := invert(gamma)

	gammaInt, _ := strconv.ParseUint(gamma, 2, 64)
	episoInt, _ := strconv.ParseUint(episo, 2, 64)
	log.Infof("gamma: %s, %d", gamma, gammaInt)
	log.Infof("episo: %s, %d", episo, episoInt)
	log.Infof("result: %d", episoInt*gammaInt)
}
