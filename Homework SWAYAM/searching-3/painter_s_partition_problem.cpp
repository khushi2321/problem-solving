bool isPossible(vector <int> &arr, int n, int m, int mid)

{

int painterCount = 1; 

int boardPaintTime = 0;

 

for(int i = 0; i<n; i++)

{

if(boardPaintTime + arr[i] <= mid)

boardPaintTime+=arr[i];

 

else

{

painterCount++;

 

if(painterCount > m or arr[i] > mid)

return false;

 

boardPaintTime = arr[i]; 

}

}

 

return true;

}

 

int findLargestMinDistance(vector<int> &arr, int m)

{



int n = arr.size();

if(m > n) 

return -1;

 

int sum = 0, s = 0;
