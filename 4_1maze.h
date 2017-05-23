#ifndef _MAZE_H_
#define _MAZE_H_
#include<iostream>
#include<fstream>
#include<cassert>
#include<string>

using namespace std;

// 坐标类
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

// 迷宫类
class Maze
{
public:
	//构造函数  读取文件里的地图和行数
	Maze(const string& filePath);

private:
	//判断是否为路
	bool IsPass(Seat& entry);

public:
	//开始走
	bool PassMaze(Seat& entry);

	//打印地图
	void PrintMap();

	//析构函数
	~Maze();
private:
	int** _map;//指向地图的指针
	int _row;
	int _col;
};

#endif