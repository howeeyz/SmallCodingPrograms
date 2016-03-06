// Example program
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

vector<int> merge(vector<int> sort, vector<int> left, vector<int> right){
    //the sort merge takes in are the chopped down bits of the original sort
    
    int dIndex = 0;
    int rIndex = 0;
    int lIndex = 0;
    
    while(lIndex < left.size() && rIndex < right.size()){
        if(left[lIndex] < right[rIndex]){
            sort[dIndex] = left[lIndex];
            dIndex++;
            lIndex++;
        }
        else{
            sort[dIndex] = right[rIndex];
            dIndex++;
            rIndex++;
        }
    }    
    
    if(lIndex == left.size()){
        while(rIndex < right.size()){
            sort[dIndex] = right[rIndex];
            dIndex++;
            rIndex++;
        }
    }
    else{
        while(lIndex < left.size()){
            sort[dIndex] = left[lIndex];
            dIndex++;
            lIndex++;
        }
    }
    
    return sort;
}

vector<int> mergeSort(vector<int> sort){
    int vSize = sort.size();
    
    if(vSize < 2)
        return sort;
    
    //split into 2 subarrays...approx equal size...
    
    int mid = vSize/2;
    
    vector<int>::iterator first = sort.begin();
    vector<int>::iterator middle = sort.begin() + mid;
    vector<int>::iterator end = sort.end();
    
    vector<int> left(first, middle);
    vector<int> right(middle,end);
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    return merge(sort, left , right);    
}

int main()
{
  
  //Lets use this to call merge sort...
  
  vector<int> a = {6,8,4,7,2,3,9};
  
  for(int i = 0; i < a.size(); i ++){
    cout << a[i] << endl;
  }
  
  vector<int> sorted = mergeSort(a);

  cout << "Sorted Here:" << endl;
  
  for(int i = 0; i < sorted.size(); i++){
    cout << sorted[i] << endl;
  }
  
  return 0;
  
  
}