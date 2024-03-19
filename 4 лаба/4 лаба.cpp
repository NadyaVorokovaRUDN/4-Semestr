#include <iostream>

// Шаблон функции поиска второго максимума в массиве
template <typename T>
int findSecondMax(T* arr, int size) {
    if (size < 2) {
        return -1; // возвращаем -1, если размер массива меньше двух
    }
    
    int maxIndex = 0;
    int secondMaxIndex = -1;
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            secondMaxIndex = maxIndex;
            maxIndex = i;
        } else if (secondMaxIndex == -1 || arr[i] > arr[secondMaxIndex]) {
            secondMaxIndex = i;
        }
    }
    
    return secondMaxIndex;
}

// Шаблон класса Matrix
template <typename T>
class Matrix {
private:
    int rows;
    int cols;
    T** data;
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    T& operator()(int row, int col) {
        return data[row][col];
    }
};

// Шаблон класса Vector
template <typename T>
class Vector {
private:
    int size;
    T* data;
public:
    Vector(int size) : size(size) {
        data = new T[size];
    }

    ~Vector() {
        delete[] data;
    }

    T& operator[](int index) {
        return data[index];
    }

    T dotProduct(Vector<T>& other) {
        T result = 0;
        for (int i = 0; i < size; i++) {
            result += data[i] * other[i];
        }
        return result;
    }

    T scalarProduct(Vector<T>& other) {
        return dotProduct(other);
    }
};

// Функция для тестирования всех функциональностей
void testFunctionality() {
    int intArr[] = {3, 5, 2, 7, 1};
    std::cout << "Индекс второго максимального элемента в  int : " << findSecondMax(intArr, 5) << std::endl;
    
    float floatArr[] = {1.5, 3.7, 2.1, 4.9, 0.8};
    std::cout << "Индекс второго максимального элемента в float : " << findSecondMax(floatArr, 5) << std::endl;
    
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    std::cout << "Индекс второго максимального элемента в char : " << findSecondMax(charArr, 5) << std::endl;

    Matrix<float> mat(3, 2);
    mat(0, 0) = 1.5;
    mat(0, 1) = 2.3;
    mat(1, 0) = 4.7;
    mat(1, 1) = 3.2;
    mat(2, 0) = 2.1;
    mat(2, 1) = 5.9;
    
    std::cout << mat(1, 0) << std::endl;

    Vector<int> vec1(3);
    vec1[0] = 2;
    vec1[1] = 3;
    vec1[2] = 4;

    Vector<int> vec2(3);
    vec2[0] = 1;
    vec2[1] = 2;
    vec2[2] = 3;

    std::cout << "Вектороное произведение: " << vec1.dotProduct(vec2) << std::endl;
    std::cout << "Скалярное произведение: " << vec1.scalarProduct(vec2) << std::endl;
}

int main() {
    testFunctionality();

    return 0;
}
