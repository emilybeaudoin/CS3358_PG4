#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct ListNode //node structure
{
	int value; //data
	ListNode *next; //pointer to next node
};

void buildSortedList(ListNode *&, int); //creates a sorted list of random numbers
void appendNode(ListNode *&, int, int &);
void insertNode(ListNode *&, int, int &); //inserts a node at the beginning
void insertNode(ListNode *&, int, int, int &); //inserts a node containing a position(starting at 0)
void rotateList(ListNode *&);//rotates list one position to the right
void searchList(ListNode *&, int);
void deleteNode(ListNode *&, int, int &); //deletes a node with contents
void deleteNodeAt(ListNode *&, int, int &); //deletes a node at position
void deleteDuplicates(ListNode *&, int &); 
void displayListForward(ListNode *&, bool, int); //displays list forward(T) or backward(F)
void displayUnion(ListNode *&, ListNode *&);
void displayIntersection(ListNode *&, ListNode *&);
void splitList(ListNode *&, int);
void deleteList(ListNode *&, int &);

int main ()
{
	ListNode *head = NULL; //initializing the main empty list
	int size = 19; //size of list starts at 19
	srand(time(NULL));

	buildSortedList(head, size);
	insertNode(head, -100, size);
	//insertNode(head, 15, 2, size); //inserts 15 at 3rd position in list
	appendNode(head, 1000, size);
	deleteNode(head, 5, size);
	//deleteNodeAt(head, 1, size); //removes 2nd node from the list
	rotateList(head);
	//searchList(head, 17);
	displayListForward(head, false, size);
	//splitList(head, size);
	//deleteDuplicates(head, size);
	deleteList(head, size);


	//testing display function:
	/*
	buildSortedList(head, SIZE_OF_LIST);
	displayListForward(head, true, SIZE_OF_LIST);
	displayListForward(head, false, SIZE_OF_LIST);
	*/





}

//creates a sorted list of random numbers
void buildSortedList(ListNode *&h, int size){
	ListNode *newNode, //ptr to new node
			 *ptr, //ptr to traverse list
			 *previous; //holds previous node address during traversal
	int num;

	for(int i = 0; i < size; i++){ //creates list of SIZE nodes, in ascending order

		num = ((rand() % 10) + 10); //randomly generates a number 10-19

		newNode = new ListNode; //dynamically allocates a new node
		newNode->value = num; //stores random number in node

		if(!h){ //if list is empty, insert at front
			h = newNode;
			newNode->next = NULL;
		}
		else{
			ptr = h;
			previous = NULL;

			while(ptr && ptr->value < num){ //goes to last node less than num
				previous = ptr; //saves
				ptr = ptr->next; //advances
			}

			if (!previous){ //insert before first
				h = newNode;
				newNode->next = ptr;
			}
			else{ //inserts before the larger number
				previous->next = newNode;
				newNode->next = ptr;
			}

		}
	}

} 

void appendNode(ListNode *&h, int num, int &size)
{
	ListNode *newNode, //points to new node
			 *ptr; //ptr to traverse the list

	//allocates a new node and stores num
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;

	if(!h) //if list is empty newNode is first/last node
		h = newNode;
	else{
		ptr = h;

		while(ptr->next) //while not at the last position in the list
			ptr = ptr->next; //advance

		ptr->next = newNode; //appends node to the end
	}

	size++;
}

//inserts node containing num at the beginning of the list
//works whether or not the list is empty
void insertNode(ListNode *&h, int num, int &size)
{
	ListNode *newNode;

	newNode = new ListNode; //dynamically allocates new node
	newNode->value = num; //assigns num to node value
	newNode->next = h; //makes new node point to head
	h = newNode; //makes head point to new node

	size++;
}

//inserts node containing num at a specific position in the list
void insertNode(ListNode *&h, int num, int position, int &size)
{
    ListNode *newNode = new ListNode; //dynamically allocates new node
    ListNode *p; //pointer to traverse the list
    ListNode *n; //pointer to traverse the list
    newNode->value = num; //assigns num to newNode value
    n = h; //makes n point to head

    if(position == 1){
        h = newNode; //makes h point to newNode
        newNode->next = n; //makes newNode point to n
    }
    else{
        for(int i = 0; i < position-1; i++)
        {
            p = n; //makes p point to n
            n = n->next; //makes n point to next node
        }
        p->next = newNode; //makes p point to newNode
        newNode->next = n; //makes newNode point to n
    }
	size++;
}

void rotateList(ListNode *&h)
{
	ListNode *ptr; //traversal pointer

	if(!h){ //empty list, exit
		return;
	}

	ptr = h; //sets ptr to beginning
	while(ptr->next){ //goes to the last node
		ptr = ptr->next;
	}

	ptr->next = h; //makes last node point to first
	h = ptr; //resets last as first
}

void searchList(ListNode *&h, int num)
{

}

//code taken from linkedlist notes
void deleteNode(ListNode *&h, int num, int &size)
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

	size--;
}

//deletes a node from a specific position in the list 
void deleteNodeAt(ListNode *&h, int num, int &size)
{
    ListNode *p; //keeps record of list
    ListNode *node; //node to be deleted
    node = h; //makes node point to head

    if(position == 1){
            p = node->next; //makes p point to next node
            h = p; //makes head point to p
    }
    else{
        for(int i = 0; i < position-1; i++)
        {
            p = node; //makes p point to node
            node = node->next; //makes node point to the next node
        }
        p->next = node->next; //connects the list so node can be deleted
    }

    delete node; //deletes node
	size--;
}

void deleteDuplicates(ListNode *&h, int &size){

	//code

}

void displayListForward(ListNode *&h, bool f, int size)
{
	ListNode *ptr; //to traverse list

	if(f){ //displays forward
		ptr = h; //points to beginning

		while(ptr){ //while ptr does not point to NULL
			cout << ptr->value << "   ";

			ptr = ptr->next; //advances
		}
		cout << endl;
	}
	else{ //displays backwards
		for(int i = size - 1; i >= 0; i--){ //goes through size times
			ptr = h; //resets at beginning
			for(int j = 0; j < i; j++) //goes to last number yet to be displayed
				ptr = ptr->next;
			cout << ptr->value << "   "; 
		}
		cout << endl;
	}
} 


void splitlist(ListNode *&h, int size)
{
	ListNode *headSub1,
			 *headSub2,
		     *ptr; //for traversal

	if (size > 10){ //ensures list is large enought to split
		headSub1 = h;
		headSub2 = h; //to start traversal

		for (int i = 0; i < 10; i++){ //goes to ninth node
				ptr = headSub2;
				headSub2 = ptr->next;
		}
		
		ptr->next = NULL; //splits the list
    }
    else{
        cout << "Not enough nodes to split the list" << endl;
        return; //exits if not enough nodes to split	
    }

    //display original list and sub lists
    //display union and intersection of sub lists
    //rejoin sublists into main list


}

void deleteList(ListNode *&h, int &size)
{
	//code

	size = 0;
}
