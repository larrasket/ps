package main

var boxs [9]map[byte]byte

func whichSubMap(i, j int) int {
	if i < 3 {
		if j < 3 {
			return 0
		}
		if j < 5 {
			return 3
		}

		if j < 9 {
			return 6
		}
	}

	if i < 5 {
		if j < 3 {
			return 1
		}
		if j < 5 {
			return 4
		}

		if j < 9 {
			return 7
		}
	}

	if i < 9 {
		if j < 3 {
			return 2
		}
		if j < 5 {
			return 5
		}

		if j < 9 {
			return 8
		}
	}
	return 0
}

func isValidSudoku(board [][]byte) bool {
	mv := [9]map[byte]byte{}
	mh := [9]map[byte]byte{}

	for i := 0; i < 9; i++ {
		boxs[i] = make(map[byte]byte)
	}


    for i := 0; i < 9; i++ {
        mv[i] = make(map[byte]byte)
        mh[i] = make(map[byte]byte)
    }

	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			if v, ok := mv[i][board[i][j]]; ok && v != byte('.') {
				return false
			}

			mv[i][board[i][j]] = board[i][j]

			if v, ok := mh[j][board[i][j]]; ok && v != byte('.') {
				return false
			}

			mh[j][board[i][j]] = board[i][j]

			s := whichSubMap(i, j)

			if v, ok := boxs[s][board[i][j]]; ok && v != byte('.') {
				return false
			}
			boxs[s][board[i][j]] = board[i][j]

		}
	}

	return true
}
