#include <bits/stdc++.h>
using namespace std;
void bubble(int n, int arr[])
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            swap(arr[j], arr[j + 1]);
         }
      }
   }
}
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   bubble(n, arr);
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
}