//=================================================
// Tren Meckel
// April 2024
// List.cpp
// Thi file contains the list class methods for the
// linked list implementation of the list ADT
//=================================================

//=================================================
// default constructor
// Creates a new empty list object
// PARAMETERS:
// none
// RETURN VALUE:
// none
//=================================================

template <typename T>
	List<T>::List  ( void ) 
{
	head = nullptr;
}
//=================================================
// copy constructor
// This function constructs a new list by copying
// the contents of another list.
// PARAMETERS:
// mylist: The list to be copied.
// RETURN VALUE:
//=================================================
template <typename T>
	List<T>::List ( const List<T> &mylist ) : head( nullptr ) 
{
    	Node *current = mylist.head;
   	while (current != nullptr) 
    	{
        	append(current->item);
        	current = current->next;
    	}
}



//=================================================
// destructor
// This function deallocates memory used by the list
//=================================================
template <typename T>
	List<T>::~List ( void )
{
	clear();
}
//=================================================
// append
// This method appends a new item onto the end of 
// the linked list
// PARAMETERS:
// - item: a new item of type T to append
// RETURN VALUE:
// none, but changees the list by adding a new
// item on the end
//=================================================
template <typename T>
void	List<T>::append ( const T &item ) 
{
	// Step 1 : create a new node
	Node *qtr = new Node;
	
	// Step 2 : set new node next to null
	qtr->next = nullptr;
	// (*qtr).next = nullptr; (same as above) dereference
	
	// Step 3 : set item to new item
	qtr->item = item;
	
	if ( head == nullptr )
	{
		// special case of empty list
		head = qtr;
	}
	else
	{
		// not empty list
		Node *ptr = head;
		while ( ptr->next != nullptr)
			ptr = ptr->next;
		ptr->next = qtr;
		
	}
	
}

//=================================================
// assignment operator
// This function assigns the contents of another list
// to the current list.
// PARAMETERS:
// mylist: The list to be assigned.
// RETURN VALUE:
// The reference to the modified list.
//=================================================
template <class T>
	List<T> List<T>::operator= ( const List<T> &mylist ) 
{
	if (this != &mylist) 
	{
        	clear();
        	Node *current = mylist.head;
        	while (current != nullptr) 
        	{
            		append(current->item);
            		current = current->next;
        	}
    	}
    return *this;
}
//=================================================
// overloaded subscript operator
// This function allows access to list elements
// using the subscript notation.
// PARAMETERS:
// index: The index of the element to access.
// RETURN VALUE:
// A reference to the element at the specified index.
// Note:
// If the index is out of range, it returns the first element.
//=================================================
template <class T>
	T &List<T>::operator[] ( int index ) 
{
    	Node *current = head;
    	int count = 0;
    	while (current != nullptr) 
    	{
        	if (count == index) 
        	{
            		return current->item;
        	}
        	count++;
        	current = current->next;
    	}
    // Throw an exception or handle error if index is out of range
    // will just return the first element if index is out of range
    return head->item;
}

//=================================================
// insert method
// This method inserts a new item into the list at
// the specified index
// PARAMETERS:
// - item: the item to insert
// - index: the index at which to insert the item
// RETURN VALUE:
// none, but modifies the list by inserting the item
//=================================================
template <class T>
void 	List<T>::insert ( const T &item, int index )  
{
	if (index < 0)
        return; // or throw an exception
    
    	if (index == 0) 
    	{
        	Node *newNode = new Node;
        	newNode->item = item;
        	newNode->next = head;
        	head = newNode;
        	return;
    	}
    
    	Node *current = head;
    	int count = 0;
    	while (current != nullptr && count < index - 1) 
    	{
        	current = current->next;
        	count++;
    	}
    
    	if (current != nullptr) 
    	{
        	Node *newNode = new Node;
        	newNode->item = item;
        	newNode->next = current->next;
        	current->next = newNode;
    	}
}
//=================================================
// remove method
// This method removes the item at the specified
// index from the list
// PARAMETERS:
// - index: the index of the item to remove
// RETURN VALUE:
// none, but modifies the list by removing the item
//=================================================
template <class T>
void	List<T>::remove ( int index ) 
{
    	if (index < 0)
        return; // or throw an exception
    
    	if (index == 0) 
    	{
        	Node *temp = head;
        	head = head->next;
        	delete temp;
        	return;
   	}
    
    	Node *current = head;
    	int count = 0;
    	while (current != nullptr && count < index - 1) 
    	{
        	current = current->next;
        	count++;
    	}
    
    	if (current != nullptr && current->next != nullptr) 
    	{
        	Node *temp = current->next;
        	current->next = current->next->next;
        	delete temp;
   	}
}

//=================================================
// concatenation operator
// This method concatenates two lists
// PARAMETERS:
// - mylist: the list to concatenate with
// RETURN VALUE:
// A new list containing the concatenated elements
//=================================================
template <class T>
List<T> 	List<T>::operator+ ( const List<T> &mylist ) const 
{
    	List<T> result = *this;
    	Node *current = mylist.head;
    	while (current != nullptr) 
    	{
        	result.append(current->item);
        	current = current->next;
    	}
    	return result;
}

//=================================================
// length method
// This method returns the length of the list
// PARAMETERS:
// none
// RETURN VALUE:
// The length of the list
//=================================================
template <class T>
int 	List<T>::length() const 
{
    	int count = 0;
    	Node *current = head;
    	while (current != nullptr) 
    	{
        	count++;
        	current = current->next;
    	}
    	return count;
}

//=================================================
// isEmpty method
// This method checks if the list is empty
// PARAMETERS:
// none
// RETURN VALUE:
// true if the list is empty, false otherwise
//=================================================
template <class T>
bool 	List<T>::isEmpty() const 
{
   	return head == nullptr;
}

//=================================================
// clear method
// This method clears the contents of the list
// PARAMETERS:
// none
// RETURN VALUE:
// none, but clears the list
//=================================================
template <class T>
void 	List<T>::clear() 
{
    	while (head != nullptr) 
    	{
        	Node *temp = head;
        	head = head->next;
        	delete temp;
    	}
}








