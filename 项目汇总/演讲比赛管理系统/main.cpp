#include <iostream>
#include "SpeechManager.h"
#include <ctime>
using namespace std;

int main(){
	srand((unsigned int)time(NULL));
	//创建管理类的对象
	SpeechManager sm;
    /*
    for(auto itor=sm.m_Speaker.begin();itor!=sm.m_Speaker.end();itor++){
        cout<<"选手编号："<<itor->first<<"姓名："<<itor->second.m_Name<<"分数："<<itor->second.m_Score[0]<<endl;
    }
    */
    int choice=0;//接收用户的输入

    while(1){
        sm.show_Menu(); 
        cout<<"请输入你的选择："<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1://开始比赛
            sm.startSpeech();
            break;
        case 2://查看往届比赛记录
            sm.showRecord();
            break;
        case 3://清空比赛记录
            sm.clearRecord();
            break;
        case 0://退出系统
            sm.exitSystem();
            break;
        default:
            system("clear");
            break;
        }
    }

	
	//system("pause");
	return 0;
}