#include<iostream>
#include<iomanip>
int src_x, src_y;
int des_x, des_y;
char map[100][100];
int step_x[100];
int step_y[100];
int step_ = 0;
int row, col;
using namespace std;
bool migong(int current_x, int current_y)//求可行路径
{

	if (current_x == des_x && current_y == des_y)
	{
		return true;
	}
	else
	{
		if (map[current_x][current_y] == '0')//该位置未被遍历
		{
			map[current_x][current_y] = 'x';//表示该位置已经遍历过
			if (migong(current_x + 1, current_y))//沿该方向遍历可以找到到终点的通路
			{
				step_x[++step_] = current_x + 1;
				step_y[step_] = current_y;
				return true;
			}
			else if (migong(current_x - 1, current_y))//沿该方向遍历可以找到到终点的通路
			{
				step_x[++step_] = current_x - 1;
				step_y[step_] = current_y;
				return true;
			}
			else if (migong(current_x, current_y + 1))//沿该方向遍历可以找到到终点的通路
			{
				step_x[++step_] = current_x;
				step_y[step_] = current_y + 1;
				return true;
			}
			else if (migong(current_x, current_y - 1))//沿该方向遍历可以找到到终点的通路
			{
				step_x[++step_] = current_x;
				step_y[step_] = current_y - 1;
				return true;
			}
			else
			{
				map[current_x][current_y] = '$';//表示该位置无通路
				return false;
			}
		}
		else
		{
			return false;
		}


	}
}
void output()//输出结果
{
	//输出整个迷宫的可走路径图
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (map[i][j] == '$')
			{
				map[i][j] = '0';
			}
		}
	}
	map[des_x][des_y] = 'x';
	cout << "迷宫地图：" << endl;
	cout << "  ";
	for (int j = 1; j <= col; j++)
	{
		cout << setw(4) << j << "列";
	}
	cout << endl;
	for (int i = 1; i <= row; i++)
	{
		cout << setiosflags(ios::left) << i << setw(4) << "行";
		for (int j = 1; j <= col; j++)
		{

			cout << setiosflags(ios::left) << setw(5) << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "迷宫路径：" << endl;
	cout << "<" << src_x << "," << src_y << "> -->";
	for (int i = step_; i > 0; i--)
	{
		if (i > 1)
			cout << " <" << step_x[i] << "," << step_y[i] << "> -->";
		else
			cout << " <" << step_x[i] << "," << step_y[i] << "> ";

	}

	cout << endl;

}
void input()//输入初始信息
{
	//输入行号加列号信息，外加错误判断
	while (1)
	{
		cout << "输入行数:";
		cin >> row;
		if (row <= 0)
		{
			cout << "行号不符，请重新输入！！！" << endl;
		}
		else
		{
			break;
		}
	}
	while (1)
	{
		cout << "输入列数:";
		cin >> col;
		if (col <= 0)
		{
			cout << "列号不符，请重新输入！！！" << endl;
		}
		else
		{
			break;
		}
	}

	//输入各行的值
	cout << "输入各行的值(障碍用#表示，通路用0表示)" << endl;

	for (int i = 0; i <= row + 1; i++)
	{
		if (i != 0 && i != row + 1)
		{
			cout << "第" << i << "行是：";
		}

		for (int j = 0; j <= col + 1; j++)
		{
			if (i == 0 || i == row + 1 || j == 0 || j == col + 1)
			{
				map[i][j] = '#';
			}

			else
			{

				cin >> map[i][j];
			}
		}
	}

	//输入开始位置和终止位置，外加错误判断信息
	while (1)
	{
		cout << "开始位置（第x行,第y列)";
		cin >> src_x;
		cin >> src_y;
		if (map[src_x][src_y] == '0')
		{
			break;
		}
		else
		{
			cout << "输入位置有误，请重新输入！！！" << endl;
		}

	}
	while (1)
	{
		cout << "结束位置（第x行,第y列)";
		cin >> des_x;
		cin >> des_y;
		if (map[des_x][des_y] == '0')
		{
			break;
		}
		else
		{
			cout << "输入位置有误，请重新输入！！！" << endl;
		}

	}
}
int main()
{
	input();
	if (migong(src_x, src_y))
	{
		output();
	}
	else
	{
		cout << "没有(" << src_x << "," << src_y << ")到(" << des_x << "," << des_y << ")的通路！！！" << endl;
	}

}