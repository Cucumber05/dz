#pragma once

class Krug {
private:
	double _x, _y, _r, lenght = 0, square = 0;
	int _k, _z, _s; //�������, �������, ����� - ������� k, z, s :)
public:
	Krug();
	Krug(double x, double y, double r, int k, int z, int s);
	//getters
	double getX();
	double getY();
	double getR();
	std::string getColor();
	//setters
	void SetX(double x);
	void SetY(double y);
	void SetR(double r);
	void Set_Color(int k, int z, int s);

	//methods
	double Krug_Lenght();
	double Krug_Square();
	void Krug_Color();
	void PrintFile(std::string* filename);
};