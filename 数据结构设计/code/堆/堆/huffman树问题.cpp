#include<iostream>
using namespace std;
#define defaultsize 10000
class MinHeap {
protected:
	int num;//实际人数是num+1
	int* heap;
public:
	MinHeap()
	{
		num = -1;
		heap = new int[defaultsize];
	}
	~MinHeap()
	{
		delete []heap;
	}
	void siftdown(int start);//从下到上进行调整
	void siftup(int start);//从上到下进行调整
	bool delmin(int& min);//删除堆顶的最小元素
	bool insert(int data_);//插入一个元素到堆尾
	void huffman_input();//霍夫曼树的输入
	void huffman_output();//霍夫曼树的输出
	
};
void MinHeap::huffman_output()//霍夫曼树的输出
{
	int sum=0;
	int min1;
	int min2;

	while (num>0)//num为0是终止条件，表示当前堆中就一个元素
	{
		delmin(min1);//从堆顶删除最小的元素
		delmin(min2);//从堆顶删除次小的元素
		sum += min1 + min2;
		insert(min1 + min2);//将两者的加和作为新元素插入到堆中

	}
	cout << "最小花费是："<<sum << endl;
}
void MinHeap::huffman_input()//霍夫曼树的输入
{
	int size;
	cout << "请输入木块的条数：" << endl;
	while (1)
	{
		cin >> size;
		if (size > 0 && size < defaultsize)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}
	
	num += size;
	cout << "请输入各木块的长度：" << endl;
	for (int i = 0; i < size; i++)
	{
		
		cin >> heap[i];
			
		
		
		siftup(i);//每输入一个数，就进行一次从下到上的调整
	}
}
bool MinHeap::insert(int data_)//插入一个元素到堆尾
{
	
	if (num+1 >= defaultsize)//如果添加后超出了堆的最大范围，则报错
	{
		cerr << "超出堆可以容纳的最大范围！" << endl;
		return 0;
	}
	else//若未超过，令num加1，给heap[num]赋值，进行从上到下的调整
	{
		num++;
		heap[num] = data_;
		siftup(num);
		return 1;
	}
}
bool MinHeap::delmin(int& min)//删除堆顶的最小元素
{
	if (num < 0)
	{
		cerr << "堆中没有可以删除的元素！" << endl;
		return 0;
	}
	else
	{
		min = heap[0];//将当前的堆顶元素传递给min这个参数，相当于记录了当前删除的最小元素
		heap[0] = heap[num];//将堆尾元素移动到堆顶
		num--;//num减1，表示当前人数减1
		siftdown(0);//对于新的堆顶元素进行从上到下的调整，保证栈顶元素仍然是最小的
		return 1;
	}
	

}
void MinHeap::siftup(int start)//从下到上调整
{
	int i, j;
	i = start;
	j = (i - 1) / 2;
	int temp = heap[start];//暂存当前节点的数值
	while (i > 0 )
	{
		if (temp > heap[j])
		{
			break;
		}
		else
		{
			heap[i] = heap[j];
			i = j;
			j = (i - 1) / 2;
		}
	}
	heap[i] = temp;//调整结束的标志
}
void MinHeap::siftdown(int start)//从上到下调整
{
	int i, j;
	i = start;
	j = 2 * i + 1;
	int temp = heap[start];
	while (j<= num)
	{
		if (j<num && heap[j]>heap[j + 1])
		{
			j++;
		}
		if (temp< heap[j])
		{
			break;
		}
		else
		{
			heap[i] = heap[j];
			i = j;
			j = 2 * i + 1;
		}
	}
	heap[i] = temp;
}
int main()
{

	MinHeap a;
	a.huffman_input();
	a.huffman_output();
}