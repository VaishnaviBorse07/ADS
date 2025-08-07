#include <iostream>
using namespace std;

int main() {
    int arr[100],n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter Array elements:";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int low = 0, high = n - 1;
    int indexOfZero = -1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == 0) {
            indexOfZero = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }

    if (indexOfZero == -1) {
        cout << "Number of 0s = 0";
    } else {
        cout << "Number of 0s = " << n - indexOfZero;
    }

    return 0;
}