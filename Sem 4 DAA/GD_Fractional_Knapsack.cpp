#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of items ";
    cin>>n;
    int M;
    cout<<"Enter the M of the knapsack ";
    cin>>M;

    int p[n],weight[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the profits of the item "<<i+1<<": ";
        cin>>p[i];
    }

    for(int i=0;i<n;i++){
        cout<<"Enter the weight of the item "<<i+1<<": ";
        cin>>weight[i];
    }

    cout<<"Maximum profit is ";
}

int sorting(int weight[],int p[],int n){
    float value[n] = {0};
    for(int i=0;i<n;i++){
        value[i] = (float)p[i]/(float)weight[i];
    }
}

int* knapsack(int n,int M,int weight[]){
    int x[n] = {0};
    int rem_capacity = M;

    for(int i=0;i<n;i++){
        if(weight[i]<=rem_capacity){
            x[i] = 1;
            rem_capacity-=weight[i];
        }
        if(i<=n){
            x[i] = rem_capacity/weight[i];
            rem_capacity = 0;
        }
    }

    return x;   
}