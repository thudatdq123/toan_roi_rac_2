#include<iostream>
#include<fstream>
using namespace std;
int a[100][100],stack[100],n,CE[100],dCE,top;
void doc_file(int a[][100])
{
	ifstream filein;
	filein.open("./euler_cycle.txt",ios_base::in);
	filein>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			filein>>a[i][j];
		}
	}
}
bool kiem_tra_euler(int a[][100])
{
	int s,d=0;
	for(int i=1;i<=n;i++)
	{
		s=0;
		for(int j=1;j<=n;j++)
		{
			s+=a[i][j];	
		}	
		if(s%2==1)
		{
			d++;
		}
	}	
	if(d>0) return false;
	return true;
}	
void euler_cycle(int u)
{
	top=1,dCE=0;
	stack[top]=u;
	int x,s;
	while(top>0)
	{
		s=stack[top];x=1;
		while(x<=n && a[s][x]==0) x++;
		if(x>n)
		{
			dCE++;
			CE[dCE]=s;
			top--;
		}else
		{
			top++;
			stack[top]=x;
			a[s][x]=0;
			a[x][s]=0;
		}
	}
	for(int i=dCE;i>0;i--)
	{
		cout<<CE[i]<<" ";
	}
}
int main()
{
	doc_file(a);
	if(kiem_tra_euler(a)==0)
	{
		cout<<"Khong co chu trinh";
	}else 
	{
		euler_cycle(1);	
	}
}
