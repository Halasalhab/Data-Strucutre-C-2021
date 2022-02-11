#include<iostream>
using namespace std;
struct node
{
	int data;
	node *lp;
	node *rp;
};

class tree
{
private:
	node * root=NULL;
public:
	node * minimum();
	int height(node *);
	int total_nodes(node *);
	int leavesCount (node *);
	void insert( int );
	node * getroot();
	bool search(int);
	void inorder(node *);
    int internal (node *);
	void search_rec(node * , int, node * &);
};

node * tree::minimum()
{
	node * cur=root;
	while(cur->lp != NULL)
		cur = cur->lp;
	return cur;
}

int tree::height(node * p)  
{  
	if (p == NULL)  
		return 0;  
	else
	{  
		int lH = height(p->lp);  
		int rH = height(p->rp);  

		if (lH > rH)  return(lH + 1);  
		else return(rH + 1);  
	}  
}  

int tree::total_nodes(node * p)
{
	if (p!= NULL)
		return (1+ total_nodes(p->lp)+total_nodes(p->rp));
	else return 0;
}

int tree::leavesCount (node *p)
{
	if (p== NULL)
		return 0;
	else if ((p->lp==NULL)&&(p->rp==NULL))
		return 1;
	else
		return (leavesCount (p->lp)+ leavesCount (p->rp));
}

node * tree::getroot()
{
	return root;
}

void tree::inorder(node * p)
{
	if (p != NULL)
	{
		inorder(p->lp);
		cout << p->data << " ";
		inorder(p->rp);
	}
}

void tree::insert( int item)
{
	node *cur; 
	node *trailCur; 
	node *newNode;
	newNode = new node;
	newNode->data = item;
	newNode->lp = NULL;
	newNode->rp = NULL;
	if (root == NULL)
		root = newNode;
	else
	{
		cur = root;
		while (cur != NULL)
		{
			trailCur = cur;
			if (cur->data == item)
			{
				cout << "The item is already in the tree ";
				return;
			}
			else if (cur->data > item)
				cur = cur->lp;
			else
				cur = cur->rp;
		}
		if (trailCur->data > item)
			trailCur->lp = newNode;
		else
			trailCur->rp = newNode;
	}
}

int tree::internal (node * p)
{

	if((p== NULL)||((p->lp==NULL) &&(p->rp==NULL)))
		return 0;
	else
		return 1+(internal(p->lp)+internal(p->rp));

}

void tree::search_rec(node * p, int key, node * & pos)
{
	if(p== NULL) pos= NULL;
	else if (key== p->data)
		pos= p;
	else if (key<= p->data)
		search_rec(p->lp, key, pos);
	else
		search_rec(p->rp, key, pos);
}


main()
{
	tree t;
	t.insert( 9); t.insert(10); t.insert(6); t.insert( 12); t.insert( 15); 
	t.inorder(t.getroot());
	node * loc = t.minimum();
	if (loc) cout<<endl<<"minimum="<<loc->data;
	cout<<endl<<"Height:"<<t.height(t.getroot());
	cout<<endl<<"Total:"<<t.total_nodes(t.getroot());
	cout<<endl<<"Leaves:"<<t.leavesCount(t.getroot());
}
