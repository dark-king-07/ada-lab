#include <iostream>
#include <chrono>
#include <cstring>
using namespace std;
using namespace chrono;
const int MAX_CHAR = 256; // Assuming ASCII characters
int ST[MAX_CHAR];
void shiftTable(string p) 
{
  int n = p.size();
  for (int i = 0; i < MAX_CHAR; i++) 
  {
     ST[i] = n;
  }
  for (int j = 0; j < n - 1; j++) 
  {
     ST[p[j]] = n - 1 - j;
   }
}
int horspool(string p, string s) 
{
  shiftTable(p);
  int m = p.size();
  int n = s.size();
  int i = m - 1;
  while (i <= n - 1) 
  {
    int k = 0;
    while (k <= m - 1 && p[m - 1 - k] == s[i - k]) 
    {
      k++;
    }
    if (k == m) 
    {
       return i - m + 1;
    } 
    else 
    {
       i = i + ST[s[i]];
    }
  }
return -1;
}
int main() 
{
   string s, p;
   cout << "\nEnter a string: ";
   getline(cin, s);
   cout << "\nEnter pattern to be searched: ";
   getline(cin, p);
   auto start = high_resolution_clock::now();
   int res = horspool(p, s);
   auto endt = high_resolution_clock::now();
   if (res == -1)
     cout << "\nPattern not found";
   else
     cout << "\nPattern found at position " << res + 1;
   auto duration = duration_cast<microseconds>(endt - start);
   cout << "\nTime complexity: " << duration.count() << " ms";
   return 0;
}
