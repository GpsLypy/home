#########################################
# 请注意，编译时，确定以下几点：
# 1、已安装oracle的客户端或oracle服务端程序，并且必须安装好OCI软件包
# 2、设置好ORACLE_HOME环境变量
#
#########################################

# oracle头文件路径
ORAINCL = -I$(ORACLE_HOME)/rdbms/public

# oracle库文件路径
ORALIB =  -L$(ORACLE_HOME)/lib -L.

# oracle的oci库
ORALIBS = -lclntsh

# 通用框架头文件路径
PUBINCL = -I/htidc/public/c

# 通用框架库文件路径
PUBCPP = /htidc/public/c/_public.cpp 
FTPCPP = /htidc/public/c/_ftp.cpp 
OCICPP = /htidc/public/c/_ooci.cpp

CC=g++

# CFLAGS = -O2
# CFLAGS = -O2 -Wall

CFLAGS = -g -Wno-write-strings -Wno-unused-variable


all:crtsurfdat psurfdata psignallog ptydata wgetrain24 wgettemp24  pzhrain24file jsonn jsonn1 jsonn2 jsonn3 pjsondata prfccdata



jsonn:jsonn.c _shqx.h _shqx.cpp 
	$(CC) $(CFLAGS) -o jsonn jsonn.c $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) _shqx.cpp cJSON.c  -lm -lc
	cp -f jsonn ../bin/.

prfccdata:prfccdata.cpp _shqx.h _shqx.cpp 
	$(CC) $(CFLAGS) -o prfccdata prfccdata.cpp $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) _shqx.cpp   -lm -lc
	cp -f prfccdata ../bin/.
pjsondata:pjsondata.c _shqx.h _shqx.cpp 
	$(CC) $(CFLAGS) -o pjsondata pjsondata.c $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) _shqx.cpp cJSON.c  -lm -lc
	cp -f pjsondata ../bin/.
jsonn3:jsonn3.c _shqx.h _shqx.cpp 
	$(CC) $(CFLAGS) -o jsonn3 jsonn3.c $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) _shqx.cpp cJSON.c  -lm -lc
	cp -f jsonn3 ../bin/.
jsonn2:jsonn2.c _shqx.h _shqx.cpp 
	$(CC) $(CFLAGS) -o jsonn2 jsonn2.c $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) _shqx.cpp cJSON.c  -lm -lc
	cp -f jsonn2 ../bin/.

jsonn1:jsonn1.c _shqx.h _shqx.cpp
	$(CC) $(CFLAGS) -o jsonn1 jsonn1.c $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) _shqx.cpp cJSON.c  -lm -lc
	cp -f jsonn1 ../bin/.

crtsurfdat:crtsurfdat.cpp _shqx.h _shqx.cpp
	$(CC) $(CFLAGS) -o crtsurfdat crtsurfdat.cpp $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) _shqx.cpp -lm -lc
	cp -f crtsurfdat ../bin/.

crtsurfdate_1:crtsurfdate_1.cpp _shqx.h _shqx.cpp
	$(CC) $(CFLAGS) -o crtsurfdate_1 crtsurfdate_1.cpp $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) _shqx.cpp -lm -lc
	cp -f crtsurfdate_1 ../bin/.

psurfdate_old: psurfdate_old.cpp 
	$(CC) $(CFLAGS) -o psurfdate_old psurfdate_old.cpp $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) -lm -lc
	cp -f psurfdate_old ../bin/.

psurfdata: psurfdata.cpp _shqx.h _shqx.cpp
	$(CC) $(CFLAGS) -o psurfdata psurfdata.cpp $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) _shqx.cpp -lm -lc
	cp -f psurfdata ../bin/.

ptydata:ptydata.cpp _shqx.h _shqx.cpp
	$(CC) $(CFLAGS) -o ptydata ptydata.cpp $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) _shqx.cpp -lm -lc
	cp -f ptydata ../bin/.



pzhrain24file: pzhrain24file.cpp _shqx.h _shqx.cpp
	$(CC) $(CFLAGS) -o pzhrain24file pzhrain24file.cpp $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) _shqx.cpp -lm -lc
	cp -f pzhrain24file ../bin/.

psurfdate_1: psurfdate_1.cpp _shqx.h _shqx.cpp
	$(CC) $(CFLAGS) -o psurfdate_1 psurfdate_1.cpp $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) _shqx.cpp -lm -lc
	cp -f psurfdate_1 ../bin/.

psignallog: psignallog.cpp _shqx.h _shqx.cpp
	$(CC) $(CFLAGS) -o psignallog psignallog.cpp $(ORAINCL) $(ORALIB) $(ORALIBS) $(PUBINCL) $(PUBCPP) $(OCICPP) _shqx.cpp -lm -lc
	cp -f psignallog ../bin/.

wgetrain24: wgetrain24.cpp 
	$(CC) $(CFLAGS) -o wgetrain24 wgetrain24.cpp $(PUBINCL) $(PUBCPP) -lm -lc
	cp -f wgetrain24 ../bin/.

wgettemp24: wgetrain24.cpp 
	$(CC) $(CFLAGS) -o wgettemp24 wgettemp24.cpp $(PUBINCL) $(PUBCPP) -lm -lc
	cp -f wgettemp24 ../bin/.


clean:
	rm -rf crtsurfdat crtsurfdate_1 psurfdate_old psurfdata psurfdate_1 psignallog wgetrain24
	rm -rf wgettemp24 pzhrain24file pjsondata jsonn jsonn1

