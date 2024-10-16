#include <bits/stdc++.h>
using namespace std;
const int INF = 999999;
int d[10][10], a[10][10], n;

void Floyd_Warshall()
{
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         d[i][j] = a[i][j];

   for (int k = 0; k < n; k++)
   {
      cout << "Step " << k + 1 <<": "<< endl;
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            if (d[i][k] < INF && d[k][j] < INF && d[i][j] > d[i][k] + d[k][j])
            {
               d[i][j] = d[i][k] + d[k][j];
            }
            cout << d[i][j] << "\t";
         }
         cout << endl;
      }
      cout << endl;
   }
}
int main()
{
   cout << "Enter number of vertics: ";
   int n;
   cin >> n;
   cout<<endl;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         cin >> a[i][j];

   Floyd_Warshall();

   cout << "The Final Distance of matrix: " << endl;
   cout << "------------------------------" << endl;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (d[i][j] == INF)
            cout << "INF\t";
         else
            cout << d[i][j] << "\t";
      }
      cout << endl;
   }
}
