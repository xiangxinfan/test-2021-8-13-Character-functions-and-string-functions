#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//�����ص�
//�ص���ܴ����ַ����ַ����Ŀ⺯����ʹ�ú�ע������

//���ַ�������
//strlen
//���Ȳ������Ƶ��ַ�������
//strcpy
//strcat
//strcmp
//���������Ƶ��ַ�����������
//strncpy
//strncat
//strncmp
//�ַ�������
//strstr
//strtok
//������Ϣ����
//strerror
//�ַ�����
//�ڴ��������
//memcpy
//memmove
//memset
//memcmp

//ǰ��
//C�����ж��ַ����ַ����Ĵ������Ƶ��������C���Ա�����û���ַ������͵ģ��ַ���ͨ������ 
//�����ַ��� �л��� �ַ����� �С� �ַ������� ��������Щ���������޸ĵ��ַ�������

//��Щ������������ͷ�ļ�#include <string.h>

//��������

//strlen  (Get the length of a string.)
//size_t strlen( const char *string );

//�ַ�����'\0'��Ϊ�����ı�־��strlen�������ص������ַ�����'\0'ǰ����ֵ��ַ�������������\0��
//����ָ����ַ�������Ҫ��'\0'����
//ע�⺯���ķ���ֵΪsize_t�����޷��ŵģ��ص���״�  size_t == unsigned int
//ѧ��strlen������ģ��ʵ��



//#include <string.h>
//int main()
//{
//	int len = strlen("abcdef");
//	//abcdef\0;
//	printf("%d\n", len);
//	return 0;
//}

//int main()
//{
//	char arr[] = { 'a','b','c','d','e' };
//	int len = strlen(arr);
//	printf("%d\n", len);
//	//���������Ǹ����ֵ����Ϊa,b,c,d,e�ֱ��Ӧ��һ����ĸ����û��\0,����Ҳ�Ҳ���\0������
//	//�ͳ��ֵ������ֵ��
//	return 0;
//}

////�Լ���д����
//
////1.�������ķ���
////2.�ݹ�
////3.ָ�롪��ָ��
//
//#include <assert.h>
//int my_strlen(char* str)
//{
//	int count = 0;
//	assert(str != NULL);//��Ϊ����������ָ�룬����ͬ���ж�һ��ָ�����Ч��
//	//����Ҳ����д��assert(str);
//	while(*str != '\0')//����д��while(*str);
//	{
//		count++;
//		str++;//���ﻻ��*str�Ƕ��һ�٣��ѿ��ӷ�ƨ
//	}
//	return count;
//}
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n", len);
//
//	return 0;
//}



//#include <string.h>
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("hehe\n");
//	}
//	//3-6=(-3)
//	//����strlen�ķ������͵�size_t
//	//�Ǹ�unsigned,�޷��ŵ�����
//	//���Լ�����Ὣ-3�����޷����������Ծͳ�������
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}






//strcpy  (Copy a string.)

//char *strcpy( char *strDestination, const char *strSource );

//Դ�ַ���������'\0'����
//�ὫԴ�ַ����е�'\0'������Ŀ��ռ�
//Ŀ��ռ�����㹻����ȷ���ܴ��Դ�ַ���
//Ŀ��ռ����ɱ�
//ѧ��ģ��ʵ��


////�õ��Դ��������������һЩ
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "shaanxi";
//	strcpy(arr1, arr2);
//	//���������лὫarr2�е�\0ͬ������ȥ
// //��Ȼ������ȥҪ���ǵ�һ���ַ����Ĵ�С������������ֹ
//	printf("%s\n", arr1);
//	return 0;
//}

//�Լ�д����ʵ��

//#include <assert.h>
//char* my_strcpy(char* dest, char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*src != '\0')
//	{
//		//*dest = *src;
//		//dest++;
//		//src++;//�����������ֻ�ܽ���\0֮ǰ���ַ�Ū��ȥ
//
//
//		*dest++ = *src++;//��146��148�м򻯳���һ�У�
//		
//	}
//	*dest = *src;//�����'\0'
//}

////���߽����沿�ֺ�������ת��������ģ�
//char* my_strcpy(char* dest,const char* src)//��Ϊstrcpy�����о���const char*
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	//����srcָ����ַ�����destָ��Ŀռ䣬����\0
//	while (*dest++ = *src++)//������Ҳ��\0Ū��ȥ��
//	{
//		;
//	}
//	//����Ŀ�Ŀռ����ʼ��ַ
//	return ret;
//	//�����Լ����࣬���Ӽ��
//}
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "shannxi";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abcdefghi";
//
//	char* arr1 = "abcdefghi";
//	//Ҳ���������ӣ����ǳ����ַ��������ܸı���������ַ���
//
//	char arr2[] = { 'a','b','c' };
//	//���Ǵ����
//	//ԭ������arr2���Ҳ���\0�Ĵ���
//	return 0;
//}






//strcat   (Append a string.)

//char *strcat( char *strDestination, const char *strSource );

//Դ�ַ���������'\0'����
//Ŀ��ռ�������㹻�Ĵ���������Դ�ַ���������
//Ŀ��ռ�����޸�
//�ַ����Լ����Լ�׷�ӣ�����ǲ��Եģ�

//int main()
//{
//	char arr1[] = "hello";
//	char arr2[] = "world";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	//�����ǿ��׷�����ˣ����Ǳ�����
//	//����ԭ������ΪĿ��ռ䲻�������Խ�����
//	return 0;
//}

//int main()
//{
//	char arr1[30] = "hello";//�����Ͳ������Խ�������
//	char arr2[] = "world";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//int main()
//{
//	char arr1[] = "hello\0xxxxxxxxxxxxxxxxxxx";
//	char arr2[] = "world";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	//������Ȼ�Ǵ�arr1�е�\0����ʼ����׷��
//	return 0;
//}



////�Լ�д����ʵ��
//#include <assert.h>
//my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest);
//	assert(src);
//	//1.�ҵ�Ŀ���ַ�����'\0'
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//2.׷��
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[30] = "hello";
//	char arr2[] = "world";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}






//strcmp  (Compare strings.)

//int strcmp( const char *string1, const char *string2 );

//��׼�涨��
//��һ���ַ������ڵڶ����ַ������򷵻ش���0����
//��һ���ַ������ڵڶ����ַ������򷵻�0
//��һ���ַ���С�ڵڶ����ַ������򷵻�С��0����

//#include <stdio.h>
//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "sqwert";
//	//if ("abcdef" == "sqwert");//����д�ǲ��Եģ�Ҳû��������д��
//	int ret = strcmp(p1, p2);
//	printf("%d\n", ret);
//	return 0;
//}


//int main()
//{
//	char* p1 = "abc";
//	char* p2 = "qwe";
//	if (strcmp(p1, p2) == 1)
//	{
//		printf("p1>p2\n");
//	}
//	else if (strcmp(p1, p2) == 0)
//	{
//		printf("p1==p2\n");
//	}
//	if (strcmp(p1, p2) == -1)
//	{
//		printf("p1<p2\n");
//	}
//	return 0;
//}

//�ַ����Ƚϣ��Ƚϵ�����Ӧ�ַ���ASCLL��ֵ���������ַ����е��ַ�����


////�Լ�ʵ��
//#include <assert.h>
//#include <string.h>
//int my_strcmp(const char* str1, const char* str2)//const ��ʾstr����ַ����ǲ��ܱ��ı�ģ���������
//{
//	assert(str1 && str2);
//	//�Ƚ�
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;//���
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;//����
//	else
//		return -1;//С��
//}
//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "qwert";
//	int ret = my_strcmp(p1, p2);
//	printf("ret = %d\n", ret);
//	return 0;
//}

//�������������0��-1��1���⼸������
//����һ����325��329�п��Ը�д��return(*str1 - &str2);






//strncpy  (Copy characters of one string to another.)

//char *strncpy( char *strDest, const char *strSource, size_t count );

//�⼸�����Ƕ���һ��Ҫ���伸��������һ��������һ���޶�����
//��ǰ���Ǽ��飬�����������\0��Ҫ��\0��
//���⼸�鲻�ǣ���ȡ���ں���Ҫ���������

//����num���ַ�����Դ�ַ�����Ŀ��ռ�
//���Դ�ַ����ĳ���С��num���򿽱���Դ�ַ���֮����Ŀ��ĺ���׷��0��֪��num��

//int main()
//{
//	char arr1[5] = "abc";
//	char arr2[] = "hello bit";
//	strncpy(arr1, arr2, 4);
//	//���û�п�����֮���\0
//	return 0;
//}
//���Ҫ�����ĸ������ڱ����еĸ�������\0



//strncat  (Append characters of a string.)

//char *strncat( char *strDest, const char *strSource, size_t count );

//int main()
//{
//	char arr1[30] = "hello\0xxxxxxxxxx";
//	char arr2[] = "world";
//	strncat(arr1, arr2, 3);
//	//ͨ�����Իᷢ���ַ���������֮�󣬻Ὣ\0һͬ������ȥ���۵�һ���ַ����к�����ɶ
//	printf("%s\n", arr1);
//	return 0;
//}




//strncmp  (Compare characters of two strings.)

//int strncmp( const char *string1, const char *string2, size_t count );

//�Ƚϵ�������һ���ַ���һ������һ���ַ�����������num���ַ�ȫ���Ƚ���

//int main()
//{
//	const char* p1 = "abcdef";
//	char* p2 = "abcqwert";
//	int ret = strncmp(p1, p2, 3);
//	printf("%d\n", ret);
//	return 0;
//}



//�����е�һЩ�����г��֣�
//NULL - ��ָ��
//NUL/Null - '\0'




//strstr (Find a substring.)

//char *strstr( const char *string, const char *strCharSet );


//int main()
//{
//	//char* p1 = "abcdef";
//	char* p1 = "abcdefabcdef";
//	char* p2 = "def";
//	
//	char* ret = strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("�Ӵ�������\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	//������ӻᷢ�֣����ҵ��ǵ�һ����֮����ϵģ�֮��Ѻ���ȫ����ӡ����
//	return 0;
//}



////�Լ�ʵ��
//#include <assert.h>
//#include <string.h>
//char* my_strstr(const char* p1, const char* p2)//���������char*����char,�����char�Ļ����ͻ����Խ�����
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//	char* s1 = NULL;
//	char* s2 = NULL;
//	char* cur = (char*)p1;
//	if (*p2 == '\0')
//	{
//		return (char*)p1;
//	}
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = (char*)p2;//ǿ������ת������ͬ����
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cur;//�ҵ��Ӵ�
//		}
//		cur++;
//	}
//	return NULL;//�Ҳ����Ӵ�
//}
//int main()
//{
//	char* p1 = "abcdefabcdef";
//	char* p2 = "def";
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("�Ӵ�������\n");
//	}
//	else
//	{
//	    printf("%s\n", ret);
//	}
//	return 0;
//}


//KMP�㷨

//strtok (Find the next token in a string.)

//char *strtok( char *strToken, const char *strDelimit );
//char *strtok( char *str, const char *sep );


//sep �����ĸ��ַ����������������ָ������ַ�����
//��һ������ָ��һ���ַ�������������0�����߶����sep�ַ�����һ�����߶���ָ����ָ�ı��
//strtok�����ҵ�str����һ����ǣ���������\0��β������һ��ָ�������ǵ�ָ�롣
//��ע��strtok������ı䱻�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ����
//  �����ݲ��ҿ��޸ģ�
//strtok�����ĵ�һ��������ΪNULL���������ҵ�str�е�һ����ǣ�strtok���������������ַ����е�λ��
//strtok�����ĵ�һ������ΪNULL����������ͬһ���ַ����б������λ�ÿ�ʼ��������һ�����
//����ַ����в����ڸ���ı�ǣ��򷵻�NULLָ��


//#include <string.h>
//int main()
//{
//	char arr[] = "2098129093@qq.com";
//	char* p = "@.";
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//	//�и�buf�е��ַ���
//	char* ret = strtok(buf, p);
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//
//	return 0;
//}

////������������ǽ����н�����������printf�õ�̫�̫࣬����
////�Ľ����룺
//#include <string.h>
//int main()
//{
//	char arr[] = "2098129093@qq.com";
//	char* p = "@.";
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//	//�и�buf�е��ַ���
//
//	char* ret = NULL;
//	for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}
//
// #include <string.h>
//int main()
//{
//	char arr[] = "192.168.31.121";
//	char* p = ".";
//	char buf[100] = { 0 };
//	strcpy(buf, arr);
//	//�и�buf�е��ַ���
//	char* ret = NULL;
//	for (ret = strtok(buf, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}


//strerror(Get a system error message (strerror) 
//or prints a user-supplied error message (_strerror).)

//char *strerror( int errnum );

//#include <errno.h>
//int main()
//{
//	//0 - No error
//	//1 - Operation not permitted
//	//2 - No such file or directory
//	//...
//	//errno��һ��ȫ�ֵĴ�����ı���
//	//��C���ԵĿ⺯����ִ�еĹ����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����룬��ֵ��errno��
//	char* str = strerror(errno);
//	printf("%s\n", str);
//
//	return 0;
//}


//#include <errno.h>
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("open file success\n");
//	}
//	//����û������ļ������Գ���No such file or directory
//	//�����ļ�������open file success
//	return 0;
//}



//�ַ����ຯ��
//      ����                           ������Ĳ����������������ͷ�����

//    iscntrl                           �κο����ַ�                   
//    isspace                           �հ��ַ� ���ո� " ",��ҳ"\f",����"\n",�س�"\r",�Ʊ��"\t"���ߴ�ֱ�Ʊ��"\v"
//    isdigit                           ʮ��������0 - 9
//    isxdigit                          ʮ���������֣��������е�ʮ�������֣�Сд��ĸa - f,��д��ĸA - F
//    islower                           Сд��ĸa - z
//    isupper                           ��д��ĸA - Z
//    isalpha                           ��ĸa - z��A - Z
//    isalnum                           ��ĸ�����֣�a - z,A - Z,0 - 9
//    ispunct                           �����ţ��κβ��������ֻ�����ĸ��ͼ���ַ����ɴ�ӡ��
//    isgraph                           �κ�ͼ���ַ�
//    isprint                           �κοɴ�ӡ�ַ�������ͼ���ַ��Ϳհ��ַ�


//int main()
//{
//	char ch = 'w';
//	int ret = islower(ch);
//	printf("%d\n", ret);
//	//�����Ѿ�˵���������һ����ֵ������һ���������
//	return 0;
//}



//�ַ�ת��
//int tolower(int c);
//int toupper(int c);



//int main()
//{
//	char arr[] = "I Am A Student";
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))
//		{
//			arr[i] = tolower(arr[i]);
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//	return 0;
//}



//strcpy,strcat,strcmp,strncpy,strncat,strncmp
//�����Ķ�����ַ�������־�ǡ�\0��
//���������飬���������飬�ṹ�����鶼������������Щ������������������Щ������


//�ڴ��������


//memcpy(Copies characters between buffers.)

//void *memcpy( void *dest, const void *src, size_t count );//����������void* 

//����memcpy��source��λ�ÿ�ʼ�����num���ֽڵ����ݵ�destination���ڴ�λ��
//���������������\0����ʱ���ͣ����
//���source��destination���κε��ص������ƵĽ������δ�����

//struct s
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[10] = { 0 };
//	struct s arr3[] = { {"����",20},{"����",25} };
//	struct s arr4[10] = { 0 };
//	memcpy(arr4, arr3, sizeof(arr3));
//	memcpy(arr2, arr1, sizeof(arr1));
//	return 0;
//}


////�Լ�ʵ��
//#include <assert.h>
//struct s
//{
//	char name[20];
//	int age;
//};
//void* my_memcpy(void* dest, const void* src, size_t num)//�����void*��const void* �Ƚ���Ҫ
//{
//	void* ret = dest;
//	assert(dest != NULL);//��������Ҫ���ж�ָ�����Ч��
//	assert(src != NULL);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;//������������ǿ������ת��char*
//		++(char*)dest;//������++��������ת����char*��++�����������ò�������ģ�û����
//		++(char*)src;//����++����ת����char*�Ϳ��ԣ�Ҳ�ܺ���
//	}
//	return ret;
//
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[10] = { 0 };
//	struct s arr3[] = { {"����",20},{"����",25} };
//	struct s arr4[10] = { 0 };
//	my_memcpy(arr4, arr3, sizeof(arr3));
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	return 0;
//}


//1��2��3��4��5��6��7��8��9��10����1��2��3��4��5������3��4��5��6��7
//���ͱ����1��2��1��2��3��4��5��8��9��10

//�������Լ�д�ĺ����ͻ�����ص��ͱ����1��2��1��2��1��2��1��8��9��10
//�����õ��������⺯���Ϳ���ʵ��


//C���Թ涨��
//memcpyֻҪ���� ���ص����ڴ濽���Ϳ���
//memmove �����ص��ڴ�Ŀ���
//memmove �����ڴ��ص������

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	//memmove(arr + 2, arr, 20);//����20���ֽڴ�С��5������ÿ��4���ֽڣ���20���ֽ�
//	memcpy(arr + 2, arr, 20);//����������������ʵ��
//	//��������ʵ�־ͱȽ�����
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}





//memmove  (Moves one buffer to another.)

//void *memmove( void *dest, const void *src, size_t count );

//��memcpy�Ĳ�����memmove���������Դ�ڴ���Ŀ���ڴ���ǿ����ص���
//���Դ�ռ��Ŀ��ռ�����ص����͵�ʹ��memmove��������


////�Լ�ʵ��
//#include <assert.h>
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	//��ǰ��>���ƶ�
//	if (dest < src)//if(dest<src||dest>(char*)src+count)
//	{
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		//�Ӻ�>ǰ�ƶ�
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr + 2, arr, 20);//һ����4���ֽڣ�5����20���ֽ�
//	return 0;
//}




//memcmp(Compare characters in two buffers.)

//int memcmp( const void *buf1, const void *buf2, size_t count );

//�Ƚϴ�ptr1��ptr2ָ�뿪ʼ��num���ֽڣ�ע���ǱȽϵ����ֽڣ�



//int main()
//{
//	//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00
//	//01 00 00 00 02 00 00 00 05 00 00 00 04 00 00 00 03 00 00 00
//	//�Ƚ�ǰ9���ֽھ��ǣ�
//	//01 00 00 00 02 00 00 00 03
//	//01 00 00 00 02 00 00 00 05
//	//3��5С�����Է���-1
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,5,4,3 };
//	int ret = memcmp(arr1, arr2, 9);
//	printf("%d\n", ret);
//	return 0;
//}



//memset (Sets buffers to a specified character.) - �ڴ�����

//void *memset( void *dest, int c, size_t count );

//int main()
//{
//	char arr[10] = "";
//	memset(arr, '#', 10);
//	//��#�滻10���ֽڵĿո�
//	//���Գ�����#��ߵ�35��#��ASCLL��ֵ
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	memset(arr, 1, 10);
//	//16843009
//	//16843009
//	//257
//	//���Ǵ�ӡ����������ֵ
//	//��Ϊ:
//	//int arr ����40���ֽ�
//	//01 01 01 01 01 01 01 01 01 01 00 00 00 00 ......
//	//01 01 01 01//һ��intֻ�ܴ�4���ֽڣ�����ֻ�ܴ�������������������16���Ƶ�
//	//ת����10���ƾ���16843009
//	//����ʣ������01 01 ��
//	return 0;
//}