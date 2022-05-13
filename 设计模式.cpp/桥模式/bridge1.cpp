class Messager{
protected:
    MessagerImp* messagerImp;//new PCMessagerBase();...
public:
    virtual void Login(string username,string password)=0;
    virtual void SendMessage(string message)=0;
    virtual void SendPicture(Image image)=0;
    virtual ~Messager(){}
};

class MessagerImp{
public:
    virtual void PlaySound()=0;
    virtual void DrawShape()=0;
    virtual void WriteText()=0;
    virtual void Connect()=0;

    virtual ~MessagerImp(){}
};


//平台实现
class PCMessagerImp : public MessagerImp{
public:
    virtual void PlaySound(){
        //*****
    }
    virtual void DrawShape(){
        //*****
    }
    virtual void WriteText(){
        //*****
    }
    virtual void Connect(){
        //*****
    }
};

class MobileMessagerImp : public MessagerImp{
public:
    virtual void PlaySound(){
        //================
    }
    virtual void DrawShape(){
        //================
    }
    virtual void WriteText(){
        //================
    }
    virtual void Connect(){
        //================
    }
};


//业务抽象->精简版
class MessagerLite : public messager{
    //MessagerImp* messagerImp;//new PCMessagerBase();...
public:
    virtual void Login(string username,string password){
        messagerImp->Connect();
        //.......
    }
    virtual void SendMessage(string messager){
        messagerImp->WriteText();
        //.......
    }
    virtual void SendPicture(Image image){
        messagerImp->DrawShape();
        //......
    }
};

class MessagerPerfect : public messager{
    //MessagerImp* messagerImp;//new PCMessagerBase();
public:
    virtual void Login(string username,string password){
        messagerImp->PlaySound();
        //******
        messagerImp->Connect();
        //.......
    }
    virtual void SendMessage(string messager){
        messagerImp->PlaySound();
        //******
        messagerImp->WriteText();
        //.......
    }
    virtual void SendPicture(Image image){
        messagerImp->PlaySound();
        messagerImp->DrawShape();
        //......
    }
};

/*

//下面还有手机版

//业务抽象->精简版
class MessagerLite{
    Messager* messager;//new MobileMessagerBase();
public:
    virtual void Login(string username,string password){
        messager->Connect();
        //.......
    }
    virtual void SendMessage(string messager){
        messager->WriteText();
        //.......
    }
    virtual void SendPicture(Image image){
        messager->DrawShape();
        //......
    }
};


*/

/*

class MobileMessagerPerfect{
    Messager* messager;//new MobileMessagerBase();
public:
    virtual void Login(string username,string password){
        messager->PlaySound();
        //******
        messager->Connect();
        //.......
    }
    virtual void SendMessage(string messager){
        messager->PlaySound();
        //******
        messager->WriteText();
        //.......
    }
    virtual void SendPicture(Image image){
        messager->PlaySound();
        messager->DrawShape();
        //......
    }
};
*/


void Process(){
    //运行时装配
    MessagerImp* mImp=new PCMessagerImp();
    Messager* m=new Messager(mImp);
}