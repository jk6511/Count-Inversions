#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
   
    long long int inversionCount(long long int arr[], long long int N){
        long long int ans[N];
        return mergesrt(arr,ans,0,N-1);
        
        
    }
    long long int mergesrt(long long int arr[],long long int ans[],long long int left,long long int right ){
        long long int mid, count=0;
        if(left<right){
            mid=(left+right)/2;
            count+=mergesrt(arr,ans,left,mid);
            count+=mergesrt(arr,ans,mid+1,right);
            count+=merge(arr,ans,left,mid,right);
        }
        return count;
    }
    long long int merge(long long int arr[],long long int ans[],long long int left,long long int mid,long long int right){
        long long int sum=0;
        long long int i=left;
        long long int j=mid+1;
        long long int k=left;
        while(i<=mid && j<=right){
            if(arr[i]<=arr[j]){
                ans[k++]=arr[i++];
            }
            else{
                ans[k++]=arr[j++];
                sum+=mid-i+1;
                
            }
        }
        while(i<=mid){
            ans[k++]=arr[i++];
        }
        while(j<=right){
            ans[k++]=arr[j++];
        }
        for(long long int p=left;p<=right;p++){
            arr[p]=ans[p];
        }
        return sum;
    }

};



int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  
