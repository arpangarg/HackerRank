/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
#include <map>
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method.
    int toRet = -1;
    bool done = false;
    Node *temp = headB;
    while ((headA != 0) && (!done)) {
        temp = headB;
        while (temp != 0) {
            if (temp == headA) {
                toRet = temp->data;
                done = true;
                break;
            }
            temp = temp->next;
        }
        headA = headA->next;
    }
    return toRet;
}