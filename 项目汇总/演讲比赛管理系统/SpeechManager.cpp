#include "SpeechManager.h" 
#include <string>
#include <algorithm>
#include <deque>
#include <functional>//包含了内建的函数对象
#include <numeric>
#include <fstream>

//具体实现 
SpeechManager::SpeechManager(){
    //初始化容器和属性
	this->initSpeech();
    //创建12名选手
    this->createSpeaker();//创建12名选手
    //加载往届记录
    this->loadRecord();
}

void SpeechManager::show_Menu(){
	cout << "********************************************" << endl;
	cout << "************* 欢迎参加演讲比赛 ************" << endl;
	cout << "************* 1.开始演讲比赛 *************" << endl;
	cout << "************* 2.查看往届记录 *************" << endl;
	cout << "************* 3.清空比赛记录 *************" << endl;
	cout << "************* 0.退出比赛程序 *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem(){
    cout<<"欢迎下次使用"<<endl;
    //system("pause");
    exit(0);
}
void SpeechManager:: initSpeech(){
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();
    this->m_Record.clear();
    this->m_Index=1;
}

void  SpeechManager::createSpeaker(){
    string nameSeed="ABCDEFGHIJKL";
    for(int ii=0;ii<nameSeed.size();ii++){
        string name="选手";
        name+=nameSeed[ii];
        //创建具体选手
        Speaker sp;
        sp.m_Name=name;
        for(int jj=0;jj<2;jj++){
            sp.m_Score[jj]=0;
        }

        //创建选手编号，并放入到v1容器中
        this->v1.push_back(ii+1001);
        //选手编号及对应选手，放入map
        this->m_Speaker.insert(pair<int,Speaker>(ii+1001,sp));
    }
}

 //开始比赛
void SpeechManager::startSpeech(){
    //第一轮比赛开始
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示晋级结果
    this->showScore();
    //第二轮比赛开始
    this->m_Index++;
    //1、抽签
    this->speechDraw();
    //2、比赛
    this->speechContest();
    //3、显示最终结果
    showScore();
    //4、保存分数到文件
    this->saveRecord();
    //重置比赛
    //初始化属性
	this->initSpeech();
    //创建12名选手
    this->createSpeaker();//创建12名选手
    //加载往届记录
    this->loadRecord();
    cout<<"本届比赛完毕"<<endl;
    //system("clear");
}

void SpeechManager::speechDraw(){
    cout<<"第<<"<<this->m_Index<<">>轮比赛选手正在抽签"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"抽签后的演讲顺序如下："<<endl;
    if(m_Index==1){
        random_shuffle(v1.begin(),v1.end());//洗牌算法
        for(auto it=v1.begin();it!=v1.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }else{
        random_shuffle(v2.begin(),v2.end());
        for(auto it=v2.begin();it!=v2.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }

    cout<<"--------------------"<<endl;
    cout<<"按任意键进入下一个环节"<<endl;
}

void SpeechManager::speechContest(){
    cout<<"------第"<<this->m_Index<<"轮比赛正式开始------"<<endl;
    //比赛规定v1容器里面的所有参赛人员每6人一小组，所以可以准备一个临时容器，存放小组成绩
    multimap<double,int,greater<double>> groupScore;
    int num=0;//记录人员个数，6人一组


    vector<int> v_Src;//比赛选手容器
    if(this->m_Index==1){
        v_Src=v1;

    }
    else{
        v_Src=v2;
    }

    //遍历所有选手进行比赛
    for(auto it=v_Src.begin();it!=v_Src.end();it++){
        ++num;
        //评委打分
        deque<double> d;
        for(int ii=0;ii<10;ii++){
            double score=(rand()%401+600)/10.f;//600~1000
            //cout<<score<<" ";
            d.push_back(score);
        }
        //cout<<endl;
        sort(d.begin(),d.end(),greater<double>());//排序
        d.pop_front();//去最高分
        d.pop_back();//去最低分
        double sum=accumulate(d.begin(),d.end(),0.0f);
        double avg=sum/(double)d.size();//平均分

        //打印平均分
        //cout<<"编号："<<*it<<"姓名："<<this->m_Speaker[*it].m_Name<<"平均分："<<avg<<endl;
        //将平均分放到map容器里
        this->m_Speaker[*it].m_Score[this->m_Index-1]=avg;
        //将打分数据放入临时小组容器里
        groupScore.insert(make_pair(avg,*it));//key:得分 value：选手编号
        //每6人取出前三名，这里实际上是打完分放一起后在把小组抽取出来
        //或者这样理解，当抽签顺序决定后，默认前6人一组，后6人一组
        if(num%6==0){
            cout<<"第"<<num/6<<"小组比赛名次："<<endl;
            for(auto it=groupScore.begin();it!=groupScore.end();it++){
                cout<<"编号："<<it->second<<"姓名："<<this->m_Speaker[it->second].m_Name<<"分数："<<this->m_Speaker[it->second].m_Score[m_Index-1]<<endl;
            }
            //取走前三名
            int count=0;
            for(auto it=groupScore.begin();it!=groupScore.end()&&count<3;it++,count++){
                if(this->m_Index==1){
                    v2.push_back((*it).second);
                }else{
                    vVictory.push_back((*it).second);
                }
            }
            groupScore.clear();
            cout<<endl;
        }
    }
    cout<<"-----------第"<<this->m_Index<<"轮比赛结束"<<endl;
}


void SpeechManager::showScore(){
    cout<<"-------第"<<this->m_Index<<"轮晋级选手信息如下：-----------"<<endl;
    vector<int> v;
    if(this->m_Index==1){
        v=v2;
    }else{
        v=vVictory;
    }

    for(auto it=v.begin();it!=v.end();it++){
        cout<<"选手编号："<<*it<<"姓名："<<this->m_Speaker[*it].m_Name<<"得分："<<this->m_Speaker[*it].m_Score[this->m_Index-1]<<endl;;
    }
    cout<<endl;
    //system("clear");
    show_Menu();
}

void SpeechManager::saveRecord(){
    ofstream ofs;
    ofs.open("speech.csv",ios::out | ios::app);//用追加的方式写文件
    //将每个选手的数据写入到文件中
    for(auto it=vVictory.begin();it!=vVictory.end();it++){
        ofs<<*it<<","<<this->m_Speaker[*it].m_Score[1]<<",";
    }
    ofs<<endl;
    //关闭
    ofs.close();
    cout<<"记录已保存"<<endl;
    fileIsEmpty=false;
}

void SpeechManager::loadRecord(){
    ifstream ifs("speech.csv",ios::in);//读文件
    //文件不存在的情况
    if(!ifs.is_open()){
        this->fileIsEmpty=true;
        cout<<"文件不存在"<<endl;
        ifs.close();
        return;
    }

    //文件被清空过的情况
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        //cout<<"文件为空"<<endl;
        this->fileIsEmpty=true;
        ifs.close();
        return;
    }

    //文件不为空
    this->fileIsEmpty=false;
    ifs.putback(ch);//将上面读取的单个字符放回来
    int index=1;//第几界
    string data;

    while(ifs>>data){
        //cout<<data<<endl;
        //10002,86.675,10009,81.3,10007,78.55,
        vector<string> v;//存放6个string字符串

        int pos = -1;//查到","位置的变量
        int start=0;
        while(true){
            pos=data.find(",",start);//5
            if(pos==-1){
                //没有找到的情况
                break;
            }
            string temp=data.substr(start,pos-start);
            //cout<<temp<<endl;
            v.push_back(temp);
            start=pos+1;
        }
        
        this->m_Record.insert(make_pair(index,v));
        index++;
    }
    /*
        for(auto it=m_Record.begin();it!=m_Record.end();it++){
            cout<<it->first<<" 冠军编号："<<it->second[0]<<" 分数："<<it->second[1]<<endl;
        }
    */
    ifs.close();
}


void SpeechManager::showRecord(){
    //cout<<m_Record.size()<<endl;
    if(this->fileIsEmpty){
        cout<<"文件不存在，或记录为空！"<<endl;
    }else{
        for(int ii=0;ii<m_Record.size();ii++){
            cout<<"第"<<ii+1<<"届"<<" 冠军编号："<<m_Record[ii+1][0]<<" 分数："<<m_Record[ii+1][1]<<" "
                                <<" 亚军编号："<<m_Record[ii+1][2]<<" 分数："<<m_Record[ii+1][3]<<" "
                                <<" 季军编号："<<m_Record[ii+1][4]<<" 分数："<<m_Record[ii+1][5]<<endl;
        }
    }
}

void SpeechManager::clearRecord(){
    cout << "确认删除吗？" << endl;
	cout << "1-是" << endl;
	cout << "2-否" << endl;
    int select=0;
    cin>>select;
    if(select==1){
        //确认
        ofstream ofs("speech.csv",ios::trunc);
        ofs.close();
        //初始化容器和属性
	    this->initSpeech();
        //创建12名选手
        this->createSpeaker();//创建12名选手
        //加载往届记录
        this->loadRecord();
        cout<<"清空成功！"<<endl;
    }else{
        system("clear");
    }
}

SpeechManager::~SpeechManager(){
	
}


