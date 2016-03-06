#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

string newString(string tester){
    
    string compress;
    char currChar = '1';
    int num = 1;
    
    for(int i = 0; i < tester.length(); i++){
        if((char)tester.at(i) == currChar)
            num++;
        else{
            currChar = (char)tester.at(i);
            
            if(num == 1)
                compress = compress + currChar;
            else
                compress = compress + to_string(num) + currChar;
            num = 1;
        }    
    }
    
    if(num > 1)
        compress = compress + to_string(num);
    
    return compress;
}

int main(void){
    string tester = "aaaaallllllldriiiiichhhhhh";

    string compressed = newString(tester);
    
    cout << compressed;
    
    return 0;
}