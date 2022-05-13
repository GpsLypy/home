//业务操作
class Stream{
public:
    virtual char Read(int number)=0;
    virtual void Seek(int position)=0;
    virtual void Write(char data)=0;
    virtual ~Stream(){}
};

//主体类
class FileStream : public Stream{
public:
    virtual char Read(int number){
        //读文件流
    }
    virtual void Seek(int position){
        //定位文件流
    }
    virtual void Write(char data){
        //写文件流
    }
};

class NetworkStream : public Stream{
public:
    virtual char Read(int number){
        //读网络流
    }
    virtual void Seek(int position){
        //定位网络流
    }
    virtual void Write(){
        //写网络流
    }
};


class MemoryStream : public Stream{
public:
    virtual char Read(int number){
        //读内存流
    }
    virtual void Seek(int position){
        //定位内存流
    }
    virtual void Write(char data){
        //写内存流
    }
};


//当我们要考虑加密操作，那么就涉及到了拓展操作
//拓展操作
class CryptoFileStream : public FileStream{
public:
    virtual char Read(int number){
        //额外的加密操作...
        FileStream::Read(number);//读文件流
    }
    virtual void Seek(int position){
        //额外的加密操作
        FileStream::Seek(position);//定位文件流
    }
    virtual void Write(byte data){
        //额外的加密操作
        FileStream::Write(data);
    }
};

class CryptoNetworkStream : public NetworkStream{
public:
    virtual char Read(int number){
        //额外的加密操作
        NetworkStream::Read(int number);//读网络流
    }
    virtual void Seek(int position){
        //额外的加密操作
        NetworkStream::Seek(position);
    }
    virtual void Write(byte data){
        //额外的加密操作
        NetworkStream::Write(data);//写网络流
    }
};

class CryptoMemoryStream : public MemoryStream{
public:
    virtual char Read(int number){
        //额外的加密操作
        MemoryStream::Read(number);
    }
    virtual void Seek(int position){
        //额外的加密操作
        MemoryStream::Seek(position);
    }
    virtual void Write(byte data){
        //额外的加密操作
        MemoryStream::Write(data);
    } 
};

class BufferedFileStream : public FileStream{
    //
};

class BufferedNetworkStream : public NetworkStream{
    //
};

class BufferedMemoryStream : public MemoryStream{
    //
};


class CryptoBufferedFileStream : public FileStream{
public:
    virtual char Read(int number){
        //额外的加密操作
        //额外的缓冲操作
        FileStream::Read(number);
    }
    virtual void Seek(int position){
        //额外的加密操作
        //额外的缓冲操作
        FileStream::Seek(position);
    }
    virtual void Write(byte data){
        //额外的加密操作
        //额外的缓冲操作
        FileStream::Write(data);
    }
};



void Process(){
    //编译时装配
    CryptoFileStream* fs1= new CryptoFileStream();
    BufferedFileStream* fs2=new BufferedFileStream();
    CryptoBufferedFileStream* fs3=new CryptoBufferedFileStream();
}