//sqlplus scott/liyupeng66@snorcl11g_192.168.65.128 @ctrtable.sql �Զ�����

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
'�ñ�����ȫ������վ�������2020��12����839��վ�㡣';

comment on column T_OBTCODE.obtid is
'վ�����';

comment on column T_OBTCODE.obtname is
'վ�����ƣ�һ���ó�������';

comment on column T_OBTCODE.provname is
'����ʡ������ʡ�ļ��';

comment on column T_OBTCODE.lat is
'γ��';

comment on column T_OBTCODE.lon is
'����';

comment on column T_OBTCODE.height is
'�߶ȣ�ָ��ѹ�������İ�װ�ĺ��θ߶�';

comment on column T_OBTCODE.rsts is
'״̬ 1-���� 2-���� 3-����';

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
'�ñ�����ȫ������վ���������';

comment on column T_SURFDATA.obtid is
'վ�����';

comment on column T_SURFDATA.ddatetime is
'����ʱ��';

comment on column T_SURFDATA.t is
'�����¶ȣ���λ��0.1���϶�';

comment on column T_SURFDATA.p is
'��վ��ѹ��0.1����';

comment on column T_SURFDATA.u is
'���ʪ�ȣ�0-100֮���ֵ';

comment on column T_SURFDATA.wd is
'����0-360֮���ֵ';

comment on column T_SURFDATA.wf is
'���٣���λ0.1m/s';

comment on column T_SURFDATA.r is
'��ˮ��0.1mm';

comment on column T_SURFDATA.vis is
'�ܼ��ȣ�0.1��';

comment on column T_SURFDATA.crttime is
'���ʱ��,default sysdate';

comment on column T_SURFDATA.keyid is
'��¼��ţ���SEQ_SURFDATA�л�ȡ';

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


