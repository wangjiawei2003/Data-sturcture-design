//#include<iostream>
//#include<iomanip>
//#define defaultsize 1000
//using namespace std;
//struct student//存储学生信息
//{
//	int rank;
//	char name[6];
//	char gender[3];
//	int age;
//	char job[11];
//
//};
//template <class T>
//struct newnode//定义结点类，包含数据和下一个结点的地址信息
//{
//	T* stu;
//	newnode<T>* link;
//
//	newnode(newnode<T>* ptr = NULL)//结构体的构造函数,注意这里空的条件是必须加的，否则无法判断循环终止，而存储的data则必须初始化
//	{
//		stu = new T;
//		link = ptr;
//	}
//
//};
//template <class T>
//class list//存储包含所有学生信息的链表
//{
//protected:
//	newnode<T>* first;
//
//public:
//
//
//	int num = 0;
//	list()
//	{
//		first = new newnode<T>;
//	}
//	~list()
//	{
//		empty();//删除链表
//		delete first;//删除链表首指针
//	}
//	void empty();
//	void input();
//	void output();
//	bool insert(int i);
//	bool del(int i);
//	bool find(int i);
//	bool edit(int i);
//
//	newnode<T>* locate(int i);
//};
//template<class T>
//bool list<T>::edit(int i)
//{
//	newnode<T>* current = first->link;
//	while (current != NULL && current->stu->rank != i)//这两句顺序不能反。因为空指针没有访问的数据，放在前半句直接就报错了
//	{
//		current = current->link;
//
//	}
//
//	if (current == NULL)
//	{
//		cerr << "您要修改的学生不存在" << endl;
//		return false;
//	}
//	cout << "请输入要修改的考生的考号，姓名，性别，年龄及报考类别！" << endl;
//	cin >> current->stu->rank;
//	cin >> current->stu->name;
//	cin >> current->stu->gender;
//	cin >> current->stu->age;
//	cin >> current->stu->job;
//	return true;
//
//}
//template<class T>
//bool list<T>::find(int i)
//{
//	newnode<T>* current = first->link;
//	while (current != NULL && current->stu->rank != i)
//	{
//		current = current->link;
//
//	}
//	if (current == NULL)
//	{
//		cout << "您要查找的学生不存在" << endl;
//		return false;
//	}
//
//	cout << setw(8) << setiosflags(ios::left) << "考号" << setw(8) << "姓名" << setw(8) << "性别" << setw(8) << "年龄" << setw(8) << "报考类别" << endl;
//	cout << setw(8) << setiosflags(ios::left) << current->stu->rank << setw(8) << current->stu->name << setw(8) << current->stu->gender << setw(8) << current->stu->age << setw(8) << current->stu->job << endl;
//	return true;
//
//}
//template<class T>
//bool list<T>::del(int i)//删除操作，注意当删除第一个元素是
//{
//	newnode<T>* p = new newnode<T>;
//	newnode<T>* current = new newnode<T>;
//	p = first;
//	while (p != NULL && p->stu->rank != i)//从头指针开始，寻找该结点
//	{
//		current = p;
//		p = p->link;
//
//	}
//
//
//	if (p == NULL)
//	{
//		cerr << "您要删除的学生不存在" << endl;
//		return false;
//	}
//	else {
//		cout << "你删除的考生的信息是：";
//		cout << setw(8) << setiosflags(ios::left) << p->stu->rank << setw(8) << p->stu->name << setw(8) << p->stu->gender << setw(8) << p->stu->age << setw(8) << p->stu->job << endl;
//		current->link = p->link;
//		delete p;
//		num--;
//		return true;
//	}
//
//}
//template <class T>
//void list<T>::empty()//清空链表中所有元素
//{
//
//	newnode<T>* p;
//
//	while (first->link != NULL)//没有删除first指针，仅删除了first指向的地址及之后的所有结点
//	{
//		p = first->link;
//
//		first->link = p->link;
//		delete p;
//	}
//	num = 0;
//}
//
//template <class T>
//void list<T>::output()//输出链表中现有元素
//{
//
//	newnode<T>* current;
//	current = first;
//	if (first->link == NULL)
//	{
//		cout << "现无学生信息！" << endl;
//	}
//	else
//	{
//		cout << setw(8) << setiosflags(ios::left) << "考号" << setw(8) << "姓名" << setw(8) << "性别" << setw(8) << "年龄" << setw(8) << "报考类别" << endl;
//		while (current->link != NULL)
//		{
//			current = current->link;
//			cout << setw(8) << setiosflags(ios::left) << current->stu->rank << setw(8) << current->stu->name << setw(8) << current->stu->gender << setw(8) << current->stu->age << setw(8) << current->stu->job << endl;
//
//		}
//	}
//
//}
//template <class T>
//void list<T>::input()//输入考生信息
//{
//	int count = 0;
//	newnode<T>* last = first;
//
//	while (count != num)
//	{
//		last->link = new newnode<T>;
//		last = last->link;
//		if (last == NULL)
//		{
//			cerr << "内存分配失败！！！" << endl;
//			exit(1);
//		}//加一个判断是否生成成功的条件
//
//		cin >> last->stu->rank;
//		cin >> last->stu->name;
//		cin >> last->stu->gender;
//		cin >> last->stu->age;
//		cin >> last->stu->job;
//		count++;
//	}
//}
//template <class T>
//bool list<T>::insert(int i)
//{
//	newnode<T>* current = locate(i);
//	if (current == NULL)
//	{
//		cout << "插入失败！！！" << endl;
//		return false;
//	}
//
//	newnode<T>* newnode_ = new newnode<T>;
//	if (newnode_ == NULL)
//	{
//		cerr << "内存分配失败！！！" << endl;
//		exit(1);
//	}
//	if (num > defaultsize)
//	{
//		cout << "人数超过最大范围！！！" << endl;
//		return false;
//	}
//	newnode_->link = current->link;
//	current->link = newnode_;
//	cout << "请依次输入要插入的考生的考号，姓名，性别，年龄及报考类别！";
//	cin >> newnode_->stu->rank;
//	cin >> newnode_->stu->name;
//	cin >> newnode_->stu->gender;
//	cin >> newnode_->stu->age;
//	cin >> newnode_->stu->job;
//	num++;
//	return true;
//
//}
//template <class T>
//newnode<T>* list<T>::locate(int i)//返回第i个结点之前那个结点的指针
//{
//	int t = 1;
//	newnode<T>* current;
//	current = first;
//	if (i < 1)
//		return NULL;
//	while (current != NULL && t != i)//区分数组，数组因为有固定长度所以通过长度可以判断是否越界，但是链表没有固定长度
//	{
//		current = current->link;
//		t++;
//	}
//	return current;
//}
//
//class system_operation//定义一个操作系统专门用来存放学生管理系统，以及使用初始化输入和菜单操作的功能
//{
//public:
//	system_operation()//构造函数，初始化一个学生管理系统
//	{
//		tj = new list<student>;
//	}
//	void init_input();
//	void multioperator();
//private:
//	list<student>* tj;
//};
//
//void system_operation::init_input()//初始化输入
//{
//
//	cout << "首先请建立考生信息系统：" << endl;
//	while (1)//错误判断
//	{
//		cout << "请输入考生人数：" << endl;
//		cin >> tj->num;
//		if (tj->num <= 0)
//		{
//			cout << "请输入一个正整数" << endl;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//
//	cout << "请依次输入考生的考号，姓名，性别，年龄及报考类别！" << endl;
//	tj->input();
//
//
//
//}
//
//void system_operation::multioperator()//操作码输入
//{
//	tj->output();
//	cout << "请选择您要进行的操作(1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作)" << endl;
//	int menu;
//	cin >> menu;
//	while (menu != 0)
//	{
//
//
//		switch (menu)
//		{
//			case 1:
//			{
//
//				int loc;
//				while (1)//错误判断
//				{
//					cout << "请选择您要插入的位置：" << endl;
//
//					cin >> loc;
//					if (loc <= 0 || loc > tj->num + 1)
//					{
//						cout << "位置不符，请重新输入！！！" << endl;
//					}
//					else
//					{
//						break;
//					}
//
//				}
//				tj->insert(loc);
//				tj->output();
//				break;
//			}
//			case 2:
//			{
//				int loc;
//				while (1)
//				{
//					cout << "请选择要删除的考生的考号：" << endl;
//					cin >> loc;
//					if (loc <= 0)
//					{
//						cout << "找不到该考生，请重新输入！！！" << endl;
//					}
//					else
//					{
//						break;
//					}
//				}
//				if (tj->del(loc))
//					tj->output();
//
//				break;
//
//			}
//			case 3:
//			{
//				int loc;
//				while (1)
//				{
//					cout << "请选择要查找的考生的考号：" << endl;
//					cin >> loc;
//					if (loc <= 0)
//					{
//						cout << "找不到该考生，请重新输入！！！" << endl;
//					}
//					else
//					{
//						break;
//					}
//				}
//				if (tj->find(loc))
//					tj->output();
//
//				break;
//			}
//			case 4:
//			{
//				int loc;
//				while (1)
//				{
//					cout << "请选择要修改的考生的考号：" << endl;
//					cin >> loc;
//					if (loc <= 0)
//					{
//						cout << "找不到该考生，请重新输入！！！" << endl;
//					}
//					else
//					{
//						break;
//					}
//				}
//				if (tj->edit(loc))
//					tj->output();
//				break;
//			}
//			case 5:
//			{
//				tj->output();
//				break;
//			}
//
//
//			default:
//			{
//				cout << "抱歉，您要进行的操作不存在，请重新输入！" << endl;
//				break;
//			}
//
//		}
//		cout << "请选择您要进行的操作(1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作)" << endl;
//		cin >> menu;
//	}
//}
//int main()
//{
//	system_operation system_tj;
//	system_tj.init_input();
//	system_tj.multioperator();
//
//
//	return 0;
//}