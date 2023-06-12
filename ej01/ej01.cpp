/*Primer Ejercicio del examen:

Asignar valor V a 1 de cada X elementos del RawArray, donde X es un entero.
void AssignEveryXElements(int v, int x); */

#include <iostream>
#include <vector>

class RawArray {
private:
    std::vector<int> arr;

public:
    RawArray(const std::vector<int>& inputArr) : arr(inputArr) {}

    void AssignEveryXElements(int value, int interval) {
        for (int i = interval - 1; i < arr.size(); i += interval) {
            arr[i] = value;
        }
    }

    void printArray() const {
        for (int i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int arrValues[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrSize = sizeof(arrValues) / sizeof(arrValues[0]);
    std::vector<int> inputArr(arrValues, arrValues + arrSize);
    int value, interval;

    // Solicitar al usuario los valores de value y interval
    std::cout << "Ingrese el valor V: ";
    std::cin >> value;
    std::cout << "Ingrese el valor X: ";
    std::cin >> interval;

    RawArray arrObj(inputArr);
    arrObj.AssignEveryXElements(value, interval);

    // Imprimir el arreglo resultante
    arrObj.printArray();

    return 0;
}