#ifndef _MAZE_H_
#define _MAZE_H_
#include<iostream>
#include<fstream>
#include<cassert>
#include<string>

using namespace std;

// ������
class Seat
{
public:
	Seat(int _x, int _y)
		:x(_x)
		,y(_y)
	{};
public:
	int x;
	int y;
};

// �Թ���
class Maze
{
public:
	//���캯��  ��ȡ�ļ���ĵ�ͼ������
	Maze(const string& filePath);

private:
	//�ж��Ƿ�Ϊ·
	bool IsPass(Seat& entry);

public:
	//��ʼ��
	bool PassMaze(Seat& entry);

	//��ӡ��ͼ
	void PrintMap();

	//��������
	~Maze();
private:
	int** _map;//ָ���ͼ��ָ��
	int _row;
	int _col;
};

#endif