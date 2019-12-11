#include"list.h"
template <class T>
List<T>::List() 
{
	this->head = NULL;
	this->tail = NULL;
	this->list_size = 0;
}
template <class T>
void List<T>::addTail(T &data) 
{
	Node *newNode= new Node;
	newNode->data= data;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if (this->head == NULL)
	{
		this->head = newNode;
		this->tail = this->head;
		this->list_size = this->list_size + 1;
	} else 
	{
		this->tail->next = newNode;
		newNode->prev = this->tail;
		this->tail = newNode;
		this->list_size = this->list_size + 1;
	}
}
template<class T>
List<T>::~List() {
	while (this->head) {
		Node* next = this->head->next;
		delete this->head;
		this->list_size = this->list_size - 1;
		this->head = next;
	}
}
/*int main()
{
	List<int> list;
	int i=0;
	list.addTail(i);
	return 0;
}*/