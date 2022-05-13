//遵循了开放封闭原则，维持了复用性

//税法策略基础类
class TaxStrategy{
public:
    //抽象方法
    virtual double Calculate(const Context& context)=0;
    virtual ~TaxStrategy(){}
};

class CNTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //*****
    }
};

class USTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***
    }
};

class DETax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //***
    }
};

//扩展
//*****************
class FRTax : public TaxStrategy{
    //....
};


 
class SalesOrder{
private:
    TaxStrategy* strategy;//保证多态性
public:
    SalesOrder(StrategyFactory* strategyFactory){
        this->strategy=strategyFactory->NewStrategy();
    }
    ~SalesOrder(){
        delete this->strategy;
    }
    double CalculateTax(){
        //...
        Context context();

        double val=strategy->Calculate(context);//多态调用
    }
};
