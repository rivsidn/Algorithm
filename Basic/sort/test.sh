#! /bin/bash

numbers=(0 1 2 3 4 5 6 7 8 9 10 100 1000 10000 100000 1000000)

for num in "${numbers[@]}"; do
	python produce_test_data.py $num
	g++ MergeSort.cpp data.cpp -o MergeSort
	./MergeSort
done
