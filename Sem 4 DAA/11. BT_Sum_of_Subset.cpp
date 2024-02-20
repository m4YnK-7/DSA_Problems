#include<bits/stdc++.h>
using namespace std;

bool func(int n,int m,int arr[],int x[],int sum){
    for(int i=n-1;i>=0;i--){
        sum+= arr[i];
        x[i] = 1;

        if(sum == m){
            return 0;
        }
        else if (sum>m || n==0){

        }
    }
    
}

int main(){
    int n = 6,M = 30;
    int arr[n] = {5,10,12,13,15,18};
    int x[n] = {0};
}