#include <iostream>
using namespace std;
class AS2
{
    int arr[100], n;
    int right, left, mid;

public:
    void merge(int arr[], int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int *l = new int[n1];
        int *r = new int[n2];
        for (int i = 0; i < n1; i++)
        {
            l[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++)
        {
            r[j] = arr[mid + 1 + j];
        }
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (l[i] !=0)
            {
                arr[k] = l[i];
                i++;
            }
            else
            {
                arr[k] = r[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k] = l[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = r[j];
            j++;
            k++;
        }
    }
    void sort(int arr[], int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            sort(arr, left, mid);
            sort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
};
int main(){
    int arr[100], n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter Array elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    AS2 a;
    a.sort(arr, 0, n - 1);
    cout << "\nSorted ARRAY:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}