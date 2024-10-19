#! /bin/bash

set -e

numbers=(100 1000 10000 100000 1000000 0 1 2 3 4 5 6 7 8 9 10)

merge_sort_test() {
	for num in "${numbers[@]}"; do
		python produce_test_data.py $num
		g++ MergeSort.cpp data.cpp -o MergeSort; ./MergeSort
	done
}

quick_sort_test() {
	for num in "${numbers[@]}"; do
		python produce_test_data.py $num
		g++ QuickSort.cpp data.cpp -o QuickSort; ./QuickSort
	done
}

case $1 in
	merge_sort)
		merge_sort_test
		;;
	quick_sort)
		quick_sort_test
		;;
	*)
		echo "None matched"
		;;
esac
