class MyCircularQueue {
public:
    int *arr;
    int size;
    int front;
    int back;
    MyCircularQueue(int k) {
       size=k;
       arr=new int[size];
        front=-1;
        back=-1;
    }
    
    bool enQueue(int value) {
        if((front==0 and back==size-1) or (back==(front-1)%(size)))
        return false;
        if(front==-1)
        {
            front=0;
            back=0;
            arr[back]=value;
        }
       else if(back==size-1 and front!=0)
        {
            back=0;
            arr[back]=value;
            
        }
        else
        {
            back++;
            arr[back]=value;
        }
        return true;
    }
    
    bool deQueue() {
        if(front==-1) return false;
        if(front==back)
        {
            front=-1;
            back=-1;
        }
        else if(front==size-1)
            front=0;
        else
        {
            front++;
        }
        return true;
        
    }
    
    int Front() {
        if(front==-1) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(back==-1) return -1;
        return arr[back];
    }
    
    bool isEmpty() {
        if(front==-1) return true;
        return false;
        
    }
    
    bool isFull() {
          if((front==0 and back==size-1) or (back==(front-1)%(size-1)))
        return true;
        return false;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */