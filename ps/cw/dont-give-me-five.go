package kata

import (
	"fmt"
	"math"
)

func DontGiveMeFive(start int, end int) int {
	return int(math.Round(float64(start/5)) - math.Round(float64(end/5)))
}
