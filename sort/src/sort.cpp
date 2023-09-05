#include <iostream>
#include "sort/sort.hpp"
#include "sort/utils.hpp"
#include <vector>
namespace sort{
	//codigo del github: quicksort
	//QUICK SORT
	int split_qs(float* A, int i, int j)
	{
		/***
		 * split for quicksort
		 * i,j are the endpoints
		 */
		int p = getRandomInt(i, j);
		while (i  < j) {
			while ( i < p && A[i] <= A[p])
			{
				i = i + 1;
			}
			while ( j > p && A[j] >= A[p])
			{
				j = j - 1;
			}
			swap(A, i, j);
			if (i == p)
			{
				p = j;
			}
			else if (j == p)
			{
				p = i;
			}
		}
		return p;
	}
	void quickSort(float* A, int i, int j)
	{
		if (i < j)
		{
			int k = split_qs(A, i, j);
			quickSort(A, i, k-1);
			quickSort(A, k + 1, j);
		}
	}
	void quickSort(float* A, int n)
	{
		quickSort(A, 0, n - 1);
	}
	//MERGE SORT
	void merge(float *A, int i, int j, int k) 
	{
		int n1 = k - i + 1;
		int n2 = j - k;

		// Crear arreglos temporales
		float L[n1], R[n2];

		// Copiar datos a los arreglos temporales L[] y R[]
		for (int x = 0; x < n1; x++) {
			L[x] = A[i + x];
		}
		for (int y = 0; y < n2; y++) {
			R[y] = A[k + 1 + y];
		}

		// Combinar los arreglos temporales de nuevo en A[i..j]
		int x = 0;
		int y = 0;
		int z = i;

		while (x < n1 && y < n2) 
		{
			if (L[x] <= R[y]) 
			{
				A[z] = L[x];
				x++;
			} 
			else 
			{
				A[z] = R[y];
				y++;
			}
			z++;
		}

		// Copiar los elementos restantes de L[], si los hay
		while (x < n1) 
		{
			A[z] = L[x];
			x++;
			z++;
		}

		// Copiar los elementos restantes de R[], si los hay
		while (y < n2) 
		{
			A[z] = R[y];
			y++;
			z++;
		}
	}

	void mergeSort(float *A, int i, int j) 
	{
		if (i < j) 
		{
			// Encuentra el punto medio
			int k = i + (j - i) / 2;

			// Ordena la primera mitad y la segunda mitad
			mergeSort(A, i, k);
			mergeSort(A, k + 1, j);

			// Combina las dos mitades ordenadas
			merge(A, i, j, k);
		}
	}
	void mergeSort(float *A, int n) 
	{
		mergeSort(A, 0, n-1);
	}
	//INSERTION SORT
	void insertionSort(float *A, int n) 
	{
		for (int i = 1; i < n; i++) 
		{
			float key = A[i];
			int j = i - 1;
			while (j >= 0 && A[j] > key) 
			{
				A[j + 1] = A[j];
				j--;
			}
			A[j + 1] = key;
		}
	}
	//RADIX SORT
	int getMax(int *A, int n) {
		int max = *A; // Inicializa max con el primer elemento del arreglo
		for (int i = 1; i < n; i++) {
			if (*(A + i) > max) { // Accede a los elementos utilizando punteros desplazados
				max = *(A + i);
			}
		}
		return max;
	}

	void countingSort(int *A, int n, int div) {
		int output[n];
		int count[10] = {0};
		for (int i = 0; i < n; i++) {
			count[(*(A + i) / div) % 10]++; // Accede a los elementos utilizando punteros desplazados
		}
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}
		for (int i = n - 1; i >= 0; i--) {
			output[count[(*(A + i) / div) % 10] - 1] = *(A + i); // Accede a los elementos utilizando punteros desplazados
			count[(*(A + i) / div) % 10]--;
		}
		for (int i = 0; i < n; i++) {
			*(A + i) = output[i]; // Accede a los elementos utilizando punteros desplazados
		}
	}

	void radixSort(int *A, int n) {
		int m = getMax(A, n);
		for (int div = 1; m / div > 0; div *= 10) {
			countingSort(A, n, div);
		}
	}
	
}



