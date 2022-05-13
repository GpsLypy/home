#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
 
int read_file(const char* filename, char** content)
{
	// open in read binary mode
	FILE* file = fopen(filename, "rb");
	if (file == NULL) {
		fprintf(stderr, "read file fail: %s\n", filename);
		return -1;
	}
 
	// get the length
	fseek(file, 0, SEEK_END);
	long length = ftell(file);
	fseek(file, 0, SEEK_SET);
 
	// allocate content buffer
	*content = (char*)malloc((size_t)length + sizeof(""));
 
	// read the file into memory
	size_t read_chars = fread(*content, sizeof(char), (size_t)length, file);
	if ((long)read_chars != length) {
		fprintf(stderr, "length dismatch: %d, %d\n", read_chars, length);
		free(*content);
		return -1;
	}
	(*content)[read_chars] = '\0';
 
	fclose(file);
	return 0;
}


int main()
   {
      const char* filename = "/tmp/json.data1";

      char *json = NULL;
      if (read_file(filename, &json) != 0) return -1;;
      if ((json == NULL) || (json[0] == '\0') || (json[1] == '\0')) 
       {
	  fprintf(stderr, "file content is null\n");
          return -1;
	}
 
      cJSON* root = cJSON_Parse(json);

      cJSON *js_w = cJSON_GetObjectItem(root, "w");

      if(!js_w)
       {
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
      //p = cJSON_PrintUnformatted(item);
      //it = cJSON_Parse(p);
      //if(!it)
      //  continue ;
      js_w1 = cJSON_GetObjectItem(item, "w1");
      printf("w1 is %s\n",js_w1->valuestring);
      js_w2 = cJSON_GetObjectItem(item, "w2");
      printf("w2 is %s\n",js_w2->valuestring);
      js_w3 = cJSON_GetObjectItem(item, "w3");
      printf("w3 is %s\n",js_w3->valuestring);
      js_w4 = cJSON_GetObjectItem(item, "w4");
      printf("w4 is %s\n",js_w4->valuestring);
      js_w5 = cJSON_GetObjectItem(item, "w5");
      printf("w5 is %s\n",js_w5->valuestring);
      js_w6 = cJSON_GetObjectItem(item, "w6");
      printf("w6 is %s\n",js_w6->valuestring); 

 
      js_w7 = cJSON_GetObjectItem(item, "w7");
      printf("w7 is %s\n",js_w7->valuestring);
      js_w8 = cJSON_GetObjectItem(item, "w8");
      printf("w8 is %s\n",js_w8->valuestring);

      js_w9 = cJSON_GetObjectItem(item, "w9");
      printf("w9 is %s\n",js_w9->valuestring);

      js_w10 = cJSON_GetObjectItem(item, "w10");
       printf("w10 is %s\n",js_w10->valuestring);
      js_w11 = cJSON_GetObjectItem(item, "w11");
      printf("w11 is %s\n",js_w11->valuestring);

      if(root)
      cJSON_Delete(root);
      return 0;
}
 
}
