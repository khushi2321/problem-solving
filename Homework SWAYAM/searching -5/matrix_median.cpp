public class Solution {
    public int findMedian(int[][] A) {
         int max = Integer.MIN_VALUE;
         int min = Integer.MAX_VALUE;
         for(int i=0;i<A.length;i++){
             max = Math.max(max,A[i][A[i].length-1]);
             min = Math.min(min,A[i][0]);
         }
         int median = (1+A.length*A[0].length)/2;
         while(min<max){
             int total_count = 0;
              int mid = min + (max -min)/2;
              for(int i=0;i<A.length;i++){
              int index = Arrays.binarySearch(A[i],mid);
             
               if(index<0){
                   index = Math.abs(index)-1;
               }else{
                   
                   while(index<A[i].length && A[i][index]==mid){
                       index++;
                   }
               }
               total_count += index;
         if(total_count<median){
             min = mid + 1;
         }else{
             max = mid;
         }
             
         }
         return min;
    }
}
