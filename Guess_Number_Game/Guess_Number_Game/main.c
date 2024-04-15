#define _CRT_SECURE_NO_DEPRECATE    
/*代码思路
	随机产生一个随机数，范围:1-100
	猜数字:若是猜的数比答案要小，则提示猜小了;反之则提示猜大了;若是猜对了，则提示恭喜玩家猜对喽，积分加一，
*/
// 头文件
#include <stdio.h>
#include <stdlib.h>			//rand函数头文件、
#include <time.h>			//时间函数头文件


void Menu() {				//菜单函数,不用返回类型
	printf("------------------------------\n");
	printf("-----------欢迎使用-----------\n");
	printf("---------[1] 进行游戏---------\n");
	printf("---------[2] 游戏介绍---------\n");
	printf("---------[3] 积分查询---------\n");
	printf("---------[0] 退出游戏---------\n");
	printf("-----------如有问题-----------\n");
	printf("-----------请多包含-----------\n");
	printf("-----------联系作者-----------\n");
	printf("-----------@: liang-----------\n");
	printf("------------------------------\n");
}
int Game()					//游戏函数,这里用int是因为这里定义了一个积分变量，要将积分进行返回
{
	int ret = rand()%100 +1;						//生成随机数,随机数范围为1-100
	int Score = 0;									//积分变量
	int guess_number = 0;							//存储你输入的数字
	while (1) {										//死循环，保证可以一直进行游戏
		printf("请输入你猜的数字:>");
		scanf("%d", &guess_number);					//输入数值
		if (guess_number < ret) {					//情况一，小于
			printf("你猜的数字比答案小，请再次输入\n");
		}
		else if (guess_number > ret) {				//情况二,大于
			printf("你猜的数字比答案大，请再次输入\n");
		}
		else {										//情况三，等于
			printf("恭喜你，猜对了！\n");
			Score++;
			break;									//猜对后要用break跳出循环
		}
	}
	return Score;									//返回积分
}
int main()
{
	//时间戳生成一次就行
	srand((unsigned int)time(NULL));		//用到时间戳，强制类型转换为unsigned int,time函数给空指针
	int input_option = 0;					//选择
	int Result = 0;							//积分
	do {									//这里用do，while的原因是首先要打印一遍菜单
		Menu();
		scanf("%d", &input_option);
		switch (input_option) {
		case 1:
			Result = Game();
			
			break;
		case 2:
			printf("以下为游戏的介绍\n");
			break;
		case 3:
			printf("你的积分为:%d\n", Result);
			break;
		case 0:
			printf("退出游戏成功\n");
			break;
		default:
			printf("你的输入有错误，请重新输入\n");
			break;
		}
	} while (input_option);
	return 0;
}