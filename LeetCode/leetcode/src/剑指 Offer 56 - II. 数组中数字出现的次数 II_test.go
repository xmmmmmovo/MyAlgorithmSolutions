package src

import "testing"

func Test_singleNumber(t *testing.T) {
	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{"1", args{nums: []int{3, 4, 3, 3}}, 4},
		{"1", args{nums: []int{9, 1, 7, 9, 7, 9, 7}}, 1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := singleNumber(tt.args.nums); got != tt.want {
				t.Errorf("singleNumber() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_singleNumberV2(t *testing.T) {
	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{"1", args{nums: []int{3, 4, 3, 3}}, 4},
		{"1", args{nums: []int{9, 1, 7, 9, 7, 9, 7}}, 1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := singleNumberV2(tt.args.nums); got != tt.want {
				t.Errorf("singleNumberV2() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_singleNumberV3(t *testing.T) {
	type args struct {
		nums []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{"1", args{nums: []int{3, 4, 3, 3}}, 4},
		{"1", args{nums: []int{9, 1, 7, 9, 7, 9, 7}}, 1},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := singleNumberV3(tt.args.nums); got != tt.want {
				t.Errorf("singleNumberV3() = %v, want %v", got, tt.want)
			}
		})
	}
}