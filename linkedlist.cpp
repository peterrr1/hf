#include "linkedlist.h"

void LinkedList::CreateNewEntry() {

	Node* newNode = new Node();

	std::cout << "Name: ";
	std::cin >> newNode->Name;

	std::cout << "Phone number: ";
	std::cin >> newNode->PhoneNumber;

	this->AppendNewElement(newNode);
}

void LinkedList::AppendNewElement(Node *newNode) {

	if (head == NULL)
		head = newNode;
	else {
		Node* tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newNode;
	}
}

void LinkedList::PrintOutList() {
	for (Node *tmp = head; tmp != NULL; tmp = tmp->next) {
		std::cout << tmp->Name << '\n' << tmp->PhoneNumber << std::endl;
	}
}

LinkedList::~LinkedList() {
	while (head != NULL) {
		Node *tmp = head->next;
		delete head;
		head = tmp;
	}
}