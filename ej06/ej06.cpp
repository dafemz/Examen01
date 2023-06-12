/* Sexto Ejercicio de Examen

Funci�n Insert.
void Insert(RawArray arrayToInsert, int startIndex);
a�ade los arrayToInsert.Size-elementos al RawArray que llam� la funci�n Insert,
 a partir del elemento en startIndex.

*/

#include <iostream>
#include <vector>

class RawArray {
private:
    std::vector<int> data;

public:
    RawArray(int size) {
        data.resize(size, 0);
    }

    void init(int value) {
        std::fill(data.begin(), data.end(), value);
    }

    void insert(const RawArray& arrayToInsert, int startIndex) {
        if (startIndex < 0 || startIndex > data.size()) {
            std::cout << "�ndice de inicio inv�lido" << std::endl;
            return;
        }

        std::vector<int> newData(data.size() + arrayToInsert.data.size());

        // Copiar los elementos antes del �ndice de inicio
        std::copy(data.begin(), data.begin() + startIndex, newData.begin());

        // Copiar los elementos de arrayToInsert
        std::copy(arrayToInsert.data.begin(), arrayToInsert.data.end(), newData.begin() + startIndex);

        // Copiar los elementos despu�s del �ndice de inicio
        std::copy(data.begin() + startIndex, data.end(), newData.begin() + startIndex + arrayToInsert.data.size());

        // Actualizar los datos del RawArray
        data = newData;
    }

    void print() const {
        std::cout << "[";
        for (size_t i = 0; i < data.size(); i++) {
            std::cout << data[i];
            if (i != data.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    int size1, size2;

    std::cout << "Ingrese el tama�o del primer RawArray: ";
    std::cin >> size1;

    std::cout << "Ingrese el tama�o del segundo RawArray: ";
    std::cin >> size2;

    RawArray myArray(size1);
    RawArray toBeInserted(size2);

    int value;

    std::cout << "Ingrese el valor para inicializar el primer RawArray: ";
    std::cin >> value;
    myArray.init(value);

    std::cout << "Ingrese el valor para inicializar el segundo RawArray: ";
    std::cin >> value;
    toBeInserted.init(value);

    int startIndex;
    std::cout << "Ingrese el �ndice de inicio: ";
    std::cin >> startIndex;

    myArray.insert(toBeInserted, startIndex);

    std::cout << "El resultado es: ";
    myArray.print();

    return 0;
}