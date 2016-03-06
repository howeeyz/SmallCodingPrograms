#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isUnique(string str){
    map<char, int> counter;
    
    int i = 0;
    
    while(str[i] != '\0'){
        
        if(counter.find(str[i]) != counter.end())
           return false;
        else
            counter.insert({str[i],1});
        i++;
    }
    return true;
}

int main (void){
    
    cout << isUnique("abbc") << endl;
             
    return 0;
}