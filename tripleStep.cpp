//Triple Step... Q1 Ch8 Dynamic Programm

/*
Want to build off getting to the n step...
We can say it'll take either 3, 2 or 1 hop to get to the last step...
So...we want to find how many hops it takes to get to the n-1, n-2 and n-3rd steps...

So...f(n) = f(n-1) + f(n-2) + f(n-3)
*/

#include <iostream>

using namespace std;

int findStep(int n, int memo[]){
    
    if(n == 0 || n == 1)
        return 1;
    else if(n == 2)
        return 2;
    else if(n == 3)
        return 4;
    
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    
    for(int i = 4; i <= n; i++){
        memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
    }
        
    return memo[n];
}

int main(void){
    
    int n;
    
    //cout << "Please enter number of steps:" << endl;
    //cin >> n;
    
    int *memo = new int[n + 1]();
    
    cout << "Number of possibilities is: " << findStep(5, memo) << endl;
    return 0;
    
}