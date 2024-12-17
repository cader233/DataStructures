#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	string data;
	Node* next;
	Node* prev;

	Node() : data(""), next(nullptr), prev(nullptr) {};
	Node(string data) : data(data), next(nullptr), prev(nullptr) {};
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

	bool append(string word);
	bool prepend(string word);
	bool remove(string word);
	void display(ostream& os);
	bool tailRemove(string word);
	void tailDisplay(ostream& os);

	friend std::ostream& operator<<(ostream& os, LinkedList& ll);
};

