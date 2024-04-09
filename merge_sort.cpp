#include <iostream>

void Merge(int *arr, int low, int mid, int high) {
    int i, j, k, temp[high-low+1];
    i=low;
    k=0;
    j=mid+1;
    while(i<=mid && j<=high) {
        if(arr[i]<arr[j]) {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while(i<=mid) {
        temp[k]= arr[i];
        i++;
        k++;
    }
    while(j<=high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

}

void MergeSort(int *arr, int low, int high) {
    int mid;
    if(low<high) {
        mid = (low+high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
}

int main() {
    int n;
    std::cout<<"Enter the size of array"<<std::endl;
    std::cin>>n;
    std::cout<<"Enter the elements of array"<<std::endl;
    int arr[n];
    for(int i=0; i<n; i++) {
        std::cin>>arr[i];
    }

    MergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        std::cout<<arr[i]<<" ";
    }
    return 0;
}