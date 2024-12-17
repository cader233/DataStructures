#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	LinkedList LL;
	LL.append("structures");
	LL.append("can");
	LL.append("efficiently");
	LL.append("manage");
	LL.append("large");
	LL.append("amounts");
	LL.append("of");
	LL.append("data");
	LL.display(cout);
	LL.remove("can");
	LL.display(cout);
	LL.prepend("data");
	LL.display(cout);
	LL.remove("systems");
	LL.display(cout);
	LL.tailDisplay(cout);
	LL.tailRemove("data");
	LL.display(cout);
	LL.tailRemove("manage");
	LL.display(cout);

	return 0;
}