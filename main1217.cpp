#include <iostream>
#include <fstream>


int main()
{
	// объявление потоков для чтения файла и записи в файл
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	// объявление массива и целочисленных переменных
	int arr[1000];// массив из 1000 элементов
	int size;// размер массива

	// ввод значений в переменные из файла
	in >> size;
	in >> arr[0];

	int x = arr[0];
	int y = arr[0];

	// обход каждого значения файла и запись значения в массив
	for (int i = 1; i < size; i++)
	{
		in >> arr[i];// запись значения в массив
		if (arr[i] > x) x = arr[i];
		else if (arr[i] < y) y = arr[i];
	}

	// обход каждого элемента массива и запись значения в файл
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x) arr[i] = y;
		out << arr[i] << ' ';
	}

	in.close();//  закрытие потока чтения файла
	out.close();// закрытие потока записи в файл
	return 0;
}