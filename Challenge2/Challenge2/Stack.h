#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node() : data(0), next(nullptr) {}
	Node(int data) : data(data), next(nullptr) {}
	Node(int data, Node* next) : data(data), next(next) {}
};

class Stack
{
private:
	Node* front;
	Node* end;

public:
	Stack() : front(nullptr), end(nullptr) {}
	~Stack();

	void push(int data);
	bool pop();
	bool peek(int& data);
	void display(ostream& os);

	friend ostream& operator<<(ostream& os, Stack& s);
};

