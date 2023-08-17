//#include<iostream>
//#include<iomanip>
//#define defaultsize 20
//#define maxweight 999
//using namespace std;
//
//struct edge {//边信息
//	char  head;
//	char tail;
//	int weight;//权值
//	edge& operator=(edge& x)//=运算符重载
//	{
//		head = x.head;
//		tail = x.tail;
//		weight = x.weight;
//		return *this;
//	}
//	bool operator<=(edge& x)//<=运算符重载
//	{
//		return (weight <= x.weight);
//	}
//	bool operator>(edge& x)//>运算符重载
//	{
//		return(weight > x.weight);
//	}
//
//};
//
//class Minheap//最小堆
//{
//public:
//	Minheap()//构造函数，初始化最小堆
//	{
//		edge_num = 0;
//		element = new edge[defaultsize];
//	}
//	~Minheap()
//	{
//		delete[]element;
//	}
//	bool removemin(edge& a);//移除堆顶元素
//	void insert(edge a);//插入元素
//	void siftdown(int start);//从上到下调整
//	void siftup(int start);//从下到上调整
//private:
//	edge* element;//存放边信息的数组
//	int edge_num;//存放边的数目
//};
//bool Minheap::removemin(edge& a)
//{
//	if (edge_num <1)
//	{
//		cout << "栈为空，无法删除！" << endl;
//		return false;
//	}
//	a = element[0];
//	element[0] = element[edge_num - 1];
//	edge_num--;
//	siftdown(0);
//	return true;
//}
//void Minheap::insert(edge a)
//{
//	edge_num++;
//	element[edge_num - 1] = a;
//	siftup(edge_num - 1);
//}
//void Minheap::siftup(int start)//从下到上调整
//{
//	int i, j;
//	i = start;
//	j = (i - 1) / 2;
//	edge temp;
//	temp = element[i];
//	while (i > 0)
//	{
//
//		if (temp > element[j])
//		{
//			break;
//		}
//		else
//		{
//			element[i] = element[j];
//		
//			i = j;
//			j = (i - 1) / 2;
//		}
//	}
//	element[i] = temp;
//}
//void Minheap::siftdown(int start)//从上到下调整
//{
//	int i, j;
//	i = start;
//	j = 2 * i + 1;
//	edge temp;
//	temp = element[i];
//	while (j <= edge_num-1)
//	{
//		if (j<edge_num && element[j]>element[j + 1])
//		{
//			j++;
//		}
//		if (temp <= element[j])
//		{
//			break;
//		}
//		else
//		{
//			element[i] = element[j];
//			i = j;
//			j = 2 * i + 1;
//		}
//	}
//	element[i] = temp;
//}
//
//
//
//class graphmtx//邻接矩阵
//{
//protected:
//	char* vertex;//顶点数组
//	int vertex_num;//顶点个数
//	int edge_num;//边个数
//	int edge_[defaultsize][defaultsize];//邻接矩阵
//public:
//	graphmtx()
//	{
//		vertex_num = 0;
//		edge_num = 0;
//		vertex = new char[defaultsize];
//		for (int i = 0; i < defaultsize; i++)
//		{
//			for (int j = 0; j < defaultsize; j++)
//			{
//				edge_[i][j] = (i == j) ? 0: maxweight;
//			}
//		}
//	}
//	char get_vertex(int i)//获取相应位置的元素
//	{
//		return vertex[i];
//	}
//	int get_edge_num()//获取边的数目
//	{
//		return edge_num;
//	}
//	int get_vertex_num()//获取顶点的数目
//	{
//		return vertex_num;
//	}
//	void insert_vertex(char a);//插入顶点
//	void insert_edge(edge a);//插入边
//	int getvertexpos(char a);//获取当前元素的位置
//	int getfirstneighbor(int a);//获取当前位置的相邻位置
//	int getnextneighbor(int w, int v);//获取当前位置的相邻位置的下一个位置
//	int getweight(int a, int b)//获取该边的权值
//	{
//		return edge_[a][b];
//	}
//};
//int graphmtx::getnextneighbor(int a, int v)
//{
//	for (int i = v + 1; i < vertex_num; i++)
//	{
//		if (edge_[a][i] > 0 && edge_[a][i] < maxweight)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//int graphmtx::getfirstneighbor(int a)
//{
//	for (int i = 0; i < vertex_num; i++)
//	{
//		if (edge_[a][i] > 0 && edge_[a][i] < maxweight)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//int graphmtx::getvertexpos(char a)
//{
//	for (int i = 0; i < vertex_num; i++)
//	{
//		if (vertex[i] == a)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//void graphmtx::insert_vertex(char a)
//{
//	vertex_num++;
//	vertex[vertex_num - 1] = a;
//}
//void graphmtx::insert_edge(edge a)
//{
//	edge_num++;
//	char b = a.head;
//	int x = getvertexpos(b);
//	char c = a.tail;
//	int y = getvertexpos(c);
//	edge_[x][y] = edge_[y][x] = a.weight;
//}
//
//class Minspantree//最小生成树
//{
//protected:
//
//	edge* element;//边信息
//	int edge_num;//边的个数
//
//	
//public:
//	Minspantree()
//	{
//		edge_num = 0;
//		element = new edge[defaultsize];
//	
//	}
//	~Minspantree()
//	{
//		delete []element;
//
//	}
//
//	void insert(edge a);//插入边
//	void output();//输出最小生成树
//	
//};
//
//void Minspantree::insert(edge a)
//{
//	edge_num++;
//	element[edge_num - 1] = a;
//}
//void Minspantree::output()
//{
//	cout << "最小生成树的顶点及边为：" << endl;
//	for (int i = 0; i < edge_num; i++)
//	{
//		cout << element[i].head << "-<" << element[i].weight << ">->" << element[i].tail<<"   ";
//	}
//	cout << endl;
//}
//void menu()
//{
//	cout << "**" << setw(29) << "电网造价模拟系统" << setw(20) << setfill(' ') << "**" << endl;
//	cout << setw(52) << setfill('=') << " " << endl;
//	cout << setw(19) << setiosflags(ios::left) << setfill(' ') << "**" << setw(30) << setfill(' ') << "A---创建电网顶点" << "**" << endl;
//	cout << setw(19) << setiosflags(ios::left) << setfill(' ') << "**" << setw(30) << setfill(' ') << "B---添加电网的边" << "**" << endl;
//	cout << setw(19) << setiosflags(ios::left) << setfill(' ') << "**" << setw(30) << setfill(' ') << "C---构造最小生成树" << "**" << endl;
//	cout << setw(19) << setiosflags(ios::left) << setfill(' ') << "**" << setw(30) << setfill(' ') << "D---显示最小生成树" << "**" << endl;
//	cout << setw(19) << setiosflags(ios::left) << setfill(' ') << "**" << setw(30) << setfill(' ') << "E---退出程序" << "**" << endl;
//
//
//	cout << setw(52) << setiosflags(ios::right) << setfill('=') << " " << endl;
//	
//
//}
//void Prim(graphmtx& G, char u0, Minspantree& MST)//求最小生成树
//{
//	Minheap H;
//	edge x;
//	int n = G.get_vertex_num();
//	int m = G.get_edge_num();
//	int u = G.getvertexpos(u0);
//	int v = 0;
//	int p = 0;
//	int q = 0;
//	bool* visited = new bool[n];
//	for (int i = 0; i < n; i++)//给遍历数组赋初值
//	{
//		visited[i] = false;
//	}
//	visited[u] = true;//顶点已访问
//	int count = 0;
//	while (count < n - 1)//生成最小生成树
//	{
//		v = G.getfirstneighbor(u);//取当前位置的相邻位置
//		while (v != -1)//若存在
//		{
//			if (visited[v] == false)//未被访问
//			{
//				x.head = G.get_vertex(u);
//				x.tail = G.get_vertex(v);
//				x.weight = G.getweight(u, v);
//				H.insert(x);//将该边送入最小堆
//
//			}
//			v = G.getnextneighbor(u, v);//获取下一个位置
//		}
//		H.removemin(x);//取出最小堆的最小元素
//		p = G.getvertexpos(x.tail);
//		q = G.getvertexpos(x.head);
//		if (u == p)
//		{
//			v = q;
//		}
//		else
//		{
//			v = p;
//		}
//		if (visited[v] == false)
//		{
//			visited[v] = true;//该位置已经遍历过，做标记
//			MST.insert(x);//插入最小生成树
//			count++;
//			u = v;
//		}
//	}
//}
//void create_vertex(graphmtx& c)//插入顶点
//{
//
//	int n = 0;
//	char a;
//	while (1)
//	{
//		cout << "请输入顶点的个数：" << endl;
//		cin >> n;
//		if (n > 0 && n < defaultsize)
//		{
//			break;
//		}
//		else
//		{
//			cout << "顶点个数有误，请重新输入！" << endl;
//		}
//	}
//	
//	cout << "请依次输入各顶点的名称：" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a;
//		c.insert_vertex(a);
//	}
//}
//void create_edge(graphmtx& c)//插入边
//{
//	char a, b;
//	int n;
//	edge x;
//	while (1)
//	{
//		cout << "请输入两个顶点及边：";
//		cin >> a;
//		cin >> b;
//		cin >> n;
//		
//		if (a == '?' || b == '?' || n == 0)
//		{
//			break;
//		}
//		else if (a == b)
//		{
//			cout << "有环，请重新输入！" << endl;
//			continue;
//		}
//		else
//		{
//			x.head = a;
//			x.tail = b;
//			x.weight = n;
//			c.insert_edge(x);
//		}
//	}
//}
//void create_minspantree(graphmtx& c,Minspantree& p)//创建最小生成树
//{
//	char a;
//	while (1)
//	{
//		cout << "请输入起始顶点：";
//		cin >> a;
//		if (c.getvertexpos(a) == -1)
//		{
//			cout << "无此顶点，请重新输入！" << endl;
//		}
//		else
//		{
//			break;
//		}
//	}
//	
//	Prim(c, a, p);
//	cout << "生成Prim最小生成树！" << endl;
//}
//void show_minspantree(Minspantree& p)//展示最小生成树
//{
//	p.output();
//}
//void input(graphmtx& c, Minspantree& p)
//{
//	char option;		
//	while (1)
//	{
//		cout << "请选择操作：";
//		cin >> option;
//		switch (option)
//		{
//			case ('A'):
//			{
//				create_vertex(c);
//				break;
//			}
//			case ('B'):
//			{
//				create_edge(c);
//				break;
//			}
//			case('C'):
//			{
//				create_minspantree(c, p);
//				break;
//			}
//			case('D'):
//			{
//				show_minspantree(p);
//				break;
//			}
//			case('E'):
//			{
//				exit(0);
//				break;
//			}
//			default:
//			{
//				cout << "无此选项，请重新输入！" << endl;
//				break;
//			}
//		}
//	}
//}
//int main()
//{
//	graphmtx c;
//	Minspantree p;
//	menu();
//	input(c, p);
//}