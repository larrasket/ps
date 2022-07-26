package main

import (
	"strconv"
	"strings"
)

func Is_valid_ip(ip string) bool {
	sgs := strings.Split(ip, ".")
	if len(sgs) != 4 {
		return false
	}
	for _, value := range sgs {
		intg, err := strconv.Atoi(value)
		if (value[0] == '0' && len(value) > 1) || err != nil || intg > 255 || intg < 0 {
			return false
		}
	}
	return true
}
