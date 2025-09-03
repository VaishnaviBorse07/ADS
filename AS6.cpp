/*given two arryas s[] and e[] of size n denoting starting and ending time of the shops and a n integer value k denoting the number of people, the
task is to find out the maximum number of shops they can visit in total if they visit each shop optimally baed on the following conditions:
1. A shop can be visited by only one person
2. A person cannot visit another shop if its timing collide with it
input:s[]={1,8,3,2,6}, e[]={5,10,6,5,9}
k=2
output:4 */
#include <iostream>
using namespace std;

class Shop
{
public:
    int start;
    int end;
};

void merge(Shop shops[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Shop L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = shops[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = shops[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i].end <= R[j].end)
            shops[k++] = L[i++];
        else
            shops[k++] = R[j++];
    }

    while (i < n1)
        shops[k++] = L[i++];

    while (j < n2)
        shops[k++] = R[j++];
}

void mergeSort(Shop shops[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(shops, left, mid);
        mergeSort(shops, mid + 1, right);
        merge(shops, left, mid, right);
    }
}

int maxShopsVisited(int S[], int E[], int N, int K)
{
    Shop shops[100];
    int endTimeOfPerson[10], count = 0;

    for (int i = 0; i < N; i++)
    {
        shops[i].start = S[i];
        shops[i].end = E[i];
    }
    mergeSort(shops, 0, N - 1);

    for (int i = 0; i < K; i++)
        endTimeOfPerson[i] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int p = 0; p < K; p++)
        {
            if (endTimeOfPerson[p] <= shops[i].start)
            {
                endTimeOfPerson[p] = shops[i].end;
                count++;
                break;
            }
        }
    }
    return count;
}

int main()
{
    int N, K;
    int S[100], E[100];
    cout << "Enter number of shops: ";
    cin >> N;
    cout << "Enter number of people: ";
    cin >> K;
    cout << "Enter start times of shops:\n";
    for (int i = 0; i < N; i++)
        cin >> S[i];
    cout << "Enter end times of shops:\n";
    for (int i = 0; i < N; i++)
        cin >> E[i];
    cout << "Maximum shops visited: " << maxShopsVisited(S, E, N, K);
    return 0;
}