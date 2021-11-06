// Лабораторная работа №8 Задание 2 Вариант 9
//
// Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). 
// Упорядочить последовательность по неубыванию произведения цифр числа, 
// числа с одинаковыми произведениями цифр дополнительно упорядочить по неубыванию первой цифры числа, 
// числа с одинаковыми произведениями цифр и одинаковыми первыми цифрами дополнительно упорядочить по неубыванию самого числа.
// 
// Переделайте задания 2 и 3 из лабораторной работы №4 своего варианта, разместив массивы в динамической памяти. 
// Размеры массивов задавайте согласно введенным данным.

#include <iostream>

void printArray(int* array, int array_length) {
	for (int i = 0; i < array_length-1; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << array[array_length-1] << std::endl;
}

int productOfDigits(int number) {
	int product = 1;
	while (number / 10 != 0) {
		product *= number % 10;
		number = number / 10;
	}
	product *= number;
	return product;
}

int findFirstDigit(int number) {
	while (number / 10 != 0) {
		number /=  10;
	}
	return number;
}

int main()
{
	int arr_length;
	std::cin >> arr_length;

	int* arr = new int[arr_length];
	int* arr_pofd = new int[arr_length];

	for (int i = 0; i < arr_length; i++) {
		std::cin >> arr[i];
		arr_pofd[i] = productOfDigits(arr[i]);
	}

	for (int i = 0; i < arr_length - 1; i++) {
		for (int j = i + 1; j < arr_length; j++) {
			if (arr_pofd[i] > arr_pofd[j] ||
				arr_pofd[i] == arr_pofd[j] && findFirstDigit(arr[i]) > findFirstDigit(arr[j]) ||
				arr_pofd[i] == arr_pofd[j] && findFirstDigit(arr[i]) == findFirstDigit(arr[j]) && arr[i] > arr[j]) {
				std::swap(arr[i], arr[j]);
				std::swap(arr_pofd[i], arr_pofd[j]);
			}
		}
	}

	printArray(arr, arr_length);
	printArray(arr_pofd, arr_length);

	delete[] arr;
	delete[] arr_pofd;
}