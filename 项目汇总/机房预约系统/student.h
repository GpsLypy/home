#pragma once
#include <iostream>
#include "Identity.h"
#include <string>
#include <vector>
#include "computerRoom.h"
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"
using namespace std;

class Student : public Identity{
public:
    int m_Id;
    //默认构造
    Student();
    //有参构造
    Student(int id,string name,string pwd);
    //菜单界面
    virtual void operMenu();
   
    //申请预约
    void applyOrder();
    //查看自身预约
    void showMyOrder();
    //查看所有预约
    void showAllOrder();
    //取消预约
    void cancelOrder();
    //机房容器
	vector<ComputerRoom> vCom;
};