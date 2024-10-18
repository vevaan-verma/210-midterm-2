// COMSC-210 | Midterm #2 | Vevaan Verma
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class DoublyLinkedList;

/* CONSTANTS */
const string FILE_PATH = "names.txt";

/* GLOBAL VARIABLES */
ifstream fin;

/* FUNCTION PROTOTYPES */
void outputLine(DoublyLinkedList line);

class DoublyLinkedList {

private:
	struct Node {

		string data;
		Node* prev;
		Node* next;

		Node(string val, Node* p = nullptr, Node* n = nullptr) {

			data = val;
			prev = p;
			next = n;

		}
	};
	Node* head;
	Node* tail;

public:
	DoublyLinkedList() { head = nullptr; tail = nullptr; }

	void insert_after(string value, int position) {

		if (position < 0) {

			cout << "Position must be >= 0." << endl;
			return;

		}

		Node* newNode = new Node(value);

		if (!head) {

			head = tail = newNode;
			return;

		}

		Node* temp = head;

		for (int i = 0; i < position && temp; ++i)
			temp = temp->next;

		if (!temp) {

			cout << "Position exceeds list size. Node not inserted.\n";
			delete newNode;
			return;

		}

		newNode->next = temp->next;
		newNode->prev = temp;

		if (temp->next)
			temp->next->prev = newNode;
		else
			tail = newNode;

		temp->next = newNode;

	}

	void delete_val(string value) {

		if (!head) return;

		Node* temp = head;

		while (temp && temp->data != value)
			temp = temp->next;

		if (!temp) return;

		if (temp->prev)
			temp->prev->next = temp->next;
		else
			head = temp->next;

		if (temp->next)
			temp->next->prev = temp->prev;
		else
			tail = temp->prev;

		delete temp;

	}

	void delete_pos(int pos) {

		if (!head) {

			cout << "List is empty." << endl;
			return;

		}

		if (pos == 1) {

			pop_front();
			return;

		}

		Node* temp = head;

		for (int i = 1; i < pos; i++) {

			if (!temp) {

				cout << "Position doesn't exist." << endl;
				return;

			} else {

				temp = temp->next;

			}
		}

		if (!temp) {

			cout << "Position doesn't exist." << endl;
			return;

		}

		if (!temp->next) {

			pop_back();
			return;

		}

		Node* tempPrev = temp->prev;
		tempPrev->next = temp->next;
		temp->next->prev = tempPrev;

		delete temp;

	}

	void push_back(string v) {

		Node* newNode = new Node(v);

		if (!tail) {

			head = tail = newNode;

		} else {

			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;

		}
	}

	void push_front(string v) {

		Node* newNode = new Node(v);

		if (!head) {

			head = tail = newNode;

		} else {

			newNode->next = head;
			head->prev = newNode;
			head = newNode;

		}
	}

	void pop_front() {

		if (!head) {

			cout << "List is empty." << endl;
			return;

		}

		Node* temp = head;

		if (head->next) {

			head = head->next;
			head->prev = nullptr;

		} else {

			head = tail = nullptr;

		}

		delete temp;

	}

	void pop_back() {

		if (!tail) {

			cout << "List is empty." << endl;
			return;

		}

		Node* temp = tail;

		if (tail->prev) {

			tail = tail->prev;
			tail->next = nullptr;

		} else {

			head = tail = nullptr;

		}

		delete temp;

	}

	~DoublyLinkedList() {

		while (head) {

			Node* temp = head;
			head = head->next;
			delete temp;

		}
	}

	void print() {

		Node* current = head;

		if (!current) {

			cout << "List is empty." << endl;
			return;

		}

		while (current) {

			cout << current->data << " ";
			current = current->next;

		}

		cout << endl;

	}

	void print_reverse() {

		Node* current = tail;

		if (!current) {

			cout << "List is empty." << endl;
			return;

		}

		while (current) {

			cout << current->data << " ";
			current = current->prev;

		}

		cout << endl;

	}
};

// main() is the entry point of the program and simulates a line at a coffee shop
// arguments: none
// returns: int - the exit code of the program
int main() {

	srand(time(0)); // seed the random number generator

	fin.open(FILE_PATH);

	if (!fin.good()) { // if the file does not exist

		cout << "File " << FILE_PATH << " not found" << endl; // output error message
		return 1; // return an error code

	}

	vector<string> names; // create a vector to store the names of the customers

	while (!fin.eof()) { // while the file has not reached the end

		string name; // create a string to store the name
		fin >> name; // read the next name from the file
		names.push_back(name); // add the name to the vector

	}

	DoublyLinkedList line; // create a new doubly linked list to represent the line

	cout << "Store opens:" << endl; // output the store opening header

	// deal with the first time period here, so the code is cleaner
	for (int i = 0; i < 5; i++) { // iterate through the first 5 customers

		string name = names[rand() % names.size()];
		line.insert_after(name, i); // insert a customer at the end of the line
		cout << "    " << name << " joins the line." << endl; // output the customer joining the line

	}

	for (int minute = 1; minute < 20; minute++) { // iterate through each time period except the first period which is dealt with prior to the loop

		cout << "Minute " << minute << ": "; // output the current minute

		if (minute % 2 == 0) { // if the minute is even

			line.pop_front(); // remove the first customer in line
			line.push_back(names[rand() % names.size()]); // add a new customer to the end of the line

		} else { // if the minute is odd

			line.pop_back(); // remove the last customer in line
			line.push_front(names[rand() % names.size()]); // add a new customer to the front of the line

		}

		line.print(); // print the line
	}

	return 0;

}

// outputLine() outputs the resulting line
// arguments: DoublyLinkedList line - the line to output
// returns: void
void outputLine(DoublyLinkedList line) {

	cout << "Resulting line:" << endl;
	line.print();

}