#include <iostream>
#include<iomanip>
using namespace std;
void menu()
{
	cout << "**" << setw(27) << "�����㷨�Ƚ�" << setw(22) << "**" << endl;
	cout <<  setfill('=') << setw(52) <<" "<< endl;
	cout << "**" << setfill( ' ')<<setw(29) << "1 --- ð������" << setw(20) << "**" << endl;
}
int main()
{
	menu();
	return 0;
}