#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

template <typename T>
void fill_arr(T*& arr, const int length, int low, int hi);

template <typename T>
void show_arr(T*& arr, const int length);

template <typename T>
T* combinTwoArr(T*& arr1, int length1, T*& arr2, int length2);

template <typename T>
void resize_arr(T*& arr, int length, int new_length);

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	srand(time(NULL));

	/*
		Даны два динамических массива A[n] и B[m]. 
	Необходимо создать динамический массив C[n + m], 
	который состоит из элементов массивов A и B. После 
	создания массива C массивы A и B должны быть 
	удалены.
		Two dynamic arrays A[n] and B[m] are given.
	It is necessary to create a dynamic array C[n + m],
	which consists of elements of arrays A and B. After
	creating array C, arrays A and B must be
	deleted.
	*/
	std::cout << "Exercise 1.\nCombining dynamic arrays\n";
	int n, m;
	std::cout << "Enter the size of the array A -> ";
	std::cin >> n;
	std::cout << "Enter the size of the array B -> ";
	std::cin >> m;
	int* A = new int[n];
	int* B = new int[m];
	fill_arr(A, n, 1, 5);
	fill_arr(B, m, 6, 10);
	std::cout << "Array A:\n";
	show_arr(A, n);
	std::cout << "Array B:\n";
	show_arr(B, m);
	int* C = combinTwoArr(A, n, B, m);
	std::cout << "Array C:\n";
	show_arr(C, n + m);
	
	delete[] C;
	

	/*
		Создайте функцию resize_arr, которая принимает 
	динамический массив, текущую длину массива и новую 
	длину массива. Переданный массив меняет свою 
	изначальную длину на новую.
		Create a resize_arr function that accepts
	a dynamic array, the current length of the array, and the new
	length of the array. The passed array changes its
	original length to a new one.
	*/
	{
		std::cout << "\n\n\nExercise 2.\nResize array.\n";
		int length;
		std::cout << "Enter the initial size of  array -> ";
		std::cin >> length;
		int* arr = new int[length];
		fill_arr(arr, length, 1, 10);
		show_arr(arr, length);
		std::cout << "Enter a new size of array -> ";
		int new_length;
		std::cin >> new_length;
		resize_arr(arr, length, new_length);
		show_arr(arr, new_length);
		delete[] arr;
	}
	return 0;
}

template <typename T>
void resize_arr(T*& arr, int length, int new_length) {
	if (length == new_length)
		return;
	T* tmp_arr = new T[new_length]{};
	for (size_t i = 0; i < (new_length > length ? length : new_length); i++){
		tmp_arr[i] = arr[i];
	}
	delete[] arr;
	arr = tmp_arr;
}


template <typename T>
T* combinTwoArr(T*& arr1, int length1, T*& arr2, int length2) {
	T* comb_arr = new T[length1 + length2];
	for (size_t i = 0; i < length1; i++)
	{
		comb_arr[i] = arr1[i];
	}
	for (size_t i = length1, j = 0; i < length1 + length2; i++, j++) {
		comb_arr[i] = arr2[j];
	}
	delete[] arr1;
	delete[] arr2;
	return comb_arr;
}

template <typename T>
void fill_arr(T*& arr, const int length, int low, int hi) {
	for (size_t i = 0; i < length; i++) {
		arr[i] = rand() % (hi + 1 - low) + low;
	}
}

template <typename T>
void show_arr(T*& arr, const int length) {
	std::cout << "[ ";
	bool first = true;
	for (size_t i = 0; i < length; i++) {
		if (!first)
			std::cout << ", ";
		first = false;
		std::cout << arr[i];
	}
	std::cout << " ]\n";
}


