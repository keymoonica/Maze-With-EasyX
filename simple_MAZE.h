#ifndef SIMPLE_MAZE_H
#define SIMPLE_MAZE_H

#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// 迷宫常量定义
#define ROWS 21           // 迷宫行数
#define COLS 21           // 迷宫列数
#define CELL_SIZE 30      // 单元格大小
#define PURPLE RGB(128,0,128)  // 紫色定义（修正拼写错误）

// 迷宫状态常量
#define WALL 1            // 墙壁
#define PATH 0            // 通路
#define ENTRANCE 2        // 入口
#define EXIT 3            // 出口

// 函数声明
void createMaze(int maze[ROWS][COLS]);
void printMaze(int maze[ROWS][COLS]);
void drawMaze(int maze[ROWS][COLS]);

#endif // SIMPLE_MAZE_H