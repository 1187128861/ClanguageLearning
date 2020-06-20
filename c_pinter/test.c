#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)


void * My_memcpy(void * dst, const void * src, size_t count)
{
	void * ret = dst;
	assert(dst);
	assert(src);
	while (count--) {
		*(char *)dst = *(char *)src;
		dst = (char *)dst + 1;
		src = (char *)src + 1;
	}

	return(ret);
}

int main()
{
	char *str = "hello bit come on";
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	char dst[] = "good good study";
	My_memcpy(dst, arr, 6);
	//memcpy(dst, str, 6);
	printf("%s\n", dst);
	system("pause");
	return 0;
}


//int My_strstr(char *p1, char *p2){
//	char *tmp = p2;
//	int num = 0;
//	int index = 0;
//	while (*p2 != '\0'){
//		num++, p2++;
//	}
//	while (*p1 != '\0'){
//		if (*p1 == *p2){
//			index++;
//			if (index == num){
//				return 1;
//			}
//			p1++, p2++;
//		}
//		else{
//			index = 0;
//			p2 = tmp;
//			if (*p1 == *p2){
//				p1++, p2++;
//			}
//			else{
//				p1++;
//			}
//		}
//	}
//	return -1;
//
//}
//
//int main()
//{
//	char *str = "good study day up 1234";
//	int num = My_strstr(str, "p 12");
//	if (num > 0){
//		printf("yes!\n");
//	}
//	else{
//		printf("no!\n");
//	}
//	system("pause");
//	return 0;
//}
//
//

//int My_strlen(char *_str){
//	int i = 0;
//	while (*_str != '\0'){
//		_str++,i++;
//	}
//	return i;
//}
//
//int main()
//{
//	char *str = "hellobit";
//	int size = My_strlen(str);
//	printf("the length of the string is %d\n", size);
//
//	system("pause");
//	return 0;
//}




//void My_strcpy(char _dst[],char _str[]){
//	int i = 0;
//	while (_str[i] != '\0'){
//		_dst[i] = _str[i];
//		i++;
//	}
//	_dst[i] = '\0';
//}
//
//int main()
//{
//	char str[] = "hellooo";
//	char dst[20] = "goddddddd";
//	My_strcpy(dst, str);
//	//strcpy(dst, str);
//	printf("%s\n", dst);
//
//	system("pause");
//	return 0;
//}




int My_strcmp1(char *p1, char *p2, int _num){
	for (int i = 0; i < _num; i++){
		if (*p1 > *p2){
			return 1;
		}
		else if (*p1 < *p2){
			return -1;
		}
		else{
			if (i == _num - 1){
				return 0;
			}
			p1++, p2++;
		}

	}
}

//int My_strcmp(char *p1, char *p2){
//
//	while (*p1 != '\0'||*p2 != '\0'){
//		if (*p1 > *p2){
//			return 1;
//		}
//		else if (*p1 < *p2){
//			return -1;
//		}
//		else{
//			p1++, p2++;
//		}
//	}
//	if (*p1 == '\0'&&*p2 != '\0'){
//		return -1;
//	}
//	else if (*p1 != '\0'&&*p2 == '\0'){
//		return 1;
//	}
//	else{
//		return 0;
//	}
//}
//
//int main()
//{
//	char *str1 = "hello";
//	char *str2 = "hellA";
//	//int num = strlen(str1) > strlen(str2) ? strlen(str1) : strlen(str2);
//	//int index = My_strcmp(str1, str2, num);
//	int index = My_strcmp(str1, str2);
//	if (index > 0){
//		printf("str1 > str2\n");
//	}
//	else if (index < 0){
//		printf("str1 < str2\n");
//	}
//	else{
//		printf("str1 == str2\n");
//	}
//
//	system("pause");
//	return 0;
//}





//×Ö·û´®Æ´½Ó

//void My_strcat(char p1[], char p2[], int n1, int n2){
//	for (int i = 0; i <= n1; i++){
//		p2[n2 + i] = p1[i];
//	}
//}

//void My_strcat(char p1[], char p2[]){
//	int i = 0;
//	int j = 0;
//	while (p1[i] != '\0'){
//		i++;
//	}
//	while (p2[j] != '\0'){
//		p1[i] = p2[j];
//		i++, j++;
//	}
//	p1[i] = '\0';
//}
//
//int main()
//{
//	char str[10] = "";
//	char dst[30] = "";
//	printf("please enter two string<len1<len2>: \n");
//	gets(str);
//	gets(dst);
//	//My_strcat(str,dst,strlen(str),strlen(dst));
//	My_strcat(dst, str);
//	printf("%s\n", dst);
//	system("pause");
//	return 0;
//}