#include<iostream>
#include<algorithm>
#include <cstdlib>
using namespace std;
#define MAX 30
int main()
{
    int arr[MAX];
    int i,pos,head,n,seek_count=0,dir,p,p1,tracks,time;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"\nEnter no. of tracks: ";
    cin>>tracks;
    cout<<"\nEnter time to move from one trck to another(in ns): ";
    cin>>time;
    cout<<"\nEnter requests: ";
    for(i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    cout<<"\nEnter head: ";
    cin>>head;
    sort(arr,arr+n);

    cout<<"After sorting requests: ";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"\n";
    }

    for(i=0;i<n;i++)
    {
        if(arr[i]<head)
        {
            pos = i+1;
        }
    }
    for(i=n; i>pos; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=head;
    
    cout<<"List of requests : \n";
    for(i=0; i<n+1; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<"\nEnter direction of head(0/1): ";
    cin>>dir;
    p=pos;
    if(dir == 1)
    {
        while(p!=n-1)
        {
                    seek_count = seek_count+abs(arr[p] - arr[p+1]);
                    p = p+1;
        }
        seek_count = seek_count + abs(arr[n-1]-arr[1]);
        p1=1;
        while(p1!=pos-1)
        {
              seek_count = seek_count+abs(arr[p1] - arr[p1+1]);
              p1 = p1+1;
        }
        
    }
    else if(dir == 0)
    {
        while(p!=1)
        {
                    seek_count = seek_count+abs(arr[p] - arr[p-1]);
                    p = p-1;
        }
        seek_count = seek_count + abs(arr[1]-arr[n-1]);
        p1=n-1;
        while(p1!=pos+1)
        {
              seek_count = seek_count+abs(arr[p1] - arr[p1-1]);
              p1 = p1-1;
        }
        
    }

    cout<<"The seek count is: "<<seek_count<<" "<<"\n";
    cout<<"\nThe seek time is: "<<seek_count*time;
    return 0;

}