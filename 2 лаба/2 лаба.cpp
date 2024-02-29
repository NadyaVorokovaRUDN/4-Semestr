#include <iostream>
#include <cstdlib>

class Matrix {
private:
    int** data; // двуерный массив 
    unsigned int m; // коллчиство строк 
    unsigned int n; // коллчиство столбцов 

public:
// Конструктор, принимающий количество строк и столбцов

    Matrix(unsigned int m, unsigned int n) : m(m), n(n) {
        data = new int*[m]; // выделение памяти под массив указателей на строки
        for (unsigned int i = 0; i < m; i++) {
            data[i] = new int[n]; // выделение памяти под каждую строку

        }
    }

// Деструктор для освобождения памяти
    ~Matrix() {
        for (unsigned int i = 0; i < m; i++) {
            delete[] data[i]; // освобождение памяти для каждой строки
        }
        delete[] data;// освобождение памяти для массива указателей на строки
    }
// Перегрузка оператора доступа к элементу по индексу
    int* operator[](unsigned int index) {
        return data[index];
    }

// Метод для заполнения матрицы случайными значениями от 0 до 9
    void fillRandom() {
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < n; j++) {
                data[i][j] = rand() % 10;
            }
        }
    }

// Перегрузка оператора вывода в поток <<
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (unsigned int i = 0; i < matrix.m; i++) {
            for (unsigned int j = 0; j < matrix.n; j++) {
                os << matrix.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

// Перегрузка операторов +=, +, -=, - , *
    Matrix& operator+=(const Matrix& other) {
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < n; j++) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& other) {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < n; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator-=(const Matrix& other) {
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < n; j++) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator-(const Matrix& other) {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < n; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) {
        Matrix result(m, other.n);
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < other.n; j++) {
                result.data[i][j] = 0;
                for (unsigned int k = 0; k < n; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

// Перегрузка операторов != и ==
    bool operator==(const Matrix& other) {
        if (m != other.m || n != other.n) {
            return false;
        }
        for (unsigned int i = 0; i < m; i++) {
            for (unsigned int j = 0; j < n; j++) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix& other) {
        return !(*this == other);
    }
};

int main() {
    Matrix mat1(3, 3);
    Matrix mat2(3, 3);
    mat1.fillRandom();
    mat2.fillRandom();

    std::cout << "Matrix 1:" << std::endl;
    std::cout << mat1;

    std::cout << "Matrix 2:" << std::endl;
    std::cout << mat2;

    Matrix mat3 = mat1 + mat2;
    std::cout << "Matrix 1 + Matrix 2:" << std::endl;
    std::cout << mat3;

    Matrix mat4 = mat1 - mat2;
    std::cout << "Matrix 1 - Matrix 2:" << std::endl;
    std::cout << mat4;

    Matrix mat5 = mat1 * mat2;
    std::cout << "Matrix 1 * Matrix 2:" << std::endl;
    std::cout << mat5;

    if (mat1 == mat2) {
        std::cout << "Matrix 1 and Matrix 2 are equal" << std::endl;
    } else {
        std::cout << "Matrix 1 and Matrix 2 are not equal" << std::endl;
    }

    return 0;
}
