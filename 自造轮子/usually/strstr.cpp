#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#include <string.h>

//父进程fork()之后返回值为子进程的pid号，而子进程fork()之后的返回值为0
//"acde" "ca"
char *Strstr(const char* str,const char* substr){
    assert(str);
    assert(substr);
    const char* start=str;
    const char* str_p=str;
    const char* sub_p=substr;
    while(*start){
        str_p=start;
        sub_p=substr;
        while( *str_p != '\0' && *sub_p != '\0'){
            if(*str_p==*sub_p){
                str_p++;
                sub_p++;
            }
            else{
               break;
            }
        }

        if(*sub_p=='\0'){
            return (char*)start;
        }
        start++;
    }
    return NULL;
}




int main(){
   
	//char str[] = "abbbbcdef";
    char str[] = "acde";
	char *p ;
	p = Strstr(str, "ca");
	if(p) printf("%s\n", p);
	//system("pause");
	return 0;

}

