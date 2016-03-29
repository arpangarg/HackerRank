/*
  Detect loop in a linked list 
  List could be empty also
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int HasCycle(Node* head)
{
   // Complete this function
   // Do not write the main method
    
    if (head == 0)
        return 0;
    
    int count = 0;
    Node *temp = head;
    Node *temp2;
    
    while (temp) {
        count++;
        temp = temp->next;
        temp2 = head;
        for (int i = 0; i < count; i++) {
            if (temp == temp2)
                return 1;
            temp2 = temp2->next;
        }
    }
    return 0;
    
}