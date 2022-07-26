package main

import (
	// "errors"
	"fmt"
	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

func main() {
	dsn := "host=localhost user=postgres password=gorm dbname=template4 port=5432 sslmode=disable TimeZone=Africa/Cairo"
	db, err := gorm.Open(postgres.Open(dsn), &gorm.Config{})
	fmt.Println(db.Error)
	fmt.Println("fuck")
	s := err.Error()
	fmt.Println(s)
	switch t := err.(type) {
	default:
		fmt.Println("not a model missing error", t)
	}

}
