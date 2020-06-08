#include <iostream>

using namespace std;

int n, mas[8], paste = 0, paste_i;

int check()
{
  for (int i = n - 2; i >= 0; i--)
  {
    for (int j = i + 1; j < n; j++)
      if (mas[i] < mas[j])
      {
        {
          int j_min, min = 100;
          for (int g = i + 1; g < n; g++)
            if (mas[g] < min && mas[g] > mas[i])
            {
              min = mas[j];
              j_min = g;
            }
          paste_i = j_min;
        }
        return i;
      }
  }
  return -1;
}
void sort(int I)
{
  int temp;
  for (int i = I + 1; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (mas[i] > mas[j])
      {
        mas[i] += mas[j];
        mas[j] -= mas[i];
        mas[i] += mas[j];
        mas[j] *= -1;
      }
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    mas[i] = i + 1;
  do
  {
    {
      cout << mas[0];
      for (int i = 1; i < n; i++)
        cout << " " << mas[i];
      cout << endl;
    }
    paste = check();
    if (paste != -1)
    {
      {
        int temp;
        temp = mas[paste];
        mas[paste] = mas[paste_i];
        mas[paste_i] = temp;
      }
      sort(paste);
    }
  } while (paste != -1);
}