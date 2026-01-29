//Q1

#include <iostream>

using namespace std;

int main(){
    int arr[] = {2,5,8,12,16,23,38,56,72,91};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ele;
    cout << "enter the element to search: ";
    cin >> ele;
    int l = 0, r = n - 1;
    int mid = l + (r - l) / 2;

    while (l <= r) {
        if (arr[mid] == ele) {
            cout << "element found at index: " << mid << endl;
            return 0;
        }
        else if (arr[mid] < ele) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
        mid = l + (r - l) / 2;
    }
    cout << "element not found in the array." << endl;
    return 0;
}


//Q2

void mergesort(int arr[], int l, int r){
    if(l >= r) return;
    
    int m = l + (r - l) / 2;
    
    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);

    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            k++;
            i++;
        } else {
            arr[k] = R[j];
            k++;
            j++;
        }
    }
    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
}

int main(){
    int arr1[] = {12,11,13,5,6,7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {38,27,43,3,9,82,10};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    mergesort(arr1, 0, n1 - 1);
    mergesort(arr2, 0, n2 - 1);
    
    for (int i=0; i<n1; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i=0; i<n2; i++){
        cout << arr2[i] << " ";
    }

    return 0;
}

//Q3

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(){

    int arr[] = {4,2,6,9,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, size - 1);
    
    for (int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    return 0;

}

//Q4

int max(int a,int b){return a>b?a:b;}

int maxCrossingSum(int arr[],int l,int m,int r){
    int sum=0,left=-1e9;
    for(int i=m;i>=l;i--){
        sum+=arr[i];
        left=max(left,sum);
    }
    sum=0;
    int right=-1e9;
    for(int i=m+1;i<=r;i++){
        sum+=arr[i];
        right=max(right,sum);
    }
    return left+right;
}

int maxSubArray(int arr[],int l,int r){
    if(l==r) return arr[l];
    int m=l+(r-l)/2;
    return max(
        max(maxSubArray(arr,l,m),maxSubArray(arr,m+1,r)),
        maxCrossingSum(arr,l,m,r)
    );
}

int main(){
    int arr[]={-2,-5,6,-2,-3,1,5,-6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum subarray sum = "<<maxSubArray(arr,0,n-1);
    return 0;
}
