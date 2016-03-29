/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    
    int count = 0;
    Node *temp = head;
    while (temp) {
        temp = temp->next;
        count++;
    }
    
    while (count > 0) {
        temp = head;
        for (int i = 0; i < count - 1; i++) {
            temp = temp->next;
        }
        cout << temp->data << endl;
        count--;
    }
    
}