#include<bits/stdc++.h>
using namespace std;

struct Student{
    int roll_no;
    string name;
    float sgpa;
};

void bubblesordeft(Student *s[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<(n-1);j++)
        {
            if(s[j]->roll_no>s[j+1]->roll_no)
            {
                swap(s[j],s[j+1]);
            }
        }
    }
}

void display(Student *s[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<s[i]->roll_no;
        cout<<s[i]->roll_no;
        cout<<s[i]->roll_no;
    }
}
int main()
{
    int n;
    cin>>n;
    Student* s[n];
    for(int i=0;i<n;i++)
    {
        s[i] = new Student;
        cin>>s[i]->roll_no;
        cin>>s[i]->name;
        cin>>s[i]->sgpa;
    }
    
    bubblesort(s, n);
    
    display(s,n);
}
