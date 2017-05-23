#include"maze.h"

bool Maze::IsPass(Seat& Entry)
{
	if (_map[Entry.x][Entry.y] == 0)
	{
		return true;
	}
	return false;
}

//���캯��
Maze::Maze(const string& filePath)
{
	ifstream read(filePath);
	string str_row_col, str_temp;
	//��ȡ��һ��
	getline(read, str_row_col);
	//��ȡ��
	str_temp = str_row_col.substr(0, str_row_col.find_first_of(',') + 1);
	_col = atoi(str_temp.c_str());

	//Ϊ��ͼ����ռ�
	_map = new int*[_row];
	for (int index = 0; index < _col; ++index)
	{
		_map[index] = new int[_col];
	}

	int index_col = 0;
	int index_row = 0;

	//����ͼ
	while (!read.eof())
	{
		//��ȡ��һ��
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

	//�ر��ļ�
	read.close();
}

//��ʼ��
bool Maze::PassMaze(Seat& Entry)
{
	//�ж��Ƿ��ߵ�����
	if (Entry.x < 0 || Entry.y < 0 || Entry.y >= _row)
	{
		return true;
	}
	
	if (IsPass(Entry))
	{
		//���߹���·��Ϊ2
		_map[Entry.x][Entry.y] = 2;

		//������
		Seat left(Entry.x, Entry.y - 1);
		if (PassMaze(left))//�ݹ����
		{
			return true;
		}

		//������
		Seat up(Entry.x - 1, Entry.y);
		if (PassMaze(up))//�ݹ����
		{
			return true;
		}
		
		//������
		Seat right(Entry.x, Entry.y + 1);
		if (PassMaze(right))//�ݹ����
		{
			return true;
		}

		//������
		Seat down(Entry.x + 1, Entry.y);
		if (PassMaze(down))//�ݹ����
		{
			return true;
		}

		//�ߵ��˴�˵������·����Ϊ3
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

//�ͷſռ�
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