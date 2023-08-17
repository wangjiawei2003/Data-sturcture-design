#include<iostream>
using namespace std;
//在函数体外创建链表，不用参数传递进去（如果是结果就用别名）；在函数体内创建变量有很多问题
struct newnode
{
	int data;
	newnode* link;
	newnode(newnode* ptr = NULL)
	{
		link = ptr;
	}
	newnode(int value, newnode* ptr = NULL)
	{
		data = value;
		link = ptr;
	}
};
class list
{


	newnode* first;

public:
	newnode* gethead()//获取头指针
	{
		return first;
	}
	list()//初始化函数
	{
		first = new newnode;
	}
	~list()//析构函数
	{
		empty();
	}
	void input();//输入函数
	void empty();//将链表置空
	void output();//输出函数

};
void list::empty()//注意析构函数要把所有元素节点都删除，若只删除头指针其他指针依然保留在内存中
{
	newnode* b;
	while (first->link != NULL)
	{



		b = first->link;
		first->link = b->link;
		delete b;
	}
}
void list::input()
{
	cout << "请输入链表中的数据（从小到大，以-1结束）";
	int val;
	newnode* a1 = first;
	cin >> val;
	while (val != -1)
	{

		a1 = a1->link = new newnode(val);
		cin >> val;
	}
}
void jiaoji(list a, list b, list& c)
{

	//求交集操作,时间复杂度为一阶

	newnode* a2 = a.gethead();
	newnode* b2 = b.gethead();
	newnode* c1 = c.gethead();
	while (a2->link != NULL && b2->link != NULL)
	{
		if (a2->link->data == b2->link->data)
		{
			c1 = c1->link = new newnode(a2->link->data);
			a2 = a2->link;
			b2 = b2->link;
		}
		else if (a2->link->data < b2->link->data)
		{
			a2 = a2->link;
		}
		else
		{
			b2 = b2->link;
		}
	}

}
void list::output()
{
	cout << "两个链表的交集元素是：";
	newnode* current = first;
	if (first->link == NULL)
		cout << "NULL" << endl;
	while (current->link != NULL)
	{
		current = current->link;
		if (current->link != NULL)
			cout << current->data << " ";
		else
			cout << current->data << endl;
	}

}

int main()
{
	list a, b;
	list d;
	a.input();
	b.input();
	jiaoji(a, b, d);
	d.output();
	return 0;
}