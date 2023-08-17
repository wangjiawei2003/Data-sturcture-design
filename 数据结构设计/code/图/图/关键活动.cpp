#include<iostream>
#define defaultsize 100
#define maxweight 999
using namespace std;
struct edge {//边信息
	int pri;
	char  head;
	char tail;
	int weight;//权值
	edge& operator=(edge& x)//=运算符重载
	{
		pri = x.pri;
		head = x.head;
		tail = x.tail;
		weight = x.weight;
		return *this;
	}
	bool operator<=(edge& x)//<=运算符重载
	{
		return (weight <= x.weight);
	}
	bool operator>(edge& x)//>运算符重载
	{
		return(weight > x.weight);
	}
	bool operator==(edge& x)
	{
		if (weight == x.weight && head == x.head && tail == x.tail&& pri==x.pri)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};	


class graphmtx//邻接矩阵(有向边)
{
protected:
	char* vertex;//顶点数组
	int vertex_num;//顶点个数
	int edge_num;//边个数
	int* edge_[defaultsize];//邻接矩阵存权值
	int* edge__[defaultsize];//邻接矩阵存pri
public:
	graphmtx()
	{
		vertex_num = 0;
		edge_num = 0;
		vertex = new char[defaultsize];
		for (int i = 0; i < defaultsize; i++)//动态生成edge_数组
		{
			edge_[i] = new int[defaultsize];
		}
		for (int i = 0; i < defaultsize; i++)//动态生成edge__数组
		{
			edge__[i] = new int[defaultsize];
		}
		for (int i = 0; i < defaultsize; i++)//对edge_数组初始化
		{
			for (int j = 0; j < defaultsize; j++)
			{
				edge_[i][j] = (i == j) ? 0 : maxweight;
			}
		}
		for (int i = 0; i < defaultsize; i++)//对edge__数组初始化
		{
			for (int j = 0; j < defaultsize; j++)
			{
				edge__[i][j] =-1;
			}
		}
	}
	~graphmtx()
	{
		delete []vertex;
		for (int i = 0; i < defaultsize; i++)//动态生成edge_数组
		{
			delete []edge_[i] ;
		}
		for (int i = 0; i < defaultsize; i++)//动态生成edge__数组
		{
			delete []edge__[i] ;
		}

	}
	char get_vertex(int i)
	{
		return vertex[i];
	}
	int get_edge_num()
	{
		return edge_num;
	}
	int get_vertex_num()
	{
		return vertex_num;
	}
	void insert_vertex(char a);
	void insert_edge(edge a);
	int getvertexpos(char a);
	int getfirstneighbor(int a);
	int getnextneighbor(int w, int v);
	int getweight(int a, int b)
	{
		return edge_[a][b];
	}
	int getpri(int a, int b)
	{
		return edge__[a][b];
	}
};
int graphmtx::getnextneighbor(int a, int v)
{
	for (int i = v + 1; i < vertex_num; i++)
	{
		if (edge_[a][i] > 0 && edge_[a][i] < maxweight)
		{
			return i;
		}
	}
	return -1;
}
int graphmtx::getfirstneighbor(int a)
{
	for (int i = 0; i < vertex_num; i++)
	{
		if (edge_[a][i] > 0 && edge_[a][i] < maxweight)
		{
			return i;
		}
	}
	return -1;
}
int graphmtx::getvertexpos(char a)
{
	for (int i = 0; i < vertex_num; i++)
	{
		if (vertex[i] == a)
		{
			return i;
		}
	}
	return -1;
}
void graphmtx::insert_vertex(char a)
{
	vertex_num++;
	vertex[vertex_num - 1] = a;
}
void graphmtx::insert_edge(edge a)
{
	edge_num++;
	char b = a.head;
	int x = getvertexpos(b);
	char c = a.tail;
	int y = getvertexpos(c);
	edge_[x][y] = a.weight;
	edge__[x][y] = a.pri;
}
void input(graphmtx& G)
{
	
	int vertex_num;//	插入顶点
	int edge_num;//	插入边
	
	while (1)
	{
		cout << "请输入顶点个数和边的个数：" << endl;
		cin >> vertex_num;
		cin >> edge_num;
		if (vertex_num <= 0)
		{
			cout << "顶点个数有误，请重新输入！" << endl;
		}
		if (edge_num <= 0)
		{
			cout << "边个数有误，请重新输入！" << endl;
		}
		if (edge_num < vertex_num - 1)
		{
			cout << "边数过小，有多余顶点,请重新输入！" << endl;
		}
		if(vertex_num>0 && edge_num>0 && edge_num>=vertex_num-1 )
		{
			break;
		}
	}
	
	for (int i = 0; i < vertex_num; i++)
	{
		G.insert_vertex(i + 49);
	}


	for (int i = 0; i < edge_num; i++)
	{
		edge x;
		while (1)
		{
			cout << "请输入第" << i + 1 << "条边的起点，终点和权值:" << endl;
			cin >> x.head;
			cin >> x.tail;
			cin >> x.weight;
			if (G.getvertexpos(x.head) == -1 || G.getvertexpos(x.tail) == -1 )
			{
				cout << "该顶点不存在，请重新输入边的完整信息！" << endl;
			}
			else if (x.weight < 0)
			{
				cout << "权值输入有误，请重新输入边的完整信息！" << endl;
			}
			else
			{
				break;
			}
		}
		
		x.pri = i;
		G.insert_edge(x);
		
	}

}
void CriticalPath(graphmtx& G, edge* cp,int& num)
{
	edge ed;
	int top = -1;
	int lnk = -1;
	int j=0;
	int u=0;
	int v=0;
	int vertex_num = G.get_vertex_num();
	int edge_num = G.get_edge_num();
	int* ind=new int [defaultsize];//建立入度数组
	for (int i = 0; i < vertex_num; i++)//所有顶点的入度初始化为0
	{
		ind[i] = 0;
	}
	for (int i = 0; i < vertex_num; i++)//统计各顶点的入度
	{
		j = G.getfirstneighbor(i);
		while (j != -1)
		{
			ind[j]++;
			j = G.getnextneighbor(i, j);
		}
	}
	for (int i = 0; i < vertex_num; i++)//初始的入度为0的元素通过栈来存储
	{
		if (ind[i] == 0)
		{
			ind[i] = top;
			top = i;

		}
	}
	
	int* Ve=new int[defaultsize];//各事件最早和最晚开始时间
	int* Vi=new int[defaultsize];
	
	int* Ae=new int[defaultsize];//各活动最早和最晚开始时间
	int* Ai=new int[defaultsize];
	for (int i = 0; i < vertex_num; i++)//事件最早开始时间初始化
	{
		Ve[i] = 0;
	}
	for (int i = 0; i < vertex_num; i++)//事件最晚开始时间初始化
	{
		Vi[i] = 0;
	}
	while (top != -1)
	{
		u = top; top = ind[top];//退栈顶点存u
		ind[u] = lnk;//反向拉链
		lnk = u;
		j = G.getfirstneighbor(u);
		while (j != -1)
		{
			if ((G.getweight(u, j) + Ve[u]) > Ve[j])//Ve[j]取最大的路径
			{
				Ve[j] = G.getweight(u, j) + Ve[u];
			}
			if (--ind[j] == 0)//当前结点的入度减1，若入度为0，加入栈中
			{
				ind[j] = top;
				top = j;
			}
			j = G.getnextneighbor(u, j);
		}
	}
	for (int i = 0; i < vertex_num; i++)//事件最晚开始时间初始化
	{
		if(lnk>0)
			Vi[i] = Ve[lnk];
	}
	
	while (lnk != -1 && ind[lnk]>=0)
	{
		
		v= ind[lnk];//lnk的前一个节点
		lnk = v;
		if (lnk == -1)
		{
			break;
		}
		j = G.getfirstneighbor(v);
		while (j != -1)
		{
			if (Vi[v] > Vi[j] - G.getweight(v, j))
			{
				Vi[v] = Vi[j] - G.getweight(v, j);

			}
			j = G.getnextneighbor(v, j);
		}
		
		
	}
	int k = 0;

	for (int i = 0; i < vertex_num; i++)//遍历所有顶点
	{
	
		j = G.getfirstneighbor(i);//	遍历每个顶点为起点的边
		while (j != -1)
		{
			int weight = G.getweight(i, j);
			
			Ae[k] = Ve[i];//求出Ae[k]和Ai[k]
			Ai[k] = Vi[j] - weight;
			if (Ae[k] == Ai[k])
			{
				
				ed.head = i + 49;
				ed.tail = j + 49;
				ed.weight = weight;
				ed.pri = G.getpri(i, j);
				cp[num++] = ed;
			}
			k++;
			j = G.getnextneighbor(i, j);
		}
	}
	delete []ind;
	delete[]Ve;
	delete[]Vi;
	delete[]Ae;
	delete[]Ai;
}
void output(edge* cp,int& count,int num)
{
	char temp = cp[0].head;
	for (int i = 0; i < num; i++)//计算整个项目所需的时间
	{
		if (cp[i].head == temp)
		{
			count += cp[i].weight;
			temp = cp[i].tail;
		}
		
		
	}
	cout << count << endl;
	
	edge x;
	for (int i = 0; i < num; i++)//输出关键路径
	{
		for (int j = i + 1; j < num - 1; j++)
		{
			if (cp[i].head == cp[j].head)//将输入的边的顺序颠倒
			{
				
				if (cp[i].pri<cp[j].pri)
				{
					x = cp[j];
					cp[j] = cp[i];
					cp[i] = x;
				}
			}
			else
			{
				break;
			}
		}
		
		cout << cp[i].head << "->" << cp[i].tail << endl;
	}
	
}
int main()
{

	graphmtx graph;
	edge* activity = new edge[defaultsize];
	int num = 0;
	int count = 0;
	input(graph);
	CriticalPath(graph, activity,  num);
	output(activity, count, num);
	delete []activity;
}