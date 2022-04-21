#include<iostream.h>
#include<string.h>

using namespace std;
class myString
{
    char str[20];
public:
    myString()
    {
        str[0]='/0';
    }
    myString(char s[20])
    {
        strcpy(str,s);
    }
    myString operator +(myString s2)
{
    myString ans;
    strcat(ans.str,str);
    strcat(ans.str,s2.str);
    return ans;
}
void disp()
{
    cout<<str;
}
};
int main()
{
    myString s1="hi";
    myString s2="friends";
    myString s3;
    s3=s1+s2;
    s3.disp();
    return 0;
}
