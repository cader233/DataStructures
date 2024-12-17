#pragma once

class Node
{
public:
	int data;
	Node* next;

	Node() : data(0), next(nullptr) {}
	Node(int data) : data(data), next(nullptr) {}
};

class Queue
{
private:
	Node* front;
	Node* end;

public: 
	Queue() : front(nullptr), end(nullptr) {}
	~Queue();
	Queue(const Queue& q);

	void push(int data);
	bool pop();
	bool peek(int& data);
};

