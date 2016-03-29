/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method

    if (headA == 0)
        return headB;
    else if (headB == 0)
        return headA;
    
    Node *toRet, *smaller, *greater, *prev, *temp;
    
    if (headA->data <= headB->data) {
        toRet = headA;
        smaller = headA;
        greater = headB;
    }
    else {
        toRet = headB;
        smaller = headB;
        greater = headA;
    }

    while (smaller) {
        if (smaller->data <= greater->data) {
            prev = smaller;
            smaller = smaller->next;
            
        }
        else {
            temp = smaller;
            prev->next = greater;
            prev = greater;
            smaller = greater->next;
            greater = temp;
        }
    }
    prev->next = greater;
    
    return toRet;
    
}