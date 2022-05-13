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
class CryptoStream : public Stream{
    Stream*  stream;//=new FileStream();.........
public:

    CryptoStream(Stream* stm): stream(stm){

    }
    virtual char Read(int number){
        //额外的加密操作...
        stream->Read(number);//读文件流
    }
    virtual void Seek(int position){
        //额外的加密操作
        stream->Seek(position);//定位文件流
    }
    virtual void Write(byte data){
        //额外的加密操作
        stream->Write(data);
    }
};

/*
class CryptoFileStream{
    Stream*  stream;//=new FileStream();.........
public:
    virtual char Read(int number){
        //额外的加密操作...
        stream->Read(number);//读文件流
    }
    virtual void Seek(int position){
        //额外的加密操作
        stream->Seek(position);//定位文件流
    }
    virtual void Write(byte data){
        //额外的加密操作
        stream->Write(data);
    }
};


class CryptoNetworkStream{
   Stream* stream;//=new NetworkStream();
public:
    virtual char Read(int number){
        //额外的加密操作
        stream->Read(int number);//读网络流
    }
    virtual void Seek(int position){
        //额外的加密操作
        stream->Seek(position);
    }
    virtual void Write(byte data){
        //额外的加密操作
        stream->Write(data);//写网络流
    }
};

class CryptoMemoryStream{
    Stream* stream;//=new MemoryStream();
public:
    virtual char Read(int number){
        //额外的加密操作
        stream->Read(number);
    }
    virtual void Seek(int position){
        //额外的加密操作
        stream->Seek(position);
    }
    virtual void Write(byte data){
        //额外的加密操作
        stream->Write(data);
    } 
};

*/

class BufferedStream : public Stream{
    Stream* stream;
public:
    BufferedStream(Stream* stm): stream(stm){
        
    }
    //
};

/*
class BufferedNetworkStream : public NetworkStream{
    //
};

class BufferedMemoryStream : public MemoryStream{
    //
};

*/



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
    /*
    //编译时装配
    CryptoFileStream* fs1= new CryptoFileStream();
    BufferedFileStream* fs2=new BufferedFileStream();
    CryptoBufferedFileStream* fs3=new CryptoBufferedFileStream();
    */

    FileStream* s1=new FileStream();
    CryptoStream* s2=new CryptoStream(s1);
    BufferedStream* s3=new BufferedStream(s1);

}