package main

import (
	"fmt"
	"log"
	"os"
	"path/filepath"
)

func main() {

	cwd, err := os.Getwd()
	println(cwd)

	if err != nil {
		log.Fatal(err)
	}

	dir, file := filepath.Split(cwd)

	fmt.Printf("Directory: %s\n", dir)
	fmt.Printf("File: %s\n", file)

	home, err := os.UserHomeDir()

	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("-------------------------")

	dir, file = filepath.Split(home)

	fmt.Printf("Directory: %s\n", dir)
	fmt.Printf("File: %s\n", file)

	path_env := os.Getenv("PATH")
	paths := filepath.SplitList(path_env)

	for _, p := range paths {
		fmt.Println(p)
	}
}
