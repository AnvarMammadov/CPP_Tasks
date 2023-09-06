#include<iostream>
using namespace std;


struct Node {
	int data;
	Node* next;


};

class LinkedList {
	Node* head;
public:
	LinkedList(Node* head)
	{
		this->head = head;
	}

	void PrintList()const {
		Node* n = head;
		while (n != nullptr) {
			cout << n->data << "   ";
			n = n->next;
		}
		cout << endl << endl;
	}

	void PushFirst(const int& data) {
		Node* newnode = new Node;
		newnode->data = data;
		newnode->next = head;
		head = newnode;
	}

	void PushLast(const int& data) {
		Node* newnode = new Node;
		newnode->data = data;
		newnode->next = nullptr;

		Node* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newnode;

	}


	void InsertAfter(Node* node, const int& data) {
		Node* newnode = new Node;
		newnode->data = data;
		newnode->next = node->next;
		node->next = newnode;
	}

	void DeleteFirst() {
		Node* newnode = new Node;
		newnode = head->next;
		head = newnode;

	}

	void DeleteLast() {
		Node* current = head;
		while (current->next->next != nullptr)
		{
			current = current->next;
		}
		current->next = nullptr;
	}

	void DeleteAfter(Node* node) {
		Node* current = head;
		while (current->next != node)
		{
			current = current->next;
		}
		current->next->next = nullptr;
	}

	void InsertByIndex(const int& index, const int& data) {

		int current_index = 0;
		Node* current = head;
		Node* newnode = new Node;
		newnode->data = data;
		while (current->next != nullptr)
		{
			if (current_index == index) {
				newnode->next = current->next;
				current->next = newnode;
				break;
			}
			current = current->next;
			current_index++;
		}
	}


	void DeleteByIndex(const int& index) {
		int current_index = 0;
		Node* current = head;

		Node* newnode = new Node;
		while (current->next != nullptr)
		{
			if (current_index == index - 1) {
				current->next = current->next->next;
				break;
			}
			current = current->next;
			current_index++;
		}
	}

};

void main() {
	Node* head = new Node;
	Node* second = new Node;
	Node* third = new Node;


	head->data = 100;
	second->data = 200;
	third->data = 300;

	head->next = second;
	second->next = third;
	third->next = nullptr;

	/*cout << head->data << endl;
	cout << head->next->data << endl;
	cout << head->next->next->data << endl;*/

	LinkedList listt(head);
	listt.PrintList();

	listt.PushLast(243);

	listt.PushLast(256);

	listt.PushFirst(333);

	listt.PrintList();

	listt.DeleteAfter(third);

	listt.PrintList();

	listt.InsertByIndex(0, 143);

	listt.PrintList();

	listt.DeleteByIndex(2);

	listt.PrintList();
}
