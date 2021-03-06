#include <iostream>
#include <string>

using namespace std;

struct STUDENT
{
    string Name, Surname;
    char Letter;
    short int Class;
    int Day, Month, Year;
};


bool operator>(const STUDENT &a, const STUDENT &b)
{
    bool res = false;
    if (a.Class > b.Class) res = true;
    else
    if (a.Class == b.Class)
        if (a.Letter > b.Letter) res = true;
        else
        if (a.Letter == b.Letter)
            if (a.Surname > b.Surname) res = true;
            else
            if (a.Surname == b.Surname)
                if (a.Name > b.Name) res = true;
    return res;
};


void swap(STUDENT &a, STUDENT &b)
{
    STUDENT temp = a;
    a = b;
    b = temp;
}

void scandate(int &day, int &month, int &year)
{
    string temp;
    cin >> temp;
    day = atoi(temp.substr(0, 2).c_str());
    month = atoi(temp.substr(3, 2).c_str());
    year = atoi(temp.substr(6, 2).c_str());
}

void z(int k)
{
    if (k > 9) cout << k;
    else cout << "0" << k;
}

int main()
{
    int n;
    cin >> n;
    STUDENT *a = new STUDENT[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].Surname >> a[i].Name >> a[i].Class >> a[i].Letter;
        scandate(a[i].Day, a[i].Month, a[i].Year);
    }
    for (int k = 2; k <= n; k++)
        for (int i = 0; i <= n - k; i++)
            if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);

    for (int i = 0; i < n; i++)
    {
        cout << a[i].Class << a[i].Letter << " " << a[i].Surname << " " << a[i].Name << " ";
        z(a[i].Day); cout << "."; z(a[i].Month); cout << "."; z(a[i].Year); cout << endl;
    }
    return 0;
}