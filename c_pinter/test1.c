#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>
#pragma warning(disable:4996)

void *My_memcopy(void *dst, void *src, size_t num){
	assert(dst);
	assert(src);
	void *ret = dst;
	const char *src_p = (char *)src;
	char *dst_p = (char *)dst;
	while(num--){
		*dst_p = *src_p;
		dst_p++, src_p++;
	}
	return ret;
}

void *My_memmove(void *dst, void *src, size_t num)
{
	assert(dst);
	assert(src);
	void *ret = dst;
	const char *src_p = (char *)src;
	char *dst_p = (char *)dst;
	if (src_p<dst_p&&src_p + num>dst_p){
		//从右向左
		src_p = src_p + num - 1;
		dst_p = dst_p + num - 1;
		while (num){
			*dst_p = *src_p;
			dst_p--, src_p--;
			num--;
		}
	}
	else{
		//从左向右
		while (num){
			*dst_p = *src_p;
			dst_p++, src_p++;
			num--;
		}
	}
	return ret;

}


int main()
{
	const char *src_str = "1234567";
	char dst_str[128]="abcdefghijk";
	//My_memcopy(dst_str, src_str, strlen(src_str) + 1);
	My_memmove(dst_str, src_str, strlen(src_str)+1);
	printf("%s\n", dst_str);

	system("pause");
	return 0;
}





//void Reverse(char *str, int start, int end){
//	while (start<end){
//		char temp = str[start];
//		str[start] = str[end];
//		str[end] = temp;
//		start++, end--;
//	}
//}
//
//void LeftRoate(char *str, int len, int num){
//	assert(str);
//	assert(len > 0);
//	assert(num >= 0);
//
//	num %= len; //去重
//	Reverse(str, 0, num - 1);
//	Reverse(str, num, len - 1);
//	Reverse(str, 0, len - 1);
//
//	//while (num){
//	//	char temp = str[0];
//	//	int i = 0;
//	//	for (; i < len - 1; i++){
//	//		str[i] = str[i + 1];
//	//	}
//	//	str[i] = temp;
//	//	num--;
//	//}
//
//
//}
//
//int Find(int a[][5], int row, int col, int target){
//	//查找的本质：排除的过程
//	//从右上角开始比较，每次排除一行或者一列
//
//	int i = 0;
//	int j = col - 1;
//	while (i < row&&j < col){
//		if (target < a[i][j]){
//			j--;
//		}
//		else if (target>a[i][j]){
//			i++;
//		}
//		else{
//			return 1;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	//杨氏矩阵查找问题
//	int a[][5] = {
//		{1, 2, 3, 4, 5},
//		{7, 8, 9, 10,11},
//		{12,13,14,15,16}
//	};
//	int x = 13;
//	int ret = Find(a, 3, 5, x);
//	printf("1:exist  -1:no :\n %d\n", ret);
//	//字符串的任意次数左旋
//	//char str1[] = "1234abcd";
//	//char str2[] = "abcd1234";
//	//int len = strlen(str1);
//	//int num = 3;
//	//printf("before: %s\n", str1);
//	//LeftRoate(str1, len, 6);
//	//printf("%s\n", str1);
//	
//	
//	//方法一：依次移动
//	//int i = 0;
//	//for (; i < len; i++){
//	//	if (strcmp(str1, str2) == 0){
//	//		printf("yes\n");
//	//		break;
//	//	}
//	//	LeftRoate(str1, len, 1);
//	//}
//	//if (i == len){
//	//	printf("no\n");
//	//}
//	//printf("%s\n", str1);
//	
//
//	//双倍串判定旋转问题
//	//char *double_string = (char *)malloc(2 * len + 1);
//	//if (double_string == NULL){
//	//	//判定开辟空间是否成功
//	//	return -1;
//	//}
//	//strcpy(double_string, str1);
//	//strcat(double_string, str1);
//	//printf("double_string is: %s\n", double_string);
//	//if (strstr(double_string, str2) != NULL){
//	//	printf("Yes!\n");
//	//}
//	//else{
//	//	printf("No!\n");
//	//}
//	//free(double_string);
//
//	//const char *src_str = "12345";
//	//char dst_str[32] = "abcdef";
//	//strcat(dst_str, src_str);
//	//printf("%s\n", dst_str);
//	//printf("%d\n", strcmp(dst_str, src_str));
//	//printf("%s\n", strcpy(dst_str, src_str));
//
//	system("pause");
//	return 0;
//}