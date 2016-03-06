// Example program
#include <iostream>
#include <string>

using namespace std;

int calculator(string calculate, int start, int end){
    
    //int index = start + 1;
    int sum = 0;
    bool first = true;
    
    char operate = calculate.at(start+1);
    
    for(int i = start+2; i < end; i++){
        if(calculate.at(i) == '('){
            int tstart = i;
            while(calculate.at(i) != ')'){
                i++;
            }
            int tend = i;
            
            if(operate == '+' || first == true){
                sum = sum + calculator(calculate, tstart, tend);
                first = false;
            }
            else if(operate == '*')
                sum = sum * calculator(calculate, tstart, tend);
            else if(operate == '/')
                sum = sum / calculator(calculate, tstart, tend);
            else if(operate == '-')
                sum = sum - calculator(calculate, tstart, tend);
          
            while(calculate.at(i) == ')' && i < end)
              i++;
        }
        else if(calculate.at(i) != ' '){
            int temp = 0;
            while(calculate.at(i) != ' ' && i < end){
                temp = temp*10 + (int)calculate.at(i) - (int)'0';
                i++;
            }
            
            if(operate == '+' || first == true){
                sum = sum + temp;
                first = false;
            }
            else if(operate == '*')
                sum = sum * temp;
            else if(operate == '/')
                sum = sum / temp;
            else if(operate == '-')
                sum = sum - temp;
        }
        
    }
    
    return sum;
}

int main(void){
    
    string calculate("(+ 1 12 (- 17 3) 5 (* 2 8 (/ 120 4)) 46 142 (* 1 10))");
    
    cout << calculator(calculate, 0, calculate.length() - 1) << endl;
    
    return 0;
}