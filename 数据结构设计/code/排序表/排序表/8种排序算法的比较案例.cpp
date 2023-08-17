#include<iostream>
#include<iomanip>
#include<time.h>
#define defaultsize 100000
using namespace std;
void swap(int* element,int x, int y)//交换x和y位置的两数
{
	int temp = element[x];
	element[x] = element[y];
	element[y] = temp;
}
class Datalist {//数据表
private:

	int maxsize;//最大可容纳的长度
	int currentsize;//当前的长度

public:
	int* element;//存放数据元素
	Datalist()
	{
		element = new int[defaultsize ];
		for (int i = 0; i < defaultsize; i++)
		{
			element[i] = 0;
		}
		currentsize = 0;
		maxsize = defaultsize;
	}
	~Datalist()
	{
		delete[]element;
	}
	int length()
	{
		return currentsize;
	}
	bool inset_element(int x)//插入元素
	{
		if (currentsize+1 > maxsize)
		{
			cout << "空间已满，无法插入！" << endl;
			return false;
		}
		else
		{
			element[currentsize] = x;
			currentsize++;
			return true;
		}
	
		
	}
	void bulid_element( int n)//创建数组表
	{
		srand(unsigned int(time(nullptr)));

		for (int i = 0; i < n; i++)
		{
			inset_element(rand() % 10000);
		}
	}
	void output()//输出数组表
	{
		for (int i = 0; i < currentsize; i++)
		{
			cout << element[i] << endl;
		}
	}
};
class MaxHeap
{
private:
	int* heap;					//存储数据的数组表
	int currentSize;			//当前数组的大小
	int operationNum;		//交换次数
public:
	MaxHeap(int num, int elems[])
	{
		heap = new int[num];
		if (heap == NULL)
		{
			cerr << "Memory request error!" << endl;
			exit(1);
		}
		currentSize = num;
		operationNum = 0;
		for (int i = 0; i < num; i++)		//初始化
		{
			heap[i] = elems[i];
		}
	}
	
	bool Remove();//移除数组

	bool Empty()//清空数组
	{
		return currentSize == 0;
	}

	void SiftDown(const int start, const int m);//最大堆调整算法

	void Swap(const int i, const int j);//交换两元素

	void HeapSort();//堆排序

	int GetoperationNum()//获取交换次数
	{
		return operationNum;
	}

	~MaxHeap()//析构函数
	{
		delete[]heap;
	}
};
bool MaxHeap::Remove()
{
	if (currentSize == 0)
		return 0;
	int max = heap[0];
	heap[0] = heap[currentSize - 1];	//最后一个元素赋给根节点
	currentSize--;
	SiftDown(0, currentSize - 1);		//调整
	return 1;
}
void MaxHeap::Swap(const int i, const int j)
{
	int tmp = heap[i];
	heap[i] = heap[j];
	heap[j] = tmp;
}
void MaxHeap::SiftDown(const int start, const int end)
{
	int current = start;
	int child = 2 * start + 1;			//左孩子
	int temp = heap[start];
	while (child <= end)
	{
		if (child + 1 < end && heap[child] < heap[child + 1])
			child = child + 1;				//指向较大的孩子
		
		if (temp >= heap[child])
			break;
		else {								//较大的孩子往上移动
			heap[current] = heap[child];
			current = child;
			child = 2 * child + 1;
		}
		
	}
	heap[current] = temp;					//变量储存到合适位置
	operationNum++;
}
void MaxHeap::HeapSort()
{
	for (int i = (currentSize - 2) / 2; i >= 0; i--)
	{
		SiftDown(i, currentSize - 1);	//创建堆
	}
	for (int i = currentSize - 1; i > 0; i--)
	{
		Swap(0, i);
		operationNum++;
		SiftDown(0, i - 1);				//交换，重建最大堆
	}
}


void DisplayMenu()//显示菜单
{
	cout << setiosflags(ios::left);
	cout << setw(18) << "**" << setw(32) << "排序算法比较" << "**" << endl;
	cout << "====================================================" << endl;
	cout << setw(16) << "**" << setw(34) << "1 --- 冒泡排序" << "**" << endl;
	cout << setw(16) << "**" << setw(34) << "2 --- 选择排序" << "**" << endl;
	cout << setw(16) << "**" << setw(34) << "3 --- 直接插入排序" << "**" << endl;
	cout << setw(16) << "**" << setw(34) << "4 --- 希尔排序" << "**" << endl;
	cout << setw(16) << "**" << setw(34) << "5 --- 快速排序" << "**" << endl;
	cout << setw(16) << "**" << setw(34) << "6 --- 堆排序" << "**" << endl;
	cout << setw(16) << "**" << setw(34) << "7 --- 归并排序" << "**" << endl;
	cout << setw(16) << "**" << setw(34) << "8 --- 基数排序" << "**" << endl;
	cout << setw(16) << "**" << setw(34) << "9 --- 退出程序" << "**" << endl;
	cout << "====================================================" << endl;
}
void input(int& n)//输入随机数
{
	while (1)
	{
		cout << "请输入要产生的随机数的个数：";
		cin >> n;
		if (n > 0 && n <= 100000)
		{
			break;
		}
		else
		{
			cout << "随机数输入有误，请重新输入！" << endl;
		}
	}
	
}
void BubbleSort(int element[], int len, int& num)//冒泡排序
{


	for (int i = 0; i < len; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (element[j] < element[j - 1])
			{
				swap(element, j, j - 1);
				num++;//交换次数
			}
		}
	}

}
void SelectSort(int element[],int len,int& num)//选择排序
{
	for (int i = 0; i < len; i++)
	{
		int k = i;
		for (int j = i + 1; j < len; j++)
		{
			if (element[j] < element[k])
			{
				k = j;
			}
		}
		if (k != i)
		{
			swap(element,k, i);
			num++;//交换次数
		}
	}
}
void InsertSort(int element[], int len, int& num)//直接插入排序
{
	int tmp;
	int j;
	for (int i =  1; i <= len-1; i++)
	{
		if (element[i] < element[i - 1])			
		{
			tmp = element[i];
			j = i - 1;
			do {
				element[j + 1] = element[j];
				j--;
				num++;//比较次数
			} while (j >= 0 && tmp < element[j]);
			element[j + 1] = tmp;
		
		}
		
	}
}
void ShellSort(int element[], int len, int& num)//希尔排序
{
	int i, j, gap = len;
	int temp;
	do {
		gap = gap / 3+1;
		for (i = gap; i <= len - 1; i++)
		{
			if (element[i] < element[i - gap])
			{
				temp = element[i];
				j = i - gap;
				do {
					element[j + gap] = element[j];
					j = j - gap;
					num++;//比较次数
				} while (j >= 0 && temp < element[j]);
				element[j + gap] = temp;

			}
			
		
		}
	} while (gap > 1);
}
int Partition(int element[],int low,int high,int& num)//划分函数
{
	int pivotpos =low;
	int pivot = element[low];//基准元素
	for (int i = low + 1; i <= high; i++)//检索整个序列，进行划分
	{
		if (element[i] < pivot)//小于基准的交换到左侧
		{
			pivotpos++;
			if (pivotpos != i)
			{
				swap(element, pivotpos, i);
				num++;//交换次数
			}
		}
	}
	element[low] = element[pivotpos];
	element[pivotpos] = pivot;//将基准元素就位
	num++;
	return pivotpos;//返回基准元素位置
}
void QuickSort(int element[], int low,int high, int& num)//快速排序
{
	if (low < high)//元素长度大于1时
	{
		int pivotpos = Partition(element, low, high, num);//划分
		QuickSort(element, low, pivotpos - 1,num);//对左侧子序列进行同样处理
		QuickSort(element, pivotpos + 1, high,num);//对右侧子序列进行同样处理
	}
}
void Merge(int List1[], int List2[], int left, int mid, int right, int& operationNum)
{
	for (int k = left; k <= right; k++)//list2是list1的拷贝
	{
		List2[k] = List1[k];
	}
	int s1 = left, s2 = mid + 1,t=left;//t是当前List1的指针
	while (s1 <= mid && s2 <= right)			//两个表未检测完，两两比较
	{
		if (List2[s1] < List2[s2])
		{
			List1[t++] = List2[s1++];
		}
		else
		{
			List1[t++] = List2[s2++];
		}
		operationNum++;//比较次数
	}
	while (s1<= mid)			//第一个表还未检测完
		List1[t++] = List2[s1++];
	while (s2 <= right)			//第二个表还未检测完
		List1[t++] = List1[s2++];
	
}
void MergeSort(int List[],int List2[], int left,int right, int& operationNum)
{
	
	if (left >= right)
		return;
	int mid = (left + right) / 2;//从中间划分两个子序列
	MergeSort(List, List2, left,  mid, operationNum);//对左子序列进行递归排序
	MergeSort(List, List2, mid + 1, right, operationNum);//对右子序列进行递归排序
	Merge(List, List2, left, mid, right, operationNum);//合并

}
int getDigit(int x, int k)//获取该位的值，k是从左往右数的第k位
{
	if (k < 1 || k>5)
	{
		return -1;
	}
	for (int i = 1; i <= 5 - k; i++)
	{
		x = x / 10;
	}
	return x % 10;
}
void RadixSort(int element[],int left,int right,int k,int& operationNum)//基数排序
{
	if (left >= right || k > 5)
		return ;
	int i, j,  p1, p2, count[10], posit[10];
	int* auxArray = new int[right - left + 1];//暂存分配结果
	for (j = 0; j < 10; j++)
	{
		count[j] = 0;
	}
	for (i = left; i <= right; i++)
	{
		count[getDigit(element[i], k)]++;//统计各桶元素个数
	}
	posit[0] = 0;
	for (j = 1; j < 10; j++)
	{
		posit[j] = count[j - 1] + posit[j - 1];//安排各桶元素位置
	}
	for (i = left; i <= right; i++)//元素按位置分配到各桶
	{
		j = getDigit(element[i], k);//取元素A【i】的第k位的值
		auxArray[posit[j]++] = element[i];//按预先计算位置存放
	}
	for (i = left, j = 0; i <= right; i++, j++)
	{
		element[i] = auxArray[j];//从辅助数组写入原数组
	}
	delete[]auxArray;
	p1 = left;
	for (j = 0; j < 10; j++)//按桶递归从第k+1位处理
	{
		p2 = p1 + count[j] - 1;//取子桶的首末位置
		RadixSort(element, p1, p2, k + 1,operationNum);//对子桶内元素做桶排序
		p1 = p2 + 1;
	}

}
void OperationModule(Datalist a)//操作码选择
{
	clock_t start_time, end_time;
	int num = 0;
	int choice=0;
	int len = a.length();
	
	while (1)
	{
		MaxHeap G(len, a.element);
		int* copy_ = new int[len];//原数组的拷贝
		for (int i = 0; i < len; i++)
		{
			copy_[i] = a.element[i];
		}
		int* copy = new int[len];//新建一个空数组
		num = 0;
		cout << "请选择排序算法：";
		cin >> choice;
	
		switch(choice)
		{
			case 1://冒泡排序
				start_time = clock();			//获取开始时间
				BubbleSort(copy_,len,num);
				end_time = clock();
				cout << "冒泡排序所用时间：" << (double)((end_time*1.0 - start_time*1.0 ) / CLOCKS_PER_SEC) << endl;
				cout << "冒泡排序交换次数：" << num << endl;
				break;
			case 2://选择排序
				start_time = clock();
				SelectSort(copy_, len, num);
				end_time = clock();
				cout << "选择排序所用时间：" << (double)((end_time * 1.0 - start_time * 1.0) / CLOCKS_PER_SEC) << endl;
				cout << "选择排序交换次数：" << num << endl;
				break;
			case 3:
				start_time = clock();
				InsertSort(copy_, len, num);
				end_time = clock();
				cout << "直接插入排序所用时间：" << (double)((end_time * 1.0 - start_time * 1.0) / CLOCKS_PER_SEC) << endl;
				cout << "直接插入排序比较次数：" << num << endl;
				break;
			case 4:
				start_time = clock();
				ShellSort(copy_, len, num);
				end_time = clock();
				cout << "希尔排序所用时间：" << (double)((end_time * 1.0 - start_time * 1.0) / CLOCKS_PER_SEC) << endl;
				cout << "希尔排序比较次数：" << num << endl;
				break;
			case 5:
				start_time = clock();
				QuickSort(copy_, 0,len-1, num);
				end_time = clock();
				cout << "快速排序所用时间：" << (double)((end_time * 1.0 - start_time * 1.0) / CLOCKS_PER_SEC) << endl;
				cout << "快速排序交换次数：" << num << endl;
				break;
			case 6:
				start_time = clock();
				G.HeapSort();
				end_time = clock();
				cout << "堆排序所用时间：" << (double)((end_time * 1.0 - start_time * 1.0) / CLOCKS_PER_SEC) << endl;
				cout << "堆排序交换次数：" << G.GetoperationNum() << endl;
				break;
			case 7:
				start_time = clock();
				MergeSort(copy_, copy,0, len - 1, num);
				end_time = clock();
				cout << "归并排序所用时间：" << (double)((end_time * 1.0 - start_time * 1.0) / CLOCKS_PER_SEC) << endl;
				cout << "归并排序比较次数：" << num << endl;
				break;
			case 8:
				start_time = clock();
				RadixSort(copy_, 0, len - 1, 1,num);
				end_time = clock();
				cout << "基数排序所用时间：" << (double)((end_time * 1.0 - start_time * 1.0) / CLOCKS_PER_SEC) << endl;
				cout << "基数排序交换次数：" << num << endl;
				break;
			case 9:
				exit(1);
				break;
			default:
				cout << "输入码输入有误，请重新输入！" << endl;
				break;
		}
	}
	cout << endl << endl;
}

int main()
{
	DisplayMenu();
	int n=0;
	
	input(n);
	Datalist a;
	a.bulid_element(n);
	OperationModule(a);
}