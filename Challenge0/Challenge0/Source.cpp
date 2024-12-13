#include <iostream>
#include <string>

using namespace std;

int main()
{
	//initializers
	string response = "";

	//menu or prompt
	cout << "How has your day been so far? " << endl << endl;
	getline(cin,response);

	//response generator
	if (response.length() < 25)
	{
		//outputs if the user responds with a short answer (under 25 characters)
		cout << endl << "Oh I gothca, I hope you have a great rest of your day!!" << endl; 
	}
	else
	{
		//outputs if the user responds with a long answer(over 25 characters)
		cout << endl << "Bro quit yapping..." << endl;
	}

	return 0;
}
