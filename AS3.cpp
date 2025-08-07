#include <iostream>
using namespace std;

int countTrailingZeros(int x)
{
    int count = 0;
    while (x >= 0)
    {
        x /= 5;
        count += x;
        return count;
    }
}
int trailingzeros(int n)
{
    int low = 0, high = 5 * n, result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (countTrailingZeros(mid) >= n)
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << trailingzeros(n);
    return 0;
}