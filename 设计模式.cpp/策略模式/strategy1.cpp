//这种设计违背了面向对象设计原则中的开闭原则(类模块尽可能用扩展的方式来应对未来的变化，而不是修改来应对)

enum TaxBase{//税率
    CN_Tax,
    US_Tax,
    DE_Tax,
    FR_Tax //更改
};

class SalesOrder{
    TaxBase tax;
public:
    double CalculateTax(){
        //...
        if(tax==CN_Tax){
            //CN****
        }
        else if(tax==US_Tax){
            //US***
        }
        else if(tax==DE_Tax){
            //DE***
        }
        else if(tax==FR_Tax){//更改
            //DE***
        }
        //....
    }
};