#include <iostream>
#include <string>

using namespace std;

string reverseString(string reverse){
	int end = reverse.length() - 1;

	int count = end;
	int subCount = 0;

	string reversed = "";

	while(count >= 0){
		if(reverse.at(count) == ' '){
            if(reversed == ""){
                reversed = reversed + reverse.substr(count+1, subCount);
            }
            else{
                reversed = reversed + " " + reverse.substr(count+1, subCount);
            }
			subCount = 0;
		}
		else{
			subCount++;
		}
		count--;
	}

	reversed = reversed + " " + reverse.substr(0, subCount);

	return reversed;

}

int main(void){
	string reverse("Hello my name is Howard");

	cout << reverseString(reverse) << endl;
}