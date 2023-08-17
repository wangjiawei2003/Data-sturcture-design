#include<iostream>
using namespace std;
struct ThreadNode {
	char data;
	ThreadNode* leftchild, * rightchild;
	int ltag, rtag;
	ThreadNode(int item)//数据用默认值调入
	{
		data = item;
		leftchild = NULL;
		rightchild = NULL;
		ltag = 0;
		rtag = 0;
	}
};
class ThreadTree {
public:
	ThreadTree()
	{
		root = NULL;
	}
	~ThreadTree()
	{
		destroy(root);
	}
	ThreadNode* first(ThreadNode* p);//以该结点为根节点的第一个遍历的数
	ThreadNode* next(ThreadNode* p);//该结点的后继结点
	ThreadNode* last(ThreadNode* p);
	ThreadNode* prior(ThreadNode* p);
protected:
	ThreadNode* root;
	void destroy(ThreadNode* p)
	{
		while (p != NULL)
		{
			destroy(p->leftchild);
			destroy(p->rightchild);
			delete p;//这里删除了p里面存放的数据，但是没有删去其指向的左右孩子
			p = NULL;
		}
	}
};
ThreadNode* ThreadTree::prior(ThreadNode* p)
{
	if (p->ltag == 1)
	{
		return p->leftchild;
	}
	else
	{
		return last(p->leftchild);
	}
}
ThreadNode* ThreadTree::last(ThreadNode* p)
{
	while (p->rtag == 0)
	{
		p = p->rightchild;
	}
	return p;
}
//以中序遍历为例
ThreadNode* ThreadTree::next(ThreadNode* p)
{
	if (p->rtag == 1)
	{
		return p->rightchild;
	}
	else
	{
		return first(p->rightchild);
	}
}
ThreadNode* ThreadTree::first(ThreadNode* p)
{
	while (p->ltag == 0)
	{
		p = p->leftchild;
	}
	return p;
}