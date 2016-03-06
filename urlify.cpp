#include <iostream>
#include <cstring>

using namespace std;

char* changeSpaces(char* input, int size){
    int spaceCount = 0;
    
    for(int i = 0; i < size; i++){
        if(input[i] == ' ')
            spaceCount++;
    }
    //cout << spaceCount << endl;
    int trueSize = size + spaceCount*2;
        
    if(trueSize == 0)
        return input;
    
    int end = trueSize - 1;
    
    while(input[end] == ' '){
        end--;
    }
    
    
    int write = trueSize - 1;

    while(write != end){        
        if(input[end] != ' '){
            input[write] = input[end];
            write--;
            end--;
        }
        else{
            input[write] = '0';
            write--;
            input[write] = '2';
            write--;
            input[write] = '%';
            write--;
            end--;
        }
    }
    
    return input;
}

int main(void){
    
    char* input = (char*)malloc(24*sizeof(char));
    strcpy(input,"hello I am howard      ");
    
    cout << changeSpaces(input, 17) << endl;
    return 0;
}