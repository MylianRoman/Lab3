#include <iostream>
#include <stdexcept>
#include <vector>
#include <windows.h>

using namespace std;

class RealNumbers {
private:
    double number;

public:
    RealNumbers() : number(0.0) {}

    RealNumbers(double num) : number(num) {}

    double getNumber() const {
        return number;
    }

    void setNumber(double num) {
        number = num;
    }

    static RealNumbers findMax(const vector<RealNumbers>& numbers) {
        if (numbers.empty()) {
            throw invalid_argument("The array must not be empty.");
        }

        RealNumbers maxNumber = numbers[0];
        for (const auto& num : numbers) {
            if (num.getNumber() > maxNumber.getNumber()) {
                maxNumber = num;
            }
        }
        return maxNumber;
    }

    static RealNumbers findMin(const vector<RealNumbers>& numbers) {
        if (numbers.empty()) {
            throw invalid_argument("The array must not be empty.");
        }

        RealNumbers minNumber = numbers[0];
        for (const auto& num : numbers) {
            if (num.getNumber() < minNumber.getNumber()) {
                minNumber = num;
            }
        }
        return minNumber;
    }

    ~RealNumbers() {
        //cout << "The RealNumbers object has been destroyed.\n";
    }
};

RealNumbers operator+(const RealNumbers& num1, const RealNumbers& num2) {
    return { num1.getNumber() + num2.getNumber() };
}

RealNumbers operator-(const RealNumbers& num1, const RealNumbers& num2) {
    return { num1.getNumber() - num2.getNumber() };
}

RealNumbers operator*(const RealNumbers& num1, const RealNumbers& num2) {
    return { num1.getNumber() * num2.getNumber() };
}

RealNumbers operator/(const RealNumbers& num1, const RealNumbers& num2) {
    if (num2.getNumber() == 0.0) {
        throw invalid_argument("Division by zero is impossible");
    }
    return { num1.getNumber() / num2.getNumber() };
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<RealNumbers> numbers = {
        RealNumbers(3.5),
        RealNumbers(1.2),
        RealNumbers(5.8)
    };

    try {
        RealNumbers maxNumber = RealNumbers::findMax(numbers);
        RealNumbers minNumber = RealNumbers::findMin(numbers);

        cout << "The largest number: " << maxNumber.getNumber() << endl;
        cout << "The smallest number: " << minNumber.getNumber() << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    RealNumbers num1(10.0), num2(5.0);

    try {
        RealNumbers sum = operator+(num1, num2);
        RealNumbers difference = operator-(num1, num2);
        RealNumbers product = operator*(num1, num2);
        RealNumbers quotient = operator/(num1, num2);

        cout << "Amount: " << sum.getNumber() << endl;
        cout << "Difference: " << difference.getNumber() << endl;
        cout << "Product: " << product.getNumber() << endl;
        cout << "Part: " << quotient.getNumber() << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
