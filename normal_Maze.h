#ifndef normal_Maze_H
#define normal_Maze_H

#include<iostream>
#include<cstdio>
#include<graphics.h>
#include<string>
#include<queue>
#include<stack>
#include<easyx.h>
#include<stack>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"WinMM.Lib")//音乐静态库
using namespace std;

#define rode 20 //每个小格子的大小
#define wall 2 //墙的宽度
#define MAXV 200 //最大顶点数
enum direction { up, down, left, right }; //方向枚举
struct vnode 
{
	int x, y; //当前矩阵位置
	int val; //标记值，0表示未访问，1表示已访问
	int repeat; //重复次数，0表示未重复，1表示已重复
	direction dir; //方向
	int go;//0表示未走，1表示已走
};//地图节点结构体
struct mazegraph 
{
	int maze[50][50][4]; //存储墙壁信息，4个方向的墙壁
	vnode graph[50][50]; //存储路径信息
	int row, col; //行数和列数
};//迷宫图结构体

struct gather
{
	vnode gather[MAXV];//存储的主要元素
	int length; //当前长度
};//集合结构体

struct D
{
	int x, y; //当前坐标
};

struct region
{
	int x, y;
	int w, h;//区域宽度和高度
	const char* arr;//区域作用名
}muice = { 1050,60,100,60,"BGM" },//音乐模块
NewGame={1050,200,100,60,"新游戏"},//新游戏
game_win={450,450,400,400},//游戏胜利
go={1050,435,300,130},//当前剩余步数显示
operate={1050,435,300,200},//操作说明
data_graph = { 1050,800,300,200 },//当前坐标 
game_begin = { 1050,60,100,60,"开始测试" },//开始游戏按钮
creat_simple= { 1050,200,100,60,"生成固定地图" },//生成普通迷宫按钮
creat_normal= { 1050,400,100,60,"随机生成地图" },//生成迷宫按钮
BFS = { 1050,340,100,60,"BFS寻路" },//BFS按钮 //退出游戏
DFS = { 1050,200,100,60,"DFS寻路" };//DFS按钮 //退出游戏

IMAGE backgroud_1;//定义迷宫背景
IMAGE backgroud_2;//定义控制台背景
IMAGE Now;//定义现在所在位置图像
IMAGE RODE;//定义迷宫格
IMAGE WALL;//定义墙
IMAGE START;//定义初始位置
IMAGE END;//定义结束位置
IMAGE GO;//定义提示格

clock_t start, END, time_1;
int CLOCK;
int X, Y;//初始实际位置
int scene;
int s = 0;
int h = 0;
char str[100], coordinate[15];
char arr[20];

D data[900];//遍历路径的存储
char MUICE;
queue<vnode>q;
stack<vnode>Q;
bool bfs_ok = false;//是否开始bfs寻路
bool dfs_ok = false;//是否开始dfs寻路
bool go_ok = false;//判断是否吃完豆子
void button(region reg, const char* arr) {
	setfillcolor(BLACK);//填充颜色
	setlinecolor(YELLOW);
	settextcolor(WHITE);
	settextstyle(0, 0, _T("宋体"));
	fillroundrect(reg.x - reg.w / 2, reg.y - reg.h / 2, reg.x + reg.w / 2, reg.y + reg.h / 2, 10, 10);//创建一个圆角矩阵，前面四个为左上角和右下角坐标，而后面两个为椭圆的宽度和高度
	int x1 = textwidth(arr) / 2, y1 = textheight(arr) / 2;
	if (arr != NULL) {
		outtextxy(reg.x - x1, reg.y - y1, arr);
	}
}//创建按钮图标


#endif // !normal_Maze_H
