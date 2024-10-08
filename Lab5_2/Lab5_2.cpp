// Lab5_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <cmath>
#include <ctime>   
#include <cstdlib> 
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int rows, cols;
 
    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;

    
    srand(time(0));
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 101 - 50;
        }
    }
    cout << "\nЗгенерований масив:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    int maxAbs = abs(arr[0][0]);
    int maxElement = arr[0][0];
    int maxRow = 0, maxCol = 0; 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (abs(arr[i][j]) > maxAbs) {
                maxAbs = abs(arr[i][j]);
                maxElement = arr[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    cout << "\nНайбільший за модулем елемент: " << maxElement
        << " (модуль = " << maxAbs << ")" << endl;
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}