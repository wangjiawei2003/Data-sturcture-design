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
struct BinTreeNode//只含有左孩子和右孩子
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
	void destroy(BinTreeNode*& subtree);//因为要修改各个结点，所以要用引用
	int Size(BinTreeNode* subtree);
	int height(BinTreeNode* subtree);

};

void BinaryTree::inorder()
{
	
	BinTreeNode* p = root;
	do {
		while (p != NULL)
		{
			b.push(p);//该子树沿途节点进栈
			p = p->leftchild;//遍历指针，一左到底
		}
		if (!b.isempty())
		{
			b.pop(p);//弹出一左到底的结点
			cout << p->data;
			p = p->rightchild;//弹出的结点由于是最左结点，所以还需要考虑该结点是否有右孩子
		}
	} while (p != NULL || !b.isempty());
}

void BinaryTree::Postorder(BinTreeNode* p)//后续遍历的递归算法
{
	while (p != NULL)
	{
		Postorder(p->leftchild);
		Postorder(p->rightchild);
		cout << p->data;
	}
}

void BinaryTree::Preorder(BinTreeNode* p)//前序遍历的递归算法
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
void BinaryTree::preorder()//前序遍历的非递归方法
{
	BinTreeNode* p=root;
	
	a.push(NULL);//必须加，否则无法终止
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
					t = s[top];//保留当前元素的父节点
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
	if (current == NULL)//该结点为空
	{
		return NULL;
	}
	if (current == subtree)//该结点是根结点
	{
		return NULL;
	}
	if (subtree->leftchild == current || subtree->rightchild == current)//判断终止条件
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