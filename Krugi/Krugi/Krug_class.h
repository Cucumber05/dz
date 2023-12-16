#pragma once

class Krug {
private:
	double _x, _y, _r, lenght, square;
	int _k, _z, _s; //красный, зеленый, синий - поэтому k, z, s :)
public:
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
	//void SetColor(int k, int z, int s);

	//methods
	double Krug_Lenght();
	double Krug_Square();
	void Krug_Color();
	void PrintFile(std::string* filename);
};