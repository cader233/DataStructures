#pragma once
class Temperature
{
private:

	double temp; // degrees Celsius

public:

	// constructors 

	Temperature() : temp(0.0) {};
	Temperature(double tempC) : temp(tempC) {};

	// setters

	void setC(double C);
	void setF(double F);
	void setK(double K);

	//getters

	double getC();
	double getF();
	double getK();
};

