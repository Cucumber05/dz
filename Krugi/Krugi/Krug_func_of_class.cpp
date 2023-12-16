#include <iostream>
#include <string>
#include <fstream>
#include <random>
#define PI 3.14
#include "Krug_class.h"

Krug:: Krug(double x, double y, double r, int k, int z, int s) {
	_x = x;
	_y = y;
	_r = r;
	_k = k;
	_z = z;
	_s = s;
}

//getters
double Krug::getX() {
    return _x;
}
double Krug::getY() {
    return _y;
}
double Krug::getR() {
    return _r;
}
std::string Krug::getColor() {
    return "rgb(" + std::to_string(_k) + "," + std::to_string(_z) + "," + std::to_string(_s) + ")";
}

//setters
void Krug::SetX(double x) {
    _x = x;
}
void Krug::SetY(double y) {
    _y = y;
}
void Krug::SetR(double r) {
    _r = r;
}
void Krug::Set_Color(int k, int z, int s) {
    _k = k;
    _z = z;
    _s = s;
}

//methods
double Krug::Krug_Lenght() {
    lenght = (2.0 * PI * _r);
    return lenght;
}

double Krug::Krug_Square() {
    square = (PI * _r * _r);
    return square;
}

void Krug::Krug_Color() {
    for (int i = 0; i <= 3; i++) {
        _k = rand() % (255 - 0 + 1) + 0;
        _z = rand() % (255 - 0 + 1) + 0;
        _s = rand() % (255 - 0 + 1) + 0;
    }
}

void Krug::PrintFile(std::string* filename) {
    std::ofstream file(*filename);
    if (file.is_open()) {
        file << "X: " << _x << std::endl;
        file << "Y: " << _y << std::endl;
        file << "Radius: " << _r << std::endl;
        file << "Color: rgb(" << _k << "," << _z << "," << _s << ")" << std::endl; //https://www.colorcodeslab.com/ru/rgb/36-45-56/ либо просто в поисковик rgb(144,73,241)
        file << "Length: " << lenght << std::endl;
        file << "Square: " << square << std::endl;
        file.close();
        std::cout << "file was successfully upload new data" << std::endl;
    }
    else {
        std::cout << "Error: unabled to open file" << std::endl;
    }

}