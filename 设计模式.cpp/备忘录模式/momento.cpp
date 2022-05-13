class Memento{
    string state;
    //...
public:
    Memento(const string& s):state(s){}
    string getState() const {return state;}
    void setState(const string& s){state=s;}
};

class Originator{
    string state;
    //...
public:
    Originator(){}

    Momento createMomento(){
        Momento m(state);
        return m;
    }

    void setMomento(const Memento& m){
        state=m.getState();
    }

};

int main(){
    Originator originator;

    //捕获对象状态，存储到备忘录
    Memento mem=originator.createMomento();

    //...改变originator

    //从备忘录中恢复

    originator.setMomento(memento);
}