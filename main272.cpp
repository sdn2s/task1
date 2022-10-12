#include <iostream>
#include <fstream>

int main() 
{
    // объявление потоков для чтения файла и записи в файл
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    // объявление целочисленных переменных
    int inputValue;
    int min = INT_MAX;// хранит максимальное значение
    int max = INT_MIN;// хранит минимальное значение


    // считывание значений файла
    for (int counter = 1; in >> inputValue; counter++) 
    {
        // определение текущего максимума и миниума
        if (max < inputValue && counter % 2 == 0) max = inputValue;
        if (min > inputValue && counter % 2 != 0) min = inputValue;
    }
    in.close();// закрытие потока чтения файла
    
    // если значения не были изменены
    if (min == INT_MAX) min = 0;
    if (max == INT_MIN) max = 0;
    // запись результата в файл
    out << min + max << std::endl;
    out.close();// закрытие потока записи в файл

    return 0;
}