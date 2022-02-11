#include <iostream>
using namespace std;


//Sequential search:

int seqSearch(int list[], int length, int item)
{
	int loc;
	bool found = false;
	loc=0;
	while (loc<length && !found)
		if (list[loc]==item)
			found =true;
		else
			loc++;

	if (found )
		return loc;
	else
		return -1;

}

main ()
{	
	int list[6]={4,6,1,9,3,7};
	int x=seqSearch(list,6,3);
	cout<<list[x]<<" found at index "<<x<<endl;
}

//Binary search:
int binSearch(int list[], int length, int item)
{
	int first=0;
	int last=length-1;
	int mid;
	bool found=false;
	while (first<=last && !found)
	{
		mid=(first+last)/2;
		if (list[mid]==item)
			found=true;
		else if (list[mid]>item)
			last=mid-1;
		else
			first=mid+1;
	}
	if (found )
		return mid;
	else
		return -1;

}
main ()
{	
	int list[7]={1,3,4,5,6,7,9};
	int x=binSearch(list,7,7);
	cout<<list[x]<<" found at index "<<x<<endl;
}
