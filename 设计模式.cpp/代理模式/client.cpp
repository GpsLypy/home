class ISubject{
public:
    virtual void process();
};

//proxy的设计
class SubjectProxy : public ISubject{
    //RealSubject  realSubject;
public:
    virtual void process(){
        //...
        //对RealSubject的一种简接访问
    }
};


class ClientApp{
    ISubject* subject;
public:
    ClientApp(){
        subject=new SubjectProxy();
    }
    void DoTask(){
        //...
        subject->process();
        //...
    }
};