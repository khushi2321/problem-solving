class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    int s=1;
	    int e=m;
	    while(s<=e)
	    {
	        int mid =(s+e)/2;
	        int power=(int)Math.pow(mid,n);
	        if(power==m)return mid;
	        if(power>m) e=mid-1;
	        else s=mid+1;
	    }
	    return -1;
	}  
};