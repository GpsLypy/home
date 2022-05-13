#pragma once
#include <iostream>
#include "Identity.h"
#include <string>
#include "globalFile.h"
#include <fstream>
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"
using namespace std;

class Manager : public Identity{
public:
    //默认构造
    Manager();

    //有参构造
    Manager(string name,string pwd);
    //菜单界面
    virtual void operMenu();
   
    //添加账号
    void addPerson();

    //查看账号
    void showPerson();

    //查看机房信息
    void showComputer();
    //清空预约记录
    void cleanFile();


    //去重所需
    void initVector();

    //学生容器
    vector<Student> vStu;

    //教师容器
    vector<Teacher> vTea;

    //检查重复操作 参数一：检测学号|职工号 参数二：检测类型
    bool checkRepeat(int id,int type);

    //机房信息
    vector<ComputerRoom> vCom;
};