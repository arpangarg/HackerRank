/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    
    if (head == 0)
        return head;
    
    Node *prev, *curr;
    prev = head;
    curr = prev->next;
    
    while (curr) {
        if (prev->data == curr->data) {
            curr = curr->next;
            delete prev->next;
            prev->next = curr;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}