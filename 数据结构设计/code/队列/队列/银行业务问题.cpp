#include<iostream>
#include<map>
using namespace std;
#define defaultsize 1000
typedef map<int, int> mip;
mip priority;

class PQueue//队列
{
public:
	PQueue(int sz=defaultsize,int num=0)
	{
		maxlen = sz;
		count = num;
		elements = new int[maxlen];//初始化优先级队列数组
	}
	~PQueue()
	{
		makeempty();
	}
	void makeempty()//清空队列元素
	{
		delete []elements;
	}
	bool insert(int x)//插入到队尾
	{
		if (isfull())
		{
			cerr << "队列已满，无法进队！！！" << endl;
			return false;
		}
		else
		{
			count++;
			elements[count - 1] = x;
			return true;
		}
	}
	bool remove(int& x)//删除队头
	{
		if (isempty())
		{
			cerr << "队列已空，无法出队！！！" << endl;
			return false;
		}
		else
		{

			x = elements[0];
			count--;
			for (int i = 0; i < count; i++)
			{
				elements[i] = elements[i + 1];
			}
			
			return true;
		}
	}
	bool isempty()//判断是否为空
	{
		if (count == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isfull()//判断是否为满
	{
		if (count == maxlen)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void paixu();//排序
	void input();//输入函数
	void output();//输出函数
protected:
	int count;//顾客总数
	int* elements;//存放顾客的数组
	int maxlen;//顾客最大数目
	void adjust(int current);//队列调整
};
void PQueue::paixu()
{
	int pri;
	int ji = 0;
	int ou = 0;
	for (int i = 0; i < count; i++)
	{
		

		if (elements[i]% 2 == 1)//若为奇数，说明他通过窗口需要1分钟
		{
			ji++;
			pri = ji;
		}
		else//若为偶数，说明他通过窗口需要2分钟
		{
			ou += 2;
			pri = ou;
		}
		priority[elements[i]] = pri;//pri指的是完成排队需要的时间，pri越短说明越早出队
		
		adjust(i);//调整队列顺序
	}
}
void PQueue::adjust(int current)
{
	int i;
	int x = priority[elements[current]];//x表示当前新插入元素排队需要的时间
	int y = elements[current];//y表示当前插入的元素
	for (i = current-1; i>=0; i--)//从插入之前的最后一个元素开始向前遍历
	{
		if (x < priority[elements[i]])
		{
			elements[i+1 ] = elements[i];
		}
		
		else
		{
			break;
		}

	}
	
	elements[i+1] = y;//至此，由排队时间从小到大的排序完成
	if (i>=0 && priority[elements[i]]==priority[elements[i+1]])//特殊情况：偶数编号的顾客和奇数编号的顾客排队时间相同时，根据题意，奇数编号优先出队
	{
		if (elements[i + 1] % 2 == 1)//交换两个元素的位置
		{
			int temp;
			temp = elements[i];
			elements[i] = elements[i + 1];
			elements[i + 1] = temp;
		}
	
	}
}
void PQueue::output()
{
	int p;
	cout << "按业务处理完成先后顺序的顾客编号是："<<endl;
	while (!isempty())
	{
		remove(p);
		if (count > 0)
			cout << p << " ";
		else
			cout << p << endl;
	}
}
void PQueue::input()
{
	
	int mark;
	int num;
	cout << "请输入一行正整数(第一个数字N为顾客总数，后面的数字是N位顾客的编号)：" <<endl;
	while (1)
	{
		cin >> num;
		if (num <= 0)
		{
			cout << "顾客总数输入有误，请重新输入！" << endl;
		}
		else
		{
			break;
		}
	}
	
	for (int i = 0; i < num; i++)
	{
		cin >> mark;
		insert(mark);//将该元素插入到队列中去
		
	}
}

int main()
{
	PQueue a;
	a.input();
	a.paixu();
	a.output();
}