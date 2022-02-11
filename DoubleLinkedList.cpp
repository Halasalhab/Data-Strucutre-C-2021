#include<iostream>
using namespace std;
struct node
{
	string data;
	node* next;
	node* prev;
};
class doublell
{

private:
	node * head;
	node * tail;

public:
	doublell();
	~doublell();
	void print ();
	bool isEmpty( );
	void add_at_end(string);
	void add_at_beg(string);
	bool search(node*,string);
	node* getTail();
};

doublell::doublell()
{
	head=NULL;
	tail=NULL;
}
doublell::~doublell()
{
  while (head)
  {
    node *move = head;
    head = head->next;
    delete move;
  }
}
node* doublell::getTail(){
    return tail;
}
void doublell::print ()
{
	if (head !=NULL)
	{
		cout << "The link list contains:\n";
		for (node *cur = head; cur != NULL; cur = cur->next)
			cout << cur->data << endl;
	}
	else 
		cout << "It is empty!\n ";
}



void doublell::add_at_end( string element)
{
	node *ptr;
	ptr=new node;
	ptr->data=element;
	ptr->next=NULL;
	if (head==NULL)
	{	
		ptr->prev=NULL;
		head=ptr;
		tail=ptr;
	}
	else
	{ 	
		ptr->prev=tail;
		tail->next=ptr;
		tail=ptr;
	}
}

void doublell::add_at_beg( string item)
{
	node *ptr;
	ptr=new node;
	ptr->data=item;
	ptr->prev=NULL;
	ptr->next=head;
	if(head==NULL)
		tail=ptr;
	else
		head->prev=ptr;
	head=ptr;
}

bool doublell::search(node* tail, string x)
{
 
    node* temp = tail;
    bool flag = false;
    while (!flag && temp->prev !=NULL) {
 
    if (temp->data == x) {
        flag=true;
        break;
    }
    temp = temp->prev;
    }
 
    return flag;
}

main()
{
	int ch;
	doublell ll;
	string val;
	do
	{ 
		cout << "options are:\n";
		cout <<"1. Read a string.\n";
		cout <<"2. Add the string's characters to a doubly linked list in the end.\n";
		cout <<"3. Print the doubly linked list items - Forward direction.\n";
		cout <<"4. Search for an element using recursion.\n";
		cout <<"5. Remove all items of the doubly linked list - Destructor.\n";
		cout <<"6. Exit\n";
		cout <<"Enter option:";
		cin >> ch;
		switch(ch)
		{
		case 1:
			cout <<"enter value\n";
			cin>>val;
			ll.add_at_beg(val);
			break;
		case 2:
			cout <<"Function 2\n";
			system("PAUSE");
			break;
		case 3:
			cout <<"the doubly linked list\n";
			ll.print();
			break;
		case 4:
			cout <<"enter value\n";
			cin>>val;
			cout<<ll.search(ll.getTail(),val)<<"\n";
			break;
		case 5:
			cout <<"Destroyed\n";
			ll.~doublell();
			break;
		case 6:
			cout <<"Bye\n";
			break;
		default :
			cout <<"Invalid option\n";
			break;
		}
	}
	while(ch!=6);
}
