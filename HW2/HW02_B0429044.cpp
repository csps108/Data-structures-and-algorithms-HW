#include<iostream>
#include<ctime>
#include<cstdlib>
#include<queue>
#include<fstream>
#include<list>
using namespace std;

void BFS(int n,int *graph)
{
	
    queue<int> q;													
    bool visit[n];
    for (int i=0; i<n; i++)										
        visit[i] = false;
    for (int m=0; m<n; m++)
        if (!visit[m])
        {
            q.push(m);												
            visit[m] = true;
            while (!q.empty())									
            {
                int e = q.front();									
                q.pop();
                for (int j=0; j<n; j++)								
                    if (*(graph+e*n+j) && !visit[j])
                    {
                        q.push(j);
                        visit[j] = true;
                        cout<<e<<" -> "<<j<<endl;
                    }
            }
        }
}

void DFS(int i,int n,int *graph,bool *visit)
{
    for (int j=0; j<n; j++)
        if (*(graph+i*n+j) && visit[j]!=true)			// graph[i][j]之間有路且 [j]沒走訪過 
        {
            visit[j] = true;   										
            cout<<i<<" -> "<<j<<endl;
            DFS(j,n,graph,visit);
        }
}
void DFStraversal(int n,int *graph)
{
    bool visit[n];
    for (int i=0; i<n; i++)								// 初始走訪點 
        visit[i] = false;
    for (int i=0; i<n; i++)
        if (!visit[i])
        {
            visit[i] = true;
            DFS(i,n,graph,visit);
        }
}

int main()
{
	int n,e;
	srand( time(0) );
	int i,j;
	for(i=0;;i++){
		cout<<"請輸入節點數目(n) : ";
		cin>>n; 
		cout<<"請輸入邊數目(e) : ";
		cin>>e; 
		if(e>(n*(n-1)/2))
			cout<<"請輸入e <= (Cn取2)/2 的數"<<endl; 
		else
			break;
	}
	
	int graph[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			graph[i][j]=0;
		}
	}
	srand(time(0));
	for(int a=e;a>0;)	
	{
		int x=rand()%n;
		int y=rand()%n;
		if(graph[x][y]==0 && x!=y)
		{
			graph[x][y]=1;				
			graph[y][x]=1;
			a=a-1;
		}
		else
			continue;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<graph[i][j];
		}
		cout<<endl; 
	}	
	cout<<"BFS:"<<"\n";	
	BFS(n,*graph);
	cout<<"DFS:"<<"\n";
	DFStraversal(n,*graph);
	
}
