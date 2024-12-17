#include "Temperature.h"


// setters

void Temperature::setC(double C)
{
	temp = C;
}

void Temperature::setK(double K)
{
	temp = K - 273.15;

}

void Temperature::setF(double F)
{
	temp = (F - 32) * 5. / 9;
}


//getters

double Temperature::getC()
{
	return temp;
}

double Temperature::getK()
{
	return temp + 273.15;
}

double Temperature::getF()
{
	return (temp * 9./5) + 32;
}
