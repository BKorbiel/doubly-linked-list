#include  <iostream>

using namespace std;


struct NODE {
    long long int data;
    NODE* prev;
    NODE* next;
};

struct DBL { //head
    NODE* first;
    NODE* last;
    int length;
};

DBL* CreateList () {
    DBL* list = new DBL;
    list->first = NULL;
    list->last = NULL;
    list->length = 0;
    return list;
}

NODE* NewNode () {
    NODE* node = new NODE;
    node->data = 0;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void DeleteNode ( NODE* node ) {
    delete node;
}

void DeleteList (DBL** list){
    if (*list==NULL) {
        return;
    }
    NODE* walkElem = (*list)->first;

    NODE* temp;
    while (walkElem!=NULL)
    {
        temp=walkElem->next;
        DeleteNode(walkElem);
        walkElem=temp;
    }
    delete *list;
    *list=NULL;
}

void ChangeValue ( DBL* list, int index, long long int* new_node_data) {
    if (list==NULL || (list->length)<=index) {
        return;
    }
    NODE* walkElem;
    if (index>(list->length)/2) {
        int i=(list->length)-1;
        walkElem = list->last;
        while (i>index) {
            walkElem=walkElem->prev;
            i--;
        }
    }
    else {

        int i=0;
        walkElem = list->first;
        while (i<index) {
            walkElem=walkElem->next;
            i++;
        }
    }
    walkElem->data = *new_node_data;
}

void InsertPrev ( DBL* list, int index, long long int* new_node_data) {
    if (list==NULL || (list->length)<=index) {
        return;
    }

    NODE* new_node = NewNode();
    new_node->data = *new_node_data;

    if (index==0) {
        new_node->prev=NULL;
        new_node->next=list->first;
        (list->first)->prev=new_node;
        list->first=new_node;
        (list->length)+=1;
        return;
    }

    NODE* walkElem;
    if (index>(list->length)/2) {
        int i=(list->length)-1;
        walkElem = list->last;
        while (i>index) {
            walkElem = walkElem->prev;
            i--;
        }
    }
    else {
        int i=0;
        walkElem = list->first;
        while (i<index) {
            walkElem = walkElem->next;
            i++;
        }
    }

    (list->length)+=1;
    new_node->prev = walkElem->prev;
    new_node->next = walkElem;
    (walkElem->prev)->next = new_node;
    walkElem->prev = new_node;
}

void InsertNext ( DBL* list, int index, long long int* new_node_data) {
    NODE* new_node = NewNode();
    new_node->data = *new_node_data;

    if (list==NULL || (list->length)<=index) {
        return;
    }

    NODE* walkElem;
    if (index>(list->length)/2) {
        int i=(list->length)-1;
        walkElem = list->last;
        while (i>index) {
            walkElem = walkElem->prev;
            i--;
        }
    }
    else {
        int i=0;
        walkElem = list->first;
        while (i<index) {
            walkElem = walkElem->next;
            i++;
        }
    }

    (list->length)+=1;
    new_node->prev = walkElem;
    new_node->next = walkElem->next;
    walkElem->next = new_node;
    if (new_node->next!=NULL) {
        (new_node->next)->prev = new_node;
    }
}

void PushFront(DBL* list, long long int* new_node_data) {
    if (list==NULL) {
        return;
    }
    (list->length)+=1;
    NODE* new_node = NewNode();
    new_node->data = *new_node_data;

    new_node->prev = NULL;
    new_node->next = list->first;
    if (list->first!=NULL) {
        (list->first)->prev = new_node;
    }
    list->first=new_node;
    if (list->length==1) {
        list->last = new_node;
    }

}

void PushBack(DBL* list, long long int* new_node_data) {
    if (list==NULL) {
        return;
    }
    (list->length)+=1;
    NODE* new_node = NewNode();
    new_node->data = *new_node_data;

    new_node->next = NULL;
    new_node->prev = list->last;
    if (list->last!=NULL) {
        (list->last)->next = new_node;
    }
    list->last=new_node;
    if (list->length==1) {
        list->first = new_node;
    }
}

void Remove(DBL* list, int index) {
    if (list==NULL || (list->length)<=index) {
        return;
    }

    NODE* walkElem;
    if (index>(list->length)/2) {
        int i=(list->length)-1;
        walkElem = list->last;
        while (i>index) {
            walkElem = walkElem->prev;
            i--;
        }
    }
    else {
        int i=0;
        walkElem = list->first;
        while (i<index) {
            walkElem = walkElem->next;
            i++;
        }
    }

    (list->length)-=1;
    if (index==list->length) {
        list->last=walkElem->prev;
    } else {
        (walkElem->next)->prev = walkElem->prev;
    }
    if (index==0) {
        list->first=walkElem->next;
    } else {
        (walkElem->prev)->next = walkElem->next;
    }

    DeleteNode(walkElem);
}

void RemoveFront(DBL* list) {
    Remove(list, 0);
}

void RemoveBack(DBL* list) {
    if (list==NULL) {
        return;
    }

    Remove(list, (list->length)-1);
}

void RemoveFirstByValue(DBL* list, long long int* value) {
    if (list==NULL) {
        return;
    }

    NODE* walkElem = list->first;

    while (walkElem!=NULL && walkElem->data!=*value) {
        walkElem=walkElem->next;
    }

    if (walkElem!=NULL) {
        (list->length)-=1;
        if (walkElem->next==NULL) {
            list->last=walkElem->prev;
        } else {
            (walkElem->next)->prev = walkElem->prev;
        }
        if (walkElem->prev==NULL) {
            list->first=walkElem->next;
        } else {
            (walkElem->prev)->next = walkElem->next;
        }
        DeleteNode(walkElem);
    }

}

void RemoveAllByValue(DBL* list, long long int* value) {
    if (list==NULL) {
        return;
    }

    NODE* walkElem = list->first;

    while (walkElem!=NULL) {
        NODE* temp = walkElem->next;
        if (walkElem->data==*value) {
            (list->length)-=1;
            if (walkElem->next==NULL) {
                list->last=walkElem->prev;
            } else {
                (walkElem->next)->prev = walkElem->prev;
            }
            if (walkElem->prev==NULL) {
                list->first=walkElem->next;
            } else {
                (walkElem->prev)->next = walkElem->next;
            }
            DeleteNode(walkElem);
        }
        walkElem = temp;
    }
}

long long int Get(DBL* list, int index) {
    if (list==NULL || index>=(list->length)) {
        return NULL;
    }

    NODE* walkElem;
    if (index>(list->length)/2) {
        int i=(list->length)-1;
        walkElem = list->last;
        while (i>index) {
            walkElem = walkElem->prev;
            i--;
        }
    }
    else {
        int i=0;
        walkElem = list->first;
        while (i<index) {
            walkElem = walkElem->next;
            i++;
        }
    }

    return walkElem->data;
}

long long int GetFirst(DBL* list) {
    if (list==NULL || list->length<1) {
        return NULL;
    }
    return (list->first)->data;
}

long long int GetLast(DBL* list) {
    if (list==NULL || list->length<1) {
        return NULL;
    }
    return (list->last)->data;
}


int FindIndex(DBL* list, long long int value) {
    if (list==NULL) {
        return -1;
    }
    int result=0;
    NODE* walkElem = list->first;
    while (walkElem!=NULL) {
        if (walkElem->data==value) {
            return result;
        }
        walkElem = walkElem->next;
        result++;
    }
    return -1;
}

int GetLength(DBL* list) {
    if (list==NULL){
        return NULL;
    }
    return list->length;
}

int main() {
    
    /**************************EXAMPLES**********************************/
    DBL* listA = CreateList();
    DBL* listB = CreateList();

    cout<<GetLength(listA)<<endl; //0
    cout<<GetLength(listB)<<endl; //0

    long long int a=250, b=127;
    PushFront(listA, &b); //listA = [&b = 127]
    PushFront(listB, &a); //listB = [&a = 250]

    ChangeValue(listA, 0, &a); //listA = [&a = 250]
    ChangeValue(listB, 0, &b);  //listB = [&b = 127]
    cout<<GetFirst(listA)<<endl;  //250
    cout<<GetLast(listB)<<endl; //127

    long long int d=15515251;
    PushBack(listA, &d);    //listA = [&a = 250, &d = 15515251]
    PushFront(listB, &d);  //listB = [&d = 15515251, &b = 127]

    long long int c=7777777777;
    InsertNext(listA, 1, &c);  //listA = [&a = 250, &d = 15515251, &c=7777777777]
    InsertPrev(listB, 1, &c);  //listB = [&d = 15515251, &c=7777777777, &b = 127]

    cout<<GetLength(listA)<<" "<<FindIndex(listA, 7777777777)<<endl;   //3 2
    cout<<GetLength(listB)<<" "<<FindIndex(listB, 7777777777)<<" "<<FindIndex(listB, 747)<<endl;  //3 1 -1

    Remove(listA, 0); //listA = [&d = 15515251, &c=7777777777]
    RemoveFirstByValue(listB, &b); //listB = [&d = 15515251, &c=7777777777]

    cout<<GetLength(listA)<<" "<<Get(listA,0)<<endl;  //2 15515251
    cout<<GetLength(listB)<<" "<<GetFirst(listB)<<" "<<GetLast(listB)<<endl; //2 15515251 7777777777

    PushBack(listA, &d);
    InsertNext(listA, 1, &d); //listA = [&d = 15515251, &c=7777777777, &d = 15515251, &d = 15515251];
    DeleteList(&listB); //listB=NULL

    cout<<GetLength(listA)<<" "<<GetLength(listB)<<endl; //4, 0

    RemoveAllByValue(listA, &d);
    cout<<GetLength(listA)<<endl; //1

    DeleteList(&listA);
    cout<<GetLength(listA)<<endl; //0
    
    
    return 0;
}

