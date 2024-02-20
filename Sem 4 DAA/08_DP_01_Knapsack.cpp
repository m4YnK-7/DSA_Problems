#include <bits/stdc++.h>
using namespace std;

/*
Aim : To return maximum profit for given knapsack data.
Time Complexity : O(n^2)
Space Complexity : O(n^2)

*/

int main(){
    // For easier I/O
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    
    //Initialising data
    int n;
    cout<<"Enter number of items\n";
    cin>>n;
    int total_capacity,current_capacity=0;
    cout<<"Enter the M of the knapsack \n";
    cin>>total_capacity;

    int profit[n],weight[n],total_profit = 0;
    int table[n+1][total_capacity+1];

    for(int i=0;i<n;i++){
        cout<<"Enter the profits of the item "<<i+1<<": \n";
        cin>>profit[i];
        cout<<"Enter the weight of the item "<<i+1<<": \n";
        cin>>weight[i];
    }

    // Dynamic Programming
    for(int i=0;i<=n;i++){
        for(int j=0;j<=total_capacity;j++){
            if(i==0 || j==0){
                table[i][j] = 0;
            }
            else if((j-weight[i-1])>=0){
                table[i][j] = max(table[i-1][j],(table[i-1][j-weight[i-1]]+profit[i-1]));
            }
            else{
                table[i][j] = max(table[i][j-1],table[i-1][j]);
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=total_capacity;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"The maximum profit is: "<<table[n][total_capacity];
    return 0;
}

