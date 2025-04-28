#include <iostream>
#include <string>
using namespace std;

// Base class: Number
class Number {
private:
    string name;
    int number;

public:
    Number(const string& name, int number) : name(name), number(number) {}

    string getName() const { return name; }
    int getNumber() const { return number; }
};

// Derived class: WholeNumber
class WholeNumber : public Number {
public:
    WholeNumber(const string& name, int number) : Number(name, number) {}

    void displayWholeNumber() const {
        cout << getName() << " represents the whole number: " << getNumber() << "." << endl;
    }
};

// Derived class: DecimalNumber
class DecimalNumber : public Number {
private:
    double decimalValue;

public:
    DecimalNumber(const string& name, int number, double decimalValue) : Number(name, number), decimalValue(decimalValue) {}

    double getDecimalValue() const { return decimalValue; }

    void displayDecimalNumber() const {
        cout << getName() << " represents the decimal number: " 
             << getNumber() << " with a decimal value of " 
             << decimalValue << "." << endl;
    }
};

int main() {
    // Using the Number class
    cout << "--- Number ---" << endl;
    Number number1("Generic Number", 101);
    cout << "Name: " << number1.getName() << endl;
    cout << "Number: " << number1.getNumber() << endl;
    cout << endl;

    // Using the WholeNumber class
    cout << "--- WholeNumber ---" << endl;
    WholeNumber wholeNumber1("Positive Integer", 102);
    cout << "Name: " << wholeNumber1.getName() << endl;
    cout << "Number: " << wholeNumber1.getNumber() << endl;
    wholeNumber1.displayWholeNumber();
    cout << endl;

    WholeNumber wholeNumber2("Negative Integer", -103);
    cout << "Name: " << wholeNumber2.getName() << endl;
    cout << "Number: " << wholeNumber2.getNumber() << endl;
    wholeNumber2.displayWholeNumber();
    cout << endl;

    // Using the DecimalNumber class
    cout << "--- DecimalNumber ---" << endl;
    DecimalNumber decimalNumber1("Decimal Value 1", 104, 104.56);
    cout << "Name: " << decimalNumber1.getName() << endl;
    cout << "Number: " << decimalNumber1.getNumber() << endl;
    cout << "Decimal Value: " << decimalNumber1.getDecimalValue() << endl;
    decimalNumber1.displayDecimalNumber();
    cout << endl;

    DecimalNumber decimalNumber2("Decimal Value 2", 105, -105.78);
    cout << "Name: " << decimalNumber2.getName() << endl;
    cout << "Number: " << decimalNumber2.getNumber() << endl;
    cout << "Decimal Value: " << decimalNumber2.getDecimalValue() << endl;
    decimalNumber2.displayDecimalNumber();
    cout << endl;

    return 0;
}