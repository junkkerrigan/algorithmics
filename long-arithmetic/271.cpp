#include <iostream>

using namespace std;

const int MAX_SIZE=10001;

class BigInt {
private:
    int number[MAX_SIZE]{};
    int length;
    bool isNegative{false};

    void print(ostream& out) const;
    void enter(istream& in);
public:
    BigInt();
    BigInt(const BigInt& object);
    BigInt(const int& num);

    bool operator==(const BigInt& num) const;
    bool operator<(const BigInt& num) const;
    BigInt operator+(const BigInt& term) const;
    BigInt operator-(const BigInt& subtr) const;
    BigInt operator*(const BigInt& mult) const;
    BigInt operator/(const BigInt& denom) const;

    ~BigInt();

    friend ostream& operator<<(ostream& out, const BigInt& num);
    friend istream& operator>>(istream& in, BigInt& num);
};

BigInt::BigInt() : length(1)
{
    for(int& i : number)
        i=0;
}

BigInt::BigInt(const BigInt& object) : length(object.length)
{
    for(int i=0;i<length;i++)
        number[i]=object.number[i];
}

BigInt::BigInt(const int& num) : length(0)
{
    if (num == 0) {
        length = 1;
    } else {
        int numClone = num;
        while (numClone) {
            number[length] = numClone % 10;
            numClone /= 10;
            length++;
        }
    }
}

void BigInt::enter(istream& in)
{
    char num[MAX_SIZE];
    in >> num;
    length=0;
    while(length<MAX_SIZE && num[length]!='\0')
        length++;
    for(int i=0;i<length;i++)
        number[i]=(int)num[length-i-1]-48;
    for(int i=length;i<MAX_SIZE;i++)
        number[i]=0;
}

void BigInt::print(ostream& out) const
{
    if (isNegative) {
        out << '-';
    }
    for(int i=length-1;i>=0;i--)
        out << number[i];
}

bool BigInt::operator==(const BigInt& num) const
{
    if (length!=num.length)
        return false;
    else {
        for(int i=length-1;i>=0;i--)
            if (number[i]!=num.number[i])
                return false;
        return true;
    }
}

bool BigInt::operator<(const BigInt& num) const
{
    if (length>num.length)
        return false;
    if (length<num.length)
        return true;
    for(int i=length-1;i>=0;i--)
    {
        if (number[i]>num.number[i])
            return false;
        if (number[i]<num.number[i])
            return true;
    }
    return false;
}

BigInt BigInt::operator+(const BigInt& term) const
{
    BigInt res;

    int maxLen=max(length, term.length);
    for(int i=0;i<maxLen;i++)
    {
        res.number[i]+=(number[i]+term.number[i])%10;
        res.number[i+1]+=(number[i]+term.number[i])/10;
    }

    res.length=maxLen;
    if (res.number[maxLen]!=0)
        res.length++;

    return res;
}

BigInt BigInt::operator-(const BigInt& subtr) const
{
    BigInt res, min(*this);

    if (min < subtr) {
        res = subtr - min;
        res.isNegative = true;
    } else {
        int maxLen = max(min.length, subtr.length);
        for (int i = 0; i < maxLen; i++) {
            if (min.number[i] < subtr.number[i]) {
                min.number[i] += 10;
                min.number[i + 1]--;
            }
            res.number[i] = min.number[i] - subtr.number[i];
        }

        res.length = maxLen;
        int i = maxLen - 1;
        while (i >= 0 && res.number[i] == 0) {
            res.length--;
            i--;
        }

        if (res.length == 0)
            res.length++;
    }

    return res;
}

BigInt BigInt::operator*(const BigInt& mult) const
{
    BigInt res;
    res.length=length+mult.length+1;
    int term;
    for(int i=0;i<length;i++)
        for(int j=0;j<mult.length;j++)
        {
            term=number[i]*mult.number[j];
            res.number[i+j]+=term%10;
            res.number[i+j+1]+=term/10;
        }
    for(int i=0;i<res.length;i++) {
        res.number[i+1]+=res.number[i]/10;
        res.number[i]%=10;
    }
    int i=res.length-1;
    while(i>=0 && res.number[i]==0)
    {
        res.length--;
        i--;
    }
    if (res.length==0)
        res.length++;
    return res;
}

BigInt BigInt::operator/(const BigInt& denom) const
{
    BigInt res, temp, ten, null;
    ten.length=2;
    ten.number[1]=1;
    for(int i=length-1;i>=0;i--)
    {
        temp=temp*ten;
        temp.number[0]=number[i];
        if (temp<denom)
            res=res*ten;
        else
        {
            BigInt tempRes;
            int j=0;
            while(tempRes*denom<temp)
            {
                j++;
                tempRes.number[0]=j;
            }
            if (!(tempRes*denom==temp))
                tempRes.number[0]--;
            res=res*ten;
            res=res+tempRes;
            temp=temp-tempRes*denom;
        }
    }
    return res;
}

BigInt::~BigInt() = default;

ostream& operator<<(ostream& out, const BigInt& num) {
    num.print(out);
    return out;
}

istream& operator>>(istream& in, BigInt& num) {
    num.enter(in);
    return in;
}

int main()
{
    int n;
    cin >> n;

    BigInt factorial(1);
    for(int i = 1; i <= n; i++) {
        factorial = factorial * BigInt(i);
    }

    cout << factorial;
    return 0;
}