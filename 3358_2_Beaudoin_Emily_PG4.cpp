#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct ListNode //node structure
{
	int value; //data
	ListNode *next; //pointer to next node
};

void appendNode(ListNode *, int);
void insertNode(ListNode *, int); //inserts a node at the beginning
void insertNode(ListNode *, int,int); //inserts a node containing a position(starting at 0)
void deleteNode(ListNode *, int); //deletes a node with contents
void deleteNodeAt(ListNode *, int); //deletes a node at position 
void displayListForward(ListNode *, bool); //displays list forward(T) or backward(F)
void splitList(ListNode *, const int);
void deleteList(ListNode *);

int main ()
{
	ListNode *head = NULL; //initializing the main empty list
	const int SIZE_OF_LIST = 19;
	srand(time(NULL));

	//build a sorted list of 12 random integers between 10 and 20
	insertNode(head, -100);
	insertNode(head, 15,2); //inserts 15 at 3rd position in list
	appendNode(head, 1000);
	deleteNode(head, 5);
	deleteNodeAt(head, 1); //removes 2nd node from the list



}

void appendNode(ListNode *h, int num)
{

}

//inserts node containing num at the beginning of the list
//works whether or not the list is empty
void insertNode(ListNode *h, int num)
{
	ListNode *newNode;

	newNode = new ListNode; //dynamically allocates new node
	newNode->value = num; //assigns num to node value
	newNode->next = h; //makes new node point to head
	h = newNode; //makes head point to new node
}

void insertNode(ListNode *h, int num, int position)
{

}


//code taken from linkedlist notes
void deleteNode(ListNode *h, int num)
{
	if (!h) //empty list, exit
		return;

	ListNode *p; //to traverse the list
	if(h->value == num){ //if first node is num
		p = h;
		h = p->next;
		delete p;
	}
	else{ 
		ListNode *previous; //trailing pointer
		p = h; //traversal start at first node

		while(p && p->value != num){ //searches for index of num
			previous = p; //saves
			p = p->next; //advances
		}

		if(p){ //num was found, deletes node
			previous->next = p->next;
			delete p;
		}
		else{ //num was not found, outputs message
			cout << num << "was not in the list" << endl;
		}
	}
}

void deleteNodeAt(ListNode *h, int num)
{

}

void displayListForward(ListNode *h, bool f)
{

} 


void splitlist(ListNode *h, const int size)
{

}

void deleteList(ListNode *h)
{
	
}
	deleteNode(head, 5);
	deleteNodeAt(head, 1); //removes 2nd node from the list



}

appendNode(ListNode *h, int num)
{

}

insertNode(ListNode *h, int num)
{

}

insertNode(ListNode *h, int num, int position)
{

}

deleteNode(ListNode *h, int num)
{

}

deleteNodeAt(ListNode *h, int num)
{

}

displayListForward(ListNode *h)
{

} 

displayListBackwards(ListNode *h)
{

}

splitlist(ListNode *h)
{

}

deleteList(ListNode *h)
{
	
}
