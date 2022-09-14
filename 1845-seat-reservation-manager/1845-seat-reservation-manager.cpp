class SeatManager {
public:
    priority_queue <int, vector<int>, greater<int>> g;
    int max=0;
    SeatManager(int n) {
     max=n;  
        for(int i=1;i<=n;i++)
            g.push(i);
    }
    
    int reserve() {
        int ans=g.top();
        g.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber<=max)
        {g.push(seatNumber);}
        return;
        
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */