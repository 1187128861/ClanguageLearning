#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

void FindSingle(int a[], int num, int *x, int *y)
{
	assert(a);
	assert(num > 0);
	assert(x);
	assert(y);
	int result = a[0];
	for (int i = 0; i < num; i++){
		result ^= a[i];
	}

	int pos = 1;
	while (1){
		if (result & pos){
			break;
		}
		pos <<= 1;
	}
	*x = 0, *y = 0;

	for (int i = 0; i < num; i++){
		if (a[i] & pos){
			*x ^= a[i];
		}
		else{
			*y ^= a[i];
		}
	}
}


int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int num = sizeof(a) / sizeof(a[0]);
	int x = 0;
	int y = 0;
	FindSingle(a, num, &x, &y);
	printf("x = %d y = %d\n ", x, y);

	system("pause");
	return 0;
}





//strncpy默认不拷贝‘\0’


//char *my_strncat(char *dst, const char *src, int num)
//{
//	assert(dst);
//	assert(src);
//
//	char *tmp = dst;
//	while (*tmp){
//		tmp++;
//	}
//	int i = 0;
//	for (; i < num; i++){
//		*(tmp + i) = *(src+i);
//
//	}
//	*(tmp+i) = '\0';
//	return dst;
//}
//
//char *my_strncpy(char *dst, const char *src, int num)
//{
//	char *tmp = dst;
//	int i = 0;
//	for (; i < num; i++){
//		*(tmp + i) = *(src + i);
//	}
//	return dst;
//}
//
//int main()
//{
//	const char *str1 = "helloworld";
//	char str2[30] = "daydayup";
//	my_strncpy(str2, str1, strlen(str1)+1);
//	//my_strncat(str2, str1, 15);
//	printf("%s\n", str2);
//	system("pause");
//	return 0;
//}


//atoi的实现，字符串转数字
//int status = 0;
//int my_atoi(const char *str)
//{
//	assert(str);
//	int flag = 1;
//	long long result = 0;
//	int i = 0;
//	while (isspace(str[i])){
//		i++;
//	}
//	if (str[i] == '-'){
//		flag = -flag;
//		i++;
//	}
//	while (str[i]){
//		if (isdigit(str[i])){
//			result = result * 10 + flag*(str[i] - '0');
//			if (result > INT_MAX || result < INT_MIN){
//				status = 1;
//				break;
//			}
//		}
//		else{
//			status = 2;
//			break;
//		}
//		i++;
//	}
//
//	return (int)result;
//}
//
//int main()
//{
//	const char *str = "123213";
//	int res = my_atoi(str);
//	if (1 == status){
//		printf("值越界,截断结果为：%d\n", res);
//	}
//	else if (2 == status){
//		printf("存在字母，截断结果为：%d\n", res);
//	}
//	else{
//		printf("res = %d\n", res);
//	}
//
//	system("pause");
//	return 0;
//}


//struct a{
//	int num;
//	char arr[0];//利用柔性数组实现变长空间的数组开辟
//};
//
//struct array{
//	int num;
//	int *mem;  //指向变长的数组
//};
//
//int main()
//{
//	//方式2：
//	struct a *p = (struct a*)malloc(sizeof(struct a) + 100 * sizeof(char));
//	if (null == p){
//		perror("error: ");
//		return -1;
//	}
//	p->num = 100;
//	for (int i = 0; i < p->num; i++){
//		p->arr[i] = i;
//	}
//	free(p);
//
//
//	//在结构体中形成变长的数组：方式一：
//	struct array *arr = (struct array *)malloc(sizeof(struct array));
//	if (null == arr){
//		perror("error:");
//			return -1;
//	}
//
//	arr->num = 100;
//	arr->mem = (int *)malloc(arr->num*sizeof(int));
//	if (null == arr->mem){
//		perror("error:");
//		free(arr);
//		return -2;
//	}
//
//	//如何释放空间：释放由内向外，申请由外向内
//	free(arr->mem);
//	free(arr);
//
//
//	system("pause");
//	return 0;
//}