#include <iostream>
using namespace std;
void rotatedsortedarray(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            cout << "Element found at index: " << mid << endl;
            return;
        }
        if (arr[low] <= arr[mid])
        {
            if (key >= arr[low] && key < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (key > arr[mid] && key <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    cout << "Element not found" << endl;
}
int main()
{
    int n, key;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of the rotated sorted array: ";
    for (int i = 0; i < n; i++){
                    cin >> arr[i];}
    cout << "Enter the element to search: ";
    cin >> key;
    rotatedsortedarray(arr, n, key);
    return 0;
}