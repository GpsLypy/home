//数据库访问有关的基类
class IDBConnection{

};
class IDBCommand{

};
class IDataReader{

};

class IDBFactory{
public:
    virtual IDBConnection* CreateDBConnection()=0;
    virtual IDBCommand* CreateDBCommand()=0;
    virtual IDataReader* CreateDataReader()=0;
};



//支持SQL Server
class SqlConnection: public IDBConnection{

};
class SqlCommand:public IDBCommand{

};
class SqlDataReader: public IDataReader{

};

class SqlDBFactory: public IDBFactory{
    virtual IDBConnection* CreateDBConnection(){};
    virtual IDBCommand* CreateDBCommand(){};
    virtual IDataReader* CreateDataReader(){};
};


//支持ORACLE
class OracleConnection: public IDBConnection{

};

class OracleCommand:public IDBCommand{

};

class OracleDataReader: public IDataReader{

};

//......




class EmployeeDAO{
    //这样存在的问题是：传递不同的工厂会乱套
    IDBFactory* dbFactory;

public:
    vector<EmployeeDAO> GetEmployees(){
        IDBConnection* connection=dbFactory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand* command=dbFactory->CreateDBCommand();
        command->CommandText=("...");
        command->SetConnection(connection);//关联性
        
        IDataReader* reader=command->ExecuteReader();
        while(reader->Read()){
            
        }
    }
};