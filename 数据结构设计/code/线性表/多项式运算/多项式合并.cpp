#include<iostream>
const int maxlen = 100;
using namespace std;
char compare(int i, int j)
{
	if (i == j)
		return '=';
	if (i > j)
		return '>';
	else
		return '<';
}

struct term
{
	int zhishu;
	int xishu;
	//friend class poly;
};
class poly
{
	term* adr=NULL;
	int term_num=0;
	int start=0;
public:
	void input();
	void output();
	poly operator+(poly a);
};	
void poly::input()
{
	
	cin >> term_num;
	adr = new term[term_num];
	for (int i = 0; i < term_num; i++)
	{
		cin >> adr[i].xishu;
		cin >> adr[i].zhishu;
	}
}
void poly::output()
{

	
	for (int i = 0; i < term_num; i++)
	{
		cout << adr[i].xishu<<" ";
		cout << adr[i].zhishu;
		cout << endl;
	}
}
poly poly::operator+(poly a)
{
	poly b;
	int count = 0;
	b.adr = new term[a.term_num+term_num];
	
	while(a.start<a.term_num && start<term_num)
	{
		switch (compare(a.adr[a.start].zhishu, adr[start].zhishu))
		{
			case '=':
				b.adr[count].zhishu = a.adr[a.start].zhishu;
				b.adr[count].xishu = a.adr[a.start].xishu+adr[start].xishu ;
				a.start++;
				start++;
				count++;
				break;
			case '<':
				b.adr[count].zhishu = a.adr[a.start].zhishu;
				b.adr[count].xishu = a.adr[a.start].xishu;
				a.start++;
				count++;
				break;
			case '>':
				b.adr[count].zhishu = adr[start].zhishu;
				b.adr[count].xishu = adr[start].xishu;
				start++;
				count++;
				break;
		}
	}
	for (;a.start < a.term_num;a.start++,count++)
	{
		b.adr[count].zhishu = a.adr[a.start].zhishu;
		b.adr[count].xishu = a.adr[a.start].xishu;
	}
	for (; start < term_num; start++, count++)
	{
		b.adr[count].zhishu = adr[start].zhishu;
		b.adr[count].xishu = adr[start].xishu;
	}
	b.term_num = count;
	return b;
}
int main()
{
	poly d,a,b;
	a.input();
	cout << "ok" << endl;
	b.input();
	d = a + b;
	d.output();
	return 0;
}