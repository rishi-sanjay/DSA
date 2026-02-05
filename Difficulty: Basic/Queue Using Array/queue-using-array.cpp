class myQueue {
    int top;
    int sz;
    int *arr;
    int end;
    int ce;
  public:
    myQueue(int n) {
        // Define Data Structures
        top=-1;
        end=-1;
        sz=n;
        arr=new int[n];
        ce=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(ce==0) return true;
        return false;
    }

    bool isFull() {
        // check if the queue is full
        if(ce==sz) return true;
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(ce==sz) return ;
        if(ce==0){
            top=0;
            end=0;
        }else{
            end=(end+1)%sz;
        }
        arr[end]=x;
        ce+=1;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(ce==0) return ;
        if(ce==1){
             top=-1;
             end=-1;
        }
        top=(top+1)%sz;
        ce-=1;
        
    }

    int getFront() {
        // Returns the front element of the queue.
        if(ce==0) return -1;
        return arr[top];
    }

    int getRear() {
        // Return the last element of queue
        if(ce==0) return -1;
        return arr[end];
    }
};