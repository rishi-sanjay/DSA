class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
  Node *temp;
  Node *head;
  int count;
  public:
    myQueue() {
        // Initialize your data members
        temp;
        head;
        count=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(count==0) return true;
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        
        
        Node *ne=new Node(x);
        if(count==0){
            temp=ne;
            head=temp;}
        else{
           head->next=ne;
           head=ne;
    }
    count+=1;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(count==0) return ;
        temp=temp->next;
        count-=1;
        return;
    }

    int getFront() {
        // Returns the front element of the queue
        if(count==0) return -1;
        return temp->data;
        // If queue is empty, return -1
    }

    int size() {
        // Returns the current size of the queue.
        return count;
    }
};
