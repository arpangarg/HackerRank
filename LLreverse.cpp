/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
  // Complete this method
    
    if (head == 0)
        return head;

    Node *prev = 0;
    Node *curr = head;
    Node *nextt  = curr->next;
    Node *temp;

    while (curr) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    
    head = prev;
    
    return head;
}