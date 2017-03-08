// Authors: Emily Beaudoin - 4, Alex Olsen - 30
// Due Date: 02/8/17
// Assignment Number: 4
// Spring - 2017 - CS 3358 - 2
// Instructor: Husain Gholoom
//
// This program randomly generates 19 integers, ranging from 10-19, and stores
// them in a linked list. The program then sorts the values in the list from
// least to greatest. Once the list is sorted, the program begins to execute
// several operations that alter the list and its integers. After each
// alteration, the program displays a message that states what changes were made
// and displays the new list.

// The user is able to re-run the program as desired before voluntarily exiting
// the program.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct ListNode //node structure
{
	int value; //data
	ListNode *next; //pointer to next node
};

void buildSortedList(ListNode *&, int); //creates a sorted list of random
// numbers
void appendNode(ListNode *&, int, int &); //inserts a node at the end
void insertNode(ListNode *&, int, int &); //inserts a node at the beginning
void insertNode(ListNode *&, int, int, int &); //inserts a node containing a
// position(starting at 0)
void rotateList(ListNode *&);//rotates list one position to the right
void searchList(ListNode *&, int); //searches the list for specific value
void deleteNode(ListNode *&, int, int &); //deletes a node with contents
void deleteNodeAt(ListNode *&, int, int &); //deletes a node at position
void deleteDuplicates(ListNode *&, int &); //deletes duplicate integers, if any
void displayList(ListNode *&); //displays the integers in the list
void displayList(ListNode *&, int); //displays list backward
void displayUnion(ListNode *&, ListNode *&);
void displayIntersection(ListNode *&, ListNode *&);
void splitList(ListNode *&, int); //splits one list into two separate lists
void deleteList(ListNode *&, int &); //deletes entire list

int main ()
{
        char answer; //represents user's answer to re-run program
	srand(time(NULL));

    do
    {
        ListNode *head = NULL; //initializing the main empty list
	int size = 19; //size of list starts at 19

        buildSortedList(head, size); //builds a sorted list of integers
	insertNode(head, -100, size); //inserts -100 to the beginning of the list
	insertNode(head, 15, 3, size); //inserts 15 at 3rd position in list
	appendNode(head, 1000, size); //inserts 1000 to the end of the list
	deleteNode(head, 5, size); //deletes integer 5 from the list, if any
	deleteNodeAt(head, 2, size); //removes 2nd node from the list
	rotateList(head); //rotates all integers in the list to the right
	searchList(head, 17); //searches the list of integers for 17
	displayList(head, size); //displays list backwards
	splitList(head, size); //splits one list into two separate lists
	deleteDuplicates(head, size); //deletes duplicate integers, if any
	deleteList(head, size); //deletes entire list
	searchList(head, 35); //searches the list of integers for 35

	cout << "Would you like to re-run the program again\n"
	     << "Enter Y or N   --->   ";
        cin >> answer; //user's answer

        while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n')
	// loop to ensure correct data type entered
        {
            cout << "\nERROR *** Invalid selection " << answer
                 << " - Must be y|Y or n|N\n\n\n"
                 << "Would you like to re-run the program again\n"
                 << "Enter Y or N   --->   ";
            cin >> answer;
        }

        cout << "\n";

    }while(answer == 'Y' || answer == 'y');

    cout << "This LL program is implemented by Alex Olsen and Emily Beaudoin\n"
	     << "March - 2017\n";

	return 0;
}

// *****************************************************************************
// buildSortedList function: creates a sorted list of random integers.
//
// h - represents the head, or beginning, of the list.
// size - represents the size of the list.
//******************************************************************************

void buildSortedList(ListNode *&h, int size){
	ListNode *newNode, //ptr to new node
			 *ptr, //ptr to traverse list
			 *previous; //holds previous node address during traversal
	int num;

	for(int i = 0; i < size; i++){ //creates list of SIZE nodes, in ascending
// order

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

	cout << "A sorted main list of " << size << " random integer numbers"
	 	 << "that are between 10 and 20 are as follows:" << endl;
	displayList(h);
	cout << endl;
}

// *****************************************************************************
// appendNode function: inserts an integer to the end of the list.
//
// h - represents the head, or beginning, of the list.
// num - represents the integer being added to the list.
// size - represents the size of the list.
//******************************************************************************

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

	cout << "Main List after appending new number " << num << ":" << endl;
	displayList(h);
	cout << endl;

	size++;
}

// *****************************************************************************
// insertNode function: inserts an integer at the beginning of the list.
//
// h - represents the head, or beginning, of the list.
// num - represents the integer being added to the list.
// size - represents the size of the list.
//******************************************************************************

void insertNode(ListNode *&h, int num, int &size)
{
	ListNode *newNode;

	newNode = new ListNode; //dynamically allocates new node
	newNode->value = num; //assigns num to node value
	newNode->next = h; //makes new node point to head
	h = newNode; //makes head point to new node

	cout << "Main List after inserting new number " << num
	     << " at the beginning:" << endl;
	displayList(h);
	cout << endl;

	size++;
}

// *****************************************************************************
// insertNode function: inserts an integer at a given position in the list.
//
// h - represents the head, or beginning, of the list.
// num - represents the integer being added to the list.
// position - represents the position where the integer will be inserted.
// size - represents the size of the list.
//******************************************************************************

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

	cout << "Main List after inserting new number " << num
	     << " at the " << position << " location:" << endl;
	displayList(h);
	cout << endl;

	size++;
}

// *****************************************************************************
// rotateList function: rotates the integers one position to the right.
//
// h - represents the head, or beginning, of the list.
//******************************************************************************

void rotateList(ListNode *&h)
{
	ListNode *ptr; //traversal pointer

	if(!h){ //empty list, exit
		return;
	}

	ptr = h; //sets ptr to beginning
	while(ptr->next->next){ //goes to the second to last node
		ptr = ptr->next;
	}

	ptr->next->next = h; //makes last node point to first
	h = ptr->next; //resets last as first
	ptr->next = NULL; //makes new end of list point to NULL

	cout << "Main list after rotating the list one position to the right:\n";
	displayList(h);
	cout << endl;
}

// *****************************************************************************
// searchList function: searches the list for a specific integer.
//
// h - represents the head, or beginning, of the list.
// num - represents the integer being searched for.
//******************************************************************************

void searchList(ListNode *&h, int num)
{
	cout << "Searching the main list for item number " << num << ":" << endl;
	if (!h){ //empty list, exit
		cout << "List empty" << endl << endl;
		return;
	}

	ListNode *p = h; //to traverse the list
	int position = 1;

	if(h->value == num){ //if first node is num
		cout << "Item " << num << " found at location " << position  << "\n";
	}
	else{
		while(p && p->value != num){ //searches for index of num
			p = p->next; //advances
			position++;
		}

		if(!p){
			cout << num << " was not in the list" << "\n";
		}
		else{
			cout << "Item " << num << " found at location " << position
			     << "\n";
		}
	}
	cout << endl;
}

// *****************************************************************************
// deleteNode function: deletes a specific integer from the list.
//
// h - represents the head, or beginning, of the list.
// num - represents the integer being deleted.
// size - represents the size of the list.
//******************************************************************************

void deleteNode(ListNode *&h, int num, int &size)
{
    cout << "Main list after removing number " << num << ":" << endl;

	if (!h) //empty list, exit
		return;

	ListNode *p; //to traverse the list
	if(h->value == num){ //if first node is num
		p = h;
		h = p->next;
		delete p;
		displayList(h); //displays list after integer has been deleted
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
			displayList(h); //displays list after integer has been deleted
		}
		else{ //num was not found, outputs message
			cout << num << " was not in the list" << endl;
		}
	}

	cout << endl;

	size--;
}

// *****************************************************************************
// deleteNodeAt function: deletes integer from the list at a specific location.
//
// h - represents the head, or beginning, of the list.
// position - represents the position of the integer being deleted.
// size - represents the size of the list.
//******************************************************************************

void deleteNodeAt(ListNode *&h, int position, int &size)
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

    cout << "Main list after removing the " << position << " element:" << endl;
    displayList(h);
    cout << endl;

	size--;
}

// *****************************************************************************
// deleteDuplicates function: deletes duplicate integers from the list.
//
// h - represents the head, or beginning, of the list.
// size - represents the size of the list.
//******************************************************************************

void deleteDuplicates(ListNode *&h, int &size)
{
	ListNode *p, //to traverse the list
		 *previous,
	         *ptr; //to hold the node searching for duplicates on

	ptr = h;

	while(ptr){
		p = ptr;


	 	while(p && p->next){ //
	 		previous = p; //saves
	 		p = p->next; //advances

	 		if(p->value == ptr->value){
	 			previous->next = p->next;
	 			delete p;
	 			p = previous;
	 			size--;
	 		}
		}

		ptr = ptr->next;
	}

	cout << "Main list after deleting duplicate numbers:" << endl;
	displayList(h);
	cout << endl;
}

// *****************************************************************************
// displayList function: displays the integers contained in the list.
//
// h - represents the head, or beginning, of the list.
//******************************************************************************

void displayList(ListNode *&h)
{
	ListNode *ptr; //to traverse list

	ptr = h; //points to beginning

	while(ptr){ //while ptr does not point to NULL
		cout << ptr->value << " ";

		ptr = ptr->next; //advances
	}
	cout << endl;
}

// *****************************************************************************
// displayList function: displays the integers contained in the list backwards.
//
// h - represents the head, or beginning, of the list.
// size - represents the size of the list.
//******************************************************************************

void displayList(ListNode *&h, int size)
{
	ListNode *ptr;

	cout << "Displaying the main list backward:" << endl;

	for(int i = size; i >= 0; i--){ //goes through size times
		ptr = h; //resets at beginning
		for(int j = 0; j < i; j++) //goes to last number yet to be displayed
			ptr = ptr->next;
		cout << ptr->value << " ";
	}

	cout << endl << endl;
}

// *****************************************************************************
// displayUnion function: displays the union of sub list 1 and sub list 2.
//
// h1 - represents the head, or beginning, of Sub List 1.
// h2 - represents the head, or beginning, of Sub List 2.
//******************************************************************************

void displayUnion(ListNode *&h1, ListNode *&h2)
{
	ListNode *h, //reconnects both sub list's
	         *p, //to traverse the list
		     *previous,
	         *ptr; //to hold the node searching for duplicates on

    h = h1; //makes h point to sub list 1

    while(h1->next){
        h1 = h1->next; //traverses sub list 1
    }
    h1->next = h2; //connects sub list 1 to sub list 2

    ptr = h; //makes point to reconnected list

	while(ptr){
		p = ptr; //makes p point to ptr

	 	while(p && p->next){ //prevent p from being null
	 		previous = p; //saves
	 		p = p->next; //advances

	 		if(p->value == ptr->value){ //checks for duplicates
	 			previous->next = p->next;
	 			delete p; //removes duplicate
	 			p = previous;
	 		}
		}
		ptr = ptr->next;
	}

    cout << "The Union of Sub List 1 and Sub List 2:\n";

    while(h) //displays the union of sub list 1 and sub list 2
    {
        cout << h->value << " ";
        h = h->next;
    }

    cout << "\n\n";
}

// *****************************************************************************
// displayIntersection function: displays the intersection of two lists.
//
// h1 - represents the head, or beginning, of the first list.
// h2 - represents the head, or beginning, of the second list.
//******************************************************************************

void displayIntersection(ListNode *&h1, ListNode *&h2)
{
	ListNode *ptr1,//first list traversal
	         *ptr2,//second list traversal
		     *intersection = NULL, // head of intersection list
		     *newNode,
		     *ptr,
		     *p,
		     *previous;

	ptr1 = h1;

	cout << "Intersection of two lists:" << endl;
//determining intersection
	while(ptr1){ //continues until all values of list 1 are checked with list 2
		ptr2 = h2; //resets to beginning of second list

		while(ptr2 && ptr2->value != ptr1->value) //finds node with same value
			ptr2 = ptr2->next;
		if(ptr2){ //if value was found, adds result to intersection list
	        newNode = new ListNode; //dynamically allocates new node
	        newNode->value = ptr2->value; //assigns num to node value
		    newNode->next = intersection; //makes new node point to head
			intersection = newNode; //makes head point to new node;
		}
			
		ptr1 = ptr1->next; //advances
	}

//deleting duplicates from intersection list
	ptr = intersection;

	while(ptr){
		p = ptr;


	 	while(p && p->next){ //
	 		previous = p; //saves
	 		p = p->next; //advances

	 		if(p->value == ptr->value){
	 			previous->next = p->next;
	 			delete p;
	 			p = previous;
	 		}
		}

		ptr = ptr->next;
	}

//display the list and delete the nodes
	ptr = intersection; //points to beginning

	while(ptr){ //while ptr does not point to NULL
		cout << ptr->value << " ";
		previous = ptr; //saves
		ptr = ptr->next; //advances
		delete previous; //deletes node that was already printed
	}

	cout << endl << endl;
}


// *****************************************************************************
// splitList function: splits the list of integers into two separate lists.
//
// h - represents the head, or beginning, of the list.
// size - represents the size of the list.
//******************************************************************************

void splitList(ListNode *&h, int size)
{
	ListNode *headSub1,
			 *headSub2,
		     *ptr; //for traversal
	int sizeSub1 = 10, //determined by assignment
		sizeSub2 = size - 10; //leftover

	cout << "Splitting the main list into 2 sub lists:" << endl;

	if (size > sizeSub1){ //ensures list is large enought to split
		headSub1 = h;
		headSub2 = h; //to start traversal

		for (int i = 0; i < sizeSub1; i++){ //goes to tenth node
				ptr = headSub2; //save
				headSub2 = ptr->next; //advance
		}

		ptr->next = NULL; //splits the list
    }
    else{
        cout << "Not enough nodes to split the list" << endl;
        return; //exits if not enough nodes to split
    }

    cout << "Sub List 1:" << endl;
    displayList(headSub1);
    cout << endl;

    cout << "Sub List 2:" << endl;
    displayList(headSub2);
    cout << endl << endl;

    //display union
    //displayIntersection(headSub1, headSub2);
    //rejoin sublists into main list

    ptr->next = headSub2;
}

// *****************************************************************************
// deleteList function: deletes all integers in the list.
//
// h - represents the head, or beginning, of the list.
// size - represents the size of the list.
//******************************************************************************

void deleteList(ListNode *&h, int &size)
{
	ListNode *p;

	while(h)
    {
        p = h;
        h = h->next;
        delete p;
        ListNode *p;
    }

    cout << "Delete the entire main list\n\n";
	size = 0;
}
