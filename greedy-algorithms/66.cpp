#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int F(string s)
{
  return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str());
}

int main()
{
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  int N, k, tmp;
  fin >> N;
  struct Time
  {
    string begin;
    string end;
  } A[N];
  int *B = new int[N];
  int *E = new int[N];
  for (int i = 0; i < N; i++)
  {
    fin >> A[i].begin >> A[i].end;
  }
  sort(A, A + N, [](const Time &a, const Time &b) {
    return a.begin < b.begin;
  });
  for (int i = 0; i < N; i++)
  {
    B[i] = F(A[i].begin);
    E[i] = F(A[i].end);
  }
  tmp = k = 0;
  for (int i = 1; i < N; i++)
  {
    for (int j = tmp; j < N; j++)
    {
      if (B[i] >= E[j])
      {
        k++;
        tmp = i;
        break;
      }
    }
  }
  fout << ++k << endl;
  fin.close();
  fout.close();
  delete[] B;
  delete[] E;
  system("pause");
  return 0;
}