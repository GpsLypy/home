class Visitor;

class Element{
public:
    virtual void accept(Visitor& visitor) = 0;//第一次动态辨析
    virtual ~Element(){}
};

class ElementA : public Element{
public:
    void accept(Visitor& visitor) override{
        visitor.visitElementA(*this);
    }
};


class ElementB : public Element{
public:
    void accept(Visitor& visitor) override{
        visitor.visitElementB(*this);//第二次动态辨析
    }
};


class   Visitor{
public:
    virtual void visitorElementA(ElementA& element)=0;
    virtual void visitorElementB(ElementB& element)=0;
    virtual ~Visitor(){}
};


//================================

//扩展1
class Visitor1 : public Visitor{
public:
    void visitElementA(ElementA& element) override{
        cout<<"Visitor1 is processing ElementA"<<endl;
    }

    void visitElementB(ElementB element) override{
        cout<<"Visitor1 is processing ElementB"<<endl;
    }
};


//扩展2
class Visitor2 : public Visitor{
public:
    void visitElementA(ElementA& element) override{
        cout<<"Visitor2 is processing ElementA"<<endl;
    }

    void visitElementB(ElementB element) override{
        cout<<"Visitor2 is processing ElementB"<<endl;
    }
};


int main(){
    Visitor2 visitor;
    ElementB elementB;
    elementB.accept(visitor);//double dispatch

    ElementA elementA;
    elementB.accept(visitor);

    return 0;
}





