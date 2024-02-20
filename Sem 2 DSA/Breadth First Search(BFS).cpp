#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/*
__________DOCUMENTATION OF SELF CODED BFS___________ 
Created by: Mayank Singh
DTV : 1:54am,7 June , My bed
Time taken : ~ 140mins

adjm - adjacency matrix
v - vertice
e - edge (not needed)

Sample input: 
            7 9
            3 2 3 4
            2 1 3
            4 1 2 4 5
            3 1 3 5
            4 3 4 6 7
            1 5
            1 5
*/

void bfs(int** adjm,int v,int n){  // using dynamic to allow variable dimension to adjacency matrix

    // queue<int> queue; 
    // // Creating a visited array to store the vertices visited by iteration to avoid output of duplicate vertices 
    // int visited[n+1] = {0};
    // visited[v] = 1;       

    // // Printing first element coz it is not printed in loop
    // cout<<v<<"->";

    // for(int j =0;j<n+1;j++){                   // 2 for loop to iterate in matrix
    //     for(int i=1;i<n+1;i++){                // Starting from 1 coz first is always 0 and we need value of i

    //     // Check if there is edge b/w v and i vertices and if it is visited or not
    //         if (adjm[v][i] == 1 && visited[i]==0){ 
    //             // Push ther vertice in queue and print and mark it as visited 
    //             queue.push(i); 
    //             visited[i] = 1;
    //             cout<<i<<"->";
    //         }
    //     }
    //     // Updating vertice to front of queue after one vertice is completly explored 
    //     if(!queue.empty()){
    //     v = queue.front();
    //     queue.pop();
    //     }
    // }
    // cout<<"End";
    queue<int> queue;
    bool visited[n+1] = {0};

    queue.push(v);
    visited[v] = 1;
    cout<<v<<" ";

    while(!queue.empty()){
        for (int i = 0;i<n+1;i++){
            if(adjm[v][i]==1 && visited[i] == 0){
                queue.push(i);
                visited[i]  = 1;
                cout<<i<<" ";
            }
        }
        queue.pop();
        v = queue.front();
    } 
}
int dfs(int** adjm,int u,int n){
    bool visited[n+1] = {0};
    stack<int> stk;

    visited[u] = 1;
    stk.push(u);
    cout<<u<<" ";

    int v = 0;
    while (!stk.empty()){
        while (v<n){
            if(adjm[u][v]==1 && visited[v]==0){
                stk.push(v);
                u = v;

                cout<<u<<" ";
                visited[u] = 1;
                v = -1;
            }
            v++;            
        }
        v = 0;

        u = stk.top();
        stk.pop();
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
    bfs(adjm,1,n);


    cout<<endl; 
    return 0;
}

