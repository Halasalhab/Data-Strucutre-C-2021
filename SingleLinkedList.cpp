#include <iostream>

using namespace std;
#include <bits/stdc++.h>
struct node
{
	int data;
	node* next;
};

class single
{
public:
	single();
	void add_end(int x);
	void add_end2(int x);
	void add_beg(int x);
	bool search(int x);
	bool isEmpty();
	void print();
	void deleteBeg();
	void deleteEnd();
	node * gethead();
	void printrec(node* curr);

private:
	node* head;
};

main()
{
	single ll;
	ll.add_end(1);
	ll.add_end(2);
	ll.add_end(3);
	ll.add_beg(4);
	ll.print();
	cout << "========\n";
	ll.deleteEnd();
	ll.print();
	ll.printrec(ll.gethead());
}
single::single()
{
	head = NULL;
}

void single::add_beg(int x)
{
	node* ptr;
	ptr = new node;
	ptr->data = x;
	ptr->next = head;
	head = ptr;
}

void single::deleteBeg()
{
	if (isEmpty())
		cout << "nothing to delete !!\n";
	else
	{
		node* cur = head;
		head = head->next;
		delete cur;
		cur = NULL;
	}
}
void single::add_end(int x)
{
	node* ptr;
	ptr = new node;
	ptr->data = x;
	ptr->next = NULL;
	if (head == NULL)
		head = ptr;
	else
	{
		node * temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = ptr;
	}
}


void single::deleteEnd()
{
	if (isEmpty())cout << "nothing to delete !!\n";
	else
	{
		if (head->next != NULL)
		{
			node* cur = head;
			node* prev = head;
			while (cur->next != NULL)
			{
				cur = cur->next;
				if (cur->next != NULL)
					prev = cur;
			}
			delete cur;
			prev->next = NULL;
		}
		else
		{
			delete head;
			head = NULL;
		}
	}
}

bool single::search(int x)
{
	node* cur;
	bool flag = false;
	for (cur = head; cur != NULL; cur = cur->next)
	{
		if (cur->data == x)
		{
			flag = true;
			break;
		}
	}
	return flag;
}
void single::print()
{
	if (isEmpty()) cout << "empty list\n";
	else
	{
		node* cur;
		for (cur = head; cur != NULL; cur = cur->next)
			cout << cur->data << "  ";
	}
	cout << endl;
}

node * single::gethead()
{
	return head;
}

void single::printrec(node* curr)
{
	if (curr == NULL)
		return;
	printrec(curr->next);
	cout << curr->data << " ";
}

bool single::isEmpty()
{
	return(head == NULL);
}
//**********************************************************
class Node
{
    public:
    int data;
    Node *next;
};
//1.add at the beginning
void push(Node** head,int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}
//2.add at the end
void append(Node** head, int data) 
{ 
    Node* new_node = new Node();
    Node *last = *head;
    new_node->data = data; 
    new_node->next = NULL; 
    if (*head == NULL) 
    { 
        *head= new_node; 
        return; 
    } 
    while (last->next != NULL)
    {
        last = last->next; 
    }
    last->next = new_node; 
    return; 
} 
//5.print list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}
//3.delete at the beginning
Node* removeFirstNode(struct Node* head)
{
    if (head == NULL)
        return NULL;
    Node* temp = head;
    head = head->next;
 
    delete temp;
 
    return head;
}
//4.delete at the end
Node* removeLastNode(struct Node* head)
{
    if (head == NULL)
        return NULL;
 
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    Node* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    delete (second_last->next);
    second_last->next = NULL;
 
    return head;
}
//6.print in Reverse
void printReverse(Node* head) 
{ 
    if (head == NULL) 
    return; 
    printReverse(head->next); 
    cout << head->data << " "; 
} 
//7.Search for item.
bool search(struct Node* head, int x)
{
    if (head == NULL)
        return false;
    if (head->data == x)
        return true;
    return search(head->next, x);
}
//8.delete minimum
//delete at postion
void deleteNode(Node **head_ref, int position)
{
    if (*head_ref == NULL)
        return;
    Node* temp = *head_ref;
    if (position == 0)
    {
        *head_ref = temp->next; 
        free(temp);             
        return;
    }
    for(int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
     Node *next = temp->next->next;
    free(temp->next); 
    temp->next = next; 
}
int smallestElement(struct Node* head) 
{ 
    int min = INT_MAX; 
    int o=0;
    while (head != NULL) { 
        if (min > head->data) 
            min = head->data; 
  
        head = head->next; 
        o++;
    } 
    cout<<" inside small o"<<o<<"\n";
    return o;
} 

 
int main()
{
    int ch,val;
    Node* head = NULL;
	do
	{ 
		cout << "options are\n";
		cout <<"1. Add at beginning\n";
		cout <<"2. Add at end\n";
		cout <<"3. delete at the beginning\n";
		cout <<"4. Delete at end\n";
		cout <<"5. print\n";
		cout <<"6. Reverse Order Print\n";
		cout <<"7. Search for an item\n";
		cout <<"8. Delete the minimum element\n";
		cout <<"9. Exit\n";
		cout <<"Enter option:";
		cin >> ch;
		switch(ch){
		case 1:
			cout <<"Pls Enter a value\n";
			cin>>val;
			push(&head,val);
			break;
		case 2:
			cout <<"pls Enter a value\n";
			cin>>val;
			append(&head, val);
			break;
		case 3:
			head = removeFirstNode(head);
			printList(head); 
			cout<<"\n";
			break;
		case 4:
			head = removeLastNode(head);
			printList(head);
			cout<<"\n";
			break;
		case 5:
			cout <<"the linked list is:";
			printList(head); 
			cout<<"\n";
			break;
		case 6:
			cout <<"Reversed list\n";
			 printReverse(head); 
			break;
		case 7:
			cout <<"pls enter the item you want to search for\n";
			cin>>val;
			search(head, val)? cout << "Yes\n" : cout << "No\n";
			break;
		case 8:
		cout <<"minimum deleted\n";
		    val=smallestElement(head);
		    deleteNode(&head,val-1);
			printList(head);
			cout<<"\n";
			break;
		case 9:
			cout <<"program out, thanks";
			break;
		default :
			cout <<"Invalid option\n";
			break;
		}
	}
	while(ch!=9);

    return 0;
}