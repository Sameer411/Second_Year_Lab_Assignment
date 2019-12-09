#include <iostream>
#include <cstring>
#define MAX 5
using namespace std;
class Graph
{
	int a[MAX][MAX],visited[MAX];
	char cityname[MAX][20];
	int n;
public:
	Graph();
	void createGraph();
	void display();
	void dfs(int i);
};
Graph::Graph()
{
	for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			a[i][j]=0;
		}
		visited[i]=0;
	}
	strcpy(cityname[0],"Mumbai");
	strcpy(cityname[1],"Nashik");
	strcpy(cityname[2],"Pune");
	strcpy(cityname[3],"Delhi");
	strcpy(cityname[4],"Bangl");
}
void Graph::createGraph()
{
	int wt,v1,v2;
	cout<<"Cities: \n";
	for(int i=0;i<5;i++)
		cout<<i<<"."<<cityname[i]<<"\n";
	cout<<"Enter total number of edges: ";
	cin>>n;
	for(int i=0;i<MAX;i++)
		a[i][i]=0;
	for(int i=0;i<n;i++)
	{
		cout<<"For edge "<<i+1<<":\n";
		cout<<"Enter vertex 1: ";
		cin>>v1;
		cout<<"Enter vertex 2: ";
		cin>>v2;
		cout<<"Enter the weight: ";
		cin>>wt;
		a[v1][v2]=wt;
		a[v2][v1]=wt;
	}
}
void Graph::display()
{

    cout <<"\t";
	for(int i=0;i<MAX;i++)
	   cout <<cityname[i] <<"\t";
	cout << "\n";
	for(int i=0;i<MAX;i++)
	{
		cout << cityname[i] << "\t";
		for(int j=0;j<MAX;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
void Graph::dfs(int i)
{
	visited[i]=1;
	cout<<i<<"."<<cityname[i]<<" - ";
	for(int k=0;k<MAX;k++)
	{
		if(a[i][k] && visited[k]==0)
			dfs(k);
	}
}
int main()
{
	int v;
	Graph g;
	g.createGraph();
	g.display();
	cout<<"Enter the vertex number from where you have to start dfs: ";
	cin>>v;
	cout<<"DFS: ";
	g.dfs(v);
	cout<<"\b\b  \n";
	return 0;
}
