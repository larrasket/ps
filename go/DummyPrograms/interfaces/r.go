package main

type Service struct {
	description    string
	durationMonths int
	monthlyFee     float64
	features       []string
}

type Product struct {
	description    string
	durationMonths int
	monthlyFee     float64
	features       []string
}

func (s Product) getName() string {
	return s.description
}
func (s Product) getCost(recur bool) float64 {
	if recur {
		return s.monthlyFee * float64(s.durationMonths)
	}
	return s.monthlyFee
}

func (s Service) getName() string {
	return s.description
}
func (s Service) getCost(recur bool) float64 {
	if recur {
		return s.monthlyFee * float64(s.durationMonths)
	}
	return s.monthlyFee
}
