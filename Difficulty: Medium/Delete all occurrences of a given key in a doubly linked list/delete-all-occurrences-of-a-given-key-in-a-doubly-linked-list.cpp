/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // code here
        
        Node * temp=*head_ref;
        Node *rem=*head_ref;
        while(temp !=nullptr){
            Node *aage=temp->next;
            if(temp->data == x){
                if(temp->prev !=nullptr){
                    temp->prev->next=aage;
                }else {
                    *head_ref=aage;
                }
                if(aage!= nullptr)
                    aage->prev=temp->prev;
                temp->next=nullptr;
                temp-> prev=nullptr;
            }
            temp=aage;
        }
    }
};