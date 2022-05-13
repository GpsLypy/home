#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"


int main(){
//char* json_string ="{\"test_1\":\"0\", \"test_2\":\"1\",\"test_3\":\"2\"}";
//char* json_string ="{"test_1":0,"test_2":1,"test_3":2}";
char* json_string ="1\"w\"2";
//JSON字符串到cJSON格式
cJSON* cjson = cJSON_Parse(json_string); 
//判断cJSON_Parse函数返回值确定是否打包成功
if(cjson == NULL){
printf("json pack into cjson error...");
}
//else{//打包成功调用cJSON_Print打印输出

//cJSON_Print(cjson);
//}
 
//获取字段值
//cJSON_GetObjectItem返回的是一个cJSON结构体所以我们可以通过函数返回结构体的方式选择返回类型！
cJSON* test_1_string = cJSON_GetObjectItem(cjson,"w");
//char* test_2_string = cJSON_GetObjectItem(cjson,"test_2")->valuestring;
//char* test_3_string = cJSON_GetObjectItem(cjson,"test_3")->valuestring;
 
//打印输出
printf("%s",test_1_string->valuestring);
//printf("%s",*test_2_string);
//printf("%s",*test_3_string);
 
//delete cjson
cJSON_Delete(cjson);
 
}



/* 最基础的类型，无父层，无数组，只有单个对象 {关键字：键值，关键字：键值}
int main()
{
    cJSON *json,*json_name,*json_passwd,*json_num;
    char* out="{\"name\":\"fengxin\",\"passwd\":\"123\",\"num\":1}";
    
    //先将普通的json串处理成json对象，也就是所谓的创建json root的过程，
    json = cJSON_Parse(out); //解析成json形式
    
    //开始拿关键字，但如果关键字还有父层或者祖层，那就需要先从父层开拿,此例是没有父层的
    json_name = cJSON_GetObjectItem( json , "name" );  //获取键值内容
    json_passwd = cJSON_GetObjectItem( json , "passwd" );
    json_num = cJSON_GetObjectItem( json , "num" );
 
    printf("name:%s,passwd:%s,num:%d\n",json_name->valuestring,json_passwd->valuestring,json_num->valueint);
    cJSON_Delete(json);  //释放内存 

  //  free(out);
    return 0;
}

*/

/*
//有父层的，先拿父层 {父层关键字:{父层关键字1:键值1，父层关键字2: 键值2},子层关键字:{子层关键字1:键值1，子层关键字2：键值2}}

int main()
{
 char *s = "{\"list\":{\"name\":\"xiao hong\",\"age\":10},\"other\":{\"name\":\"hua hua\"}}";
 
 cJSON *root = cJSON_Parse(s);
 if(!root) 
 {
    printf("get root faild !\n");
    return -1;
 }
 
 cJSON *js_list = cJSON_GetObjectItem(root, "list");
 if(!js_list) {
    printf("no list!\n");
    return -1;
}
printf("list type is %d\n",js_list->type);

cJSON *name = cJSON_GetObjectItem(js_list, "name");
if(!name) {
    printf("No name !\n");
    return -1;
}
printf("name type is %d\n",name->type);
printf("name is %s\n",name->valuestring);
 
cJSON *age = cJSON_GetObjectItem(js_list, "age");
if(!age) {
    printf("no age!\n");
    return -1;
}
printf("age type is %d\n", age->type);
printf("age is %d\n",age->valueint);
 
cJSON *js_other = cJSON_GetObjectItem(root, "other");
if(!js_other) {
    printf("no other!\n");
    return -1;
}
printf("other type is %d\n",js_other->type);
 
cJSON *js_name = cJSON_GetObjectItem(js_other, "name");
if(!js_name) {
    printf("No name !\n");
    return -1;
}
printf("name type is %d\n",js_name->type);
printf("name is %s\n",js_name->valuestring);
 
if(root)
    cJSON_Delete(root);
    return 0;

}

*/

/*
//带数组的json
int main(int argc, char **argv)
{
char *s = "{\"list\":[\"name1\",\"name2\"]}";
cJSON *root = cJSON_Parse(s);
if(!root) {
    printf("get root faild !\n");
    return -1;
}
cJSON *js_list = cJSON_GetObjectItem(root, "list");
if(!js_list){
    printf("no list!\n");
    return -1;
}

//获取里面数组大小
int array_size = cJSON_GetArraySize(js_list);
printf("array size is %d\n",array_size);

int i = 0;
cJSON *item;
for(i=0; i< array_size; i++) {
    item = cJSON_GetArrayItem(js_list, i);
    printf("item type is %d\n",item->type);
    printf("%s\n",item->valuestring);
}
 
if(root)
    cJSON_Delete(root);
    return 0;
}

*/


//如果json数组里面又搞了对象怎么办

//<1> 既然是数组里面，那肯定要先测量数组的大小，然后根据大小循环拿；

//<2> 拿到一个数组项，然后把这个项先转化成普通的json字符串，也就是 char *s 能接受的。

//<3> 再次将这个json字符串，转化成一个json对象

//<4> 按照拿普通对象中的东西那样开干就行了。


//list 是一个数组，数组里面有两个对象

/*
int main(int argc, char **argv)
{
char *s = "{\"list\":[{\"name\":\"xiao hong\",\"age\":10},{\"name\":\"hua hua\",\"age\":11}]}";
cJSON *root = cJSON_Parse(s);
if(!root) {
    printf("get root faild !\n");
    return -1;
}

cJSON *js_list = cJSON_GetObjectItem(root, "list");
if(!js_list){
    printf("no list!\n");
    return -1;
}

int array_size = cJSON_GetArraySize(js_list);
printf("array size is %d\n",array_size);

int i = 0;
cJSON *item,*it, *js_name, *js_age;
char *p  = NULL;
for(i=0; i< array_size; i++) {
    item = cJSON_GetArrayItem(js_list, i);//根据list先拿第一个对象
    if(!item) 
    {
     printf("failed!\n");
     return -1;
    }
 
  //  p = cJSON_PrintUnformatted(item);
    //it = cJSON_Parse(p);
    //if(!it)  continue ;

    js_name = cJSON_GetObjectItem(item, "name");
    printf("name is %s\n",js_name->valuestring);
    js_age = cJSON_GetObjectItem(item, "age");
    printf("age is %d\n",js_age->valueint);
 
}
 
if(root)
    cJSON_Delete(root);
    return 0;
}

*/

/*
int main(int argc, char **argv)
{

char *s = "{\"w\":[{\"w1\":\"山东省\",\"w2\":\"烟台市\",\"w3\":\"莱州市\",\"w4\":\"09\",\"w5\":\"雷电\",\"w7\":\"黄色\",\"w6\":\"02\",\"w8\":\"2019-07-08 06:15\",\"w9\":\"莱州市气象局2019年07月08日06时15分解除雷电黄色预警信号。目前我市已无雷电活动。\",\"w10\":\"37068341600000_20190708061529\",\"w11\":\"http:\/\/370683-20190708061500-11B1402.html\"}]}";

//char *s = "{"w":[{"w1":"山东省","w2":"烟台市","w3":"莱州市"}]}";
//char *s = "{\"w\":[{\"w1\":\"山东省\",\"w2\":\"烟台市\",\"w3\":\"莱州市\",\"w4\":\"09\"}]}";
cJSON *root = cJSON_Parse(s);
if(!root) {
    printf("get root faild !\n");
    return -1;
}
cJSON *js_w = cJSON_GetObjectItem(root, "w");
if(!js_w){
    printf("no w!\n");
    return -1;
}
int array_size = cJSON_GetArraySize(js_w);
printf("array size is %d\n",array_size);
int i = 0;
cJSON *item,*it,*js_w1,*js_w2,*js_w3,*js_w4,*js_w5,*js_w6,*js_w7,*js_w8,*js_w9,*js_w10,*js_w11;
char *p  = NULL;
for(i=0; i< array_size; i++) {
    item = cJSON_GetArrayItem(js_w, i);
    if(!item) {
        //TODO...
    }
    p = cJSON_PrintUnformatted(item);
    it = cJSON_Parse(p);
    if(!it)
        continue ;
    js_w1 = cJSON_GetObjectItem(it, "w1");
    printf("w1 is %s\n",js_w1->valuestring);
    js_w2 = cJSON_GetObjectItem(it, "w2");
    printf("w2 is %s\n",js_w2->valuestring);
    js_w3 = cJSON_GetObjectItem(it, "w3");
    printf("w3 is %s\n",js_w3->valuestring);
    js_w4 = cJSON_GetObjectItem(it, "w4");
    printf("w4 is %s\n",js_w4->valuestring);
    js_w5 = cJSON_GetObjectItem(it, "w5");
    printf("w5 is %s\n",js_w5->valuestring);
    js_w6 = cJSON_GetObjectItem(it, "w6");
    printf("w6 is %s\n",js_w6->valuestring);

    js_w7 = cJSON_GetObjectItem(it, "w7");
    printf("w7 is %s\n",js_w7->valuestring);
    js_w8 = cJSON_GetObjectItem(it, "w8");
    printf("w8 is %s\n",js_w8->valuestring);

    js_w9 = cJSON_GetObjectItem(it, "w9");
    printf("w9 is %s\n",js_w9->valuestring);

    js_w10 = cJSON_GetObjectItem(it, "w10");
    printf("w10 is %s\n",js_w10->valuestring);
    js_w11 = cJSON_GetObjectItem(it, "w11");
    printf("w11 is %s\n",js_w11->valuestring);
}
 
if(root)
    cJSON_Delete(root);
    return 0;
}

*/
