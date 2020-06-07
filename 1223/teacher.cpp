#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
			break;
		int q=n;int Count=1;int add=0;
		while(1)
		{
			if(q%2==1)
			{
				n+=Count;
				q/=2;
				while(q%2==1)
				{
					add*=2;
					add+=1;
					q/=2;
				}
				break;
			}
			Count*=2;
			q/=2;
		}
		cout<<n+add<<endl;
	}
}
