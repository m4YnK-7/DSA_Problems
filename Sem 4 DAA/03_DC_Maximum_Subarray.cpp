#include <bits/stdc++.h> 
using namespace std; 

int max(int a, int b, int c) { 
	return max(max(a, b), c); 
} 

int maxCrossingSum(int arr[], int l, int m, int h) { 
	// Include elements on left of mid. 
	int sum = 0; 
	int left_sum = INT_MIN; 
	for (int i = m; i >= l; i--) { 
		sum += arr[i]; 
		left_sum = max(left_sum,sum);
	} 

	sum = 0; 
	int right_sum = INT_MIN; 
	for (int i = m; i <= h; i++) { 
		sum += arr[i]; 
		right_sum = max(right_sum,sum);
	} 

	return max(left_sum + right_sum - arr[m], left_sum, right_sum); 
} 

int maxSubArraySum(int arr[], int l, int h) {  
	if (l > h) 
		return INT_MIN; 
	// Base Case: Only one element 
	if (l == h) 
		return arr[l]; 

	// Find middle point 
	int m = (l + h) / 2; 

	return max(maxSubArraySum(arr, l, m - 1), maxSubArraySum(arr, m + 1, h), maxCrossingSum(arr, l, m, h)); 
} 

int main() { 
    cout<<"Enter the number of elements:";
    int n;
    cin>>n;
    cout<<"Enter the elements: ";
	int arr[n]; 
	for(int i=0;i<n;i++){
        cin>>arr[i];
    } 
	int max_sum = maxSubArraySum(arr, 0, n - 1); 
	cout << "Maximum contiguous sum is " << max_sum; 
	return 0; 
} 
