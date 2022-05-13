#include <iostream>
#include "student.h"
#include "Identity.h"
#include <fstream>
#include <string>
#include "teacher.h"
#include "globalFile.h"
#include "manager.h"
using namespace std;


//进入学生子菜单界面
void studentMenu(Identity* &student)
{
    while (true)
	{
		//调用学生子菜单
		student->operMenu();

		Student * stu = (Student *)student;

		int select = 0;
		cin >> select; //接受用户选择

		if (select == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3) //查看所有人预约
		{
			stu->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			//注销登录
			delete student;
			cout << "注销成功" << endl;
			return;
		}
	}
}


//进入教师子菜单界面
void teacherMenu(Identity * &teacher)
{
	while (true)
	{
		//调用子菜单界面
		teacher->operMenu();

		Teacher * tea = (Teacher*)teacher;

		int select = 0; //接受用户选择

		cin >> select;

		if (select == 1) //查看所有预约
		{
			tea->showAllOrder();
		}
		else if (select == 2) //审核预约
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			return;
		}
	}
}


//进入管理员子菜单界面
void managerMenu(Identity * &manager){
    while(true){
        //调用管理员子菜单
	    manager->operMenu();
        //将父类指针 转为子类指针，调用子类里其他接口
        Manager* man=(Manager*)manager;
        int select = 0;
        cin>>select;

        if(select==1){
            cout << "添加账号" << endl;
            man->addPerson();
        }
        else if(select==2){
            //cout << "查看账号" << endl;
			man->showPerson();
        }
        else if(select==3){
            //cout << "查看机房" << endl;
			man->showComputer();
        }
        else if(select==4){
            //cout << "清空预约" << endl;
			man->cleanFile();
        }
        else{
            delete manager;
            cout<<"注销成功"<<endl;
            return;
        }
    }
}

//登录功能   参数1  操作文件名   参数2  操作身份类型
void LoginIn(string fileName,int type){
    //父类指针 ，用于指向子类对象
    Identity* person=NULL;
    //读文件
    ifstream ifs;
    ifs.open(fileName,ios::in);

    //判断文件是否存在
    if(!ifs.is_open()){
        cout<<"文件不存在"<<endl;
        ifs.close();
        return;
    }

    int id=0;
    string name;
    string pwd;

    //判断身份
    if(type == 1){//学生身份
        cout<<"请输入你的学号："<<endl;
        cin>>id;
    }
    else if(type ==2 ){
        cout<<"请输入你的职工号："<<endl;
        cin>>id;
    }

    cout<<"请输入用户名:"<<endl;
    cin>>name;
    cout<<"请输入密码:"<<endl;
    cin>>pwd;

    if(type==1){
        //学生身份验证
        int fId;//从文件中读取的id号
        string fName;
        string fPwd;

        while(ifs>>fId && ifs >> fName && ifs>>fPwd){
            //cout<<fId<<" "<<fName<<" "<<fPwd<<endl;
            if(fId==id && fName==name && fPwd==pwd){
                cout<<"学生认证成功！"<<endl;
                //system("clear");
                person=new Student(id,name,pwd);
                //进入到学生身份的子菜单
                studentMenu(person);
                //while(1);
                return;
            }
        }
        //while(1);
    }
    else if(type==2){
        //教师身份的验证
        int fId;//从文件中读取的id号
        string fName;
        string fPwd;
        while(ifs>>fId && ifs >> fName && ifs>>fPwd){
            //cout<<fId<<" "<<fName<<" "<<fPwd<<endl;
            if(fId==id && fName==name && fPwd==pwd){
                cout<<"教师认证成功！"<<endl;
                //system("clear");
                person=new Teacher(id,name,pwd);
                //进入到教师身份的子菜单
				teacherMenu(person);
                return;
            }
        }
    }
    else if(type==3){
        //管理员身份验证
        string fName;
        string fPwd;
        while(ifs >> fName && ifs>>fPwd){
            if(fName==name && fPwd==pwd){
                cout<<"管理员认证成功！"<<endl;
                //system("clear");
                person=new Manager(name,pwd);
                //进入到管理员身份的子菜单
                managerMenu(person);
                return;
            }
        }
    }

    cout<<"验证登录失败！"<<endl;
    system("clear");
}
int main()
{
	int select = 0; //用于接受用户的选择

	while (true)
	{
		cout << "======================  欢迎来到传智播客机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择
        switch (select)
        {
        case 1://学生身份
            /* code */
            LoginIn(STUDENT_FILE,1);
            break;
        case 2://老师身份
            LoginIn(TEACHER_FILE,2);
            break;
        case 3://管理员身份
            LoginIn(ADMIN_FILE,3);
            break;
        case 0://退出系统
            cout<<"欢迎下一次使用"<<endl;
            return 0;
            break;
        default:
            cout<<"输入有误,请重新选择！"<<endl;
            //sleep(1);
            system("clear");
            break;
        }
    }
}