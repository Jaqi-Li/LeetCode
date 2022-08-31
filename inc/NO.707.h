/********************************************************************************
* @author: Li jiaqi
* @email: 547222867@qq.com
* @date: 2022/8/31 16:20
* @version: 1.0
* @description:
********************************************************************************/

#ifndef LEETCODE_NO_707_H
#define LEETCODE_NO_707_H

#include <stdio.h>
#include <malloc.h>

typedef struct {
    int val;
    struct MyLinkedList * next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate();

int myLinkedListGet(MyLinkedList* obj, int index);

void myLinkedListAddAtHead(MyLinkedList* obj, int val);

void myLinkedListAddAtTail(MyLinkedList* obj, int val);

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);

void myLinkedListFree(MyLinkedList* obj);

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
#endif //LEETCODE_NO_707_H
