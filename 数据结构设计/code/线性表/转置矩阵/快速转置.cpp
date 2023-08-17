#include<iostream>
using namespace std;
struct array_ {
	int row_;
	int col_;
	int value;
	friend class matrix;
};
class matrix
{
	array_ newarray[100];
	int col, row,notzero=0;
	
	int col_num[];
	public:
		void input();
		void fasttrans();
		void output();
		
};	

void matrix::fasttrans()
{
	matrix b;
	int* rowsize = new int[col];
	int* rowstart = new int[col];
	rowstart[0] = 0;
	for (int i = 0; i < col; i++)
	{
		rowsize[i] = 0;
	}
	for (int i = 0; i < notzero; i++)
	{
		rowsize[newarray[i].col_]++;
	}
	for (int i = 1; i < col; i++)
	{
		rowstart[i] = rowstart[i - 1] + rowsize[i - 1];
	}


	for (int i = 0; i < notzero; i++)
	{
		int j = rowstart[newarray[i].col_];
		b.newarray[j].col_ = newarray[i].row_;
		b.newarray[j].row_ = newarray[i].col_;
		b.newarray[j].value = newarray[i].value;
		rowstart[newarray[i].col_]++;//�ؼ�������
	}
	delete []rowsize;
	delete []rowstart;
	cout << b.newarray[0].value;
	for (int i = 1; i < notzero; i++)
	{
		
		
		if (b.newarray[i].row_ != b.newarray[i - 1].row_)
		{
			cout << endl;
		}
		
		cout << b.newarray[i].value;
		
	}
	
}
void matrix::output()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < notzero; j++)
		{
			if (newarray[j].row_ == i)
			{
				cout << newarray[j].value<<" ";

			}
			else
			{
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
}
void matrix::input()
{
	
	cout << "��������:";
	cin >> row;
	cout << "��������:";
	cin >> col;
	cout << "�밴�����룺";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int p;
			cin >> p;
			if (p != 0)
			{
				newarray[notzero].value = p;
				newarray[notzero].row_ = i;//ʵ�ʴ洢���кź��к�
				newarray[notzero].col_ = j ;
				notzero++;//�������Ԫ�ظ���
				
			}
		}
		
	}

}
int main()
{
	matrix a,b;
	a.input();
	a.fasttrans();

	return 0;
}