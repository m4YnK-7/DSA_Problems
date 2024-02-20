#include <bits/stdc++.h>
using namespace std;

void sorting(int n,float* values,int* profit,int* weight,int *x);

int main(){
    // For easier I/O.
    // #ifndef IO
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    // Initialising data
    int n;
    cout<<"Enter number of items\n";
    cin>>n;
    int total_capacity,current_capacity=0;
    cout<<"Enter the M of the knapsack \n";
    cin>>total_capacity;

    int profit[n],weight[n],x[n] = {0};
    float values[n] = {0}, total_profit = 0;

    for(int i=0;i<n;i++){
        cout<<"Enter the profits of the item "<<i+1<<": \n";
        cin>>profit[i];
        cout<<"Enter the weight of the item "<<i+1<<": \n";
        cin>>weight[i];
        values[i] = float(weight[i])/(float)profit[i];
    }

    // Sorting all arrays based on values
    sorting(n,values,profit,weight,x);

    // Greedy logic
    for (int i=0;i<n;i++){
        if(total_capacity>current_capacity+weight[i]){
            current_capacity+= weight[i];
            total_profit += profit[i];
            x[i] = 1;
        }
        else{
            float frac = (total_capacity-current_capacity)/(float)weight[i] ;
            x[i] = frac;
            total_profit += frac*profit[i];
            break;
        }
    }

    cout<<"Maximum profit is "<<total_profit;
    return 0;
}

void sorting(int n,float* values,int* profit,int* weight,int *x){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(values[j]>values[j+1]){
                swap(values[j],values[j+1]);
                swap(profit[j],profit[j+1]);
                swap(weight[j],weight[j+1]);
                swap(x[j],x[j+1]);
            }
        }
    }
    return;
}

/*
Example : 
7
15
p = 10,5,15,7,6,18,3
w = 2,3,5,7,1,4,1
*/