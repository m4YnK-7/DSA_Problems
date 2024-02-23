#include <iostream> 
#include <vector> 
using namespace std; 

/*
a : Assembly Lines Time
t : Time for changing line
cs: current state
cl: current line
x1,x2: intial time for both lines
e1,e2: exit time for both lines
L : path table
*/

int fun(vector<vector<int>> a, vector<vector<int>> t, int cl, int cs, int x1, int x2, int n,int L[][2]){ 
	// base case 
	if (cs == n - 1) { 
		if (cl == 0) { // exiting from (current) line =0 
			return x1; 
		} 
		else // exiting from line 2 
			return x2; 
	} 
	// continue on same line 
	int same  = fun(a, t, cl, cs + 1, x1, x2, n,L) + a[cl][cs + 1]; 
  
	// continue on different line 
	int diff = fun(a, t, !cl, cs + 1, x1, x2, n,L) + a[!cl][cs + 1] + t[cl][cs + 1]; 

	if(min(same,diff)==same){
		L[cs][cl] = !cl;
	}
	else{
		L[cs][cl] = cl;
	}

	return min(same, diff); 
} 


int main() { 
	int n = 6; // number of station

	vector<vector<int> > a  = { {7,9,3,4,8,4}, {8,5,6,4,5,7} }; 
	vector<vector<int> > t  = { {0,2,3,1,3,4}, {0,2,1,2,2,1} }; 

	int L[n-1][2];
			
	int e1 = 2; 
	int e2 = 4; 
	int x1 = 3; 
	int x2 = 2; 
	
	// entry from 1st line 
	int x = fun(a, t, 0, 0, x1, x2, n,L) + e1 + a[0][0]; 
	// entry from 2nd line 
	int y = fun(a, t, 1, 0, x1, x2, n,L) + e2 + a[1][0]; 
	cout <<"The minimum time required for the assembly is: "<< min(x, y) << endl; 

}

