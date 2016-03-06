#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int find, vector<int> array){
	int end = array.size();
	int middle  = end/2;
	int beginning = 0;

	while(1){   
		if(array[middle] == find){
            cout << middle << endl;
			return middle;
		}
        else if(end == beginning){
            cout << "nope" << endl;
            return 9999;
        }
		else if(array[middle] > find){
			end = middle - 1;
			middle = (beginning + end)/2;
		}
		else{
			beginning = middle + 1;
			middle = (middle + end)/2 + 1;
		}
	}
}

int main(void){
	vector<int> array = {1,3,6,7,8,10,14,24,33,57,65,66,67,90,99};
    
	return binarySearch(99, array);
}