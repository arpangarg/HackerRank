/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    
    int count = 0;
    Node *temp = head;
    while (temp) {
        temp = temp->next;
        count++;
    }
    
    temp = head;
    
    for (int i = 0; i < count - positionFromTail - 1; i++)
        temp = temp->next;
    
    return temp->data;
    
}