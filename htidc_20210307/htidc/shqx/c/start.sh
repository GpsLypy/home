#���ű����������Ϻ������������ķ������

#����ȫ������վ���������ļ�
#/htidc/shqx/bin/crtsurfdat /htidc/shqx/ini/stcode.ini /data/shqx/ftp/surfdata /log/shqx/crtsurfdata.log &

#����ɾ��ȫ������վ���������ļ�,�˳�������crontab -e �е���
#/htidc/public/bin/deletefiles /data/shqx/ftp/surfdata 0.1 "*.TXT,*.CSV"

#�ɼ�ȫ������վ���������ļ�
#/htidc/public/bin/ftpgetfiles /log/shqx/ftpgetfiles_surfdata.log "<host>192.168.65.130:21</host><port>21</port><mode>1</mode><username>oracle</username><password>liyupeng66</password><localpath>/data/shqx/sdata/surfdata</localpath><remotepath>/data/shqx/ftp/surfdata</remotepath><matchname>SURF_*.TXT,*.DAT</matchname><ptype>1</ptype><remotepathbak></remotepathbak><listfilename>/data/shqx/ftplist/ftpgetfiles_surfdata.list</listfilename><okfilename>/data/shqx/ftplist/ftpgetfiles_surfdata.xml</okfilename><timetvl>30</timetvl>" &

#����ȫ������վ���������ļ������
#/htidc/shqx/bin/psurfdata /data/shqx/sdata/surfdata /log/shqx/psurfdata.log shtqapp/pwdidc  10 &

#/htidc/shqx/bin/psurfdata1 /data/shqx/sdata/surfdata /log/shqx/psurfdata1.log  shtqapp/pwdidc 10 &

#����T_SURFDATA����0.2��֮ǰ������
/htidc/public/bin/deletetables "<logfilename>/log/shqx/deletetables_SURFDATA.log</logfilename><connstr>shtqapp/pwdidc</connstr><tname>T_SURFDATA</tname><where>where ddatetime<sysdate-0.2</where><hourstr>00,02,04,06,08,10,12,14,15,16,17,18</hourstr>" &

#���й���������ȡÿСʱ��ʵ������ͼ
#/htidc/public/bin/wgetrain24 /log/shqx/wgetrain24.log /data/wgettmp /data/wfile/zhrain24 &
#���й���������ȡÿСʱ��ʵ���¶�ͼ
#/htidc/public/bin/wgettemp24 /log/shqx/wgetrain24.log /data/wgettmp /data/wfile/zhtemp24 &

#���ڴ���ȫ����Сʱ��������ʵ��ͼƬ
#/htidc/shqx/bin/pzhrain24file /log/shqx/pzhrain24file.log  girla/girlpwdaa@Tencent11g_49.232.185.49 /data/wfile/zhrain24 /data/qxfile/zhrain24 T_ZHRAIN24 30

# /data/wfile/zhrain24��/data/wfile/zhtem24Ŀ¼�µ�����ǰ���ļ�Ҫ����ɾ��
