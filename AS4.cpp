#include <iostream>
using namespace std;
int calculatepower(double b, int e)
{
    int temp;
    if (e == 0)
        return 1;
    if (e < 1)
    {
        return 1 / (calculatepower(b, -e));
    }
    else
    {
        temp = calculatepower(b, e / 2);
    }
    if (e % 2 == 0){
        return temp * temp;
    }
    else{
        return b * temp * temp;
    }
}
int main()
{
    double b;
    int e;
    cout<< "Enter base and exponent: ";
    cin >> b >> e;
    cout << "Value is "<<calculatepower(b,e)<<".0";
    return 0;
}