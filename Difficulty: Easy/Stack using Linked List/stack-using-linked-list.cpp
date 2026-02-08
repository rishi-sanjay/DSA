/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {
   Node* temp;
   int count;
   
  public:
    myStack() {
        // Initialize your data members
        temp=nullptr;
        count=0;
    }

    bool isEmpty() {
        // check if the stack is empty
        if(temp==nullptr) return true;
        return false;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node *ne=new Node(x);
        ne->next=temp;
        temp=ne;
        count+=1;
    }

    void pop() {
        // Removes the top element of the stack
        if(temp==nullptr) return;
           count-=1;
           temp=temp->next;
           return;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(temp==nullptr ) return -1;
        return temp->data;
    }

    int size() {
        // Returns the current size of the stack.
        return count;
    }
};