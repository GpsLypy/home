#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
using namespace std;

//设计演讲管理类
//头文件中只做声明，不做实现 
class SpeechManager{
public:
	SpeechManager();
	
	//菜单
	void show_Menu(); 
    void exitSystem();

    ~SpeechManager();

    //初始化容器和属性
    void initSpeech();

    //创建12名选手
    void createSpeaker();

    //开始比赛
    void startSpeech();

    //抽签
    void speechDraw();

    //比赛
    void speechContest();

    //显示得分
    void showScore();

    //保存记录
    void saveRecord();

    //读取记录
    void loadRecord();

    void showRecord();

    void clearRecord();

    //判断文件是否为空
    bool fileIsEmpty;

    //判断往届记录的容器
    map<int,vector<string>> m_Record;



    //成员属性
    //保存第一轮比赛选手编号容器 12
    vector<int> v1;
    //保存第一轮晋级选手编号容器 6
    vector<int> v2;
    //保存胜出前三名选手编号 3
    vector<int> vVictory;

    //保存编号及对应具体选手容器
    map<int,Speaker> m_Speaker;

    //存放比赛轮数
    int m_Index;
}; 