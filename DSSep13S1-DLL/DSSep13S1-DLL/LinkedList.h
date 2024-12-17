#pragma once
#include <iostream>

class Data
{
public:
	int id;
	double cost;
	Data() : id(0), cost(0) {};
	friend std::ostream& operator<<(std::ostream& os, Data& d);
};


class Node
{
public:
	Data data;
	Node* next;
	Node* prev;

	Node() : next(nullptr), prev(nullptr) {};
	Node(const Data & data) : data(data), next(nullptr), prev(nullptr) {};
};

class LinkedList
{
private:
	Node* head;
	Node* tail;

public:
	LinkedList() : head(nullptr), tail(nullptr) {};
	~LinkedList();
	LinkedList(const LinkedList& ll);

	bool append(const Data & val);
	bool prepend(const Data & val);
	bool search(int id,  Data &val);
	bool remove(const Data & val);
	void display(std::ostream& os);

	friend std::ostream& operator<<(std::ostream& os, LinkedList& ll);
};

