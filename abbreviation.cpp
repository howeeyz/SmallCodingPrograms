#include <iostream>
#include <cstring>

using namespace std;

bool isAbbr(char* original, char* abbr){
    
    if(original == NULL || abbr == NULL)
        return false;
    
    int oLen = strlen(original);
    int aLen = strlen(abbr);
    
    int j = 0;
    
    for(int i = 0; i < aLen; i++){
        
        if(abbr[i] == NULL || original[j] == NULL)
            return false;
        
    	int num = 0;
    	if((int)abbr[i] >= (int)'0' && (int)abbr[i] <= (int)'9'){
    		while((int)abbr[i] >= (int)'0' && (int)abbr[i] <= (int)'9'){
    			num = num*10 + (int)abbr[i] - (int)'0';
                i++;
    		}
            i--;
    		j = j + num;
    	}
    	else{
    		if(abbr[i] == original[j]){
    			j++;
    		}
    		else
    			return false;
    	}
    }
    return true;
}

int main(void){
    char* original = (char*)malloc(15*sizeof(char));
    strcpy(original,"HOWARDAWESOME");
    char* abbr = (char*)malloc(6*sizeof(char));
    strcpy(abbr,"HO22E");

    cout << isAbbr(original, abbr) << endl;;

    return 0;
}