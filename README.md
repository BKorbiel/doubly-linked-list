# Doubly Linked List of pointers
> This project is simple implementation of doubly linked list with several functions.

## Table of Contents
* [General Info](#general-information)
* [Functions](#functions)

## General Information
This is the structure of a single node:
`
struct MY_LIST { <br/>
    long long int* data; <br/>
    MY_LIST* prev; <br/>
    MY_LIST* next; <br/>
};  
`
"Data" field is pointer to long long int. "Prev" and "next" fields are pointers to neighbour nodes. <br/> 
The program uses dynamic memory and doesn't cause memory leaks. <br/>
The list is represented by its first node.

## Functions
- MY_LIST* NewNode() - creates new node and allocates dynamic memory. The "prev" and "next" fields are assigned a null value. Returns the created node.
- void DeleteNode(MY_LIST* node) - deletes node given in the argument.
- void Clear(MY_LIST** list) - deletes every node of the list given in the argument.
- void ChangeValue(MY_LIST** list, int index, long long int* data) - changes value of the element with the index given in the second argument. The third argument is pointer to new value. The first argument is pointer to pointer to the list that this item is in.
- void InsertPrev(MY_LIST** list, int index, long long int* data) - inserts a new node before the index given in the second argument. The third argument is inserted node "data" field. The first argument represents list (pointer to pointer to the first node).
- void InsertNext ( MY_LIST** list, int index, long long int* data) - same as InsertPrev, but the new node is inserted after the index given in the second argument.
- void PushFront(MY_LIST** list, long long int* data) - inserts new node at index 0.
- void PushBack(MY_LIST** list, long long int* data) - inserts a new item at the end of the list.
- void Remove(MY_LIST** list, int index) - removes element at given index.
- void RemoveFront(MY_LIST** list) - removes the first element of the list.
- void RemoveBack(MY_LIST** list) - removes the last element of the list.
- void RemoveFirstByValue(MY_LIST** list, long long int value) - removes the first element whose "data" field points to the same number as the one in the second argument.
- void RemoveAllByValue(MY_LIST** list, long long int value) - removes all elements whose "data" field point to the same number as the one in the second argument.
- long long int* Get(MY_LIST* list, int index) - returns "data" field of the element at given index.
- long long int* GetFirst(MY_LIST* list) - returns "data" field of the first element.
- long long int* GetLast(MY_LIST* list) - returns "data" field of the last element.
- int Find(MY_LIST* list long long int value) - returns index of the first element whose "data" fields points to the same number as the one given in the second argument.
- int GetLength(MY_LIST* array) - return length of the array.
