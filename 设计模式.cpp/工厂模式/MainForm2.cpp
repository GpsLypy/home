class MainForm : public Form{
    TexBox* txtFilePath;
    TexBox* txtFileNumber;
    ProgressBar* progressBar;
    SplitterFactory* factory;
public:
    MainForm(SplitterFactory* factory){
        this->factory=factory;
    }
    void Button1_Click(){
        //ISplitter* splitter=new BinarySpkitter();//依赖具体类
        //SplitterFactory* factory;
        ISplitter* splitter=factory->CreateSplitter();//多态new
        splitter->split();
    }
};