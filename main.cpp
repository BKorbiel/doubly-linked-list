#include  <iostream>

using namespace std;

struct MY_LIST {
    long long int* data;
    MY_LIST* prev;
    MY_LIST* next;
};


MY_LIST* NewNode () {
    MY_LIST* node = new MY_LIST;
    node->data = new long long int;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void DeleteNode ( MY_LIST* node ) {
    delete (node->data);
    delete node;
}

void Clear (MY_LIST** array){
    MY_LIST* walkElem = *array;
    MY_LIST* temp;
    while (walkElem!=NULL)
    {
        temp=walkElem->next;
        DeleteNode(walkElem);
        walkElem=temp;
    }
    *array=NULL;
}

void ChangeValue ( MY_LIST** array, int index, long long int* new_node_data) {
    int i=0;
    MY_LIST* walkElem = *array;
    while (i<index && walkElem!=NULL) {
        walkElem=walkElem->next;
        i++;
    }
    if (walkElem!=NULL) {
        *(walkElem->data) = *new_node_data;
    }
}

void InsertPrev ( MY_LIST** array, int index, long long int* new_node_data) {
    MY_LIST* new_node = NewNode();
    *(new_node->data) = *new_node_data;

    if (*array==NULL) {
        *array=new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else if (index==0) {
        MY_LIST* temp = *array;
        *array = new_node;
        new_node->next = temp;
        new_node->prev = NULL;
        temp->prev = new_node;
    }
    else {
        MY_LIST* walkElem = *array;
        int i=0;
        while (i<index-1 && walkElem->next!=NULL) {
            walkElem = walkElem->next;
            i++;
        }
        if (walkElem->next!=NULL) {
            (walkElem->next)->prev = new_node;
            new_node->next = walkElem->next;
            new_node->prev = walkElem;
            walkElem->next = new_node;
        } else {
            walkElem->next = new_node;
            new_node->prev = walkElem;
            new_node->next = NULL;
        }
    }
}

void InsertNext ( MY_LIST** array, int index, long long int* new_node_data) {
    MY_LIST* new_node = NewNode();
    *(new_node->data) = *new_node_data;

    if (*array==NULL) {
        *array=new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else {
        MY_LIST* walkElem = *array;
        int i=0;
        while (i<index && walkElem->next!=NULL) {
            walkElem = walkElem->next;
            i++;
        }
        if (walkElem->next!=NULL) {
            (walkElem->next)->prev = new_node;
            new_node->next = walkElem->next;
            new_node->prev = walkElem;
            walkElem->next = new_node;
        } else {
            walkElem->next = new_node;
            new_node->prev = walkElem;
            new_node->next = NULL;
        }
    }
}

void PushFront(MY_LIST** array, long long int* new_node_data) {
    InsertPrev(array, 0, new_node_data);
}

void PushBack(MY_LIST** array, long long int* new_node_data) {
    InsertNext(array, 2147483647, new_node_data); //work smart, not hard xD
}

void Remove(MY_LIST** array, int index) {
    if (*array!=NULL) {
        int i=0;
        MY_LIST* walkElem = *array;
        while (i<index && walkElem!=NULL) {
            walkElem = walkElem->next;
            i++;
        }
        if (walkElem!=NULL) {
            if (walkElem->prev!=NULL) {
                if (walkElem->next!=NULL) {
                    (walkElem->prev)->next = walkElem->next;
                    (walkElem->next)->prev = walkElem->prev;
                } else {
                    (walkElem->prev)->next=NULL;
                }
            } else {
                if (walkElem->next!=NULL) {
                    *array=walkElem->next;
                    (walkElem->next)->prev = NULL;
                } else {
                    *array=NULL;
                }
            }
            DeleteNode(walkElem);
        }
    }
}

void RemoveFront(MY_LIST** array) {
    Remove(array, 0);
}

void RemoveBack(MY_LIST** array) {
    if (*array!=NULL) {
        MY_LIST* walkElem = *array;
        while (walkElem->next!=NULL) {
            walkElem=walkElem->next;
        }
        if (walkElem->prev!=NULL) {
            (walkElem->prev)->next=NULL;
        } else {
            *array=NULL;
        }
        DeleteNode(walkElem);
    }
}

void RemoveFirstByValue(MY_LIST** array, long long int value) {
    MY_LIST* walkElem = *array;
    while (walkElem!=NULL && *(walkElem->data)!=value) {
        walkElem=walkElem->next;
    }
    if (walkElem!=NULL) {
        if (walkElem->next!=NULL) {
            if (walkElem->prev!=NULL) {
                (walkElem->prev)->next = walkElem->next;
                (walkElem->next)->prev = walkElem->prev;
            }
            else {
                *array=walkElem->next;
                (walkElem->next)->prev = NULL;
            }
        } else {
            if (walkElem->prev!=NULL) {
                (walkElem->prev)->next = NULL;
            } else {
                *array=NULL;
            }
        }
        DeleteNode(walkElem);
    }
}

void RemoveAllByValue(MY_LIST** array, long long int value) {
    if (*array!=NULL) {
        MY_LIST* walkElem = *array;
        while (walkElem!=NULL) {
            MY_LIST* temp = walkElem->next;
            if (*(walkElem->data)!=value) {

                if (walkElem->next!=NULL) {
                    if (walkElem->prev!=NULL) {
                        (walkElem->prev)->next = walkElem->next;
                        (walkElem->next)->prev = walkElem->prev;
                    }
                    else {
                        *array=walkElem->next;
                        (walkElem->next)->prev = NULL;
                    }
                } else {
                    if (walkElem->prev!=NULL) {
                        (walkElem->prev)->next = NULL;
                    } else {
                        *array=NULL;
                    }
                }
                DeleteNode(walkElem);
            }
            walkElem = temp;
        }
    }
}

long long int* Get(MY_LIST* array, int index) {
    if (array==NULL) {
        return NULL;
    } else {
        int i = 0;
        MY_LIST* walkElem = array;
        while (i<index && walkElem!=NULL) {
            walkElem=walkElem->next;
            i++;
        }
        if (walkElem!=NULL) {
            return walkElem->data;
        }
    }
}

long long int* GetFirst(MY_LIST* array) {
    return Get(array, 0);
}

long long int* GetLast(MY_LIST* array) {
    if (array==NULL) {
        return NULL;
    } else {
        MY_LIST* walkElem = array;
        while (walkElem->next!=NULL) {
            walkElem = walkElem->next;
        }
        return walkElem->data;
    }
}


int Find(MY_LIST* array, long long int value) {
    int result=0;
    MY_LIST* walkElem = array;
    while (walkElem!=NULL) {
        if (*(walkElem->data)==value) {
            return result;
        }
        walkElem = walkElem->next;
        result++;
    }
    return -1;
}

int GetLength(MY_LIST* array) {
    int result = 0;
    MY_LIST* walkElem = array;
    while (walkElem!=NULL) {
        walkElem = walkElem->next;
        result++;
    }
    return result;
}

int main() {
    MY_LIST* listA = NewNode();
    MY_LIST* listB = NewNode();
    cout<<GetLength(listA)<<endl; //1
    cout<<GetLength(listB)<<endl; //1
    long long int a=250, b=127;
    ChangeValue(&listA, 0, &a); //listA = [&a = 250]
    ChangeValue(&listB, 0, &b);  //listB = [&b = 127]
    cout<<*GetFirst(listA)<<endl;  //250
    cout<<*GetLast(listB)<<endl; //127
    long long int d=15515251;
    PushBack(&listA, &d);    //listA = [&a = 250, &d = 15515251]
    PushFront(&listB, &d);  //listB = [&d = 15515251, &b = 127]
    long long int c=7777777777;
    InsertNext(&listA, 1, &c);  //listA = [&a = 250, &d = 15515251, &c=7777777777]
    InsertPrev(&listB, 1, &c);  //listB = [&d = 15515251, &c=7777777777, &b = 127]
    cout<<GetLength(listA)<<" "<<Find(listA, 7777777777)<<endl;   //3 2
    cout<<GetLength(listB)<<" "<<Find(listB, 7777777777)<<" "<<Find(listB, 747)<<endl;  //3 1 -1
    Remove(&listA, 0); //listA = [&d = 15515251, &c=7777777777]
    RemoveFirstByValue(&listB, 127); //listB = [&d = 15515251, &c=7777777777]
    cout<<GetLength(listA)<<" "<<*Get(listA,0)<<endl;  //2 15515251
    cout<<GetLength(listB)<<" "<<*GetFirst(listB)<<" "<<*GetLast(listB); //2 15515251 7777777777
    return 0;
}
