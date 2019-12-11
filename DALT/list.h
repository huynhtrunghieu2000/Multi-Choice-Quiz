#include<iostream>
using namespace std;
/*template <class T>
class Node {
	public:
        T data;
		Node* next;
		Node* previous;
        Node(T data);
};
template<class T>
Node<T>::Node(T data) {
	this->data = data;
}*/
template <class T>
class List 
{
	private:
		struct Node 
		{   
			T data;
			Node* next = NULL;
			Node* prev = NULL;
		};
		Node* head;
		Node* tail;
		int list_size;
    public:
    List();
    ~List();
    void addTail(T &data);
	//void findAdress(int pos);
	//void removePos(int pos);
};