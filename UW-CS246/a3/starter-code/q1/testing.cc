#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[])
{
string str=argv[1];
int size=atoi(str.c_str());;
int a[size];
for(int i=0;i<size;i++)
{
a[i]=i+1;
cout<<a[i]<<endl;
}
}
