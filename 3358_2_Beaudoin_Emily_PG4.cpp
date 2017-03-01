#include <iostream>
#include <ctime>
#include <cstdlib>

struct ListNode //node structure
{
	int number; //data
	list *next; //pointer to next node
}

appendNode(int);
insertNode(int); //inserts a node at the beginning
insertNode(int,int); //inserts a node containing a position
deleteNode(int); //deletes a node with contents
deleteNodeAt(int); //deletes a node at position 
displayListForward(); 
displayListBackwards();
splitList();
deleteList();

#include <iostream>
#include <ctime>
#include <cstdlib>

struct ListNode //node structure
{
	int number; //data
	list *next; //pointer to next node
}

appendNode(ListNode *, int);
insertNode(ListNode *, int); //inserts a node at the beginning
insertNode(ListNode *, int,int); //inserts a node containing a position(starting at 0)
deleteNode(ListNode *, int); //deletes a node with contents
deleteNodeAt(ListNode *, int); //deletes a node at position 
displayListForward(ListNode *); 
displayListBackwards(ListNode *);
splitList(ListNode *);
deleteList(ListNode *);

int main ()
{
	ListNode *head = NULL; //initializing the main empty list
	int SIZE_OF_MAIN = 19;

	//build a sorted list of 12 random integers between 10 and 20
	insertNode(head, -100);
	insertNode(head, 15,2); //inserts 15 at 3rd position in list
	appendNode(head, 1000);
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
