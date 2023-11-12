#include <iostream>
#include <cmath>
using namespace std;

double calculateVelocity(double height) {
    double G = 6.67430e-11; // гравитационная постоянная
    double M = 5.972e24; // масса Земли в кг
    double R = 6371e3; // радиус Земли в метрах

    height = height * 1000; // переводим высоту ввода в метры

    double velocity = sqrt(G * M / (R + height));
    return velocity;
}

int main() {
    double minHeight = 0;
    double maxHeight = 60000;
    double step = 100;

    cout << "Satellite altitude (km)\tsatellite speed (m/s)" << endl;
    for (double height = minHeight; height <= maxHeight; height += step) {
        double velocity = calculateVelocity(height);
        cout << height << " " << velocity << endl;
    }

    return 0;
}
