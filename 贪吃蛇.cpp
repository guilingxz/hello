#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAPW     (30)  //地图宽度 
#define MAPH     (30)  //地图高度 
#define SNAKELEN (3)   //贪吃蛇的初始长度 

//构建节点类型 
typedef struct{
    char *Char;
    char Type;
	int  Color;
}MapData;

//创建并初始化背景地图中要显示的字符信息  
MapData BorderNode = {"□", 1, 0x4};      //边框
MapData BackgroundNode = {"■", 2, 0x2};  //背景
MapData SnakeNode = {"■", 3, 0xb};       //贪吃蛇节点
MapData FoodNode = {"●", 4, 0xc};        //食物

//构建存储全局地图各节点的类别及索引的数据类型
typedef struct{
    char Type;
    int  Pos;
}GlobalMap;

GlobalMap GlobalMapInfo[MAPW][MAPH];

//贪吃蛇有效活动范围地图的索引
typedef struct{
    int X;
    int Y;
}SnakeMap;

SnakeMap SnakePos[(MAPW-2)*(MAPH-2)]; 
SnakeMap ScoresPos;

int Scores = 0;  					//得分
int SnakeMapLen = (MAPW-2)*(MAPH-2);//蛇的活动区域长度 
int SnakeHeadPos, SnakeTailPos;     //蛇头蛇尾对应的SnakeMap中的索引（下标）
HANDLE HandleStdin;  				//控制台句柄

char name[20];//人名 
int  speed=500;//蛇移速 

//设置光标位置，X为行，Y为列 
void SetPosition(int X, int Y){
    COORD Coord; 
    Coord.X = 2*Y;//Coord定义的坐标与我们相反 
    Coord.Y = X;
    SetConsoleCursorPosition(HandleStdin, Coord);
}

//设置颜色
void SetColor(int Color){
    SetConsoleTextAttribute(HandleStdin, Color);
}

//生成食物
void CreateFood(){
    int Pos, Rang, X, Y;
    //产生随机数，确定 SnakePos 数组的索引 
    srand((unsigned int)time(NULL));//引用当前时间作为随机数种子
	//随机生成食物位置 
    if( SnakeTailPos < SnakeHeadPos ){//当SnakePos数组中蛇的位置像{X X X 尾。。。。。头 X X}时 
        Rang = SnakeHeadPos-SnakeTailPos-1;//不属于蛇的节点数 
        Pos  = SnakeTailPos + 1 + rand()%Rang;//让生成的食物落在 [尾-头] 之间的非蛇节点位置 
    }else{							  //当SnakePos数组中蛇的位置像{。。。头 X X X X 尾。。}时 
        Rang = SnakeMapLen - (SnakeTailPos - SnakeHeadPos+1);//不属于蛇的节点数  
        Pos = rand()%Rang;//先随机生成一个食物位置
        if( Pos >= SnakeHeadPos ){//若该位置与蛇身节点重合，则以该位置为基础，向前再移动一个当前蛇身长度
			Pos += (SnakeTailPos-SnakeHeadPos+1);//由于 Pos(=Rang)+当前蛇身长度 始终小于SnakeMapLen，故不用担心数组越界
        }
    }
    //获取Pos位置对应的X、Y坐标 
    X = SnakePos[Pos].X;
    Y = SnakePos[Pos].Y;
    //设置光标位置和食物颜色 
    SetPosition(X,Y);
    SetColor(FoodNode.Color);
    printf("%s",FoodNode.Char);//打印食物 
    GlobalMapInfo[X][Y].Type=FoodNode.Type;//记录该节点类型到全局地图中 
}

//输出死亡信息 
void Die(){
    int x,y;
	HandleStdin = GetStdHandle(STD_OUTPUT_HANDLE);//控制台句柄 
    //设置窗口大小 
    system("cls"); //清空控制台 
	SetColor(0xb);
	for(x=8;x<21;x++){//打印边框 
		for(y=9;y<38;y++){
			if(x==8||x==20||y==9||y==37){
				SetPosition(x,y);
				printf("■");	
			}
			
		}
	} 
	SetPosition(10,14);
	printf("You Die !!! GAME OVER     o(*￣▽￣*)o");
	SetPosition(14,19);
	printf("Your Score is %d !",Scores*10);
	SetPosition(18,15);
	printf(" 还不错哦      继续努力O(∩_∩)O\n");
	getch();
	SetPosition(25,20);
	exit(0);
}

//蛇移动
void Move(char Direction){
    int NewSnakeHeadPos_X, NewSnakeHeadPos_Y;  //新蛇头坐标
    int OldIndex_In_NewSnakeHeadPos;           //新蛇头坐标对应的旧索引（全局地图中） 
    int OldPosX_In_NewSnakeHeadIndex, OldPosY_In_NewSnakeHeadIndex;//新蛇头索引对应的旧坐标（蛇地图） 
    int NewSnakeHead_OldType; 				   //新蛇头的旧类型（全局地图中）
    int OldSnakeTailPos_X, OldSnakeTailPos_Y;  //老蛇尾坐标
    //根据移动方向确定新蛇头的坐标
    switch(Direction){
        case 'w':
            NewSnakeHeadPos_X = SnakePos[SnakeHeadPos].X-1;
            NewSnakeHeadPos_Y = SnakePos[SnakeHeadPos].Y;
            break;
        case 's':
            NewSnakeHeadPos_X = SnakePos[SnakeHeadPos].X+1;
            NewSnakeHeadPos_Y = SnakePos[SnakeHeadPos].Y;
            break;
        case 'a':
            NewSnakeHeadPos_X = SnakePos[SnakeHeadPos].X;
            NewSnakeHeadPos_Y = SnakePos[SnakeHeadPos].Y-1;
            break;
        case 'd':
            NewSnakeHeadPos_X = SnakePos[SnakeHeadPos].X;
            NewSnakeHeadPos_Y = SnakePos[SnakeHeadPos].Y+1;
            break;
    }
    //新蛇头位置索引 
    SnakeHeadPos = SnakeHeadPos==0 ? SnakeMapLen-1 : SnakeHeadPos-1;
    //新蛇头坐标对应的旧索引
    OldIndex_In_NewSnakeHeadPos = GlobalMapInfo[NewSnakeHeadPos_X][NewSnakeHeadPos_Y].Pos;
    //新蛇头索引对应的旧坐标
    OldPosX_In_NewSnakeHeadIndex = SnakePos[SnakeHeadPos].X;
    OldPosY_In_NewSnakeHeadIndex = SnakePos[SnakeHeadPos].Y;

    //双向绑定新蛇头索引与坐标的对应关系
    SnakePos[SnakeHeadPos].X = NewSnakeHeadPos_X;
    SnakePos[SnakeHeadPos].Y = NewSnakeHeadPos_Y;
    GlobalMapInfo[NewSnakeHeadPos_X][NewSnakeHeadPos_Y].Pos = SnakeHeadPos;
    //双向绑定旧的索引与坐标的对应关系
    SnakePos[OldIndex_In_NewSnakeHeadPos].X = OldPosX_In_NewSnakeHeadIndex;
    SnakePos[OldIndex_In_NewSnakeHeadPos].Y = OldPosY_In_NewSnakeHeadIndex;
    GlobalMapInfo[OldPosX_In_NewSnakeHeadIndex][OldPosY_In_NewSnakeHeadIndex].Pos = OldIndex_In_NewSnakeHeadPos;

    //新蛇头的旧类型
    NewSnakeHead_OldType = GlobalMapInfo[NewSnakeHeadPos_X][NewSnakeHeadPos_Y].Type;
    //设置新蛇头类型
    GlobalMapInfo[NewSnakeHeadPos_X][NewSnakeHeadPos_Y].Type = SnakeNode.Type; 
    // 判断是否出界或撞到自己
    if(NewSnakeHead_OldType==BorderNode.Type || NewSnakeHead_OldType==SnakeNode.Type ){
        Die();
    }
    //输出新蛇头
    SetPosition(NewSnakeHeadPos_X, NewSnakeHeadPos_Y);
    SetColor(SnakeNode.Color);
    printf("%s", SnakeNode.Char);
    //判断是否吃到食物
    if(NewSnakeHead_OldType==FoodNode.Type){  //吃到食物
        if(speed>=50){//加快蛇移动速度 
        	speed-=10;
        }
        CreateFood();//重新生成食物 
        //更改分数
        SetPosition(ScoresPos.X, ScoresPos.Y);
        printf("%d", ++Scores*10);
    }else{
        //老蛇尾坐标
        OldSnakeTailPos_X = SnakePos[SnakeTailPos].X;
        OldSnakeTailPos_Y = SnakePos[SnakeTailPos].Y;
        //删除蛇尾
        SetPosition(OldSnakeTailPos_X, OldSnakeTailPos_Y);
        SetColor(BackgroundNode.Color);
        printf("%s", BackgroundNode.Char);
        GlobalMapInfo[OldSnakeTailPos_X][OldSnakeTailPos_Y].Type = BackgroundNode.Type;
        SnakeTailPos = (SnakeTailPos==0) ? SnakeMapLen-1 : SnakeTailPos-1;
    }
}

//下次移动的方向
char NextDirection(char NewDirection, char OldDirection){
    int NoBack = NewDirection+OldDirection;//蛇后退标志 
    NewDirection = tolower(NewDirection);
    if( (NewDirection=='w' || NewDirection=='a' || NewDirection=='s' || NewDirection=='d') && NoBack!='a'+'d' && NoBack!='w'+'s' ){
        return NewDirection;
    }else{
        return OldDirection;
    }
}

//暂停
char pause(){
    return getch();
}

void welcome(char *name) 
{	
	int x,y;
	HandleStdin = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置窗口大小 
    system("mode con: cols=96 lines=31");
	SetColor(0xb);
	for(x=8;x<21;x++){//打印边框 
		for(y=9;y<38;y++){
			if(x==8||x==20||y==9||y==37){
				SetPosition(x,y);
				printf("■");	
			}
			
		}
	} 
	SetPosition(10,15);
	printf("WELCOME TO THE GAME OF RETRO SNAKE\n");
	SetPosition(14,10);
	printf(" 请在英文输入法中操作 WSAD控制蛇身移动 空格键暂停游戏\n");
	SetPosition(18,17);
	printf("PLEASE ENTER YOUR NAME:");
	scanf("%s", name);
	system("cls"); 
}

// 初始化
void SnakeGameInit(char *name){
    // 设置相关变量 
    int X, Y, i, Pos;
    int Center_X = MAPH%2 ? MAPH/2+1 : MAPH/2;
    int Center_Y = MAPW%2 ? MAPW/2+1 : MAPW/2;
    CONSOLE_CURSOR_INFO cci;//控制台光标信息

    //判断相关设置是否合理
    if(MAPW<16){
        printf("'MAXWIDTH' is too small!");
        getch();
        exit(0);
    }

    //隐藏光标
    GetConsoleCursorInfo(HandleStdin, &cci);
    cci.bVisible = 0;
    SetConsoleCursorInfo(HandleStdin, &cci);
     
    //打印背景 
    for(X=0; X<MAPH; X++){//行 
        for(Y=0; Y<MAPH; Y++){//列 
            if(Y==0 || Y==MAPW-1 || X==0 || X==MAPH-1){//墙 
                GlobalMapInfo[X][Y].Type = BorderNode.Type;
                SetColor(BorderNode.Color);
                printf("%s", BorderNode.Char);
            }else{//活动区域 
                Pos = (X-1)*(MAPW-2)+(Y-1);
                SnakePos[Pos].X= X;
                SnakePos[Pos].Y= Y;
                GlobalMapInfo[X][Y].Type = BackgroundNode.Type;
                GlobalMapInfo[X][Y].Pos = Pos;
                SetColor(BackgroundNode.Color);
                printf("%s", BackgroundNode.Char);
            }
        }
        printf("\n");
    }
    
    //初始化贪吃蛇
    GlobalMapInfo[Center_X][Center_Y-1].Type = GlobalMapInfo[Center_X][Center_Y].Type = GlobalMapInfo[Center_X][Center_Y+1].Type = SnakeNode.Type;

    SnakeHeadPos = (Center_X-1)*(MAPW-2)+(Center_Y-1) - 1;
    SnakeTailPos = SnakeHeadPos+SNAKELEN-1;
    SetPosition(Center_X, Center_Y-1);
    SetColor(SnakeNode.Color);
    for(Y = Center_Y-1; Y<=Center_Y+1; Y++){
        printf("%s", SnakeNode.Char);
    }
    //生成食物
    CreateFood();

    //设置程序信息
    SetColor(0xb);	
	SetPosition(Center_X-3, MAPW+1);
	printf("Hello %s,Welcome to Play",name);
    SetPosition(Center_X-1, MAPW+1);
    printf("Your Score is:  0   \\(*▽*)/");
    SetPosition(Center_X+1, MAPW+1);
	printf("This Game is Created by XiaoMi");
	SetPosition(Center_X+3, MAPW+1);
    printf("Press the Space to Pause the Game");
    ScoresPos.X = Center_X-1;
    ScoresPos.Y = MAPW+9;
}

int main(){
	welcome(name);//启动页面 
    char Input, Direction = 'a';
    SnakeGameInit(name);//初始化游戏地图 
 	Input = tolower(getch());//等待输入 
    Direction = NextDirection(Input, Direction);
    while(1){
        if(kbhit()){
            Input = tolower(getch());
            if(Input == ' '){//空格暂停 
                Input = pause();
            }
            Direction = NextDirection(Input, Direction);
        }
        Move(Direction);
       	Sleep(speed);
    }
    return 0;
}
