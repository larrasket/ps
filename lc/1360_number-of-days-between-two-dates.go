package lc

import (
	"math"
	"time"
)

func daysBetweenDates(date1 string, date2 string) int {
	l := "2006-01-02"
	s, _ := time.Parse(l, date1)
	e, _ := time.Parse(l, date2)
	return int(math.Abs(float64(e.Sub(s).Hours() / 24)))
}
