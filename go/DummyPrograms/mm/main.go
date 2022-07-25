package main

import (
	"fmt"
	"time"
)

func PrintTime(label string, t *time.Time) {
	layout := "Month: Jan Year: 2006"
	fmt.Println(label, t.Format(layout))
}
func main() {
	current := time.Now()
	specific := time.Date(1995, time.June, 9, 0, 0, 0, 0, time.Local)
	unix := time.Unix(1433228090, 0)
	PrintTime("Current", &current)
	PrintTime("Specific", &specific)
	PrintTime("UNIX", &unix)

}
