/* ************************************************************************
> File Name:     246.h
> Author:        想名字多费事
> 微信公众号:    xxxxxxx
> Created Time:  Sat 17 Jul 2021 05:35:08 PM CST
> Description:   
 ************************************************************************/
#ifndef __246__H
#define __246__H
#include <string>
using namespace std;

class Window_mgr{
public:
    void clear();
};

class Screen{
friend void Window_mgr::clear();
public:
    typedef string::size_type pos;
public:
    Screen()=default;
    Screen(unsigned ht,unsigned wd):height(ht),width(wd),contents(ht*wd,' '){}
    Screen(unsigned ht,unsigned wd,char c):height(ht),width(wd),contents(ht*wd,c){}

public:
    Screen& move(unsigned r,unsigned c){
        cursor=r*width+c;
        return *this;
    }
    Screen& set(char c){
        contents[cursor]=c;
        return *this;
    }
    Screen& set(unsigned r,unsigned c,char ch){
        contents[cursor+=r*width+c]=ch;
        return *this;
    }
    Screen& display(ostream& os){
        do_display(os);
        return *this;
    }
    const Screen& display(ostream& os) const{
        do_display(os);
        return *this;
    }
    pos size() const;
private:
    unsigned height=0,width=0;
    unsigned cursor=0;
    string contents;
    void do_display(ostream& os) const{
        os<<contents;
    }
};

Screen::pos
Screen::size()const{
    return height*width;
}
void Window_mgr::clear(){
    Screen myScreen(10,20,'X');
    cout<<"清理之前myScreen的内容是："<<endl;
    cout<<myScreen.contents<<endl;
    myScreen.contents="";
    cout<<"清理之后myscreen的内容是："<<endl;
    cout<<myScreen.contents<<endl;
}
#endif
