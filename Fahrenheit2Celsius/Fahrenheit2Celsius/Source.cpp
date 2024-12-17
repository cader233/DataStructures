#include <iostream>
#include "Temperature.h"
using namespace std;

// functions for temperature
/*
double F2K(double temp)
{
	double kelvin = (temp - 32) * 5/9 + 273.15;

	cout << endl << "That means that it is " << kelvin << " degrees Kelvin!";
	return 0;
}

double F2C(double temp)
{
	double celsius = (temp - 32) * 5 / 9;

	cout << endl << "That means that it is " << celsius << " degrees Celsius!";
	return 0;
}

double C2F(double temp)
{
	double fahrenheit = (temp + 32) * 9 / 5;

	cout << endl << "That means that is is " << fahrenheit << " degrees Fahrenheit!";
	return 0;
}

double C2K(double temp)
{
	double kelvin = temp + 273.15;

	cout << endl << "That means that it is " << kelvin << " degrees Kelvin!";
	return 0;
}

double K2C(double temp)
{
	double celsius = temp - 273.15;

	cout << endl << "That means that it is " << celsius << " degrees Celsius!";
	return 0;
}

double K2F(double temp)
{
	double fahrenheit = (temp - 273.15) * 9/5 +32;

	cout << endl << "That means that it is " << fahrenheit << " degrees Fahrenheit!";
	return 0;
}
*/

char getScale()
{
	char scale;
	while (true)
	{
		cout << endl << "What is the scale of the temperature (F, C, K?) ";
		cin >> scale;
		switch (scale)
		{
		case 'c':
		case 'C':
		case 'f':
		case 'F':
		case 'k':
		case 'K':
			return scale;
		default: 
			break;
		}
	}
}

double AverageTemp()
{
	int tempnum = 0;
	Temperature *arr;
	cout << "How many different temperatures do you have? ";
	cin >> tempnum;

	arr = new Temperature[tempnum];

	for (int i = 0; i < tempnum; ++i)
	{
		double temp;
		char scale;
		cout << endl << "Enter temperature: " << (i+1) << " ";
		cin >> temp;
		cout << endl << "What is the scale? ";
		scale = getScale();

		switch (scale)
		{
		case 'c':
		case 'C':
			arr[i].setC(temp);
			break;
		case 'f':
		case 'F':
			arr[i].setF(temp);
			break;
		case 'k':
		case 'K':
			arr[i].setK(temp);
			break;
		default:
			break;
		}
	}

	double sum = 0.0;
	for (int i = 0; i < tempnum; i++)
	{
		sum += arr[i].getC();
	}

	double avg = sum / tempnum;

	Temperature average;
	average.setC(avg);

	cout << "Average temp in F " << average.getF() << endl;
	cout << "Average temp in C " << average.getC() << endl;
	cout << "Average temp in K " << average.getK() << endl;

	delete[] arr;
}

int main()
{
	Temperature t;
	double temp = 0; //initializers
	int cont = 1;
	int option = 0;


	cout << "Welcome to the temperature converter machine! " << endl; //welcome

	while (cont != 0) //runs the program until the user wants to quit
	{
		cout << endl << "1. Convert Fahrenheit to Celsius" << endl << "2. Convert Fahrenheit to Kelvin" << endl << "3. Convert Celcius to Fahrenheit"; // menu
		cout << endl << "4. Convert Celsius to Kelvin" << endl << "5. Convert Kelvin to Fahrenheit" << endl << "6. Convert Kelvin to Celsius" << endl; // menu
		cout << "7. Exit the program" << endl << "8. Average Temperatures" << endl; // menu

		cout << endl << "Please enter in the corresponding number for the desired action: ";
		cin >> option;

		while (option < 1 || option > 7) //verifies a correct input
		{
			cout << endl << "ERROR : Please enter a correct corresponding number for the desired action: ";
			cin >> option;
		}

		if (option == 1)
		{
			cout << endl << "What is the current temperature? ";
			cin >> temp;
			t.setF(temp);
			cout << t.getC() << " degrees Celsius." << endl;
		}
		else if (option == 2)
		{
			cout << endl << "What is the current temperature? ";
			cin >> temp;
			t.setF(temp);
			cout << t.getK() << " degrees Kelvin." << endl;
		}
		else if (option == 3)
		{
			cout << endl << "What is the current temperature? ";
			cin >> temp;
			t.setC(temp);
			cout << t.getF() << " degrees Fahrenheit." << endl;
		}
		else if (option == 4)
		{
			cout << endl << "What is the current temperature? ";
			cin >> temp;
			t.setC(temp);
			cout << t.getK() << " degrees Kelvin." << endl;
		}
		else if (option == 5)
		{
			cout << endl << "What is the current temperature? ";
			cin >> temp;
			t.setK(temp);
			cout << t.getF() << " degrees Fahrenheit." << endl;
		}
		else if (option == 6)
		{
			cout << endl << "What is the current temperature? ";
			cin >> temp;
			t.setK(temp);
			cout << t.getC() << " degrees Celsius." << endl;
		}
		else if (option == 7)
		{
			cont = 0;
		}
		else if (option == 8)
		{
			AverageTemp();
		}
	}

	cout << endl << "Have a nice day!";

	return 0;
}

