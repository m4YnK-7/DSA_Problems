#include <bits/stdc++.h>
using namespace std;

#define MAX_SETS 100
#define MAX_ELEMENTS 1000


int setCover(int X[], int S[][MAX_ELEMENTS], int numSets, int numElements, int output[]){
   int U[MAX_ELEMENTS];

   for (int i = 0; i < numElements; i++) {
      U[i] = X[i];
   }
   int selectedSets[MAX_SETS];
   for (int i = 0; i < MAX_SETS; i++) {
      selectedSets[i] = 0; 
   }
   int outputIdx = 0;

   while (outputIdx < numSets) {  
      int maxIntersectionSize = 0;
      int selectedSetIdx = -1;
     
      for (int i = 0; i < numSets; i++) {
         if (selectedSets[i] == 0) { 
            int intersectionSize = 0;
            for (int j = 0; j < numElements; j++) {
               if (U[j] && S[i][j]) {
                  intersectionSize++;
               }
            }
            if (intersectionSize > maxIntersectionSize) {
               maxIntersectionSize = intersectionSize;
               selectedSetIdx = i;
            }
         }
      }
      
      if (selectedSetIdx == -1) {
         break;
      }
      selectedSets[selectedSetIdx] = 1;
      for (int j = 0; j < numElements; j++) {
         U[j] = U[j] - S[selectedSetIdx][j];
      }
      output[outputIdx++] = selectedSetIdx;
   }
   return outputIdx;
}
int main(){
   int X[MAX_ELEMENTS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int S[MAX_SETS][MAX_ELEMENTS] = {
      {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1}
   };
   int numSets = 5;
   int numElements = 10;
   int output[MAX_SETS];
   int numSelectedSets = setCover(X, S, numSets, numElements, output);
   cout << "Selected Sets: ";
   for (int i = 0; i < numSelectedSets; i++) {
       cout << output[i] << " ";
   }
   cout << endl;
   return 0;
}