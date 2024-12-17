#include <iostream>
#include "LinkedList.h"

/*void test(LinkedList m)
{
	m.append(15);
	std::cout << m << std::endl;
}
*/

int main()
{
	LinkedList ll;

	int idz[10] = {20, 50, 10, 200, 60, 90, 15};
	double costz[10] = { 5.0, 10.0, 2.0, 22.5, 6.0, 3.5, 1.0 };
	Data d;


	for (int i = 0; i < 4; ++i) 
	{
		d.id = idz[i];
		d.cost = costz[i];
		ll.append(d);
	}
	for (int i = 4; i < 7; ++i)
	{
		d.id = idz[i];
		d.cost = costz[i];
		ll.prepend(d);
	}


	std::cout << ll << std::endl;
	d.id = 15;
	ll.remove(d);
	std::cout << ll << std::endl;

}