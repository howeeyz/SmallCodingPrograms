#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int partition(vector<int> &array, int startIndex, int endIndex){
  
  int i = startIndex - 1, j = 0;
  
  for(j = startIndex; j < endIndex; j++){
    if(array[j] > array[endIndex]){
      ; //move on
    }
    else{
      i++;
      int temp;
      temp = array[j];
      array[j] = array[i];
      array[i] = temp;
    }
  }
  
  i++;
  
  int temp;
  temp = array[endIndex];
  array[endIndex] = array[i];
  array[i] = temp;
  
  return i;
}

void quicksort(vector<int> &array, int startIndex, int endIndex){
  
  if(startIndex >= endIndex){
    return;
  }
  else{
    int pivot = partition(array, startIndex, endIndex);
    
    quicksort(array, startIndex, pivot - 1);
    quicksort(array, pivot, endIndex);
  }
  
  return;
}

// To execute C++, please define "int main()"
int main() {
  
  vector<int> array = {35,46,12,74,4,23,75,33,99,50};
  
  cout << "PRE SORT:" << endl;
  
  for(int i = 0; i < array.size(); i++){
    cout << array[i] << endl;
  }
  
  quicksort(array,0,9);
  
  cout << "POST SORT:" << endl;
  
  for(int i = 0; i < array.size(); i++){
    cout << array[i] << endl;
  }
  
  return 0;
}