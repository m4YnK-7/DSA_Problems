#include <iostream>
using namespace std;

/*
__________DOCUMENTATION OF SELF CODED BFS___________ 
Created by: Mayank Singh
DTV : 3:04 am,7 June , My bed
Time taken : ~ 30mins

adjm - adjacency matrix
v - vertice
e - edge (not needed)
*/

void dfs(int** adjm,int v,int n,int* visited){
    if(visited[v]==1) return; // If already printed the return

    cout<<v<<" "; // Print vertice and mark it as visited
    visited[v]=1;

    for (int i=1;i<n+1;i++){ // iterate in v's row to see its neighbours vertices
        if(adjm[v][i]==1 && visited[i] == 0){ // if adjm=1 and not visited
            dfs(adjm,i,n,visited); // go to that node
        }
    }
}

int** create_adjm(int n){

    // 2-D array using Dynamic allocation
    int** adjm = new int*[n+1];
    for(int i=0;i<n+1;i++){
        
        adjm[i] = new int[n+1];
        for (int k=0;k<n+1;k++){adjm[i][k] = 0;}

        if(i!=0){ // To make the first array 0
            int e,x;
            // cout<<"Enter the no of edges for vertices "<<i+1<<": ";
            cin>>e;
            // cout<<"Enter the vertices connected: ";
            for(int j=0;j<e;j++){
                cin>>x;
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
    #ifndef IO
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int v,n;
    // cout<<"Enter no of vertices and edges: ";
    cin>>v>>n;

    int **adjm = create_adjm(v);
    int visited[n+1] = {0};

    dfs(adjm,1,n,visited);

    cout<<endl;
    return 0;
}