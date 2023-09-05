#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP

namespace sort{
	int split_qs(float* A, int i, int j);
	void quickSort(float* A, int i, int j);
	void quickSort(float* A, int n);
	void merge(float* A, int i, int j, int k);
	void mergeSort(float* A, int i, int j);
	void mergeSort(float* A, int n);
	void insertionSort(float* A, int n);
	//radix:
	int getMax(int *A, int n);
	void countingSort(int *A, int n, int div);
	void radixSort(int* A, int n);
}

#endif
