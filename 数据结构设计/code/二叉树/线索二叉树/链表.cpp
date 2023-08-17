#include<iostream>
using namespace std;
struct ThreadNode {
	char data;
	ThreadNode* leftchild, * rightchild;
	int ltag, rtag;
	ThreadNode(int item)//������Ĭ��ֵ����
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
	ThreadNode* first(ThreadNode* p);//�Ըý��Ϊ���ڵ�ĵ�һ����������
	ThreadNode* next(ThreadNode* p);//�ý��ĺ�̽��
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
			delete p;//����ɾ����p�����ŵ����ݣ�����û��ɾȥ��ָ������Һ���
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
//���������Ϊ��
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