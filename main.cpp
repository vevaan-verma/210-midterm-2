// COMSC-210 | Midterm #2 | Vevaan Verma
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/* CONSTANTS */
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;
const string FILE_PATH = "names.txt";

/* GLOBAL VARIABLES */
ifstream fin;

class DoublyLinkedList {

private:
	struct Node {

		int data;
		Node* prev;
		Node* next;

		Node(int val, Node* p = nullptr, Node* n = nullptr) {

			data = val;
			prev = p;
			next = n;

		}
	};
	Node* head;
	Node* tail;

public:
	DoublyLinkedList() { head = nullptr; tail = nullptr; }

	void insert_after(int value, int position) {

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

	void delete_val(int value) {

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

	void push_back(int v) {

		Node* newNode = new Node(v);

		if (!tail) {

			head = tail = newNode;

		} else {

			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;

		}
	}

	void push_front(int v) {

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

	// deal with the first time period here, so the code is cleaner


	for (int minute = 1; minute < 20; minute++) { // iterate through each time period (20 minutes)

	}

	return 0;

}