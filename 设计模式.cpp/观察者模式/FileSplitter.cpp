class IProgress{
public:
    virtual void DoProgress(float value)=0;
    virtual ~IProgress(){}
};

class FileSplitter{
    string m_filePath;
    int m_fileNumber;

    //ProgressBar* m_progressBar;//实现细节变更新会有困扰（扮演了通知的角色）具体通知控件
    //IProgress* m_iprogress;//抽象通知机制,这样fileSplitter就不会紧耦合一个界面类,但只支持一个观察者
    //首先mainForm是IProgress的一个子类，所以传递this指针
    List<IProgress*> m_iprogressList;
public:
    /*
    FileSplitter(const string& filePath,int fileNumber,IProgress* iprogress)
    : m_filePath(filePath),m_fileNumber(fileNumber),m_iprogress(iprogress){

    }
    */

    FileSplitter(const string& filePath,int fileNumber)
    : m_filePath(filePath),m_fileNumber(fileNumber){

    }

    void addIProgress(IProgress* iprogress){
        m_iprogressList.add(iprogress);
    }

    void removeIProgress(IProgress* iprogress){
        m_iprogressList.remove(iprogress);
    }

    void split(){
        //1、读取大文件
        //2、分批次向小文件写入
        for(int ii=0;ii<m_fileNumber;ii++){
            //...
           
            float progressValue=m_fileNumber;
            progressValue = (ii+1) / progressValue;
            onProgress(progressValue);
        }
    }
protected:
    void onProgress(float value){
        /*
        if(m_iprogress!=nullptr){
            m_iprogress->DoProgress(value);//更新进度条
        }
        */
       auto itor=m_iprogressList.begin();
       while(itor!=m_iprogressList.end()){
           (*itor)->DoProgress(value);//发送通知
           itor++;
       }
    }
}

