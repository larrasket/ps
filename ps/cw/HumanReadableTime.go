package kata

import "strconv"

func HumanReadableTime(seconds int) string {
	hours, minutes := 0, 0
	for seconds >= 3600 {
		hours = seconds / 3600
		seconds = seconds % 3600
	}
	for seconds >= 60 {
		minutes = seconds / 60
		seconds = seconds % 60
	}

	shours, sminutes, sseconds := "00", "00", "00"
	if hours <= 9 {
		shours = strconv.Itoa(hours)
	} else {
		shours = strconv.Itoa(hours)
	}

	if minutes <= 9 {
		sminutes = "0" + strconv.Itoa(minutes)
	} else {
		sminutes = strconv.Itoa(minutes)
	}

	if seconds <= 9 {
		sseconds = "0" + strconv.Itoa(seconds)
	} else {
		sseconds = strconv.Itoa(seconds)
	}

	return shours + ":" + sminutes + ":" + sseconds

}
