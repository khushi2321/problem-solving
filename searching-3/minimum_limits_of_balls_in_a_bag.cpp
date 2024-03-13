class Solution {
public:
    bool possible(vector<int> v,long long int mid,int op)
    {
        int cnt=0;
        for(long int i=0;i<v.size();++i)
        {
            cnt+=(v[i]-1)/mid;
            if(cnt>op)
                return 0;
        }
        
        return 1;
    }
    int minimumSize(vector<int>& v, int op) {
        
        long long int l=1;
        long long int h=*max_element(v.begin(),v.end());
        long long int ans=0;
        
        
        while(l<=h)
        {
            long long int mid=l+(h-l)/2;
            if(possible(v,mid,op))
            {
                ans=mid;
                h=mid-1;
            }
            
            else
                l=mid+1;
        }
        
        return ans;
    }
};