#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math>

using namespace std;

struct Friend
{
	int value;
	string name;
};

typedef Friend buddy;

bool compare(const buddy &a, const buddy &b)
{
    return a.value < b.value;
}

void printFriends(vector<buddy> fVector){
    sort(fVector.begin(), fVector.end(), compare);
    
    for(int i = 0; i < fVector.size(); i++){
		cout << fVector[i].name;
	}

    cout << endl;


    for(i = 0; i < fVector.size(); i++){
    	cout << fVector[i].name << ": ";

    	if(i < 4){
    		int min = 0;
    		int max = i + 3

    		

    	}
    	else if(i > fVector.size() - 4){

    	}
    	else{

    	}
    }
}

int main(void){
	
	buddy f1;
	f1.value = 3;
	f1.name = "a";

	buddy f2;
	f2.value = 11;
	f2.name = "b";

	buddy f3;
	f3.value = 1;
	f3.name = "c";

	buddy f4;
	f4.value = 15;
	f4.name = "d";

	buddy f5;
	f5.value = 6;
	f5.name = "e";

	buddy f6;
	f6.value = 2;
	f6.name = "f";

	buddy f7;
	f7.value = 7;
	f7.name = "g";

	buddy f8;
	f8.value = 12;
	f8.name = "h";

	buddy f9;
	f9.value = 4;
	f9.name = "i";

	vector<buddy> fVector = {f1,f2,f3,f4,f5,f6,f7,f8,f9};

	for(int i = 0; i < fVector.size(); i++){
		cout << fVector[i].name;
	}

    cout << endl;
    
	printFriends(fVector);

	return 0;
}