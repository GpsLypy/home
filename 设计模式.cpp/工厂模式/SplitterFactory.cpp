class ISplitter{
public:
    virtual void split()=0;
    virtual ~ISplitter(){}
};


/*
//对应MainForm1
class SplitterFactory{
public:
    ISplitter* CreateSplitter(){
        return new BinarySplitter();
    }
    virtual ~SplitterFactory(){}
};
*/


class SplitterFactory{
public:
    virtual ISplitter* CreateSplitter()=0;
    virtual ~SplitterFactory(){}
};


//具体类
class BinarySplitter : public ISplitter{

};

class TxtSplitter : public ISplitter{

};

class PictureSplitter : public ISplitter{
    
};

class BinarySplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new BinarySplitter();
    }
};


class TxtSplitterFactory: public SplitterFactory{
public:
    virtual ISplitter* CreateSplitter(){
        return new TxtSplitter();
    }
};
......
......



