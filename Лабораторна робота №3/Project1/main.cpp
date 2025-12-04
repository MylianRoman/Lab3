#include <windows.h>
#include "RealNumbers.cpp"

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    try {
        RealNumbers set1({ 1.2, 3.4, 5.6 });
        RealNumbers set2({ 2.0, 1.1, 3.0 });

        // Демонстрація додавання
        RealNumbers sum = set1 + set2;

        // Демонстрація знаходження максимального та мінімального значення
        std::cout << "Максимум в set1: " << set1.findMax() << std::endl;
        std::cout << "Мінімум в set2: " << set2.findMin() << std::endl;

        // Демонстрація ділення
        RealNumbers division = set1 / set2;

    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}