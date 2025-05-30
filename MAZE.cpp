#include "simple_MAZE.h"

// 创建自定义迷宫
void createMaze(int maze[ROWS][COLS]) {
    int customMaze[ROWS][COLS] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1},
        {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1},
        {1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1},
        {1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1},
        {0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1},
        {1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1},
        {1,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1},
        {1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1},
        {1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
        {1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1},
        {1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1},
        {1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1},
        {1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1},
        {1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1},
        {1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1},
        {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    // 复制迷宫数组
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = customMaze[i][j];
        }
    }

    // 设置入口（修正为数组中的实际位置）
    maze[7][0] = ENTRANCE;  // 对应原始迷宫的入口位置
    // 设置出口
    maze[ROWS - 2][COLS - 1] = EXIT;
}

// 输出迷宫数组
void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// 绘制迷宫
void drawMaze(int maze[ROWS][COLS]) {
    initgraph(COLS * CELL_SIZE, ROWS * CELL_SIZE);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            switch (maze[i][j]) {
            case WALL:
                setfillcolor(BLACK);   // 墙壁为黑色
                break;
            case PATH:
                setfillcolor(WHITE);   // 通路为白色
                break;
            case ENTRANCE:
                setfillcolor(RED);     // 入口为红色
                break;
            case EXIT:
                setfillcolor(PURPLE);  // 出口为紫色
                break;
            default:
                setfillcolor(GREEN);   // 其他状态为绿色（调试用）
            }
            fillrectangle(j * CELL_SIZE, i * CELL_SIZE,
                (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE);
        }
    }

    // 显示操作提示
    settextcolor(YELLOW);
    settextstyle(16, 0, _T("宋体"));
    outtextxy(10, ROWS * CELL_SIZE - 20, _T("按任意键退出..."));

    closegraph();    // 关闭绘图窗口
}
