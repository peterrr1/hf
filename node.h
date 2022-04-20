#include <iostream>

class Node {
public:
	std::string Name;
	std::string PhoneNumber;
	Node* next;

	Node() : next(NULL) {}
};