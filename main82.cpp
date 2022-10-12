#include <iostream>
#include <fstream>


int main()
{
    // объявление потоков для чтения файла и записи в файл
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    
    // одномерный массив и вспомогательные переменные
    int arr[100000];
    int A, B;
    int size1, size2;

    // ввод данных в переменные из файла
    in >> size1 >> size2;
    // обход элементов массива
    for (int i = 0; i < size1; i++)
    {
        in >> A;// чтение элементов из файла
        arr[A] = 1;
    }

    // обход элементов массива
    for (int i = 0; i < size2; i++)
    {
        in >> B;// чтение элементов из файла
        if (arr[B] == 1) arr[B] = 2;
    }

    // запись результата в файл
    for (int i = 0; i < 100000; i++)
        if (arr[i] == 2)out << i << ' ';

    in.close();// закрытие потока чтения файла
    out.close();// закрытие потока записи в файл
    return 0;
}