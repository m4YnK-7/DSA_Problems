#include<iostream>
#include<algorithm>
using namespace std;

#define inf 99

int** create_adjm(int n){
    // 2-D array using Dynamic allocation
    int** adjm = new int*[n+1];
    for(int i=0;i<n+1;i++){
        
        adjm[i] = new int[n+1];
        for (int k=0;k<n+1;k++){adjm[i][k] = inf;}

        if(i!=0){ // To make the first array 0
            int e,x,w;
            // cout<<"Enter the no of edges for vertices "<<i+1<<": ";
            cin>>e;
            // cout<<"Enter the vertices and cost connected: ";
            for(int j=0;j<e;j++){
                cin>>x>>w;
                adjm[i][x] = 1;
            }
        } 
    } 
    // Displaying adjm
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){cout<<adjm[i][j]<<" ";}
        cout<<endl;
    } 
    return adjm;
}

int main(){

    int n;
    cin>>n;

    // Required data structures for prims algo
    int** adjm = create_adjm(n);
    int near[n+1] = {inf};
    int path[2][n-1];

    // Finding minimum cost b/w any vertices
    int minm,u,v;
    for (int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            minm = min(minm,adjm[i][j]);
            u = i;
            v = j;
        }
    }

    path[0][0] = u;path[0][1] = v;
    near[u] = 0;near[v] = 0;

    // Filling the near array
    for(int i=1;i<=n;i++){
        if(near[i]!=0 && adjm[i][u]>adjm[i][v]){
            near[i] = v;
        }
        else near[i] = u;
    }

    // Recurring part begins
    int test;
    for (int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            test = min(test,adjm[near[i]][i]);
        }
    }










    return 0;
}
