class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> s;
        int sz=arr.size();
        for(int i=sz-1;i>=0;i--){
            int x=arr[i];
            while(!s.empty() && s.top()>=arr[i])
               s.pop();
        if(s.empty())
             arr[i]=-1;
        else 
            arr[i]=s.top();
        s.push(x);
        }
    return arr;
    }
};