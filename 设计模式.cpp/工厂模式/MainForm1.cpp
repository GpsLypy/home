class MainForm : public Form{
    TexBox* txtFilePath;
    TexBox* txtFileNumber;
    ProgressBar* progressBar;
public:
    void Button1_Click(){
        SplitterFactory factory;
        ISplitter* splitter=factory.CreateSplitter();
        //ISplitter* splitter=new BinarySpkitter();//依赖具体类
        splitter->split();
    }
};











