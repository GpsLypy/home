#include "_shqx.h"

//地面观测数据处理的类
CSURFDATA::CSURFDATA(connection *conn,CLogFile *logfile)
{
  initdata();

  m_conn=conn; m_logfile=logfile;
}

void CSURFDATA::initdata()
{
  totalcount=insertcount=updatecount=invalidcount=0;
  m_conn=0; m_logfile=0;
  memset(&m_stsurfdata,0,sizeof(struct st_surfdata));
}

CSURFDATA::~CSURFDATA()
{
}

// 把用逗号分隔的记录拆分到m_stsurfdata结构中。
bool CSURFDATA::SplitBuffer(const char *strBuffer)
{
  totalcount++;

  memset(&m_stsurfdata,0,sizeof(struct st_surfdata));

  CCmdStr CmdStr;

  CmdStr.SplitToCmd(strBuffer,",",true);
  if (CmdStr.CmdCount()!=9) { invalidcount++; return false; }

  CmdStr.GetValue(0,m_stsurfdata.obtid,5);      // 站点代码
  CmdStr.GetValue(1,m_stsurfdata.ddatetime,19); // 数据时间：格式yyyy-mm-dd hh:mi:ss。
  double dtmp=0;
  CmdStr.GetValue(2,&dtmp); m_stsurfdata.t=(int)(dtmp*10);  // 气温：单位，0.1摄氏度
  CmdStr.GetValue(3,&dtmp); m_stsurfdata.p=(int)(dtmp*10);  // 气压：0.1百帕
  CmdStr.GetValue(4,&m_stsurfdata.u);  // 相对湿度，0-100之间的值。
  CmdStr.GetValue(5,&m_stsurfdata.wd); // 风向，0-360之间的值。
  CmdStr.GetValue(6,&dtmp); m_stsurfdata.wf=(int)(dtmp*10);  // 风速：单位0.1m/s
  CmdStr.GetValue(7,&dtmp); m_stsurfdata.r=(int)(dtmp*10);   // 降雨量：0.1mm
  CmdStr.GetValue(8,&dtmp); m_stsurfdata.vis=(int)(dtmp*10); // 能见度：0.1米

  return true;
}

// 把xml格式的记录拆分到m_stsurfdata结构中。
bool CSURFDATA::SplitBuffer1(const char *strBuffer)
{
  totalcount++;

  memset(&m_stsurfdata,0,sizeof(struct st_surfdata));

  GetXMLBuffer(strBuffer,"obtid",m_stsurfdata.obtid,5);      // 站点代码
  GetXMLBuffer(strBuffer,"ddatetime",m_stsurfdata.ddatetime,19); // 数据时间：格式yyyy-mm-dd hh:mi:ss。
  double dtmp=0;
  GetXMLBuffer(strBuffer,"t",&dtmp); m_stsurfdata.t=(int)(dtmp*10);  // 气温：单位，0.1摄氏度
  GetXMLBuffer(strBuffer,"p",&dtmp); m_stsurfdata.p=(int)(dtmp*10);  // 气压：0.1百帕
  GetXMLBuffer(strBuffer,"u",&m_stsurfdata.u);  // 相对湿度，0-100之间的值。
  GetXMLBuffer(strBuffer,"wd",&m_stsurfdata.wd);  // 风向，0-360之间的值。
  GetXMLBuffer(strBuffer,"wf",&dtmp); m_stsurfdata.wf=(int)(dtmp*10);  // 风速：单位0.1m/s
  GetXMLBuffer(strBuffer,"r",&dtmp); m_stsurfdata.r=(int)(dtmp*10);   // 降雨量：0.1mm
  GetXMLBuffer(strBuffer,"vis",&dtmp);  m_stsurfdata.vis=(int)(dtmp*10); // 能见度：0.1米

  return true;
}

// 把m_stsurfdata结构中的值更新到T_SURFDATA表中。
long CSURFDATA::InsertTable()
{
  if (stmtsel.m_state==0) //与数据库连接池的绑定状态，0-未绑定，1-已绑定。
  {
    stmtsel.connect(m_conn);
    stmtsel.prepare("select count(*) from T_SURFDATA where obtid=:1 and ddatetime=to_date(:2,'yyyy-mm-dd hh24:mi:ss')");
    stmtsel.bindin( 1, m_stsurfdata.obtid,5);
    stmtsel.bindin( 2, m_stsurfdata.ddatetime,19);
    stmtsel.bindout(1,&iccount);
  }

  if (stmtins.m_state==0)
  {
    stmtins.connect(m_conn);
    stmtins.prepare("insert into T_SURFDATA(obtid,ddatetime,t,p,u,wd,wf,r,vis,crttime,keyid) values(:1,to_date(:2,'yyyy-mm-dd hh24:mi:ss'),:3,:4,:5,:6,:7,:8,:9,sysdate,SEQ_SURFDATA.nextval)");
    stmtins.bindin( 1, m_stsurfdata.obtid,5);
    stmtins.bindin( 2, m_stsurfdata.ddatetime,19);
    stmtins.bindin( 3,&m_stsurfdata.t);
    stmtins.bindin( 4,&m_stsurfdata.p);
    stmtins.bindin( 5,&m_stsurfdata.u);
    stmtins.bindin( 6,&m_stsurfdata.wd);
    stmtins.bindin( 7,&m_stsurfdata.wf);
    stmtins.bindin( 8,&m_stsurfdata.r);
    stmtins.bindin( 9,&m_stsurfdata.vis);
  }

  if (stmtupt.m_state==0)
  {
    stmtupt.connect(m_conn);
    stmtupt.prepare("update T_SURFDATA set t=:1,p=:2,u=:3,wd=:4,wf=:5,r=:6,vis=:7 where obtid=:8 and ddatetime=to_date(:2,'yyyy-mm-dd hh24:mi:ss')");
    stmtupt.bindin( 1,&m_stsurfdata.t);
    stmtupt.bindin( 2,&m_stsurfdata.p);
    stmtupt.bindin( 3,&m_stsurfdata.u);
    stmtupt.bindin( 4,&m_stsurfdata.wd);
    stmtupt.bindin( 5,&m_stsurfdata.wf);
    stmtupt.bindin( 6,&m_stsurfdata.r);
    stmtupt.bindin( 7,&m_stsurfdata.vis);
    stmtupt.bindin( 8, m_stsurfdata.obtid,5);
    stmtupt.bindin( 9, m_stsurfdata.ddatetime,19);
  }

  if (stmtsel.execute() != 0)
  {
    invalidcount++; 
    m_logfile->Write("stmtsel.execute() failed.\n%s\n%s\n",stmtsel.m_sql,stmtsel.m_cda.message); 
    return stmtsel.m_cda.rc;
  }

  iccount=0;
  stmtsel.next();

  if (iccount>0) 
  {
    // 执行更新的SQL语句，一定要判断返回值，0-成功，其它-失败。
    if (stmtupt.execute() != 0)
    {
      invalidcount++; 
      m_logfile->Write("stmtupt.execute() failed.\n%s\n%s\n",stmtupt.m_sql,stmtupt.m_cda.message);
      return stmtupt.m_cda.rc;
    }
    updatecount++;
  }
  else
  {
    // 执行插入的SQL语句，一定要判断返回值，0-成功，其它-失败。
    if (stmtins.execute() != 0)
    {
      invalidcount++; 
      m_logfile->Write("stmtins.execute() failed.\n%s\n%s\n",stmtins.m_sql,stmtins.m_cda.message);
      return stmtins.m_cda.rc;
    }
    insertcount++;
  }

  return 0;
}

//全国气象站点参数文件处理的类
CINIDATA::CINIDATA(connection *conn,CLogFile *logfile)
{
  initdata();

  m_conn=conn; m_logfile=logfile;
}

void CINIDATA::initdata()
{
  totalcount=insertcount=updatecount=invalidcount=0;
  m_conn=0; m_logfile=0;
  memset(& m_stcode,0,sizeof(struct st_stcode));
}

CINIDATA::~CINIDATA()
{
}

// 把用逗号分隔的记录拆分到 m_stcode结构中。
bool CINIDATA::SplitBuffer(const char *strBuffer)
{
  totalcount++;

  memset(& m_stcode,0,sizeof(struct st_stcode));

  CCmdStr CmdStr;

  CmdStr.SplitToCmd(strBuffer,",",true);
  if (CmdStr.CmdCount()!=6) { invalidcount++; return false; }

  CmdStr.GetValue(0, m_stcode.provname,31);      // 站点代码
  CmdStr.GetValue(1, m_stcode.obtid,5); // 数据时间：格式yyyy-mm-dd hh:mi:ss。
  CmdStr.GetValue(2, m_stcode.obtname,31);
  CmdStr.GetValue(3, &m_stcode.lat);
  CmdStr.GetValue(4, &m_stcode.lon);
  CmdStr.GetValue(5, &m_stcode.height);
  return true;
}


// 把 m_stcode结构中的值更新到T_OBTCODE表中。
long CINIDATA::InsertTable()
{
  if (stmtins.m_state==0)
  {
    stmtins.connect(m_conn);
    stmtins.prepare("insert into T_OBTCODE(obtid,provname,obtname,lat,lon,height) values(:1,:2,:3,:4,:5,:6)");
    stmtins.bindin( 1,  m_stcode.obtid,5);
    stmtins.bindin( 2,  m_stcode.provname,31);
    stmtins.bindin( 3,  m_stcode.obtname,31);
    stmtins.bindin( 4,& m_stcode.lat);
    stmtins.bindin( 5,& m_stcode.lon);
    stmtins.bindin( 6,& m_stcode.height);
  }

    // 执行插入的SQL语句，一定要判断返回值，0-成功，其它-失败。
    if (stmtins.execute() != 0)
    {
      invalidcount++; 
      m_logfile->Write("stmtins.execute() failed.\n%s\n%s\n",stmtins.m_sql,stmtins.m_cda.message);
      return stmtins.m_cda.rc;
    }
    insertcount++;
  return 0;
}

//处理分区预警信号数据文件的类
CSIGNALLOG::CSIGNALLOG(connection *conn,CLogFile *logfile)
{
  initdata();

  m_conn=conn; m_logfile=logfile;
}

void CSIGNALLOG::initdata()
{
  totalcount=insertcount=updatecount=invalidcount=0;
  m_conn=0; m_logfile=0;
  memset(&m_stsignallog,0,sizeof(struct st_signallog));
  vsignallog.clear();
}

CSIGNALLOG::~CSIGNALLOG()
{
}

// 把记录拆分到vsignallog容器中。考虑到一行有多个预警信号
bool CSIGNALLOG::SplitBuffer(const char *strBuffer)
{
  vsignallog.clear();
  memset(&m_stsignallog,0,sizeof(struct st_signallog));

  CCmdStr CmdStr;

  CmdStr.SplitToCmd(strBuffer," ",true);
  if (CmdStr.CmdCount()<3) { invalidcount++; return false; }

  CmdStr.GetValue(0,m_stsignallog.ddatetime,12); // 数据时间：格式yyyymmddhh24mi
  strcat(m_stsignallog.ddatetime,"00");
  AddTime(m_stsignallog.ddatetime,m_stsignallog.ddatetime,8*60*60,"yyyy-mm-dd hh24:mi:ss");
  CmdStr.GetValue(1,m_stsignallog.obtid,4);      // 站点代码
  char strtemp[11];
  for (int ii=3;ii<=CmdStr.CmdCount();ii++)
  {
    memset(strtemp,0,sizeof(strtemp));
    CmdStr.GetValue(ii-1,strtemp,5);
    m_stsignallog.signalname[0]=strtemp[0];
    m_stsignallog.signalcolor[0]=strtemp[1];
    vsignallog.push_back(m_stsignallog);
    totalcount++;
  }

  return true;
}

// 把vsignallog容器中的值更新到T_SIGNALDATA表中。
long CSIGNALLOG::InsertTable()
{
  if (stmtsel.m_state==0)
  {
    stmtsel.connect(m_conn);
    stmtsel.prepare("select count(*) from T_SIGNALLOG where obtid=:1 and ddatetime=to_date(:2,'yyyy-mm-dd hh24:mi:ss') and signalname=:3");
    stmtsel.bindin( 1, m_stsignallog.obtid,4);
    stmtsel.bindin( 2, m_stsignallog.ddatetime,19);
    stmtsel.bindin( 3, m_stsignallog.signalname,1);
    stmtsel.bindout(1,&iccount);
  }

  if (stmtins.m_state==0)
  {
    stmtins.connect(m_conn);
    stmtins.prepare("insert into T_SIGNALLOG(obtid,ddatetime,signalname,signalcolor,crttime,keyid) values(:1,to_date(:2,'yyyy-mm-dd hh24:mi:ss'),:3,:4,sysdate,SEQ_SIGNALLOG.nextval)");
    stmtins.bindin( 1, m_stsignallog.obtid,4);
    stmtins.bindin( 2, m_stsignallog.ddatetime,19);
    stmtins.bindin( 3, m_stsignallog.signalname,1);
    stmtins.bindin( 4, m_stsignallog.signalcolor,1);
  }

  if (stmtupt.m_state==0)
  {
    stmtupt.connect(m_conn);
    stmtupt.prepare("update T_SIGNALLOG set signalcolor=:1 where obtid=:2 and ddatetime=to_date(:3,'yyyy-mm-dd hh24:mi:ss') and signalname=:4");
    stmtupt.bindin( 1, m_stsignallog.signalcolor,1);
    stmtupt.bindin( 2, m_stsignallog.obtid,4);
    stmtupt.bindin( 3, m_stsignallog.ddatetime,19);
    stmtupt.bindin( 4, m_stsignallog.signalname,1);
  }

  for (int ii=0;ii<vsignallog.size();ii++)
  {
    memcpy(&m_stsignallog,&vsignallog[ii],sizeof(struct st_signallog));
    m_logfile->Write("%s,%s,%s,%s\n",m_stsignallog.obtid,m_stsignallog.ddatetime,m_stsignallog.signalname,m_stsignallog.signalcolor);

    if (stmtsel.execute() != 0)
    {
      invalidcount++; 
      m_logfile->Write("stmtsel.execute() failed.\n%s\n%s\n",stmtsel.m_sql,stmtsel.m_cda.message); 
      return stmtsel.m_cda.rc;
    }
  
    iccount=0;
    stmtsel.next();
  
    if (iccount>0) 
    {
      // 执行更新的SQL语句，一定要判断返回值，0-成功，其它-失败。
      if (stmtupt.execute() != 0)
      {
        invalidcount++; 
        m_logfile->Write("stmtupt.execute() failed.\n%s\n%s\n",stmtupt.m_sql,stmtupt.m_cda.message);
        return stmtupt.m_cda.rc;
      }
      updatecount++;
    }
    else
    {
      // 执行插入的SQL语句，一定要判断返回值，0-成功，其它-失败。
      if (stmtins.execute() != 0)
      {
        invalidcount++; 
        m_logfile->Write("stmtins.execute() failed.\n%s\n%s\n",stmtins.m_sql,stmtins.m_cda.message);
        return stmtins.m_cda.rc;
      }
      insertcount++;
    }
  }

  return 0;
}



// 把非结构化数据文件写入oracle数据库的表中
int FileToTable(connection *in_conn,CLogFile *in_logfile,char *in_tname,char *in_filename,char *in_ddatetime)
{
  sqlstatement stmt(in_conn);

  // 判断文件记录在表中是否已存在
  int icount=0;
  stmt.prepare("select count(*) from %s where filename=:1",in_tname);
  stmt.bindin(1,in_filename,300);
  stmt.bindout(1,&icount);
  if (stmt.execute() != 0)
  {
    in_logfile->Write("FileToTable() failed.%s\n%s\n",stmt.m_sql,stmt.m_cda.message); return stmt.m_cda.rc;
  }
  stmt.next();
  // 如果记录已存在，直接返回0-成功。
  if (icount>0) return 0;

  // 把文件信息插入表中。
  int ifilesize=FileSize(in_filename);
  stmt.prepare("\
       insert into %s(filename,ddatetime,filesize,filecontent,crttime,keyid)\
               values(:1,to_date(:2,'yyyymmddhh24miss'),:3,empty_blob(),sysdate,SEQ_%s.nextval)",\
       in_tname,in_tname+2);
  stmt.bindin(1,in_filename,300);
  stmt.bindin(2,in_ddatetime,14);
  stmt.bindin(3,&ifilesize);
  
  if (stmt.execute() != 0)
  {
    in_logfile->Write("FileToTable() failed.%s\n%s\n",stmt.m_sql,stmt.m_cda.message); return stmt.m_cda.rc;
  }
    
  // 把文件内容更新到BLOB字段中。
  stmt.prepare("select filecontent from %s where filename=:1 for update",in_tname);
  stmt.bindin(1,in_filename,300);
  stmt.bindblob();

  // 执行SQL语句，一定要判断返回值，0-成功，其它-失败。
  if (stmt.execute() != 0)
  {
    in_logfile->Write("FileToTable() failed.%s\n%s\n",stmt.m_sql,stmt.m_cda.message); return stmt.m_cda.rc;
  }

  // 获取一条记录，一定要判断返回值，0-成功，1403-无记录，其它-失败。
  if (stmt.next() != 0) return -1;

  // 把磁盘文件pic_in.jpg的内容写入BLOB字段，一定要判断返回值，0-成功，其它-失败。
  if (stmt.filetolob((char *)in_filename) != 0)
  {
    in_logfile->Write("FileToTable() stmt.filetolob() failed.\n%s\n",stmt.m_cda.message); return -1;
  }

  // 提交事务
  in_conn->commit();

  return 0;
}


CTYDATA::CTYDATA(connection *conn,CLogFile *logfile)//构造函数
{
  initdata();

  m_conn=conn; m_logfile=logfile;
}

CTYDATA::~CTYDATA()//析构函数
{
 
}
void CTYDATA::initdata() // 数据初始化
{
  sum=totalcount1=insertcount1=updatecount1=invalidcount1=totalcount2=insertcount2=updatecount2=invalidcount2=0;
  m_conn=0; m_logfile=0;m_set=0;
  memset(&m_sttycode,0,sizeof(struct st_tycode));
  memset(&m_sttypath,0,sizeof(struct st_typath));
}

 // 把用" "分隔的记录拆分到m_sttycode和m_sttypath结构中。
bool CTYDATA::SplitBuffer1(const char *strBuffer)
{
  memset(&m_sttycode,0,sizeof(struct st_tycode));
 
  memset(&m_sttypath,0,sizeof(struct st_typath));  
  CCmdStr CmdStr;
 
  CmdStr.SplitToCmd(strBuffer," ",true);

 /*
  for(int ii=0;ii<CmdStr.m_vCmdStr.size();ii++)
   {
     m_logfile->Write("0-m_vCmdStr[ii]=%s",CmdStr.m_vCmdStr[ii].c_str());
   }
 */

  if (CmdStr.CmdCount()==9)
 {
   CmdStr.GetValue(0,m_sttycode.sortflag);
   CmdStr.GetValue(1,m_sttycode.internum);
   CmdStr.GetValue(2,m_sttycode.line);
   CmdStr.GetValue(3,m_sttycode.cynum);
   CmdStr.GetValue(4,m_sttycode.donum);
   if(strlen(m_sttycode.donum)!=4)
    {
     sum++;
     totalcount1++;
     invalidcount1++;
     return false;
    }
   CmdStr.GetValue(5,&m_sttycode.endflag);
   CmdStr.GetValue(6,&m_sttycode.vtime);
   CmdStr.GetValue(7,m_sttycode.tscname);
   CmdStr.GetValue(8,m_sttycode.time);
   
//m_logfile->Write("sortflag=%s,internum=%s,line=%s,cynum=%s \n",m_sttycode.sortflag,m_sttycode.internum,m_sttycode.line,m_sttycode.cynum);
    m_set=1;
    sum++;
    totalcount1++;
    return true;
 }

 else
 {
    if (CmdStr.CmdCount()==6) 
    { 
      CmdStr.GetValue(0,m_sttypath.ttime,10);
      CmdStr.GetValue(1,&m_sttypath.fflag);
      CmdStr.GetValue(2,&m_sttypath.llat);
      CmdStr.GetValue(3,&m_sttypath.llon);
      CmdStr.GetValue(4,&m_sttypath.pressure);
      CmdStr.GetValue(5,&m_sttypath.windspeed);

// m_logfile->Write("ttime=%s,flag=%d,lat=%d,lon=%d,pressure=%d,windspeed=%d\n",m_sttypath.ttime,m_sttypath.fflag,m_sttypath.llat,m_sttypath.llon,m_sttypath.pressure,m_sttypath.windspeed);
      sum++;
      totalcount2++;
      m_set=2;
      return true;
    }
   
   //iinvalidcount1++;
   totalcount2++;
   invalidcount2++; 
   sum++;
   return false;
  }
 
  
//  return true;

}

 // 把m_sttycode和m_sttypath结构中的值更新到T_SURFDATA表中。
long CTYDATA::InsertTable1()
{
  if (stmtsel.m_state==0)
  {
    stmtsel.connect(m_conn);
    stmtsel.prepare("select count(*) from T_TYCODE where donum=:1");
    stmtsel.bindin( 1,m_sttycode.donum,4);
    stmtsel.bindout(1,&iccount1);
  }

  if (stmtins.m_state==0)
  {
    stmtins.connect(m_conn);

    stmtins.prepare("insert into T_TYCODE(sortflag,internum,line,cynum,donum,endflag,vtime,tscname,time,crttime,keyid) values(:1,:2,:3,:4,:5,:6,:7,:8,:9,sysdate,SEQ_TYCODE.nextval)");
    stmtins.bindin( 1,m_sttycode.sortflag,5);
    stmtins.bindin( 2,m_sttycode.internum,4);
    stmtins.bindin( 3,m_sttycode.line,3);
    stmtins.bindin( 4,m_sttycode.cynum,4);
    stmtins.bindin( 5,m_sttycode.donum,4);
    stmtins.bindin( 6,&m_sttycode.endflag); 
    stmtins.bindin( 7,&m_sttycode.vtime);
    stmtins.bindin( 8,m_sttycode.tscname,20); 
    stmtins.bindin( 9,m_sttycode.time,8);

  }

  if (stmtupt.m_state==0)
  {
    stmtupt.connect(m_conn);
    stmtupt.prepare("update T_TYCODE set sortflag=:1,internum=:2,line=:3,cynum=:4,endflag=:5,vtime=:6,tscname=:7,time=:8 where donum=:9");
    stmtupt.bindin( 1,m_sttycode.sortflag,5);
    stmtupt.bindin( 2,m_sttycode.internum,4);
    stmtupt.bindin( 3,m_sttycode.line,3);
    stmtupt.bindin( 4,m_sttycode.cynum,4);
    stmtupt.bindin( 5,&m_sttycode.endflag);
    stmtupt.bindin( 6,&m_sttycode.vtime);
    stmtupt.bindin( 7,m_sttycode.tscname,20);
    stmtupt.bindin( 8,m_sttycode.time,8);
    stmtupt.bindin( 9,m_sttycode.donum,4);
  } 
   
  if (stmtsel.execute() != 0)
  {
    invalidcount1++; 
    m_logfile->Write("stmtsel.execute() failed.\n%s\n%s\n",stmtsel.m_sql,stmtsel.m_cda.message); 
    return stmtsel.m_cda.rc;
  }

  iccount1=0;
  stmtsel.next();
  //m_logfile->Write("icoout1=%d\n",iccount1);
  if (iccount1>0) 
  {
    // 执行更新的SQL语句，一定要判断返回值，0-成功，其它-失败。
    if (stmtupt.execute() != 0)
    {
      invalidcount1++; 
      m_logfile->Write("stmtupt.execute() failed.\n%s\n%s\n",stmtupt.m_sql,stmtupt.m_cda.message);
      return stmtupt.m_cda.rc;
    }
    updatecount1++;
  }
  else
  {
    // 执行插入的SQL语句，一定要判断返回值，0-成功，其它-失败。
    if (stmtins.execute() != 0)
    {
      invalidcount1++; 
      m_logfile->Write("stmtins.execute() failed.\n%s\n%s\n",stmtins.m_sql,stmtins.m_cda.message);
      return stmtins.m_cda.rc;
    }
    insertcount1++;
  }

  return 0;


}
 
long CTYDATA::InsertTable2()
{
   if (stmtsel2.m_state==0)
  {
    stmtsel2.connect(m_conn);
    stmtsel2.prepare("select count(*) from T_TYPATH where time=:1");
    stmtsel2.bindin( 1,m_sttypath.ttime,10);
    stmtsel2.bindout(1,&iccount2);
  }
 
  if (stmtins2.m_state==0)
  {
    stmtins2.connect(m_conn);
    stmtins2.prepare("insert into T_TYPATH(time,mark,lat,lon,pressure,windspeed,crttime,keyid) values(:1,:2,:3,:4,:5,:6,sysdate,SEQ_TYPATH.nextval)");
   
    //stmtins.prepare("insert into T_TYPATH(time,crttime,keyid) values(:1,sysdate,SEQ_TYPATH.nextval)");
    stmtins2.bindin( 1,m_sttypath.ttime,10);
    stmtins2.bindin( 2,&m_sttypath.fflag);
    stmtins2.bindin( 3,&m_sttypath.llat);
    stmtins2.bindin( 4,&m_sttypath.llon);
    stmtins2.bindin( 5,&m_sttypath.pressure);
    stmtins2.bindin( 6, &m_sttypath.windspeed);
 
  }
  if (stmtupt2.m_state==0)
  {
    stmtupt2.connect(m_conn);
    stmtupt2.prepare("update T_TYPATH set mark=:1,lat=:2,lon=:3,pressure=:4,windspeed=:5 where time=:6");
    stmtupt2.bindin( 1,&m_sttypath.fflag); 
    stmtupt2.bindin( 2,&m_sttypath.llat);
    stmtupt2.bindin( 3,&m_sttypath.llon);
    stmtupt2.bindin( 4,&m_sttypath.pressure);
    stmtupt2.bindin( 5,&m_sttypath.windspeed);
    stmtupt2.bindin( 6,m_sttypath.ttime,10); 
  }

  if (stmtsel2.execute() != 0)
  {
    invalidcount2++; 
    m_logfile->Write("stmtsel.execute() failed.\n%s\n%s\n",stmtsel2.m_sql,stmtsel2.m_cda.message); 
    return stmtsel2.m_cda.rc;
  }
 
  iccount2=0;
  stmtsel2.next();

  //m_logfile->Write("icoout2=%d\n",iccount2);

  if (iccount2>0) 
  {
    // 执行更新的SQL语句，一定要判断返回值，0-成功，其它-失败。
    if (stmtupt2.execute() != 0)
     {
      invalidcount2++; 
      m_logfile->Write("stmtupt.execute() failed.\n%s\n%s\n",stmtupt2.m_sql,stmtupt2.m_cda.message);
      return stmtupt2.m_cda.rc;
    }
    updatecount2++;
  }
  else
  {
    // 执行插入的SQL语句，一定要判断返回值，0-成功，其它-失败。
    if (stmtins2.execute() != 0)
    {
      invalidcount2++; 
      m_logfile->Write("stmtins2.execute() failed.\n%s\n%s\n",stmtins2.m_sql,stmtins2.m_cda.message);
      return stmtins2.m_cda.rc;
    }
    insertcount2++;
  }

  return 0;  

}



//处理json类
CJSONDATA::CJSONDATA(connection *conn,CLogFile *logfile)
{
  initdata();

  m_conn=conn; m_logfile=logfile;
}

void CJSONDATA::initdata()
{
  totalcount=insertcount=updatecount=invalidcount=0;
  m_conn=0; m_logfile=0;
  //memset(&m_stsurfdata,0,sizeof(struct st_surfdata));
}

CJSONDATA::~CJSONDATA()
{
}

long CJSONDATA::InsertTable(struct st_json *stjson)
{
  if (stmtsel.m_state==0) //与数据库连接池的绑定状态，0-未绑定，1-已绑定。
  {
    stmtsel.connect(m_conn);
    stmtsel.prepare("select count(*) from T_JSON where w1=:1 and w2=:2 and w3=:3 and w4=:4");
    stmtsel.bindin( 1, stjson->w1,31);
    stmtsel.bindin( 2, stjson->w2,31);
    stmtsel.bindin( 3, stjson->w3,31);
    stmtsel.bindin( 4, stjson->w4,3);
    stmtsel.bindout(1,&iccount);
  }

  if (stmtins.m_state==0)
  {
    stmtins.connect(m_conn);
    stmtins.prepare("insert into T_JSON(w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,crttime,keyid) values(:1,:2,:3,:4,:5,:6,:7,to_date(:8,'yyyy-mm-dd hh24:mi'),:9,:10,:11,sysdate,SEQ_TJSON.nextval)");
    stmtins.bindin( 1, stjson->w1,31);
    stmtins.bindin( 2, stjson->w2,31);
    stmtins.bindin( 3, stjson->w3,31);
    stmtins.bindin( 4, stjson->w4,3);
    stmtins.bindin( 5, stjson->w5,11);
 
    stmtins.bindin( 6, stjson->w6,3);
    stmtins.bindin( 7, stjson->w7,11);
    stmtins.bindin( 8, stjson->w8,21);
    stmtins.bindin( 9, stjson->w9,600);

    stmtins.bindin( 10, stjson->w10,51);
    stmtins.bindin( 11, stjson->w11,51);
  }

  if (stmtupt.m_state==0)
  {
    stmtupt.connect(m_conn);
    stmtupt.prepare("update T_JSON set w5=:1,w6=:2,w7=:3,w8=:4,w9=:5,w10=:6,w11=:7 where w1=:8 and w2=:9 and w3=:10 and w4=11");
    stmtupt.bindin( 1,stjson->w5,11);
    stmtupt.bindin( 2,stjson->w6,3);
    stmtupt.bindin( 3,stjson->w7,11);
    stmtupt.bindin( 4,stjson->w8,21);
    stmtupt.bindin( 5,stjson->w9,600);
    stmtupt.bindin( 6,stjson->w10,51);
    stmtupt.bindin( 7,stjson->w11,51);
    stmtupt.bindin( 8, stjson->w1,31);
    stmtupt.bindin( 9, stjson->w2,31);
    stmtupt.bindin( 10, stjson->w3,31);
    stmtupt.bindin( 11, stjson->w4,3);

  }

   if (stmtsel.execute() != 0)
  {
    invalidcount++;
    m_logfile->Write("stmtsel.execute() failed.\n%s\n%s\n",stmtsel.m_sql,stmtsel.m_cda.message);
    return stmtsel.m_cda.rc;
  }

  iccount=0;
  stmtsel.next();

  if (iccount>0)
  {
    // 执行更新的SQL语句，一定要判断返回值，0-成功，其它-失败。
    if (stmtupt.execute() != 0)
    {
      invalidcount++;
      m_logfile->Write("stmtupt.execute() failed.\n%s\n%s\n",stmtupt.m_sql,stmtupt.m_cda.message);
      return stmtupt.m_cda.rc;
    }
    updatecount++;
  }
else
  {
    // 执行插入的SQL语句，一定要判断返回值，0-成功，其它-失败。
    if (stmtins.execute() != 0)
    {
      invalidcount++;
      m_logfile->Write("stmtins.execute() failed.\n%s\n%s\n",stmtins.m_sql,stmtins.m_cda.message);
      return stmtins.m_cda.rc;
    }
    insertcount++;
  }

  return 0;
}



CRFFC::CRFFC(connection *conn,CLogFile *logfile)
{
  initdata();

  m_conn=conn; m_logfile=logfile;
}

void CRFFC::initdata()
{
  totalcount=insertcount=updatecount=invalidcount=0;
  m_conn=0; m_logfile=0;
  memset(&m_strffc,0,sizeof(struct st_rffc));
}

CRFFC::~CRFFC()
{
}

// 把用逗号分隔的记录拆分到m_stsurfdata结构中。
bool CRFFC::SplitBuffer(const char *strBuffer)
{
  totalcount++;

  memset(&m_strffc,0,sizeof(struct st_rffc));

  CCmdStr CmdStr;

  CmdStr.SplitToCmd(strBuffer," ",true);

  //char buffer1[5],buffer2[6],buffer3[11],buffer4[5],buffer5[10],buffer6[7],buffer7[3];

  if (CmdStr.CmdCount()==1) 
  { 
    if(strlen(CmdStr.m_vCmdStr[0].c_str())<9) return false; 
    else
     {
       memset(m_buffer1,0,sizeof(m_buffer1));
       CmdStr.GetValue(0,m_buffer1,100);//
       return false;
      }
   }

  if (CmdStr.CmdCount()==2)
  {
    memset(m_buffer2,0,sizeof(m_buffer2));
    memset(m_buffer3,0,sizeof(m_buffer3));
    CmdStr.GetValue(0,m_buffer2,5);//
    CmdStr.GetValue(1,m_buffer3,10);//
    return false;
  }

  if (CmdStr.CmdCount()==3) 
  {
    memset(m_buffer4,0,sizeof(m_buffer4));
    memset(m_buffer5,0,sizeof(m_buffer5));
    CmdStr.GetValue(1,m_buffer4,4);//
    CmdStr.GetValue(2,m_buffer5,9);//
    return false;
  }

  if (CmdStr.CmdCount()==6)
  {
    memset(m_buffer6,0,sizeof(m_buffer6));
    memset(m_buffer7,0,sizeof(m_buffer7));
    CmdStr.GetValue(0,m_buffer6,6);//
    CmdStr.GetValue(4,m_buffer7,2);//
    return false;
  }

  if (CmdStr.CmdCount()==22)
 {
  CmdStr.GetValue(1,&m_strffc.t);    
  CmdStr.GetValue(2,&m_strffc.rh); // 数据时间：格式yyyy-mm-dd hh:mi:ss。
  CmdStr.GetValue(3,&m_strffc.wd);
  CmdStr.GetValue(4,&m_strffc.wf);
  CmdStr.GetValue(5,&m_strffc.p);
  CmdStr.GetValue(6,&m_strffc.hourrf);
  CmdStr.GetValue(7,&m_strffc.cloudh);
  CmdStr.GetValue(8,&m_strffc.cloudl);
  CmdStr.GetValue(9,&m_strffc.phenomena);
  CmdStr.GetValue(10,&m_strffc.visibility);
  CmdStr.GetValue(11,&m_strffc.maxt);
  CmdStr.GetValue(12,&m_strffc.mint);
  CmdStr.GetValue(13,&m_strffc.maxrh);
  CmdStr.GetValue(14,&m_strffc.minrh);
  CmdStr.GetValue(15,&m_strffc.hourrf24);
  CmdStr.GetValue(16,&m_strffc.hourrf12);
  CmdStr.GetValue(17,&m_strffc.cloudh12);
  CmdStr.GetValue(18,&m_strffc.cloudl12);
  CmdStr.GetValue(19,&m_strffc.phenomena12);
  CmdStr.GetValue(20,&m_strffc.wd12); 
  CmdStr.GetValue(21,&m_strffc.wf12);

  strcpy(m_strffc.encode,m_buffer4);
  strcpy(m_strffc.yygggg,m_buffer5);
  strcpy(m_strffc.commet,m_buffer1);
  strcpy(m_strffc.pcode,m_buffer2);
  strcpy(m_strffc.ctime,m_buffer3);
  strcpy(m_strffc.pvalue,m_buffer7);
  strcpy(m_strffc.obtid,m_buffer6);
 }
  return true;
}

// 把m_stsurfdata结构中的值更新到T_SURFDATA表中。
long CRFFC::InsertTable()

{
  if (stmtsel.m_state==0) //与数据库连接池的绑定状态，0-未绑定，1-已绑定。
  {
    stmtsel.connect(m_conn);
    stmtsel.prepare("select count(*) from T_RFFC where pcode=:1 and ctime=:2 and pvalue=:3 and obtid=:4");
    stmtsel.bindin( 1, m_strffc.pcode,6);
    stmtsel.bindin( 2, m_strffc.ctime,11);
    stmtsel.bindin( 3, m_strffc.pvalue,3);
    stmtsel.bindin( 4, m_strffc.obtid,7);
    stmtsel.bindout(1,&iccount);
  }

  if (stmtins.m_state==0)
  {
    stmtins.connect(m_conn);
    stmtins.prepare("insert into T_RFFC(encode,yygggg,commet,pcode,ctime,pvalue,obtid,t,rh,wd,wf,p,hourrf,cloudh,cloudl,phenomena,visibility,\
                                        maxt,mint,maxrh,minrh,hourrf24,hourrf12,cloudh12,cloudl12,phenomena12,wd12,wf12,crttime,keyid)\
    values(:1,:2,:3,:4,:5,:6,:7,:8,:9,:10,:11,:12,:13,:14,:15,:16,:17,:18,:19,:20,:21,:22,:23,:24,:25,:26,:27,:28,sysdate,SEQ_RFFC.nextval)");

    stmtins.bindin( 1, m_strffc.encode,4);  stmtins.bindin( 2, m_strffc.yygggg,9);   stmtins.bindin( 3, m_strffc.commet,100);
    stmtins.bindin( 4, m_strffc.pcode,5);   stmtins.bindin( 5, m_strffc.ctime,10);   stmtins.bindin( 6, m_strffc.pvalue,2);
    stmtins.bindin( 7, m_strffc.obtid,6);   stmtins.bindin( 8,&m_strffc.t);          stmtins.bindin( 9,&m_strffc.rh);
    stmtins.bindin( 10,&m_strffc.wd);       stmtins.bindin( 11,&m_strffc.wf);        stmtins.bindin( 12,&m_strffc.p);
    stmtins.bindin( 13,&m_strffc.hourrf);   stmtins.bindin( 14,&m_strffc.cloudh);    stmtins.bindin( 15,&m_strffc.cloudl);
    stmtins.bindin( 16,&m_strffc.phenomena);stmtins.bindin( 17,&m_strffc.visibility);stmtins.bindin( 18,&m_strffc.maxt);
    stmtins.bindin( 19,&m_strffc.mint);       stmtins.bindin( 20,&m_strffc.maxrh);         stmtins.bindin( 21,&m_strffc.minrh);
    stmtins.bindin( 22,&m_strffc.hourrf24);        stmtins.bindin( 23,&m_strffc.hourrf12);        stmtins.bindin( 24,&m_strffc.cloudh12);
    stmtins.bindin( 25,&m_strffc.cloudl12);       stmtins.bindin( 26,&m_strffc.phenomena12);         stmtins.bindin( 27,&m_strffc.wd12);
    stmtins.bindin( 28,&m_strffc.wf12);
  }


  if (stmtupt.m_state==0)
  {
    stmtupt.connect(m_conn);
    stmtupt.prepare("update T_RFFC set encode=:1,yygggg=:2,t=:3,rh=:4,wd=:5,wf=:6,p=:7,hourrf=:8,cloudh=:9,cloudl=:10,phenomena=:11,visibility=:12,maxt=:13,mint=:14,maxrh=:15,minrh=:16,hourrf24=:17,hourrf12=:18,cloudh12=:19,cloudl12=:20,phenomena12=:21,wd12=:22,wf12=:23 where pcode=:24 and ctime=:25 and pvalue=:26 and obtid=:27");
  
    stmtupt.bindin( 1, m_strffc.encode,4);      stmtupt.bindin( 2, m_strffc.yygggg,9); 
    stmtupt.bindin( 3,&m_strffc.t);             stmtupt.bindin( 4,&m_strffc.rh);
    stmtupt.bindin( 5,&m_strffc.wd);            stmtupt.bindin( 6,&m_strffc.wf);              stmtupt.bindin( 7,&m_strffc.p);
    stmtupt.bindin( 8,&m_strffc.hourrf);        stmtupt.bindin( 9,&m_strffc.cloudh);          stmtupt.bindin( 10,&m_strffc.cloudl);
    stmtupt.bindin( 11,&m_strffc.phenomena);    stmtupt.bindin( 12,&m_strffc.visibility);     stmtupt.bindin( 13,&m_strffc.maxt);
    stmtupt.bindin( 14,&m_strffc.mint);         stmtupt.bindin( 15,&m_strffc.maxrh);          stmtupt.bindin( 16,&m_strffc.minrh);
    stmtupt.bindin( 17,&m_strffc.hourrf24);     stmtupt.bindin( 18,&m_strffc.hourrf12);       stmtupt.bindin( 19,&m_strffc.cloudh12);
    stmtupt.bindin( 20,&m_strffc.cloudl12);     stmtupt.bindin( 21,&m_strffc.phenomena12);    stmtupt.bindin( 22,&m_strffc.wd12);
    stmtupt.bindin( 23,&m_strffc.wf12);         stmtupt.bindin( 24,m_strffc.pcode,5);           stmtupt.bindin( 25,m_strffc.ctime,10);                  stmtupt.bindin( 26,m_strffc.pvalue,2);        stmtupt.bindin( 27,m_strffc.obtid,6);  
  }

  if (stmtsel.execute() != 0)
  {
    invalidcount++; 
    m_logfile->Write("stmtsel.execute() failed.\n%s\n%s\n",stmtsel.m_sql,stmtsel.m_cda.message); 
    return stmtsel.m_cda.rc;
  }

  iccount=0;
  stmtsel.next();

  if (iccount>0) 
  {
    // 执行更新的SQL语句，一定要判断返回值，0-成功，其它-失败。
    if (stmtupt.execute() != 0)
    {
      invalidcount++; 
      m_logfile->Write("stmtupt.execute() failed.\n%s\n%s\n",stmtupt.m_sql,stmtupt.m_cda.message);
      return stmtupt.m_cda.rc;
    }
    updatecount++;
  }
  else
  {
    // 执行插入的SQL语句，一定要判断返回值，0-成功，其它-失败。
    if (stmtins.execute() != 0)
    {
      invalidcount++; 
      m_logfile->Write("stmtins.execute() failed.\n%s\n%s\n",stmtins.m_sql,stmtins.m_cda.message);
      return stmtins.m_cda.rc;
    }
    insertcount++;
  }

  return 0;
}


