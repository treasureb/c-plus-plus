#include"maze.h"

bool Maze::IsPass(Seat& Entry)
{
	if (_map[Entry.x][Entry.y] == 0)
	{
		return true;
	}
	return false;
}

//构造函数
Maze::Maze(const string& filePath)
{
	ifstream read(filePath);
	string str_row_col, str_temp;
	//读取第一行
	getline(read, str_row_col);
	//获取行
	str_temp = str_row_col.substr(0, str_row_col.find_first_of(',') + 1);
	_col = atoi(str_temp.c_str());

	//为地图分配空间
	_map = new int*[_row];
	for (int index = 0; index < _col; ++index)
	{
		_map[index] = new int[_col];
	}

	int index_col = 0;
	int index_row = 0;

	//填充地图
	while (!read.eof())
	{
		//获取第一行
		getline(read, str_temp);
		char* line = (char*)str_temp.c_str();
		while ((*line) != '\0')
		{
			if (*line == '0' || *line == '1')
			{
				_map[index_row][index_col] = *line - '0';
			}
			++line;
		}
		++index_row;
		index_col = 0;
	}

	//关闭文件
	read.close();
}

//开始走
bool Maze::PassMaze(Seat& Entry)
{
	//判断是否走到出口
	if (Entry.x < 0 || Entry.y < 0 || Entry.y >= _row)
	{
		return true;
	}
	
	if (IsPass(Entry))
	{
		//将走过的路置为2
		_map[Entry.x][Entry.y] = 2;

		//向左走
		Seat left(Entry.x, Entry.y - 1);
		if (PassMaze(left))//递归调用
		{
			return true;
		}

		//向上走
		Seat up(Entry.x - 1, Entry.y);
		if (PassMaze(up))//递归调用
		{
			return true;
		}
		
		//向右走
		Seat right(Entry.x, Entry.y + 1);
		if (PassMaze(right))//递归调用
		{
			return true;
		}

		//向下走
		Seat down(Entry.x + 1, Entry.y);
		if (PassMaze(down))//递归调用
		{
			return true;
		}

		//走到此处说明是死路，置为3
		_map[Entry.x][Entry.y] = 3;
	}

	return false;
}

void Maze::PrintMap()
{
	for (int row = 0; row < _row; ++row)
	{
		for (int col = 0; col < _col; ++col)
		{
			cout << _map[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//释放空间
Maze::~Maze()
{
	for (int idx = 0; idx < _row; ++idx)
	{
		delete _map[idx];
	}
	delete[] _map;
	_map = NULL;
}

int main()
{
	return 0;
}