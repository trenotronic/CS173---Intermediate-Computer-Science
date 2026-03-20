//==============================================================
// Tren Meckel
// April 10 2024
// List.cpp
// This file contains the class method definitions for
// the List class.
//==============================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

//==============================================================
// default constructor
// creates a new empty list
// PARAMETERS: none
// RETURN VALUE: none
//==============================================================
template <typename T>
	List<T>::List  ( void )
{
	size = 0;
	capacity = DEFAULT_LIST_SIZE;
	list = new T[capacity];
	
}

//==============================================================
// copy constructor
// creates a new list object as a copy of another list
// PARAMETERS:
//    const List<T> &l: Reference to the list to be copied
// RETURN VALUE: none
//==============================================================
template <typename T>
	List<T>::List(const List<T> &l) 
{
   	capacity = l.capacity;
   	size = l.size;
    	list = new T[capacity];
    	for (int i = 0; i < size; ++i) 
    	{
        	list[i] = l.list[i];
    	}
}

//==============================================================
// destructor
// cleans up the memory allocated for the list
// PARAMETERS: none
// RETURN VALUE: none
//==============================================================
template <typename T> 
	List<T>::~List ( void ) 
{
	delete[] list;
}
//==============================================================
// operator=
// assigns one list to another list
// PARAMETERS:
//    const List<T> &l: Reference to the list to be assigned
// RETURN VALUE:
//    List<T>: Reference to the assigned list
//==============================================================
template <typename T>
	List<T> List<T>::operator=(const List<T> &l) 
{
    	if (this != &l) 
    	{
        	delete[] list;
        	capacity = l.capacity;
        	size = l.size;
        	list = new T[capacity];
        	for (int i = 0; i < size; ++i) 
        	{
            		list[i] = l.list[i];
            	 }
    	}
	return *this;
}

//==============================================================
// append
// appends an item to the end of the list
// PARAMETERS:
//    T item: The item to be appended to the list
// RETURN VALUE: none
//==============================================================
template <typename T> 
void	List<T>::append ( T item )
{
 	if ( size == capacity )
 	{
 	reallocate();
 	}
 	
	list[size] = item;
	size++;
 
}
//==============================================================
// insert  ( item, position )
// inserts an item into the list at the specified position
// PARAMETERS:
//    T item: The item to be inserted into the list
//    int position: The position at which the item should be inserted
// RETURN VALUE: none
//==============================================================
template <typename T>
void 	List<T>::insert(T item, int position) 
{
   	if (position < 0 || position > size) 
   	{
        	cout << "Invalid position for insertion." << endl;
        	return;
    	}
   	if (size == capacity) 
   	{
        	reallocate();
    	}
    	for (int i = size; i > position; --i) 
    	{
        	list[i] = list[i - 1];
    	}
    	list[position] = item;
    	size++;
}

//==============================================================
// length
// returns the number of items in the list
// PARAMETERS: none
// RETURN VALUE:
//    int: The number of items in the list
//==============================================================
template <typename T>
int 	List<T>::length() const 
{
   	return size;
}

//==============================================================
// operator[]
// Valid indices are 0 to size-1.   Invalid indices generate
// a run-time error and end the program.
// accesses an item in the list by index
// PARAMETERS:
//    int position: The index of the item to be accessed
// RETURN VALUE:
//    T&: Reference to the item at the specified index
//==============================================================
template <typename T>
T &	List<T>::operator[](int position) 
{
    	if (position < 0 || position >= size) 
    	{
        	cout << "Invalid index." << endl;
        	exit(1);
    	}
   	return list[position];
}

//==============================================================
// remove
// Valid indices are 0 to size-1.   Invalid indices generate
// a run-time error and end the program.
// removes an item from the list at the specified position
// PARAMETERS:
//    int position: The position of the item to be removed
// RETURN VALUE: none
//==============================================================
template <typename T>
void 	List<T>::remove(int position) 
{
    	if (position < 0 || position >= size) 
    	{
        	cout << "Invalid position for removal." << endl;
        	return;
    	}
   	for (int i = position; i < size - 1; ++i) 
   	{
        	list[i] = list[i + 1];
    	}
    	size--;
}

//==============================================================
// isEmpty
// checks if the list is empty
// PARAMETERS: none
// RETURN VALUE:
//    bool: true if the list is empty, false otherwise
//==============================================================
template <typename T>
bool 	List<T>::isEmpty() const 
{
   	return size == 0;
}

//==============================================================
// operator+  (concatenate two lists)
// concatenates two lists into a new list
// PARAMETERS:
//    const List<T> &l: Reference to the second list to be concatenated
// RETURN VALUE:
//    List<T>: New list containing the concatenated items
//==============================================================
template <typename T>
List<T> 	List<T>::operator+(const List<T> &l) const 
{
    	List<T> result;
    	result.capacity = capacity + l.capacity;
   	result.size = size + l.size;
    	result.list = new T[result.capacity];
    	for (int i = 0; i < size; ++i) 
    	{
        	result.list[i] = list[i];
    	}
    	for (int i = 0; i < l.size; ++i) 
    	{
        	result.list[size + i] = l.list[i];
    	}
    	return result;
}

//==============================================================
// clear
// clears all items from the list
// PARAMETERS: none
// RETURN VALUE: none
//==============================================================
template <typename T>
void 	List<T>::clear() 
{
	delete[] list;
	capacity = DEFAULT_LIST_SIZE;
    	size = 0;
    	list = new T[DEFAULT_LIST_SIZE];
}

//==============================================================
// reallocate
// double the size of the array holding the list
// *** If you choose to implement this.  It is not part of the
// public interface so you may opt to do something different. ***
// doubles the capacity of the list
// PARAMETERS: none
// RETURN VALUE: none
//==============================================================
template <typename T>
void 	List<T>::reallocate() 
{
    	capacity *= 2;
    	T *newList = new T[capacity];
    	for (int i = 0; i < size; ++i) 
    	{
        	newList[i] = list[i];
    	}
    	delete[] list;
    	list = newList;
}

//==============================================================
