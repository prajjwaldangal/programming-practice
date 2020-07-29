//////
//////  main.cpp
//////  LinkedListProb
//////
//////  Created by Prajjwal Dangal on 7/1/18.
//////  Copyright © 2018 Prajjwal Dangal. All rights reserved.
//////
////
////
////// Note: operator keyword can be used to overload, for example,
//////          <<, or + ( void operator+(int i);)
////
//#include <iostream>
//#include <sstream>
//
//using namespace std;
//
//// given in question
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//// this function add digits from two linked lists that have
//// digits in reversed order, e.g.: l1 : 0->8->0->2->0->1 for 102080
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//    ListNode dummy(0);
//    ListNode * ret = &dummy;
//    int c = 0;
//    while (l1 || l2) {
//        int val = c + (l1 ? l1->val : 0) + (l2? l2->val : 0);
//        c = val / 10;
//        ret->next = new ListNode(val % 10);
//        ret = ret->next;
//        if (l1) {
//            l1 = l1->next;
//        }
//
//        if (l2) {
//            l2 = l2->next;
//        }
//    }
//    ret->next = new ListNode(c);
//    return dummy.next;
//}
//
//int main(int argc, const char * argv[]) {
//    ListNode * L1 = new ListNode(2);
//    L1->next = new ListNode(4);
//    L1->next->next = new ListNode(3);
//
//    ListNode * L2 = new ListNode(5);
//    L2->next = new ListNode(6);
//    L2->next->next = new ListNode(4);
//
//    ListNode * ret = addTwoNumbers(L1, L2);
//    cout << "addrsess of variable in main: " << &ret << endl;
//    cout << "addrsess of linked list in main: " << ret << endl;
//    cout << "342 + 465 = " ;
//    while (ret) {
//        cout << ret->val;
//        ret = ret->next;
//    }
//
//    return 0;
//}
//
//
////////////////////// linked list/////////////////////
//
////int main(int argc, const char * argv[]) {
////
////}


#include <stdio.h>


int main() {
    int arr[5] = {3, 7, 9, 2, 0};
    
}
