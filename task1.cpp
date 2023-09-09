#include <iostream>
using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double fahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit + 459.67) * 5.0 / 9.0;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvinToFahrenheit(double kelvin) {
    return (kelvin * 9.0 / 5.0) - 459.67;
}

int main() {
    cout << "Temperature Converter" << endl;
    cout << "Available units: Celsius, Fahrenheit, Kelvin" << endl;

    double temperature;
    string originalUnit;

    cout << "Enter the temperature value: ";
    cin >> temperature;
    cin.ignore();

    cout << "Enter the original unit of measurement (e.g., Celsius, Fahrenheit, Kelvin): ";
    getline(cin, originalUnit);

    if (originalUnit == "Celsius" || originalUnit == "celsius") {
        double fahrenheit = celsiusToFahrenheit(temperature);
        double kelvin = celsiusToKelvin(temperature);
        cout << temperature << " Celsius is equivalent to:" << endl;
        cout << fahrenheit << " Fahrenheit" << endl;
        cout << kelvin << " Kelvin" << endl;
    } else if (originalUnit == "Fahrenheit" || originalUnit == "fahrenheit") {
        double celsius = fahrenheitToCelsius(temperature);
        double kelvin = fahrenheitToKelvin(temperature);
        cout << temperature << " Fahrenheit is equivalent to:" << endl;
        cout << celsius << " Celsius" << endl;
        cout << kelvin << " Kelvin" << endl;
    } else if (originalUnit == "Kelvin" || originalUnit == "kelvin") {
        double celsius = kelvinToCelsius(temperature);
        double fahrenheit = kelvinToFahrenheit(temperature);
        cout << temperature << " Kelvin is equivalent to:" << endl;
        cout << celsius << " Celsius" << endl;
        cout << fahrenheit << " Fahrenheit" << endl;
    } else {
        cout << "Invalid input for the original unit." << endl;
    }

    return 0;
}
