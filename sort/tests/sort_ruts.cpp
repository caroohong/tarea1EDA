#include "sort/sort.hpp"
#include "sort/utils.hpp"
#include <chrono>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream> //files
#include <vector>
#include <iomanip> //formato para outfile

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
	string rutafile = "../../data/" + fname;
	char alg = args[2][0];
	ifstream infile(rutafile);
	ofstream outfile(fname + ".sorted");
	if (!infile.is_open())
	{
		cout << "Error: el archivo de entrada no se pudo abrir" << endl;
		return 1;
	}
	vector<float> ruts;
	float rut;
	vector<int>iruts;
	int irut;
	while(infile >> irut)
	{
		ruts.push_back(irut);
		iruts.push_back(irut);
	}
	infile.close();
	
	if (alg == 'I')
	{
		sort::insertionSort(ruts.data(), ruts.size());
		cout << "ordenado con: insertionSort" << endl;
		double insertionTime = sort::get_time(sort::insertionSort, ruts.data(), ruts.size());
		cout << "time: "<< insertionTime <<endl;
	}
	else if (alg == 'M')
	{
		sort::mergeSort(ruts.data(), 0, ruts.size() - 1);
		cout << "ordenado con: mergeSort" << endl;
		double mergeTime = sort::get_time(sort::mergeSort, ruts.data(), ruts.size());
		cout << "time: "<< mergeTime <<endl;
	}
	else if (alg == 'Q')
	{
		sort::quickSort(ruts.data(), ruts.size());
		cout << "ordenado con: quickSort" << endl;
		double quickTime = sort::get_time(sort::quickSort, ruts.data(), ruts.size());
		cout << "time: "<< quickTime <<endl;
	}
	else if (alg == 'R')
	{
		sort::radixSort(iruts.data(), iruts.size());
		cout << "ordenado con: radixSort" << endl;
		double radixTime = sort::get_time(sort::radixSort, iruts.data(), iruts.size());
		cout << "time: "<< radixTime <<endl;
	}
	if (!outfile.is_open())
	{
		cout << "Error: El archivo de salida no se pudo crear" << endl;
	}
	outfile <<std::fixed;
	outfile<<std::setprecision(0);
	for(int i = 0; i < ruts.size(); i++)
	{
		if (alg == 'R') outfile << iruts[i] << endl;
		else outfile << ruts[i] << endl;
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
