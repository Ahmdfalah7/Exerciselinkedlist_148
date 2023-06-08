#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class Circularlinkedlist {
private:
	Node* LAST;
public:
	Circularlinkedlist() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listempty();
	bool delNode();
	void traverse();
};

Circularlinkedlist::Circularlinkedlist() {
	LAST = NULL;
}

void Circularlinkedlist::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node();	//Step 1
	newNode->name = nim;	//Step 2
	newNode->name = nm;	//step 2

	if (LAST == NULL || nim <= LAST->rollNumber) {
		if (LAST != NULL && nim <= LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST;	//Step 3
		if (LAST != NULL)
			LAST->next = new Node;	//Step 4
		newNode->next = NULL;	//Step 5
		LAST = newNode;	//step 6
		return;
	}
}

bool Circularlinkedlist::search(int rollNo, Node * *Falah, Node * *Ahmad) {
	*Falah = LAST->next;
	*Ahmad = LAST->next;

	while (*Ahmad != LAST) {
		if (rollNo == (*Ahmad)->rollNumber) {
			return true;
		}
		*Falah = *Ahmad;
		*Ahmad = (*Ahmad)->next;
	}

	if (rollNo == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}


bool Circularlinkedlist::listempty() {
	return (LAST == NULL);
}



int main() {
	Circularlinkedlist obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				
			}
			case '3': {
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;