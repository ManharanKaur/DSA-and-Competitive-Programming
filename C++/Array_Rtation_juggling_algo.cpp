#include <iostream>
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
void swapper(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // 8 9 10 1 2 3 4 5 6 7
    int len = sizeof(arr) / sizeof(int);
    int k = 4;
    for (int i = 0; i < gcd(len, k); i++)
    {
        for (int j = 1; j <= len / gcd(len, k); j++)
        {
            swapper(arr[i], arr[(i + j * k) % len]);
        }
    }
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}