#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"


int main(){
//char* json_string ="{\"test_1\":\"0\", \"test_2\":\"1\",\"test_3\":\"2\"}";
//char* json_string ="{"test_1":0,"test_2":1,"test_3":2}";
char* json_string ="1\"w\"2";
//JSON�ַ�����cJSON��ʽ
cJSON* cjson = cJSON_Parse(json_string); 
//�ж�cJSON_Parse��������ֵȷ���Ƿ����ɹ�
if(cjson == NULL){
printf("json pack into cjson error...");
}
//else{//����ɹ�����cJSON_Print��ӡ���

//cJSON_Print(cjson);
//}
 
//��ȡ�ֶ�ֵ
//cJSON_GetObjectItem���ص���һ��cJSON�ṹ���������ǿ���ͨ���������ؽṹ��ķ�ʽѡ�񷵻����ͣ�
cJSON* test_1_string = cJSON_GetObjectItem(cjson,"w");
//char* test_2_string = cJSON_GetObjectItem(cjson,"test_2")->valuestring;
//char* test_3_string = cJSON_GetObjectItem(cjson,"test_3")->valuestring;
 
//��ӡ���
printf("%s",test_1_string->valuestring);
//printf("%s",*test_2_string);
//printf("%s",*test_3_string);
 
//delete cjson
cJSON_Delete(cjson);
 
}



/* ����������ͣ��޸��㣬�����飬ֻ�е������� {�ؼ��֣���ֵ���ؼ��֣���ֵ}
int main()
{
    cJSON *json,*json_name,*json_passwd,*json_num;
    char* out="{\"name\":\"fengxin\",\"passwd\":\"123\",\"num\":1}";
    
    //�Ƚ���ͨ��json�������json����Ҳ������ν�Ĵ���json root�Ĺ��̣�
    json = cJSON_Parse(out); //������json��ʽ
    
    //��ʼ�ùؼ��֣�������ؼ��ֻ��и��������㣬�Ǿ���Ҫ�ȴӸ��㿪��,������û�и����
    json_name = cJSON_GetObjectItem( json , "name" );  //��ȡ��ֵ����
    json_passwd = cJSON_GetObjectItem( json , "passwd" );
    json_num = cJSON_GetObjectItem( json , "num" );
 
    printf("name:%s,passwd:%s,num:%d\n",json_name->valuestring,json_passwd->valuestring,json_num->valueint);
    cJSON_Delete(json);  //�ͷ��ڴ� 

  //  free(out);
    return 0;
}

*/

/*
//�и���ģ����ø��� {����ؼ���:{����ؼ���1:��ֵ1������ؼ���2: ��ֵ2},�Ӳ�ؼ���:{�Ӳ�ؼ���1:��ֵ1���Ӳ�ؼ���2����ֵ2}}

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
//�������json
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

//��ȡ���������С
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


//���json���������ָ��˶�����ô��

//<1> ��Ȼ���������棬�ǿ϶�Ҫ�Ȳ�������Ĵ�С��Ȼ����ݴ�Сѭ���ã�

//<2> �õ�һ�������Ȼ����������ת������ͨ��json�ַ�����Ҳ���� char *s �ܽ��ܵġ�

//<3> �ٴν����json�ַ�����ת����һ��json����

//<4> ��������ͨ�����еĶ����������ɾ����ˡ�


//list ��һ�����飬������������������

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
    item = cJSON_GetArrayItem(js_list, i);//����list���õ�һ������
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

char *s = "{\"w\":[{\"w1\":\"ɽ��ʡ\",\"w2\":\"��̨��\",\"w3\":\"������\",\"w4\":\"09\",\"w5\":\"�׵�\",\"w7\":\"��ɫ\",\"w6\":\"02\",\"w8\":\"2019-07-08 06:15\",\"w9\":\"�����������2019��07��08��06ʱ15�ֽ���׵��ɫԤ���źš�Ŀǰ���������׵���\",\"w10\":\"37068341600000_20190708061529\",\"w11\":\"http:\/\/370683-20190708061500-11B1402.html\"}]}";

//char *s = "{"w":[{"w1":"ɽ��ʡ","w2":"��̨��","w3":"������"}]}";
//char *s = "{\"w\":[{\"w1\":\"ɽ��ʡ\",\"w2\":\"��̨��\",\"w3\":\"������\",\"w4\":\"09\"}]}";
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
