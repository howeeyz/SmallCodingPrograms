#include <iostream>
#include <string>

using namespace std;

int ehToAy(string number){
    
    int converted = 0, i;
    bool negative = false;
    
    if(number.at(0) == '-'){
        negative = true;
        i = 1;
    }
    else
        i = 0;
    
    for(; i < number.length(); i++){
        converted = converted*10 + (int)(number.at(i) - '0');
    }
    
    if(negative == true)
        converted = converted * -1;
    
    return converted;
}

int main()
{
    
    string number = "-1242834325";
    
    cout << "This is the number:" << ehToAy(number) << endl;
    
    return 0;
    
}
