#include <iostream>
#include <map>
#include <string>
#include <math.h>

using namespace std;

bool isUnique(string str){
    int i = 0;
	int tracker = 0b0;
	
	int temp;
    
    if(str[i] != '\0'){
        int charNum = (int)tolower(str[i]) - (int)'a';
        temp = pow(2,charNum);
        tracker = tracker | temp;
    }
    else
        return true;
    
    i++;
    
    while(str[i] != '\0'){
		if(tracker == (tracker | (int)pow(2,int(tolower(str[i])-(int)'a'))))
			return false;
		else{
			int charNum = (int)tolower(str[i]) - (int)'a';     
			temp = pow(2,charNum);
			tracker = tracker | temp;
		}
        i++;
    }
    return true;
}

int main (void){
    
    cout << isUnique("abdcsgpolh") << endl;
             
    return 0;
}