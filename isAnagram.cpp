#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

bool isAnagram(string s1, string s2){
    
    
    if(s1.length() != s2.length())
        return false;
    else{
        
        int s1Arr[26];
        int s2Arr[26];
        
        for(int j = 0; j < 26; j++){
            s1Arr[j] = 0;
            s2Arr[j] = 0;
        }
        
        for(int i = 0; i < s1.length(); i++){
            tolower(s1.at(i));
            tolower(s2.at(i));
            s1Arr[(int)s1.at(i) - (int)'a']++;
            s2Arr[(int)s2.at(i) - (int)'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(s1Arr[i] != s2Arr[i])
                return false;
        }
        return true;
    }
}

int main(void){
    
    string s1 = "avvvsd";
    string s2 = "asvvvd";
    
     if(isAnagram(s1, s2))
         cout << "True\n";
     else
         cout << "False\n";
    
     return 0;
}    