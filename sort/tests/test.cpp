#include "sort/sort.hpp"
#include "sort/utils.hpp"
#include <chrono>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream> //files
#include <vector>

long getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> t1,
		std::chrono::time_point<std::chrono::high_resolution_clock> t2){
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	return static_cast<long>(int_ms.count());
}

void testSort(int max_size, int n_sizes){
	int* sizes = sort::linspace(max_size, n_sizes);
	float* A = nullptr;
	int n = 0;
	for (int i = 0; i < n_sizes; i++){
		n = sizes[i];
		A = sort::createRandomIntArray(n, 0, 100);
		auto start = std::chrono::high_resolution_clock::now();
		//change the sort method here
		sort::quickSort(A, n);
		//
		auto end = std::chrono::high_resolution_clock::now();
		long elapsed =  getElapsedTime(start, end);
		sort::deleteArray(A);
		std::cout << " [" << n << "," << elapsed << "]" << std::endl;
	}
	delete[] sizes;
}


//int main(int nargs, char** nvargs){
//	int n_sizes = 10;
//	int max_size = 100000;
//	testSort(max_size, n_sizes);
//	return 0;
//}

using namespace std;
int main(int nargs, char** args){

	std::srand(std::time(nullptr));
	string fname = args[1];
	char alg = args[2][0];
	
	ifstream infile(fname);
	ofstream outfile(fname + ".sorted");

	vector<float> ruts;
	float rut;
	while(infile >> rut)
	{
		ruts.push_back(rut);
	}
	infile.close();
	
	if (alg == 'I')
	{
		sort::insertionSort(ruts.data(), ruts.size());
		cout << "ordenado con: insertionSort" << endl;
	}
	else if (alg == 'M')
	{
		sort::mergeSort(ruts.data(), 0, ruts.size() - 1);
		cout << "ordenado con: mergeSort" << endl;
	}
	else if (alg == 'Q')
	{
		sort::quickSort(ruts.data(), ruts.size());
		cout << "ordenado con: quickSort" << endl;
	}
	else if (alg == 'R')
	{
		sort::radixSort(ruts.data(), ruts.size());
		cout << "ordenado con: radixSort" << endl;
	}
	for(int i = 0; i < ruts.size(); i++)
	{
		outfile << ruts[i] << endl;
	}
	outfile.close();
	cout << "archivo generado: " << fname << ".sorted" << endl;
//	auto start = std::chrono::high_resolution_clock::now();
//	sort::quickSort(A, n);
//	sort::printArray(A, n);
//	sort::deleteArray(A);
//	auto end = std::chrono::high_resolution_clock::now();
//	std::cout<<" Elapsed : " << getElapsedTime(start, end) << std::endl;
	return 0;
}
