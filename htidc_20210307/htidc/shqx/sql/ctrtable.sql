//sqlplus scott/liyupeng66@snorcl11g_192.168.65.128 @ctrtable.sql 自动运行

/*==============================================================*/
/* DBMS name:      ORACLE Version 9i2                           */
/* Created on:     2020/12/31 23:10:52                          */
/*==============================================================*/


drop table T_OBTCODE cascade constraints;

drop index IDX_SURFDATA_3;

drop index IDX_SURFDATA_2;

drop index IDX_SURFDATA_1;

drop table T_SURFDATA cascade constraints;

/*==============================================================*/
/* Table: T_OBTCODE                                             */
/*==============================================================*/
alter table T_OBTCODE
   drop primary key cascade;
create table T_OBTCODE  (
   obtid              char(5)                         not null,
   obtname            varchar2(30)                    not null,
   provname           varchar2(30)                    not null,
   lat                number(8,2),
   lon                number(8,2),
   height             number(8,2),
   rsts               number(1)                      default 1 not null
      constraint CKC_RSTS_T_OBTCOD check (rsts in (1,2,3)),
   constraint PK_OBTCODE primary key (obtid)
);

comment on table T_OBTCODE is
'该表存放了全国气象站点参数，2020年12月有839个站点。';

comment on column T_OBTCODE.obtid is
'站点代码';

comment on column T_OBTCODE.obtname is
'站点名称，一般用城市名称';

comment on column T_OBTCODE.provname is
'所属省，采用省的简称';

comment on column T_OBTCODE.lat is
'纬度';

comment on column T_OBTCODE.lon is
'经度';

comment on column T_OBTCODE.height is
'高度，指气压传感器的安装的海拔高度';

comment on column T_OBTCODE.rsts is
'状态 1-正常 2-禁用 3-故障';

/*==============================================================*/
/* Table: T_SURFDATA                                            */
/*==============================================================*/
alter table T_SURFDATA
   drop primary key cascade;
drop sequence SEQ_SURFDATA;
create sequence SEQ_SURFDATA minvalue 1;
create table T_SURFDATA  (
   obtid              char(5)                         not null,
   ddatetime          date                            not null,
   t                  number(6),
   p                  number(6),
   u                  number(6),
   wd                 number(6),
   wf                 number(6),
   r                  number(6),
   vis                number(6),
   crttime            date                           default sysdate not null,
   keyid              number(6)                       not null,
   constraint PK_SURFDATA primary key (obtid, ddatetime)
);

comment on table T_SURFDATA is
'该表存放了全国气象站点测试数据';

comment on column T_SURFDATA.obtid is
'站点代码';

comment on column T_SURFDATA.ddatetime is
'数据时间';

comment on column T_SURFDATA.t is
'空气温度，单位，0.1摄氏度';

comment on column T_SURFDATA.p is
'本站气压，0.1百帕';

comment on column T_SURFDATA.u is
'相对湿度，0-100之间的值';

comment on column T_SURFDATA.wd is
'风向，0-360之间的值';

comment on column T_SURFDATA.wf is
'风速，单位0.1m/s';

comment on column T_SURFDATA.r is
'降水，0.1mm';

comment on column T_SURFDATA.vis is
'能见度，0.1米';

comment on column T_SURFDATA.crttime is
'入库时间,default sysdate';

comment on column T_SURFDATA.keyid is
'记录序号，从SEQ_SURFDATA中获取';

/*==============================================================*/
/* Index: IDX_SURFDATA_1                                        */
/*==============================================================*/
create unique index IDX_SURFDATA_1 on T_SURFDATA (
   keyid ASC
);

/*==============================================================*/
/* Index: IDX_SURFDATA_2                                        */
/*==============================================================*/
create index IDX_SURFDATA_2 on T_SURFDATA (
   obtid ASC
);

/*==============================================================*/
/* Index: IDX_SURFDATA_3                                        */
/*==============================================================*/
create index IDX_SURFDATA_3 on T_SURFDATA (
   ddatetime ASC
);


