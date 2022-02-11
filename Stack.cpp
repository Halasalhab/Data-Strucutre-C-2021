#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//stack based on single linked list implementation
template <class T>
struct node {
	T data;
	node* next;
};

template <class T>
class StackList {
private:
	node<T>* top;
	int count;
public:
	StackList() {
		top = NULL;
		count = 0;
	}
	~StackList() {
		cout << "start destruct\n";
		while (!isEmpty())
			pop();
	}
	bool isEmpty() {
		return top == NULL;
	}
	void pop() {
		if (isEmpty()) {
			cout << "Stack is empty\n";
			return;
		}
		node<T>* del = top;
		top = top->next;
		delete del;		
		count--;
	}
	void push(T item) {
		node<T> *newNode = new node<T>;
		newNode->data = item;
		newNode->next = top;
		top = newNode;
		count++;
	}
	T peek() {
		return top->data;
	}
	int getSize() {
		return count;
	}
	void clearStack() {
		while (!isEmpty())
			pop();
		top = NULL;
	}
};

//Stack based on Array implementation
template <class T>
class StackArr {
private:
	T* arr;
	int MaxSize;
	int top;
public:
	StackArr(int size) {
		MaxSize = size;
		arr = new T[MaxSize];
		top = -1;
	}
	~StackArr() {
		delete[] arr;
	}
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == MaxSize - 1;
	}
	void pop() {
		if(isEmpty()) {
			cout << "stack is empty\n";
			return;
		}
		top--;
	}
	void push(T item) {
		if (isFull()) {
			cout << "stack is full\n";
			return;
		}
		arr[++top] = item;
	}
	T peek() {
		return arr[top];
	}
	int getSize() {
		return top + 1;
	}
	void clearStack() {
		top = -1;
	}
};
int main() {
	cout << "part1: Use stack operations to check whether a given string is palindrome or not.\n\n";
	string word;
	cout << "Enter a word: ";
	cin >> word;	
	
	StackArr<char> stack(word.length());
	for (int i = 0; i < word.length(); i++)
		stack.push(word[i]);
	string reverse = "";
	while (!stack.isEmpty()) {
		reverse += stack.peek();
		stack.pop();
	}
	if (reverse == word)
		cout << word << " is pal\n";
	else
		cout << word << " is not pal\n";
	cout << endl << endl;

	cout << "part2: Use a stack instance to read the contents of a text file, and print number of "
		<< "lines and its lines in reverse order on the console\n\n";
	string line;
	ifstream fin;
	fin.open("input.txt");
	StackList<string> stack2;
	getline(fin,line);
	while (fin) {
		stack2.push(line);
		getline(fin, line);
	}
	fin.close();
	cout << "number of lines= " << stack2.getSize() << endl;
	cout << "file content in reverse:\n";
	while (!stack2.isEmpty()) {
		cout << stack2.peek() << endl;
		stack2.pop();
	}
	system("pause");
	return 0;
}

/*
Description:
o Implement a Stack template class using single linked list; the class must include the
following stack operations:
o Constructor: initialize the stack to empty state
o Destructor: to delete all dynamically allocated data
o is_empty: check whether the stack is empty
o pop: remove the item from the top of the stack if the stack is not empty
o push: store an item on the top of the stack if the stack is not full
o peek: retrieve the value of the item on the top of the stack if the stack is not
empty
o get_size: returns number of items in the stack
 In the main function:
o Use stack operations to check whether a given string is palindrome or not.
o Use a stack instance to read the contents of a text file, and print number of
lines and its lines in reverse order on the console
*/