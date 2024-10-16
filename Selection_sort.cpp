#include <bits/stdc++.h>
using namespace std;
void selection(int n, int arr[])
{
   for (int i = 0; i < n - 1; i++)
   {
      int minIdx = i;
      for (int j = i + 1; j < n; j++)
      {
         if ( arr[j]<arr[minIdx])
         {
            minIdx = j;
         }
      }
      swap(arr[minIdx], arr[i]);
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
   selection(n, arr);
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
}