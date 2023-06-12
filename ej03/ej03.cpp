/* Tercer Ejericio de Examen

Función GetIndexOf, recibe un valor X, itera en los elementos del RawArray y, si encuentra un elemento con valor X,
regresa la posición P de dicho elemento. Si no, regresa -1.

int GetIndexOf(int x); */

#include <iostream>
#include <vector>

class RawArray {
private:
    std::vector<int> raw_array;

public:
    void addElement(int element) {
        raw_array.push_back(element);
    }

    int getIndexOf(int x) {
        for (int i = 0; i < raw_array.size(); i++) {
            if (raw_array[i] == x) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    RawArray raw_array;
    int array_size;
    std::cout << "Ingrese el tamaño del arreglo: ";
    std::cin >> array_size;

    std::cout << "Ingrese los elementos del arreglo separados por espacios:\n";
    for (int i = 0; i < array_size; i++) {
        int element;
        std::cin >> element;
        raw_array.addElement(element);
    }

    int search_value;
    std::cout << "Ingrese el valor a buscar: ";
    std::cin >> search_value;

    int index = raw_array.getIndexOf(search_value);
    if (index != -1) {
        std::cout << "El valor " << search_value << " se encuentra en la posición " << index << " del arreglo." << std::endl;
    }
    else {
        std::cout << "El valor " << search_value << " no se encuentra en el arreglo." << std::endl;
    }

    return 0;
}