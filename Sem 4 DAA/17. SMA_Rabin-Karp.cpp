#include <iostream>
using namespace std;
int main() {
    char p[]={'\0','a','a','b','a','a','b','a','a','a'}; // Given pattern string. 1st char is null, since we start array with index 1 
    int pi[]={0,0,0,0,0,0,0,0,0,0}; // prefix fn -  initialise
    int i=1,j=2; // initialize i and j
    while(j<=10) // for substring length 1, 2, ....,m of p[]
    {
    if (p[i]==p[j])
    {
        pi[j]=i;
        i++;
        j++;
    }
    else
    {
        if(i==1)
        {
            pi[j]=0;
            j++;
        }
        else
        {
            i=pi[i-1]+1;
        }
        
    }
}
for(int i=1;i<=9;i++)
cout<<pi[i]<<" ";
    return 0;
}
    