class NetworkState{
public:
    NetworkState* pNext;
    virtual void Operation1()=0;
    virtual void OPeration2()=0;
    virtual void OPeration3()=0;

    virtual ~NetworkState(){}
};



class OpenState : public NetworkState{
    static NetworkState* m_instance;
public:
    static NetworkState* getInstance(){
        if(m_instance==nullptr){
            m_instance=new OpenState();
        }
        return m_instance;
    }

    void Operation1(){
        //****
        pNext=CloseState::getInstance();
    }

    void Operation2(){
        //....
        pNext=ConnectState::getInstance();
    }

    //.....
};

class CloseState : public NetworkState{

};

//....


class NetworkProcessor{
    NetworkState* pState;

public:
    NetworkProcessor(NetworkState* pState){
        this->pState=pState;
    }

    void Operation1(){
        //...
        pState->Operation1();
        pState=pState->pNext;
        //...
    }

    void Operation2(){
        //...
        pState->OPeration2();
        pState=pState->pNext;
        //...
    }
};