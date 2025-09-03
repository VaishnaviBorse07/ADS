/* Implement a problem of minimum work to be done per day to finish given taks within D days problem
input: task[]=[3,4,7,15]
D=10
output:4*/
#include <iostream>
using namespace std;

class Work
{
public:
    bool calculate(int tasks[], int n, int D, int x)
    {
        int days = 0;
        for (int i = 0; i < n; i++)
        {
            days += (tasks[i] + x - 1) / x;
            if (days > D)
                return false;
        }
        return true;
    }
    int minWork(int tasks[], int n, int D)
    {
        int left = 1, right = tasks[0];
        for (int i = 1; i < n; i++)
        {
            if (tasks[i] > right)
            {
                right = tasks[i];
            }
        }

        int ans = right;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (calculate(tasks, n, D, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int n, D;
    int tasks[100];

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter amount of work in each task: ";
    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i];
    }

    cout << "Enter number of days: ";
    cin >> D;

    Work w;
    cout << "Minimum work to be done per day: " << w.minWork(tasks, n, D) << endl;

    return 0;
}
