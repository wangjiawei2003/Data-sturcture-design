#include<iostream>
#include<map>
using namespace std;
//链表相对数组的优点是不需要固定数组长度，可以自由地开辟数组空间；同时对于数据的增删查改更加方便。但是栈的逻辑结构相比数组对于增删查改又更加简便。
typedef map<char, int>mcp;
mcp isp;//栈内优先级
mcp icp;//栈外优先级

struct linknode//建立链式栈
{
	char data;
	linknode* link;
	linknode(int x, linknode* ptr = NULL) :link(ptr), data(x) { ; }
};
class linkedstack
{
protected:
	linknode* top;
public:
	linkedstack(linknode* p = NULL) :top(p) { ; }//构造函数
	~linkedstack()//析构函数
	{
		empty();
	}
	bool isempty()const;//栈是否为空
	void push(char x);//插入栈中
	bool pop(char& x);//弹出栈中
	void empty();//清空栈中元素
	bool gettop(char& x)const;//获取栈顶元素
	void calculate();//计算
};
void linkedstack::calculate()
{
	cout << "请输入一个中缀表达式：";
	push('#');//先把终止符压入栈中
	char formula[22];//公式存储在里面
	char ch;
	int p = 0;
	while ((ch = getchar()) != '\n')
	{
		if (ch != 32)//排除空格的影响
			formula[p++] = ch;
	}
	formula[p] = '#';//公式末尾加一个#表示终止符
	cout << "转换后的后缀表达式是：";
	for ( int i = 0; i < p + 1; i++)//遍历公式所有的元素
	{
		int end = 0;
		//加号和减号作为符号而非运算符的特判
		if (i == 0 && formula[i] == '-')//减号出现在开头
		{
			cout << "-";
		}
		else if (i == 0 && formula[i] == '+')//加号出现在开头
		{
			;
		}
		else if (formula[i] == '-' && formula[i - 1] == '(')//减号作为符号而非运算符
		{
			cout << "-";
		}
		else if (formula[i] == '+' && formula[i - 1] == '(')//加号作为符号而非运算符
		{
			;
		}
		else if (formula[i] == '+' || formula[i] == '-' || formula[i] == '*' || formula[i] == '/' || formula[i] == '(' || formula[i] == ')' || formula[i] == '#')//遍历运算符
		{

			char t;
			gettop(t);//取出栈顶元素
			while (isp[t] >= icp[formula[i]])//如果当前搜索的元素的优先级小于等于栈顶的元素，则持续令栈顶元素退栈
			{

				if (isp[t] == icp[formula[i]] && t == '(')//如果要退栈元素是（，退栈但不输出，重新读入下一个字符
				{
					end = 1;
					pop(t);

					break;//跳出该循环，从下一个字符开始
				}
				else if (isp[t] == icp[formula[i]] && t == '#')//若到达尾部，则终止循环
				{
					break;

				}
				else
				{

					//这里做一个if-else分支的目的是让结尾之后没有空格
					if (formula[i] == '#' && top->link->data == '#')//判断是否达到输出的结尾
					{
						cout << t;
					}
					else
					{
						cout << t << " ";
					}


					pop(t);//弹出栈顶元素
					gettop(t);//重新取一次栈顶元素
				}

			}
			//出了循环，表示栈顶元素优先级小于该元素优先级,进栈
			if (end == 0)//排除左右括号的情况
				push(formula[i]);
		}
		else//遍历整数和小数，小数可以加小数点
		{
			if (i == p - 1 || formula[i + 1] == '*' || formula[i + 1] == '/' || formula[i + 1] == '(' || formula[i + 1] == ')' || formula[i] == '#' || formula[i + 1] == '+' || formula[i + 1] == '-')//判断数字是否连续，若是连续数字，中间不需要加空格
			{
				cout << formula[i] << " ";

			}
			else
			{
				cout << formula[i];
			}

		}


	}
}
bool linkedstack::gettop(char& x)const//常函数中只能访问常函数
{
	if (isempty())
	{
		return false;
	}
	else
	{
		x = top->data;
		return true;
	}
}
bool linkedstack::isempty()const
{
	if (top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool linkedstack::pop(char& x)//因为可能出现异常情况，所以返回值是bool类型；因为要将pop的数值返回，所以用引用类型
{
	if (isempty())
	{
		cerr << "链表为空！" << endl;
		return false;
	}
	else
	{
		linknode* p = top;
		x = top->data;
		top = top->link;
		delete p;
		return true;
	}


}
void linkedstack::push(char x)//线性表是头指针，栈是尾指针作头指针
{
	linknode* p = new linknode(x);
	p->link = top;
	top = p;
}
void linkedstack::empty()//链式栈和链式表的删除算法不一样。因为链式表first指针固定，而链式栈的指针top会随着栈中数据移动发生变化
{
	linknode* p;
	while (top != NULL)
	{
		p = top;
		top = top->link;

		delete p;
	}
}

int main()
{
	//isp代表栈内的优先级，icp代表栈外的优先级
	isp['#'] = 0;
	isp['('] = 1;
	isp['*'] = 5;
	isp['/'] = 5;
	isp['+'] = 3;
	isp['-'] = 3;
	isp[')'] = 6;
	icp['#'] = 0;
	icp['('] = 6;
	icp['*'] = 4;
	icp['/'] = 4;
	icp['+'] = 2;
	icp['-'] = 2;
	icp[')'] = 1;
	linkedstack a;
	a.calculate();
	cout << endl;

}
