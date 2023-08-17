#include<iostream>
#include<iomanip>
using namespace std;
//子树结点
struct treenode {//树节点存储每个成员的信息
	string data;
	treenode* leftchild;
	treenode* nextsibling;
	treenode(string name)
	{
		data = name;
		leftchild = NULL;
		nextsibling = NULL;
	}
};
class Tree {//树包含所有树节点

private:
	treenode* root;
public:
	Tree(treenode* p = NULL)
	{
		root = p;
	}
	treenode* Parent(treenode* p, treenode* current);//寻找父亲节点
	treenode* Find(treenode* p, string value);//寻找当前结点
	void input();//初始化输入
	void createfamily();//完善家庭
	void addfamilymember();//添加家庭成员
	void deletefamily();//删除家庭成员
	void changename();//改名
};
void Tree::deletefamily()
{
	treenode* p;
	string name;
	while (1)
	{
		cout << "请输入要解散家庭的人的姓名：";

		cin >> name;
		if ((p = Find(root, name)) == NULL)
		{
			cout << "该家庭不包含该成员，请重新输入！" << endl;
		}
		else
		{
			break;
		}
	}


	treenode* t = Parent(root, p);
	treenode* current;
	if (t->leftchild->data == p->data)
	{
		t->leftchild = p->nextsibling;
	}
	else
	{
		for (current = t->leftchild; current != NULL; current = current->nextsibling)
		{
			if (current->nextsibling->data == p->data)
			{
				current->nextsibling = p->nextsibling;
				break;
			}

		}
	}
	cout << "要解散家庭的人是：" << name << endl;
	cout << name << "的第一代子孙是：";
	for (current = p->leftchild; current != NULL; current = current->nextsibling)
	{
		cout << current->data << " ";
	}
	cout << endl;


}
void Tree::addfamilymember()
{

	treenode* p;
	string name;
	treenode* current_;
	while (1)
	{

		cout << "请输入要添加儿子(或女儿)的人的姓名：";
		cin >> name;
		if ((p = Find(root, name)) == NULL)
		{
			cout << "该家庭不包含该成员，请重新输入！" << endl;
		}
		else
		{
			break;
		}
	}
	treenode* current = p->leftchild;
	string child;
	while(1)
	{
		cout << "请输入" << name << "新添加的儿子(或女儿)的姓名：";
		
		cin >> child;
		if ((current_ = Find(root, child)) != NULL)
		{
			cout << "新添加的姓名已经被家庭成员所占用，请重新输入！" << endl;
		}
		else
		{
			break;
		}
	}
	
	
	if (p->leftchild == NULL)
	{
		p->leftchild = new treenode(child);
	}
	else
	{

		while (current->nextsibling != NULL)
		{
			current = current->nextsibling;
		}
		current->nextsibling = new treenode(child);
	}
	cout << name << "的第一代子孙是：";
	for (current = p->leftchild; current != NULL; current = current->nextsibling)
	{
		cout << current->data << " ";
	}
	cout << endl;
}
void Tree::createfamily()
{
	string name;
	//包含错误输入，若输入一个不在该家庭中的名字，输出错误信息
	while (1)
	{
		cout << "请输入要建立家庭的人的姓名：";

		cin >> name;
		if (Find(root, name) == NULL)
		{
			cout << "该家庭不包含该成员，请重新输入！" << endl;
		}
		else if (Find(root, name)->leftchild != NULL)
		{
			cout << "此人已有家庭，无法新建家庭！" << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入" << name << "的儿女人数：";
	int num;
	cin >> num;
	cout << "请依次输入" << name << "的儿女的姓名：";
	treenode* p = Find(root, name);
	treenode* current = p;
	string child;
	for (int i = 0; i < num; i++)
	{
		cin >> child;
		if (i == 0)
		{
			current->leftchild = new treenode(child);
			current = current->leftchild;
		}
		else
		{
			current->nextsibling = new treenode(child);
			current = current->nextsibling;
		}
	}
	cout << name << "的第一代子孙是：";
	for (current = p->leftchild; current != NULL; current = current->nextsibling)
	{
		cout << current->data << " ";
	}
	cout << endl;
}

treenode* Tree::Find(treenode* p, string value)
{
	treenode* s;
	if (p->data == value)
	{
		return p;
	}
	while (p != NULL)
	{
		for (p = p->leftchild; p != NULL; p = p->nextsibling)
		{
			s = Find(p, value);
			if (s != NULL)
			{
				return s;
			}
		}

	}
	return NULL;
}
void Tree::changename()
{
	string name;
	treenode* current;
	treenode* current_;
	while (1)
	{
		cout << "请输入要更改名字的人的目前姓名：";

		cin >> name;
		if ((current = Find(root, name)) == NULL)
		{
			cout << "该家庭不包含该成员，请重新输入！" << endl;
		}
		else
		{
			break;
		}
	}


	string newname;
	while (1)
	{
		cout << "请输入更改后的姓名：";
		cin >> newname;
		if ((current_ = Find(root, newname)) != NULL)
		{
			cout << "该新名字已经被家庭成员所占用，请重新输入！" << endl;
		}
		else
		{
			current->data = newname;
			cout << name << "已更名为" << newname;
			cout << endl;
			break;
		}
	
	}
	
}
treenode* Tree::Parent(treenode* p, treenode* current)
{
	treenode* s;
	if (current == root)
	{
		return NULL;
	}


	for (s = p->leftchild; s != NULL; s = s->nextsibling)
	{
		if (s == current)
		{
			return p;
		}
		if (Parent(s, current) != NULL)
		{
			return Parent(s, current);
		}
		
	}

	
	return NULL;
}
void menu()
{
	cout << "**" << setw(29) << "家谱管理系统" << setw(20) << setfill(' ') << "**" << endl;
	cout << setw(52) << setfill('=') << " " << endl;
	cout << setw(19) << setiosflags(ios::left) << setfill(' ') << "**" << setw(30) << setfill(' ') << "请选择要执行的操作：" << "**" << endl;
	cout << setw(19) << setiosflags(ios::left) << setfill(' ') << "**" << setw(30) << setfill(' ') << "A---完善家庭" << "**" << endl;
	cout << setw(19) << setiosflags(ios::left) << setfill(' ') << "**" << setw(30) << setfill(' ') << "B---添加家庭成员" << "**" << endl;
	cout << setw(19) << setiosflags(ios::left) << setfill(' ') << "**" << setw(30) << setfill(' ') << "C---解散局部家庭" << "**" << endl;
	cout << setw(19) << setiosflags(ios::left) << setfill(' ') << "**" << setw(30) << setfill(' ') << "D---更改家庭成员姓名：" << "**" << endl;
	cout << setw(19) << setiosflags(ios::left) << setfill(' ') << "**" << setw(30) << setfill(' ') << "E---退出程序" << "**" << endl;


	cout << setw(52) << setiosflags(ios::right) << setfill('=') << " " << endl;
}
void Tree::input()
{
	cout << "首先建立一个家谱！" << endl;
	cout << "请输入祖先的姓名：";

	string zuxian;
	cin >> zuxian;
	root = new treenode(zuxian);//若不加这步会报错，必须将root初始化

	cout << "此家谱的祖先是：" << zuxian << endl;
	char option;
	while (1)
	{
		cout << "请选择要执行的操作：";
		cin >> option;
		switch (option)
		{
			case 'A':
			{
				createfamily();
				break;
			}
			case 'B':
			{
				addfamilymember();
				break;
			}
			case 'C':
			{
				deletefamily();
				break;
			}
			case 'D':
			{
				changename();
				break;
			}
			case 'E':
			{
				exit(1);
				break;
			}
			default:
			{
				cout << "无此选项，请重新输入！" << endl;
				break;
			}
		}
	}

}
int main()
{

	Tree a;
	menu();
	a.input();

}