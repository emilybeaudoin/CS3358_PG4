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
void displayList(ListNode *&);
void displayList(ListNode *&, int); //displays list backward
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
	insertNode(head, 15, 3, size); //inserts 15 at 3rd position in list
	appendNode(head, 1000, size);
	deleteNode(head, 5, size);
	deleteNodeAt(head, 2, size); //removes 2nd node from the list
	rotateList(head);
	searchList(head, 17);
	displayList(head, size); //displays list backwards
	splitList(head, size);
	//deleteDuplicates(head, size);
	//deleteList(head, size);
	searchList(head, 35);

	return 0;

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

	cout << "A sorted main list of " << size << " random integer numbers" << endl
	 	 << "that are between 10 and 20 are as follows:" << endl;
	displayList(h);
	cout << endl;

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

	cout << "Main List after appending new number " << num << ":" << endl;
	displayList(h);
	cout << endl;

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

	cout << "Main List after inserting new number " << num 
	     << " at the beginning:" << endl;
	displayList(h);
	cout << endl;

	size++;
}

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

	cout << "Main list after rotating the list one position to the right:" << endl;
	displayList(h);
	cout << endl;

}

void searchList(ListNode *&h, int num)
{
	cout << "Searching the main list for number " << num << endl;
	if (!h){ //empty list, exit
		cout << "List empty" << endl;
		return;
	}

	ListNode *p = h; //to traverse the list
	int position = 1;

	if(h->value == num){ //if first node is num
		cout << "Item " << num << " found at location " << position  << endl;
	}
	else{ 
		while(p && p->value != num){ //searches for index of num
			p = p->next; //advances
			position++;
		}

		if(!p){ 
			cout << num << " was not in the list" << endl;
		}
		else{
			cout << "Item " << num << " found at location " << position  << endl;
		}
	}
	cout << endl;
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
			cout << num << " was not in the list" << endl;
		}
	}

	cout << "Main list after removing number " << num << ":" << endl;
	displayList(h);
	cout << endl;

	size--;
}

//deletes a node from a specific position in the list
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

void deleteDuplicates(ListNode *&h, int &size)
{
	ListNode *p, //to traverse the list
		 *previous,
	         *ptr; //to hold the node searchind for duplicates on
	
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

//displays list forward
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

//displays list backwards
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

void displayUnion(ListNode *&h1, ListNode *&h2)
{
	//display the union of two list sets
}


//****problem with this, displays duplicates
void displayIntersection(ListNode *&h1, ListNode *&h2)
{
	ListNode *ptr1,//first list traversal
			 *ptr2;//second list traversal

	ptr1 = h1;

	cout << "Intersection of two lists:" << endl;

	while(ptr1){ //continues until all values of list 1 are checked with list 2
		ptr2 = h2; //resets to beginning of second list

		while(ptr2 && ptr2->value != ptr1->value) //finds node with same value
			ptr2 = ptr2->next; 
		if(ptr2) //if value was found, prints result
			cout << ptr2->value << " ";

		ptr1 = ptr1->next; //advances
	}
	cout << endl;
}

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
    cout << endl;

    //display union 
    //displayIntersection(headSub1, headSub2);
    //rejoin sublists into main list

    ptr->next = headSub2;

}

void deleteList(ListNode *&h, int &size)
{
	//code

	size = 0;
}
