# Doubly Linked List of pointers
> This project is simple implementation of doubly linked list with several functions.

## Table of Contents
* [General Info](#general-information)
* [Functions](#functions)

## General Information

- Structure of the head: <br/>
```
struct DBL {
    NODE* first;
    NODE* last;
    int length;
};                       
```
"First" and "last" fields point to the first and the last nodes.

- Structure of a single node: <br/>
```
struct MY_LIST{
    long long int data;
    MY_LIST* prev;
    MY_LIST* next;
};                        
```
"Prev" and "next" fields are pointers to neighbour nodes. <br/><br/>
The program uses dynamic memory and doesn't cause memory leaks. <br/>

## Functions
- DBL* CreateList () - creates new head (list) and allocates dynamic memory. Returns the created head.
- void DeleteList (DBL** list) - deletes head and every node. Changes the pointer to list to NULL value.
- NODE* NewNode() - creates new node and allocates dynamic memory. The "prev" and "next" fields are assigned a NULL value. Returns the created node.
- void DeleteNode(NODE* node) - deletes node given in the argument.
- void ChangeValue(DBL* list, int index, long long int* new_node_data) - changes value of the element with the index given in the second argument. The third argument is pointer to the new value. The first argument is pointer to the head.
- void InsertPrev(DBL* list, int index, long long int* new_node_data) - inserts a new node before the index given in the second argument.
- void InsertNext ( DBL* list, int index, long long int* data) - same as InsertPrev, but the new node is inserted after the index given in the second argument.
- void PushFront(DBL* list, long long int* data) - inserts new node at index 0.
- void PushBack(DBL* list, long long int* data) - inserts a new item at the end of the list.
- void Remove(DBL* list, int index) - removes element at given index.
- void RemoveFront(DBL* list) - removes the first element of the list.
- void RemoveBack(DBL* list) - removes the last element of the list.
- void RemoveFirstByValue(DBL* list, long long int* value) - removes the first element whose "data" field has the same value as that given by the third argument.
- void RemoveAllByValue(DBL* list, long long int* value) - removes all elements whose "data" field has the same value as that given by the third argument.
- long long int Get(DBL* list, int index) - returns "data" field of the element at given index.
- long long int GetFirst(DBL* list) - returns "data" field of the first element.
- long long int GetLast(DBL* list) - returns "data" field of the last element.
- int FindIndex(DBL* list, long long int value) - returns index of the first element whose "data" fields has the same value as that given by the second argument.
- int GetLength(DBL* list) - returns length of the list.
