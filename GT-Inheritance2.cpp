#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Number {
private:
    int rawValue;

public:
    Number(int rawValue) : rawValue(rawValue) {}

    int getRawValue() const { return rawValue; }
    void setRawValue(int value) { rawValue = value; }
};

class WholeNumber : public Number {
public:
    WholeNumber(int value) : Number(value) {}

    void multiply(WholeNumber otherWhole) {
        setRawValue(getRawValue() * otherWhole.getRawValue());
    }

    string toString() const {
        return to_string(getRawValue());
    }
};

class DecimalNumber : public Number {
private:
    int decimalPlaces;

public:
    DecimalNumber(int value, int decimalPlaces)
        : Number(value), decimalPlaces(decimalPlaces) {}

    int getDecimalPlaces() const { return decimalPlaces; }
    void setDecimalPlaces(int places) { decimalPlaces = places; }

    void multiply(DecimalNumber otherDecimal) {
        setRawValue(getRawValue() * otherDecimal.getRawValue());
        setDecimalPlaces(getDecimalPlaces() + otherDecimal.getDecimalPlaces());
    }

    string toString() const {
        double value = getRawValue() / pow(10.0, getDecimalPlaces());
        return to_string(value);
    }
};

int main() {
    int wholeNumber1Value, wholeNumber2Value;
    cout << "Enter first whole number: ";
    cin >> wholeNumber1Value;
    cout << "Enter second whole number: ";
    cin >> wholeNumber2Value;

    WholeNumber wholeNumber1(wholeNumber1Value);
    WholeNumber wholeNumber2(wholeNumber2Value);

    wholeNumber1.multiply(wholeNumber2);
    cout << "WholeNumber Result (Multiplication): " << wholeNumber1.toString() << endl;
    cout << endl;

    int decimal1RawValue, decimal1Places, decimal2RawValue, decimal2Places;
    cout << "Enter first decimal number's raw value (e.g. 125 for 1.25): ";
    cin >> decimal1RawValue;
    cout << "Enter number of decimal places for first decimal: ";
    cin >> decimal1Places;

    cout << "Enter second decimal number's raw value (e.g. 20 for 0.20): ";
    cin >> decimal2RawValue;
    cout << "Enter number of decimal places for second decimal: ";
    cin >> decimal2Places;

    DecimalNumber decimalNumber1(decimal1RawValue, decimal1Places);
    DecimalNumber decimalNumber2(decimal2RawValue, decimal2Places);

    decimalNumber1.multiply(decimalNumber2);
    cout << "DecimalNumber Result (Multiplication): " << decimalNumber1.toString() << endl;

    return 0;
}
