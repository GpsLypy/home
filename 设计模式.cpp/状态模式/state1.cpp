//可能的问题是这个枚举类型可能会有其他的类型状态出现，违背开闭原则
enum NetworkState{
    Network_OPen,
    Network_Close,
    Network_Connect,
};





class NetworkProcessor{

    NetworkState state;

public:
    void Operation1(){
        if(state == Network_OPen){
            //****
            state=Network_Close;
        }
        else if(state == Network_Close){
            //....
            state=Network_Connect;
        }
        else if(state == Network_Connect){
            //@@@@@
            state=Network_OPen;
        }
    }
};













