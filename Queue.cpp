#include<iostream>
#include<string>
using namespace std;

template <class T>
struct node {
	T data;
	node* next, * prev;
};

template <class T>
class Queue {
private:
	node<T>* front, * rear;
public:
	Queue() {
		front = rear = NULL;
	}
	~Queue() {
		while (!isEmpty())
			deQueue();
	}
	void enQueue(T item) {
		//add at end
		node<T>* newNode = new node<T>;
		newNode->data = item;
		newNode->next = NULL;
		if (isEmpty()) {
			front = rear = newNode;
			newNode->prev = NULL;
		}
		else {
			newNode->prev = rear;
			rear->next = newNode;
			rear = newNode;
		}
	}
	void deQueue() {
		//delete from beginning
		if (isEmpty()) {
			cout << "Queue is empty\n";
			return;
		}
		node<T>* del = front;
		front = front->next;
		if (front == NULL)
			rear == NULL;
		else
			front->prev = NULL;
		delete del;
	}
	T peek() {
		return front->data;
	}
	bool isEmpty() {
		return front == NULL;
	}
	void change() {
		if (isEmpty())
			return;
		node<T>* old = front;
		node<T>* ptr = front;
		while (ptr != NULL) {
			if (ptr->data.age > old->data.age)
				old = ptr;
			ptr = ptr->next;
		}
		if (old == front)
			return;
		else if (old == rear) {
			rear = rear->prev;
			rear->next = NULL;
		}
		else {
			old->prev->next = old->next;
			old->next->prev = old->prev;
		}
		old->next = front;
		front->prev = old;
		old->prev = NULL;
		front = old;
	}
};

int main()
{
	struct patient {
		string name;
		int age;
	};
	Queue<patient> queue;
	int choice;
	patient p;
	while (true) {
		cout << "1. add patient\n"
			<< "2. Serve Patient\n"
			<< "3. print the patient to be served information\n"
			<< "4. serve oldest patint first\n"
			<< "5. exit\n"
			<< "Enter choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter patient name and age: ";
			cin >> p.name >> p.age;
			queue.enQueue(p);
			break;
		case 2:
			queue.deQueue();
			break;
		case 3:
			p = queue.peek();
			cout << "Patient name: " << p.name << "\t" << "age: " << p.age << endl;
			break;
		case 4:
			queue.change();
			break;
		case 5:
			return 0;
		}
		system("pause");
		system("cls");
	}
}

/*
Description:
Write a complete C++ program that creates a doubly linked list Queue ADT class that
holds patient information {name as string, age as integer}
Please use the method names listed below in your code.
 Node
struct node
{
string name;
int age;
node *next,*prev;
};
 Class Members:
1. Queue (): constructor.
2. void enQueue(): inserts a patient at the rear of queue
3. void deQueue(): removes patient from the front of the queue
4. node*Front(): returns value at the front of the queue
5. void change oldest(): brings oldest patient at the front of the queue and shift other patients
In this program, you have to implement simple clinic with the following operations:
1. Add patient
2. Serve patient
3. Print patient’s information to be served
4. Serve oldest patient first, in this option the patient with largest age must be at the front of
the list (Queue) and all other patients are shifted.
*/