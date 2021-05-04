#include<iostream>
#include<fstream>
using namespace std;
int n,p[20],b[20],c[20][20],d=0;
void doc_file(int c[][20])
{
	ifstream filein;
	filein.open("./hamilton.txt",ios_base::in);
	filein>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			filein>>c[i][j];
		}
	}
}
void khoitao()
{
	int i;
	p[1]=1;
	for(i=2;i<=n;i++) b[i]=1;
}
void xuly()
{
	int t,kd;
	kd=1;
	for (t=1;t<=n-1;t++)
	{
		if(c[p[t]][p[t+1]]==0){
			kd=0;
			goto l1;	
		} 
	}
	if(c[p[n]][p[1]]==0) kd=0;
	l1:
		{
			if(kd)
			{
				d++;
				cout<<"Hamilton : ";
				for(t=1;t<=n;t++)
				{
					cout<<p[t]<<"  ";
				}
				cout<<p[1]<<"\n";
			}
		}
}
void HoanVi(int k)
{
	int j;
	for(j=2;j<=n;j++){
		if(b[j])
		{
			p[k]=j;b[j]=0;
			if(k==n) {
			xuly();}
				else HoanVi(k+1);
			b[j]=1;
		}
	}
}
int main()
{
	doc_file(c);
	khoitao();
	HoanVi(2);
	if(d==0)
	{
		cout<<"Khong co chu trinh Hamilton";
	}
}
