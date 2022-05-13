//数据库访问有关的基类
class IDBConnection{

};

class IDBConnectionFactory{
public:
    virtual IDBConnection* CreateDBConnection()=0;
};


class IDBCommand{

};

class IDBCommandFactory{
public:
    virtual IDBCommand* CreateDBCommand()=0;
};

class IDataReader{

};
class IDataReaderFactory{
public:
    virtual IDataReader* CreateDataReader()=0;
};

//支持SQL Server
class SqlConnection: public IDBConnection{

};
class SqlConnectionFactory: public IDBConnectionFactory{

};

class SqlCommand:public IDBCommand{

};
class SqlCommandFactory: public IDBCommandFactory{

};

class SqlDataReader: public IDataReader{

};
class SqlDataReaderFactory: public IDataReaderFactory{

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
    IDBConnectionFactory* dbConnectionFactory;
    IDBCommandFactory* dbCommandFactory;
    IDataReaderFactory* dataReaderFactory;
public:
    vector<EmployeeDAO> GetEmployees(){
        IDBConnection* connection=dbConnectionFactory->CreateDBConnection();
        connection->ConnectionString("...");

        IDBCommand* command=dbCommandFactory->CreateDBCommand();
        command->CommandText=("...");
        command->SetConnection(connection);//关联性
        
        IDataReader* reader=command->ExecuteReader();
        while(reader->Read()){
            
        }
    }
};