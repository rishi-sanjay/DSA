class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());
        int i=0,ans=0;
        for(int val:t){
            if(i>=p.size()) break;
            if( val<p[i] )continue;
            ans+=1;
            i+=1;
        }
        return ans;
    }
};