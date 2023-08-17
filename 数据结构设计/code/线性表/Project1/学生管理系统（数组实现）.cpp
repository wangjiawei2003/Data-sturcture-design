#include<iostream>
#include<iomanip>
using namespace std;
#define maxlen 100//宏定义
const int defaultsize = 100;
struct stu {
	
	int rank;
	char name[10];//实际只能存储10-1，即9个字符
	char gender[3];
	int age;
	char job[maxlen];
};
class System {
	protected:
		int stu_num;//当前学生个数
		int max_stu;//最大可容纳的学生个数
		stu* student;//动态存储指针
		void resize(int newsize);//改变数组的大小

	public:
		System(int a=0,stu* b=NULL, int sz = defaultsize);//带默认参数的构造函数
		int get_stunum();//通过成员函数访问内部保护成员
		int get_maxstu();
		void output();
		void input();
		void insert();
		void del();
		void find();
		void edit();
		void sum();
		System operator=(System& L);//表整体赋值
};
System System::operator=(System& L)
{
	max_stu = L.max_stu;
	stu_num = L.stu_num;
	student = new stu[max_stu];
	if (student == NULL)
	{
		cerr << "存储空间错误！" << endl;
		exit(1);
	}
	int n = stu_num;
	stu* src = student;
	stu* des = L.student;
	while (n--)
	{
		*src++ = *des++;
	}
	return L;
}
void System::resize(int newsize)
{
	if (newsize < stu_num)
	{
		cerr << "人数超出范围！" << endl;
		exit(1);
	}
	stu* new_student = new stu[newsize];
	if (new_student == NULL)
	{
		cerr << "存储分配错误！" << endl;
		exit(1);
	}
	int n = stu_num;//注意，类中的数据成员不能随意改动，要使用的时候最好新建一个变量
	stu* src = student;//这里同理
	stu* des = new_student;
	while (n--)
	{
		*des++ = *src++;//复制
	}
	delete []student;//删除原数组
	student = new_student;//将原数组首地址变成新的数组首地址
	max_stu = newsize;

}
System::System(int a, stu* b,int sz )//设置过一遍默认值之后不需要再设置一次
{
	stu_num = a;
	student = b;
	max_stu = sz;
	if (sz <= 0)
	{
		exit(1);
	}
	if (sz > 0)
	{
		
		
		student = new stu[max_stu];//动态分配一个长为max_stu的stu数组，首地址是student
		if (student == NULL)
		{
			cerr << "存储分配失败！！！" << endl;//每分配一次都要加上错误判断，考虑健壮性
			exit(1);//若分配失败，直接退出程序
		}
	}
}
int System::get_stunum()
{
	return stu_num;
}
int System::get_maxstu()
{
	return max_stu;
}
void System::input()
{

	cout << "首先请建立考生信息系统！" << endl;
	cout << "请输入考生人数：";
	cin >> stu_num;
	cout << "请依次输入考生的考号，姓名，性别，年龄及报考类别！" << endl;
	for (int i = 0; i < stu_num; i++)
	{
		stu* pupil = new stu;//动态生成pupil
		cin >> pupil->rank;
		cin >> pupil->name;
		cin >> pupil->gender;
		cin >> pupil->age;
		cin >> pupil->job;
		student[i] = *pupil;
		delete pupil;//删除pupil
	}
	cout << endl;
	output();
	cout << "请选择您要进行的操作(1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作)" << endl;
	cout << endl;
}
void System::output()
{
	//标准输出格式
	//一个汉字占用两个像素空间
	cout << setw(8) << setiosflags(ios::left)<<"考号" << setw(8) << "姓名" << setw(8) << "性别" << setw(8) << "年龄" << setw(8) << "报考类别" << endl;
	for (int i = 0; i < stu_num; i++)
	{
		cout << setw(8) << setiosflags(ios::left)<<student[i].rank<< setw(8) << student[i].name << setw(8) << student[i].gender << setw(8) << student[i].age << setw(8) << student[i].job << endl;
	}
}
void System::insert()
{
	int loc;
	cout << "请输入你要插入的考生的位置：";
	cin >> loc;
	cout << "请依次输入要插入的考生的考号，姓名，性别，年龄及报考类别！";
	stu* pupil = new stu;//动态生成pupil
	cin >> pupil->rank;
	cin >> pupil->name;
	cin >> pupil->gender;
	cin >> pupil->age;
	cin >> pupil->job;
	stu_num++;
	for (int i = stu_num-1; i>loc-1; i--)
	{
		student[i] = student[i - 1];
	}
	student[loc - 1] = *pupil;
	delete pupil;

}
void System::del()
{
	cout << "请输入要删除的考生的考号：";
	int loc;
	cin >> loc;
	int flag=0;
	for (int i = 0; i < stu_num; i++)
	{
		
		if (loc == student[i].rank)
		{
			flag = i;
			cout << "你删除的考生信息是：";
			cout << setw(8) << setiosflags(ios::left) << student[i].rank << setw(8) << student[i].name << setw(8) << student[i].gender << setw(8) << student[i].age << setw(8) << student[i].job << endl;
			break;
		}
		if (i == stu_num - 1)//健壮性
		{
			cerr << "找不到该学生！";
			exit(1);
		}
	}
	for (int i = flag; i < stu_num-1; i++)
	{
		student[i] = student[i + 1];
	}
	stu_num--;
}
void System::find()
{
	cout << "请输入要查找的考生的考号：";
	int loc;
	cin >> loc;
	for (int i = 0; i < stu_num; i++)
	{
		if (loc == student[i].rank)
		{
			cout << setw(8) << setiosflags(ios::left) << "考号" << setw(8) << "姓名" << setw(8) << "性别" << setw(8) << "年龄" << setw(8) << "报考类别" << endl;
			cout << setw(8) << setiosflags(ios::left) << student[i].rank << setw(8) << student[i].name << setw(8) << student[i].gender << setw(8) << student[i].age << setw(8) << student[i].job << endl;
			break;
		}
	}

}
int main()
{
	System tj(100);
	tj.input();
	
	//记录现在的考生人数
	

	int menu;
	while (1)
	{
		cout << "请选择你要进行的操作：";
		cin >> menu;
		switch (menu)
		{
			case 1:
				tj.insert();
				break;
			case 2:
				tj.del();
				break;
			case 3:
				//tj.find();
				break;
			case 4:
				//tj.edit();
				break;
			case 5:
				//tj.sum();
				break;
			case 0:
				exit(1);
		}
		tj.output();
	}
	
	return 0;
}