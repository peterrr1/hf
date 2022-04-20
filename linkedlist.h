#include "node.h"

class LinkedList {
	Node* head;
public:
	LinkedList() : head(NULL) {}

	void CreateNewEntry();

	void AppendNewElement(Node *newNode);

	void PrintOutList();

	~LinkedList();
};