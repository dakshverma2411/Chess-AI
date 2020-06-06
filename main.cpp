#include<bits/stdc++.h>
using namespace std;
void print_board(char * * arr)
{
    for(int i=0;i<3;i++)
    {
        cout<<arr[i][0]<<" "<<"|"<<" "<<arr[i][1]<<" "<<"|"<<" "<<arr[i][2]<<endl;
    }
}
bool win_condition(char * * arr)
{
    for(int i=0;i<3;i++)
    {
        if((arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2])&&arr[i][0]!=' ')
        {
            return true;
        }
    }
    for(int i=0;i<3;i++)
    {
        if((arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i])&&arr[0][i]!=' ')
        {
            return true;
        }
    }
    if((arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2])&&arr[0][0]!=' ')
    {
        // cout<<"here\n";
        return true;
    }
    if((arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0])&&arr[0][2]!=' ')
    {
        return true;
    }
    return false;
}
int main()
{
    int n=9;
    char * * arr=new char *[3];
    cout<<"You are 'X'\n";
    for(int i=0;i<3;i++)
    {
        arr[i]=new char[3];
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr[i][j]=' ';
        }
    }
   
    while(n--)
    {
        print_board(arr);

    }
}

