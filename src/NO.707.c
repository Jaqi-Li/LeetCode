/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/31 16:20
* @version: 1.0
* @description:
********************************************************************************/
#include "../inc/NO.707.h"

MyLinkedList* myLinkedListCreate() {
    MyLinkedList * obj = NULL;
    obj = (MyLinkedList *) malloc(sizeof(MyLinkedList));
    obj->val = -1;
    obj->next = NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    int i = 0;
    MyLinkedList *p = obj->next;
    while (i < index && p){
        p = p->next;
        i++;
    }
    if (!p)
        return -1;
    return p->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {

    MyLinkedList *p = (MyLinkedList *) malloc(sizeof(MyLinkedList));
    p->val = val;
    p->next = obj->next;
    obj->next = p;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *p;
    p = obj->next;
    while (p->next){
        p = p->next;
    }
    MyLinkedList *q = (MyLinkedList *) malloc(sizeof(MyLinkedList));
    q->val = val;
    q->next = NULL;
    p->next = q;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList *p;
    int i = 0;
    p = obj;
    while (p->next && i < index){
        p = p->next;
        ++i;
    }
    if (i!= index && !p->next)
        return;
    MyLinkedList *q = (MyLinkedList *) malloc(sizeof(MyLinkedList));
    q->val = val;
    q->next = p->next;
    p->next = q;

}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList *p;
    MyLinkedList *q;
    int i = 0;
    p = obj;
    while (p->next && i < index){
        p = p->next;
        ++i;
    }
    if (i!= index && !p->next)
        return;
    if (p->next){
        q = p->next;
        p->next = q->next;
        free(q);
    }

}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/