#include<iostream>
using namespace std;
#include<stack>
enum tag_ { L, R }; 
struct stknode
{
	BinTreeNode* ptr;
	tag_ tag;
	stknode(BinTreeNode* t = NULL)
	{
		ptr = t;
		tag = L;
	}
};
struct BinTreeNode//ֻ�������Ӻ��Һ���
{
	char data;
	BinTreeNode* leftchild;
	BinTreeNode* rightchild;
	BinTreeNode() 
	{
		leftchild = NULL;
		rightchild = NULL;
	}
	BinTreeNode(char x, BinTreeNode* l = NULL, BinTreeNode* r = NULL)
	{
		data = x;
		leftchild = l;
		rightchild = r;
	}
};

stack<BinTreeNode*> a;

stack<BinTreeNode*> b;

stack<stknode*> c;

class BinaryTree
{
public:
	BinaryTree()
	{
		root = NULL;
	}
	~BinaryTree()
	{
		destroy(root);
	}

	BinaryTree* Parent(BinTreeNode* subtree,BinTreeNode* current);
	void createBinTree(char in[]);
	void Traverse(BinTreeNode* subtree);
	void preorder();
	void Preorder(BinTreeNode* p);
	void inorder();
	void postorder(BinTreeNode* p);
	void Postorder(BinTreeNode* p);
protected:
	BinTreeNode* root;
	void destroy(BinTreeNode*& subtree);//��ΪҪ�޸ĸ�����㣬����Ҫ������
	int Size(BinTreeNode* subtree);
	int height(BinTreeNode* subtree);

};

void BinaryTree::inorder()
{
	
	BinTreeNode* p = root;
	do {
		while (p != NULL)
		{
			b.push(p);//��������;�ڵ��ջ
			p = p->leftchild;//����ָ�룬һ�󵽵�
		}
		if (!b.isempty())
		{
			b.pop(p);//����һ�󵽵׵Ľ��
			cout << p->data;
			p = p->rightchild;//�����Ľ�������������㣬���Ի���Ҫ���Ǹý���Ƿ����Һ���
		}
	} while (p != NULL || !b.isempty());
}

void BinaryTree::Postorder(BinTreeNode* p)//���������ĵݹ��㷨
{
	while (p != NULL)
	{
		Postorder(p->leftchild);
		Postorder(p->rightchild);
		cout << p->data;
	}
}

void BinaryTree::Preorder(BinTreeNode* p)//ǰ������ĵݹ��㷨
{
	
	while (p != NULL)
	{
		cout << p->data;
	
		Preorder(p->leftchild);
	
		Preorder(p->rightchild);
	}
}
void BinaryTree::postorder(BinTreeNode* p)
{
	p = root; 
	stknode* t,*c[10];
	int top = -1;
	while (p != NULL || top != -1)
	{
		while (p != NULL)
		{

			t->ptr = p;
			t->tag = L;
			c[++top] = t;
			p = p->leftchild;
		}
		t= c[top--];
		p = t->ptr;
		if (t->tag == L)
		{
			t->tag = R;
			top++;
			c[top] = t;
			p = p->rightchild;
		}
		else
		{
			cout << p->data;
			p = NULL;
		}
	}
}
void BinaryTree::preorder()//ǰ������ķǵݹ鷽��
{
	BinTreeNode* p=root;
	
	a.push(NULL);//����ӣ������޷���ֹ
	while (p != NULL)
	{
		cout << p->data;
		if (p->rightchild != NULL)
		{
			a.push(p->rightchild);
		}
		if (p->leftchild != NULL)
		{
			p = p->leftchild;
		}
		else
		{
			a.pop(p);
		}
	}
}

int BinaryTree::height(BinTreeNode* subtree)
{
	if (subtree == NULL)
	{
		return 0;
	}
	else
	{
		return (height(subtree->leftchild) < height(subtree->rightchild)) ? 1 + height(subtree->rightchild) : 1 + height(subtree->leftchild));
	}
}

int BinaryTree::Size(BinTreeNode* subtree)
{
	if (subtree == NULL)
		return 0;
	else
	{
		return 1 + Size(subtree->leftchild) + Size(subtree->rightchild);
	}
}

void BinaryTree::Traverse(BinTreeNode*subtree)
{
	if (subtree != NULL)
	{
		cout << subtree->data << endl;
		Traverse(subtree->leftchild);
		Traverse(subtree->rightchild);
	}
	else
	{
		cout << "#" << endl;
	}
}

void BinaryTree::createBinTree(char in[])
{
	int i = -1;
	char ch;
	int flag=0;
	int top = -1;
	BinTreeNode* p= new BinTreeNode();
	BinTreeNode* t;
	BinTreeNode* s[30];
	ch = in[++i];
	while (ch != '#')
	{
		switch (ch) 
		{
			case '(':
			{
				s[++top] = p;
				flag = 1;
				break;
			}
			case ')':
			{
				top--;
				break;
			}
			case ',':
			{
				flag = 2;
				break;
			}
			default:
			{
				p = new BinTreeNode(ch);
				if (root == NULL)
				{
					root = p;
				}
				else
				{
					t = s[top];//������ǰԪ�صĸ��ڵ�
					if (flag == 1)
					{
						t->leftchild = p;
					}
					else
					{
						t->rightchild = p;
					}
				}
			}
		}
		ch = in[++i];
		
	}
	Traverse(root);
}
template<class T>
BinaryTree* Parent(BinTreeNode*subtree ,BinTreeNode* current)
{
	if (current == NULL)//�ý��Ϊ��
	{
		return NULL;
	}
	if (current == subtree)//�ý���Ǹ����
	{
		return NULL;
	}
	if (subtree->leftchild == current || subtree->rightchild == current)//�ж���ֹ����
	{
		return subtree;
	}
	BinTreeNode* p;
	if ((p=Parent(subtree->leftchild,  current ))!=NULL)
	{
		return p;
	}
	else
	{
		return Parent(subtree->rightchild);
	}
}

void BinaryTree::destroy(BinTreeNode*& subtree)
{
	if (subtree != NULL)
	{
		destroy(subtree->leftchild);
		destroy(subtree->rightchild);
		delete subtree;
		subtree = NULL;
	}
}
int main()
{
	BinaryTree a;
	char formula[20];
	cin>>formula;
	a.createBinTree(formula);
	
	return 0;
}