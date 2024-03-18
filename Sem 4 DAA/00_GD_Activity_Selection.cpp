#include <bits/stdc++.h>
using namespace std;

// Creating a class for easier implementation 
class Activity{
    public:
    int Activity_no;
    int start_time;
    int finish_time;

    Activity(){}

    Activity(int i,int j,int k){
        Activity_no = i;
        start_time = j;
        finish_time = k;
    }
};

int main(){
    // Code for easier I/O.
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    
    // a,b : temporary variables to input start and finish time
    int n,a,b;
    cin>>n;
    Activity arr[n];

    for(int i=0;i<n;i++){
        cin>>a>>b;
        arr[i] = Activity(i+1,a,b);
    }

    // Sorting by finish time
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j].finish_time>arr[j+1].finish_time){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    // Printing selected activity
    cout<<"Activity Selected: \n";
    int current = arr[0].finish_time;
    cout<<arr[0].Activity_no<<"->";
    for(int i=0;i<n-1;i++){
        if(arr[i+1].start_time>current){
            cout<<arr[i+1].Activity_no<<"->";
            current = arr[i+1].finish_time;
        }
    }
    cout<<"END";

    return 0;
}

/*
Sample Input: 
6
0 6
3 4
1 2
5 9
5 7
8 9

Output : 
Activity Selected: 
3->2->5->6->END
*/
