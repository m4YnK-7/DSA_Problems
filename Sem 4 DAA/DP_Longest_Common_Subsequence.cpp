#include<bits/stdc++.h>
using namespace std;

int main(){
    string A = "longest";
    string B = "stone";
        
    int n = A.length(), m = B.length();
    int lcs[6][8] = {0};

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(A[j-1]==B[i-1]){
                lcs[i][j] = 1 + lcs[i-1][j-1];    
            }
            else{
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    cout<<lcs[m][n]<<endl;

    for (int i = 0; i < m+1; i++){
        for (int  j = 0; j<n+1; j++){
            cout<<lcs[i][j]<<" ";
        }
        cout<<endl; 
    }

    string cs = "";
    for(int i=0;i<n;i++){
        if(lcs[m][i]!=lcs[m][i+1]){
            cs += A[i];
        }
    }
    cout<<cs;
    return 0;
}