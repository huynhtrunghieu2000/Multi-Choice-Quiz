#pragma once
#include<iostream>
using namespace std;
template <class T>
struct Node
{
	T data;
	Node* next = NULL;
	Node* prev = NULL;
};
template <class T>
class List
{
public:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* current;
	int list_size;
	List();
	~List();
	void addTail(T& data);
	
};
template <class T>
List<T>::List()
{
	head = NULL;
	tail = NULL;
	current = NULL;
	list_size = 0;
}
template <class T>
void List<T>::addTail(T& data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (head == NULL)
	{
		head = newNode;
		tail = head;
		list_size++;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		list_size++;
	}
}
template<class T>
List<T>::~List()
{
	while (head != NULL)
	{
		Node<T>* tmp = head->next;
		delete head;
		head = tmp;
	}
}