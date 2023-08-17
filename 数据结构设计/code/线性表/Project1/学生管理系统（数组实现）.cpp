#include<iostream>
#include<iomanip>
using namespace std;
#define maxlen 100//�궨��
const int defaultsize = 100;
struct stu {
	
	int rank;
	char name[10];//ʵ��ֻ�ܴ洢10-1����9���ַ�
	char gender[3];
	int age;
	char job[maxlen];
};
class System {
	protected:
		int stu_num;//��ǰѧ������
		int max_stu;//�������ɵ�ѧ������
		stu* student;//��̬�洢ָ��
		void resize(int newsize);//�ı�����Ĵ�С

	public:
		System(int a=0,stu* b=NULL, int sz = defaultsize);//��Ĭ�ϲ����Ĺ��캯��
		int get_stunum();//ͨ����Ա���������ڲ�������Ա
		int get_maxstu();
		void output();
		void input();
		void insert();
		void del();
		void find();
		void edit();
		void sum();
		System operator=(System& L);//�����帳ֵ
};
System System::operator=(System& L)
{
	max_stu = L.max_stu;
	stu_num = L.stu_num;
	student = new stu[max_stu];
	if (student == NULL)
	{
		cerr << "�洢�ռ����" << endl;
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
		cerr << "����������Χ��" << endl;
		exit(1);
	}
	stu* new_student = new stu[newsize];
	if (new_student == NULL)
	{
		cerr << "�洢�������" << endl;
		exit(1);
	}
	int n = stu_num;//ע�⣬���е����ݳ�Ա��������Ķ���Ҫʹ�õ�ʱ������½�һ������
	stu* src = student;//����ͬ��
	stu* des = new_student;
	while (n--)
	{
		*des++ = *src++;//����
	}
	delete []student;//ɾ��ԭ����
	student = new_student;//��ԭ�����׵�ַ����µ������׵�ַ
	max_stu = newsize;

}
System::System(int a, stu* b,int sz )//���ù�һ��Ĭ��ֵ֮����Ҫ������һ��
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
		
		
		student = new stu[max_stu];//��̬����һ����Ϊmax_stu��stu���飬�׵�ַ��student
		if (student == NULL)
		{
			cerr << "�洢����ʧ�ܣ�����" << endl;//ÿ����һ�ζ�Ҫ���ϴ����жϣ����ǽ�׳��
			exit(1);//������ʧ�ܣ�ֱ���˳�����
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

	cout << "�����뽨��������Ϣϵͳ��" << endl;
	cout << "�����뿼��������";
	cin >> stu_num;
	cout << "���������뿼���Ŀ��ţ��������Ա����估�������" << endl;
	for (int i = 0; i < stu_num; i++)
	{
		stu* pupil = new stu;//��̬����pupil
		cin >> pupil->rank;
		cin >> pupil->name;
		cin >> pupil->gender;
		cin >> pupil->age;
		cin >> pupil->job;
		student[i] = *pupil;
		delete pupil;//ɾ��pupil
	}
	cout << endl;
	output();
	cout << "��ѡ����Ҫ���еĲ���(1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ������)" << endl;
	cout << endl;
}
void System::output()
{
	//��׼�����ʽ
	//һ������ռ���������ؿռ�
	cout << setw(8) << setiosflags(ios::left)<<"����" << setw(8) << "����" << setw(8) << "�Ա�" << setw(8) << "����" << setw(8) << "�������" << endl;
	for (int i = 0; i < stu_num; i++)
	{
		cout << setw(8) << setiosflags(ios::left)<<student[i].rank<< setw(8) << student[i].name << setw(8) << student[i].gender << setw(8) << student[i].age << setw(8) << student[i].job << endl;
	}
}
void System::insert()
{
	int loc;
	cout << "��������Ҫ����Ŀ�����λ�ã�";
	cin >> loc;
	cout << "����������Ҫ����Ŀ����Ŀ��ţ��������Ա����估�������";
	stu* pupil = new stu;//��̬����pupil
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
	cout << "������Ҫɾ���Ŀ����Ŀ��ţ�";
	int loc;
	cin >> loc;
	int flag=0;
	for (int i = 0; i < stu_num; i++)
	{
		
		if (loc == student[i].rank)
		{
			flag = i;
			cout << "��ɾ���Ŀ�����Ϣ�ǣ�";
			cout << setw(8) << setiosflags(ios::left) << student[i].rank << setw(8) << student[i].name << setw(8) << student[i].gender << setw(8) << student[i].age << setw(8) << student[i].job << endl;
			break;
		}
		if (i == stu_num - 1)//��׳��
		{
			cerr << "�Ҳ�����ѧ����";
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
	cout << "������Ҫ���ҵĿ����Ŀ��ţ�";
	int loc;
	cin >> loc;
	for (int i = 0; i < stu_num; i++)
	{
		if (loc == student[i].rank)
		{
			cout << setw(8) << setiosflags(ios::left) << "����" << setw(8) << "����" << setw(8) << "�Ա�" << setw(8) << "����" << setw(8) << "�������" << endl;
			cout << setw(8) << setiosflags(ios::left) << student[i].rank << setw(8) << student[i].name << setw(8) << student[i].gender << setw(8) << student[i].age << setw(8) << student[i].job << endl;
			break;
		}
	}

}
int main()
{
	System tj(100);
	tj.input();
	
	//��¼���ڵĿ�������
	

	int menu;
	while (1)
	{
		cout << "��ѡ����Ҫ���еĲ�����";
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