package kata

import "fmt"

// func DigitalRoot(n int) int {
// }

func slv(n int, ans *int) int {
	if n <= 0 {
		return 0
	}
	return slv(n/10, ans)
}

func main() {

	var i, ans int = 12, 0
	fmt.Print(slv(i, &ans))

}
