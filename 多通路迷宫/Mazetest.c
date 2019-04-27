#include"Maze.h"

void TestMaze()
{
	int Maze[ROW][COL] = {{ 0, 0, 0, 0, 0, 0 }, 
	                      { 0, 1, 1, 1, 0, 0 }, 
						  { 0, 1, 0, 1, 0, 0 },
						  { 0, 1, 0, 1, 0, 0 }, 
						  { 0, 1, 1, 1, 1, 1 },
						  { 0, 1, 0, 0, 0, 0 } };
	stack path;
	stack shortpath;

	//¶¨ÒåÃÔ¹¬Èë¿Ú
	position enter;
	position Enter;
	enter.x = 5;
	enter.y = 1;
	Enter = enter;
	//Õ»³õÊ¼»¯
	StackInit(&path);
	StackInit(&shortpath);
	//×ßÃÔ¹¬
	PassMaze(Maze, enter, Enter, &path, &shortpath);
	//´òÓ¡ÃÔ¹¬
	print(Maze);
	//´òÓ¡ÃÔ¹¬×î¶ÌÂ·¾¶
	Print(&shortpath);
}
int main()
{
	TestMaze();
	system("pause");
	return 0;
}
