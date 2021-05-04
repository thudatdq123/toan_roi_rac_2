#include<iostream>
#include<fstream>
using namespace std;
int a[100][100],n,stack[100],chuaxet[100],truoc[100];
int queue[100],rear,front;
void doc_file(int a[][100])
{
	ifstream filein;
	filein.open("./dfs.txt");
	filein>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			filein>>a[i][j];
		}
	}
}
void DFS(int u)
{
	cout<<u<<"  ";
	chuaxet[u]=0;
	int v;
	for(int v=1;v<=n;v++)
	{
		if(a[u][v] ==1 && chuaxet[v]==1)
		{
			truoc[v]=u,DFS(v);
		}
	}
}
int dfs_khu_de_quy(int u)
{
	int x=0,s,t;
	x++;
	stack[x]=u;
	cout<<u<<" ";
	chuaxet[u]=0;
	while(x>=0)
	{
		s=stack[x];
		x--;
		for(int i=1;i<=n;i++)
		{
			if(chuaxet[i]==1 && a[s][i]==1)
			{			
				cout<<i<<" ";		
				chuaxet[i]=0;
				x++;
				stack[x]=s;
				x++;
				stack[x]=i;
				break;
			}
		}
	}
//	cout<<x<<" ";
}
void BFS_queue(int u)
{
	rear=1;
	front=1;
	queue[rear]=u;
	rear++;
	chuaxet[u]=0;
	while(rear>front)
	{
		int s=queue[front];
		front++;
		cout<<s<<" ";
		for(int t=1;t<=n;t++)
		{
			if(chuaxet[t]==1&&a[s][t]==1)
			{
				queue[rear]=t;
				rear++;
				chuaxet[t]=0;
			}
		}
	}
}
void Duong_di_s_t(int s,int t)
{
	if(truoc[t]==0)
	{
		cout<<"Khong co duong di !";	
	}else
	{
		int j=t;
		cout<<j<<"  ";
		while(truoc[j]!=s)
		{
			cout<<truoc[j]<<"  ";
			j=truoc[j];
		}
		cout<<s;
	}
}
int so_lien_thong(int u)
{
	int solt=0;
	for(int i=1;i<=n;i++)
	{
		if(chuaxet[i]==1)
		{
			DFS(i);
			cout<<"\n";
			solt++;
		}
	}
	return solt;	
}

int main()
{
	doc_file(a);
	for(int i=1;i<=n;i++) chuaxet[i]=1;
	//DFS(1);
	cout<<"\n";
	//dfs_khu_de_quy(1);
	//BFS_queue(1);
	//cout<<so_lien_thong(1);
	//Duong_di_s_t(2,6);
	int s=0;
	if(s%2) cout<<"oke";
}
