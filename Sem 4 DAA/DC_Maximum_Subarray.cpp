#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int array[n];

    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    
    int max_sf = INT_MIN, max_end = 0;
    int max_sum = 0;
 
    for (int i = 0; i < n; i++) {
        max_end = max_end + array[i];
        if (max_sf < max_end)
            max_sf = max_end;
            max_sum += array[i];
 
        if (max_end < 0) {
            max_end = 0;
            max_sum = 0;
        }
    }

    cout<<"The maximum subarrayay is : ";
    for(int i=max_end;i<max_sf;i++){
        cout<<array[i]<<" ";
    }
    cout<<"\nThe maximum sum is : "<<max_sum;

    return 0;
}