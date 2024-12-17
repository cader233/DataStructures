#include <chrono>
#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include "BST.h"
#include "LinkedList.h"
using namespace std;

void insertIntoBST(const vector<int>& values, BST& bst)
{
	// Clears the BST
	bst.clear();
	// Measures the time it takes to insert all of the values into a BST
	// Starts the timer
	auto start_time = std::chrono::high_resolution_clock::now();

	// Insert all values from the vector into the BST
	for (int value : values)
	{
		bst.insert(value);
	}

	// Stops the timer
	auto end_time = std::chrono::high_resolution_clock::now();
	// Calculates the elapsed time
	std::chrono::duration<double> elapsed_time = end_time - start_time;
	cout << "Took " << fixed << setprecision(8) << elapsed_time.count() << " seconds to insert all of the elements into the BST" << endl;
}

void insertIntoLinkedList(const vector<int>& values, LinkedList& ll)
{
	// Clears the LinkedList
	ll.destroy();
	// Measures the time it takes to insert all of the values into a BST
	// Starts the timer
	auto start_time = std::chrono::high_resolution_clock::now();

	// Append all values from the vector to the linked list
	for (int value : values)
	{
		ll.append(value);
	}

	// Stops the timer
	auto end_time = std::chrono::high_resolution_clock::now();
	// Calculates the elapsed time
	std::chrono::duration<double> elapsed_time = end_time - start_time;
	cout << "Took " << fixed << setprecision(8) << elapsed_time.count() << " seconds to insert all of the elements into the LinkedList" << endl;
}

void reverseGeneration(int total, BST& bst, LinkedList& ll)
{
	// BST insertion + timer
	auto start_time = std::chrono::high_resolution_clock::now();
	for (int i = total; i >= 1; --i)
	{
		bst.insert(i);
	}

	auto end_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_time = end_time - start_time;
	cout << "Took " << elapsed_time.count() << " seconds to insert all of the elements into the BST" << endl;

	// LinkedList insertion + timer
	start_time = chrono::high_resolution_clock::now();

	for (int i = total; i >= 1; --i)
	{
		ll.append(i);
	}

	end_time = chrono::high_resolution_clock::now();
	elapsed_time = end_time - start_time;
	cout << "Took " << elapsed_time.count() << " seconds to insert all of the elements into the LinkedList" << endl;
}

void forwardGeneration(int total, BST& bst, LinkedList& ll)
{
	// BST insertion + timer
	auto start_time = std::chrono::high_resolution_clock::now();

	for (int i = 1; i <= total; ++i)
	{
		bst.insert(i);
	}

	auto end_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_time = end_time - start_time;
	cout << "Took " << elapsed_time.count() << " seconds to insert all of the elements into the BST" << endl;

	// LinkedList insertion + timer
	start_time = chrono::high_resolution_clock::now();

	for (int i = 1; i <= total; ++i)
	{
		ll.append(i);
	}

	end_time = chrono::high_resolution_clock::now();
	elapsed_time = end_time - start_time;
	cout << "Took " << elapsed_time.count() << " seconds to insert all of the elements into the LinkedList" << endl;
}

void randGeneration(int total, vector<int> values)
{
	mt19937 gen(time(NULL));
	values.clear();

	for (int i = 0; i < total; ++i)
	{
		int value = (gen() % 1001 + 1);
		values.push_back(value);
	}
}

int main()
{
	// Setup
	BST bst;
	LinkedList ll;
	vector<int> randomValues;
	mt19937 gen(time(NULL));



	// 500k
	cout << "500,000 random numbers: " << endl;
	randGeneration(500000, randomValues);

	// Insertions
	insertIntoBST(randomValues, bst);
	insertIntoLinkedList(randomValues, ll);

	// Measures time it takes to search for a value in the BST
	// Starts the timer
	int value = (gen() % 1001 + 1);
	auto start_time = chrono::high_resolution_clock::now();
	// Calls the search function
	bst.find(value);
	// Stops the timer
	auto end_time = chrono::high_resolution_clock::now();
	// Calculates the elapsed time
	std::chrono::duration<double> elapsed_time = end_time - start_time;
	cout << "Took " << fixed << setprecision(8) << elapsed_time.count() << " seconds to find " << value << " in the BST" << endl;

	// Measures time it takes to search for a value in the LinkedList
	// Starts the timer
	start_time = chrono::high_resolution_clock::now();
	// Calls the search function
	ll.search(value);
	// Stops the timer
	end_time = chrono::high_resolution_clock::now();
	// Calculates the elapsed time
	elapsed_time = end_time - start_time;
	cout << "Took " << fixed << setprecision(8) << elapsed_time.count() << " seconds to find " << value << " in the linked list" << endl << endl;



	// 1mil ~ for detailed commentation go up to 500k
	cout << "1,000,000 random numbers: " << endl;
	randGeneration(1000000, randomValues);

	insertIntoBST(randomValues, bst);
	insertIntoLinkedList(randomValues, ll);

	// BST Search
	value = (gen() % 1001 + 1);
	start_time = chrono::high_resolution_clock::now();

	bst.find(value);

	end_time = chrono::high_resolution_clock::now();
	elapsed_time = end_time - start_time;
	cout << "Took " << fixed << setprecision(8) << elapsed_time.count() << " seconds to find " << value << " in the BST" << endl;

	// LinkedList Search
	start_time = chrono::high_resolution_clock::now();

	ll.search(value);

	end_time = chrono::high_resolution_clock::now();
	elapsed_time = end_time - start_time;
	cout << "Took " << fixed << setprecision(8) << elapsed_time.count() << " seconds to find " << value << " in the linked list" << endl << endl;



	// 2mil ~ for detailed commentation go up to 500k
	cout << "2,000,000 random numbers: " << endl;
	randGeneration(2000000, randomValues);

	insertIntoBST(randomValues, bst);
	insertIntoLinkedList(randomValues, ll);

	// BST Search
	value = (gen() % 1001 + 1);
	start_time = chrono::high_resolution_clock::now();

	bst.find(value);

	end_time = chrono::high_resolution_clock::now();
	elapsed_time = end_time - start_time;
	cout << "Took " << fixed << setprecision(8) << elapsed_time.count() << " seconds to find " << value << " in the BST" << endl;

	// LinkedList Search
	start_time = chrono::high_resolution_clock::now();

	ll.search(value);

	end_time = chrono::high_resolution_clock::now();
	elapsed_time = end_time - start_time;
	cout << "Took " << fixed << setprecision(8) << elapsed_time.count() << " seconds to find " << value << " in the linked list" << endl << endl;



	// 1 - 10k backwards ~ for detailed commentation go up to 500k
	cout << "1 through 10k backwards:" << endl;
	reverseGeneration(10000, bst, ll);
	value = (gen() % 10001 + 1);

	// BST Search
	start_time = chrono::high_resolution_clock::now();

	bst.find(value);

	end_time = chrono::high_resolution_clock::now();
	elapsed_time = end_time - start_time;
	cout << "Took " << fixed << setprecision(8) << elapsed_time.count() << " seconds to find " << value << " in the BST" << endl;

	// LinkedList Search
	start_time = chrono::high_resolution_clock::now();

	ll.search(value);

	end_time = chrono::high_resolution_clock::now();
	elapsed_time = end_time - start_time;
	cout << "Took " << fixed << setprecision(8) << elapsed_time.count() << " seconds to find " << value << " in the linked list" << endl << endl;



	// 1 - 10k forwards ~ for detailed commentation go up to 500k
	cout << "1 through 10k forwards:" << endl;
	forwardGeneration(10000, bst, ll);
	value = (gen() % 10001 + 1);

	// BST Search
	start_time = chrono::high_resolution_clock::now();

	bst.find(value);

	end_time = chrono::high_resolution_clock::now();
	elapsed_time = end_time - start_time;
	cout << "Took " << fixed << setprecision(8) << elapsed_time.count() << " seconds to find " << value << " in the BST" << endl;

	// LinkedList Search
	start_time = chrono::high_resolution_clock::now();

	ll.search(value);

	end_time = chrono::high_resolution_clock::now();
	elapsed_time = end_time - start_time;
	cout << "Took " << fixed << setprecision(8) << elapsed_time.count() << " seconds to find " <<  value << " in the linked list" << endl << endl;

	return 0;
}
