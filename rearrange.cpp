//if the input is -1 2 1 3 -1 -2 -3 
// then it should print 2 -1 1 -3 3 -2 -1 
// we will be using partition algorithm. This algorithm will be used if order does not need to be maintained as partition 
// algorithm is not stable.
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  vector < int > arr = {-1, 2, 1, 3, -1, -2, -3};
  int n = arr.size();
  
  // printing the array before rearrangement
  cout << "Array before the rearrangement: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  
  // intiliazing the temp variable to bring negative elements at the front
  int temp = -1;

  
  // for loop to bring all the negative elements at the front of the array
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) swap(arr[i], arr[++temp]);
  }

  // intializing the two variable pos and neg,
  int pos = temp + 1, neg = 0;
  //now we will swap positive and negative elements
  while (pos < n && arr[neg] < 0 && pos > neg) {
    swap(arr[pos], arr[neg]);
    pos++;
    neg += 2;
  }
  cout << "Printing the array after rearrangement: ";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
}