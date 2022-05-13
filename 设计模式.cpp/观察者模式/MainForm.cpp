//违反了依赖倒置原则（高层模块不能依赖于低级模块，依赖于抽象，抽象不能依赖于实现细节）

//界面（文件分割器）
class MainForm : public MainForm，public IProgress{
    TextBox* txtFilePath;
    TextBox* txtFileNumber;

    ProgressBar* progressBar;//观察者1->进度条

public:
    void Button1_Click(){//按键点击
        string filePath=txtFilePath->getText();//收集用户输入的两个参数信息
        int number=atoi(txtFileNumber->getText().c_str());

        ConsoleNotifier cn;
        //FileSplitter splitter(filePath,number,this);//mainForm是IProgress的一个子类，所以传递this指针
        
        FileSplitter splitter(filePath,number);
        splitter.addIProgress(this);//订阅通知
        splitter.addIProgress(&cn);
        splitter.split();

        spitter.removeIProgress();//....
    }
    virtual void DoProgress(float value){
        progressBar->setValue(value);
    }
};


class ConsoleNotifier : public IProgress{
public:
    virtual void DoProgress(float value){
        cout<<".";
    }
}