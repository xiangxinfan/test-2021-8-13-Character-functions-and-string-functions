#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//本章重点
//重点介绍处理字符和字符串的库函数的使用和注意事项

//求字符串长度
//strlen
//长度不受限制的字符串函数
//strcpy
//strcat
//strcmp
//长度受限制的字符串函数介绍
//strncpy
//strncat
//strncmp
//字符串查找
//strstr
//strtok
//错误信息报告
//strerror
//字符操作
//内存操作函数
//memcpy
//memmove
//memset
//memcmp

//前言
//C语言中对字符和字符串的处理很是频繁，但是C语言本身是没有字符串类型的，字符串通常放在 
//常量字符串 中或者 字符数组 中。 字符串常量 适用于那些对它不做修改的字符串函数

//这些函数都得引用头文件#include <string.h>

//函数介绍

//strlen  (Get the length of a string.)
//size_t strlen( const char *string );

//字符串以'\0'作为结束的标志，strlen函数返回的是在字符串中'\0'前面出现的字符个数（不包含\0）
//参数指向的字符串必须要以'\0'结束
//注意函数的返回值为size_t，是无符号的（重点加易错）  size_t == unsigned int
//学会strlen函数的模拟实现



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
//	//这个结果就是个随机值，因为a,b,c,d,e分别对应的一个字母，并没有\0,而且也找不到\0在哪里
//	//就出现的是随机值，
//	return 0;
//}

////自己编写函数
//
////1.计数器的方法
////2.递归
////3.指针——指针
//
//#include <assert.h>
//int my_strlen(char* str)
//{
//	int count = 0;
//	assert(str != NULL);//因为传过来的是指针，这里同样判断一下指针的有效性
//	//这里也可以写成assert(str);
//	while(*str != '\0')//可以写成while(*str);
//	{
//		count++;
//		str++;//这里换成*str是多此一举，脱裤子放屁
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
//	//但是strlen的返回类型的size_t
//	//是个unsigned,无符号的数字
//	//所以计算机会将-3看成无符号数，所以就成整数了
//	else
//	{
//		printf("haha\n");
//	}
//	return 0;
//}






//strcpy  (Copy a string.)

//char *strcpy( char *strDestination, const char *strSource );

//源字符串必须以'\0'结束
//会将源字符串中的'\0'拷贝到目标空间
//目标空间必须足够大，以确保能存放源字符串
//目标空间必须可变
//学会模拟实现


////用调试窗口来看会更明显一些
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "shaanxi";
//	strcpy(arr1, arr2);
//	//拷贝过程中会将arr2中的\0同样拷过去
// //当然拷贝过去要考虑第一个字符串的大小，否则编译会终止
//	printf("%s\n", arr1);
//	return 0;
//}

//自己写函数实现

//#include <assert.h>
//char* my_strcpy(char* dest, char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*src != '\0')
//	{
//		//*dest = *src;
//		//dest++;
//		//src++;//这括号里面的只能将除\0之前的字符弄进去
//
//
//		*dest++ = *src++;//将146到148行简化成这一行；
//		
//	}
//	*dest = *src;//这个是'\0'
//}

////或者将上面部分函数代码转换成下面的：
//char* my_strcpy(char* dest,const char* src)//因为strcpy定义中就有const char*
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	//拷贝src指向的字符串到dest指向的空间，包含\0
//	while (*dest++ = *src++)//这里面也将\0弄进去了
//	{
//		;
//	}
//	//返回目的空间的起始地址
//	return ret;
//	//更加言简意赅，更加简便
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
//	//也不可这样子，这是常量字符串，不能改变这个常量字符串
//
//	char arr2[] = { 'a','b','c' };
//	//这是错误的
//	//原因是在arr2上找不到\0的存在
//	return 0;
//}






//strcat   (Append a string.)

//char *strcat( char *strDestination, const char *strSource );

//源字符串必须以'\0'结束
//目标空间必须有足够的大，能容纳下源字符串的内容
//目标空间必须修改
//字符串自己给自己追加（这个是不对的）

//int main()
//{
//	char arr1[] = "hello";
//	char arr2[] = "world";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	//这个是强行追加上了，但是崩溃了
//	//崩溃原因是因为目标空间不够大，造成越界访问
//	return 0;
//}

//int main()
//{
//	char arr1[30] = "hello";//这样就不会出现越界访问了
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
//	//这里依然是从arr1中的\0处开始往上追加
//	return 0;
//}



////自己写函数实现
//#include <assert.h>
//my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest);
//	assert(src);
//	//1.找到目的字符串的'\0'
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//2.追加
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

//标准规定：
//第一个字符串大于第二个字符串，则返回大于0的数
//第一个字符串等于第二个字符串，则返回0
//第一个字符串小于第二个字符串，则返回小于0的数

//#include <stdio.h>
//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "sqwert";
//	//if ("abcdef" == "sqwert");//这样写是不对的，也没见过这样写的
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

//字符串比较，比较的是相应字符的ASCLL码值，而不是字符串中的字符多少


////自己实现
//#include <assert.h>
//#include <string.h>
//int my_strcmp(const char* str1, const char* str2)//const 表示str这个字符串是不能被改变的，被锁定了
//{
//	assert(str1 && str2);
//	//比较
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;//相等
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;//大于
//	else
//		return -1;//小于
//}
//int main()
//{
//	char* p1 = "abcdef";
//	char* p2 = "qwert";
//	int ret = my_strcmp(p1, p2);
//	printf("ret = %d\n", ret);
//	return 0;
//}

//这是如果不返回0，-1，1，这几个数话
//还有一种是325到329行可以改写成return(*str1 - &str2);






//strncpy  (Copy characters of one string to another.)

//char *strncpy( char *strDest, const char *strSource, size_t count );

//这几个就是多了一个要传输几个数字这一个，加了一个限定条件
//而前面那几组，传输的依据是\0，要找\0；
//而这几组不是，这取决于后面要传输的数字

//拷贝num个字符，从源字符串到目标空间
//如果源字符串的长度小于num，则拷贝完源字符串之后，在目标的后面追加0，知道num个

//int main()
//{
//	char arr1[5] = "abc";
//	char arr2[] = "hello bit";
//	strncpy(arr1, arr2, 4);
//	//这个没有拷贝完之后加\0
//	return 0;
//}
//如果要拷贝的个数大于本身有的个数，则补\0



//strncat  (Append characters of a string.)

//char *strncat( char *strDest, const char *strSource, size_t count );

//int main()
//{
//	char arr1[30] = "hello\0xxxxxxxxxx";
//	char arr2[] = "world";
//	strncat(arr1, arr2, 3);
//	//通过调试会发现字符串拷贝完之后，会将\0一同拷贝过去无论第一个字符串中后面有啥
//	printf("%s\n", arr1);
//	return 0;
//}




//strncmp  (Compare characters of two strings.)

//int strncmp( const char *string1, const char *string2, size_t count );

//比较到出现另一个字符不一样或者一个字符串结束或者num个字符全部比较完

//int main()
//{
//	const char* p1 = "abcdef";
//	char* p2 = "abcqwert";
//	int ret = strncmp(p1, p2, 3);
//	printf("%d\n", ret);
//	return 0;
//}



//文献中等一些资料中出现：
//NULL - 空指针
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
//		printf("子串不存在\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	//这个例子会发现，查找的是第一个与之相符合的，之后把后面全部打印出来
//	return 0;
//}



////自己实现
//#include <assert.h>
//#include <string.h>
//char* my_strstr(const char* p1, const char* p2)//这个类型是char*不是char,如果是char的话，就会出现越界访问
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
//		s2 = (char*)p2;//强制类型转换成相同类型
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cur;//找到子串
//		}
//		cur++;
//	}
//	return NULL;//找不到子串
//}
//int main()
//{
//	char* p1 = "abcdefabcdef";
//	char* p2 = "def";
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("子串不存在\n");
//	}
//	else
//	{
//	    printf("%s\n", ret);
//	}
//	return 0;
//}


//KMP算法

//strtok (Find the next token in a string.)

//char *strtok( char *strToken, const char *strDelimit );
//char *strtok( char *str, const char *sep );


//sep 参数四个字符串，定义了用作分隔符的字符集合
//第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记
//strtok函数找到str中下一个标记，并将其用\0结尾，返回一个指向这个标记的指针。
//（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝
//  的内容并且可修改）
//strtok函数的第一个参数不为NULL，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置
//strtok函数的第一个参数为NULL，函数将在同一个字符串中被保存的位置开始，查找下一个标记
//如果字符串中不存在更多的标记，则返回NULL指针


//#include <string.h>
//int main()
//{
//	char arr[] = "2098129093@qq.com";
//	char* p = "@.";
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//	//切割buf中的字符串
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

////上面这个代码是将所有结果输出，但是printf用的太多，太繁琐
////改进代码：
//#include <string.h>
//int main()
//{
//	char arr[] = "2098129093@qq.com";
//	char* p = "@.";
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//	//切割buf中的字符串
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
//	//切割buf中的字符串
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
//	//errno是一个全局的错误码的变量
//	//当C语言的库函数在执行的过程中，发生了错误，就会把对应的错误码，赋值到errno中
//	char* str = strerror(errno);
//	printf("%s\n", str);
//
//	return 0;
//}


//#include <errno.h>
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("open file success\n");
//	}
//	//但是没有这个文件，所以出现No such file or directory
//	//若有文件，就是open file success
//	return 0;
//}



//字符分类函数
//      函数                           如果他的参数符合下列条件就返回真

//    iscntrl                           任何控制字符                   
//    isspace                           空白字符 ：空格 " ",换页"\f",换行"\n",回车"\r",制表符"\t"或者垂直制表符"\v"
//    isdigit                           十进制数字0 - 9
//    isxdigit                          十六进制数字，包括所有的十进制数字，小写字母a - f,大写字母A - F
//    islower                           小写字母a - z
//    isupper                           大写字母A - Z
//    isalpha                           字母a - z或A - Z
//    isalnum                           字母或数字，a - z,A - Z,0 - 9
//    ispunct                           标点符号，任何不属于数字或者字母的图形字符（可打印）
//    isgraph                           任何图形字符
//    isprint                           任何可打印字符，包括图形字符和空白字符


//int main()
//{
//	char ch = 'w';
//	int ret = islower(ch);
//	printf("%d\n", ret);
//	//上面已经说了这是输出一个真值，就是一个非零的数
//	return 0;
//}



//字符转换
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
//操作的对象的字符串，标志是“\0”
//而整型数组，浮点型数组，结构体数组都不能用上面这些函数，而得用下面这些函数：


//内存操作函数


//memcpy(Copies characters between buffers.)

//void *memcpy( void *dest, const void *src, size_t count );//返回类型是void* 

//函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置
//这个函数在遇到‘\0’的时候会停下来
//如果source和destination有任何的重叠，复制的结果都是未定义的

//struct s
//{
//	char name[20];
//	int age;
//};
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[10] = { 0 };
//	struct s arr3[] = { {"张三",20},{"李四",25} };
//	struct s arr4[10] = { 0 };
//	memcpy(arr4, arr3, sizeof(arr3));
//	memcpy(arr2, arr1, sizeof(arr1));
//	return 0;
//}


////自己实现
//#include <assert.h>
//struct s
//{
//	char name[20];
//	int age;
//};
//void* my_memcpy(void* dest, const void* src, size_t num)//这里得void*，const void* 比较重要
//{
//	void* ret = dest;
//	assert(dest != NULL);//这两句重要，判断指针的有效性
//	assert(src != NULL);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;//还有这里所有强制类型转换char*
//		++(char*)dest;//若后置++，就是先转换成char*再++，这样子是拿不到结果的，没意义
//		++(char*)src;//若先++，再转换成char*就可以，也很合理
//	}
//	return ret;
//
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[10] = { 0 };
//	struct s arr3[] = { {"张三",20},{"李四",25} };
//	struct s arr4[10] = { 0 };
//	my_memcpy(arr4, arr3, sizeof(arr3));
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	return 0;
//}


//1，2，3，4，5，6，7，8，9，10，用1，2，3，4，5来覆盖3，4，5，6，7
//左后就变成了1，2，1，2，3，4，5，8，9，10

//用上面自己写的函数就会出现重叠就变成了1，2，1，2，1，2，1，8，9，10
//所以用到了下面这函数就可以实现


//C语言规定：
//memcpy只要处理 不重叠的内存拷贝就可以
//memmove 处理重叠内存的拷贝
//memmove 处理内存重叠的情况

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//	//memmove(arr + 2, arr, 20);//这里20是字节大小，5个数，每个4个字节，共20个字节
//	memcpy(arr + 2, arr, 20);//这两个函数都可以实现
//	//但是自我实现就比较困难
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}





//memmove  (Moves one buffer to another.)

//void *memmove( void *dest, const void *src, size_t count );

//和memcpy的差别就是memmove函数处理的源内存块和目标内存块是可以重叠的
//如果源空间和目标空间出现重叠，就得使用memmove函数处理


////自己实现
//#include <assert.h>
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	//从前—>后移动
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
//		//从后—>前移动
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
//	my_memmove(arr + 2, arr, 20);//一个数4个字节，5个数20个字节
//	return 0;
//}




//memcmp(Compare characters in two buffers.)

//int memcmp( const void *buf1, const void *buf2, size_t count );

//比较从ptr1和ptr2指针开始得num个字节（注意是比较的是字节）



//int main()
//{
//	//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00
//	//01 00 00 00 02 00 00 00 05 00 00 00 04 00 00 00 03 00 00 00
//	//比较前9个字节就是：
//	//01 00 00 00 02 00 00 00 03
//	//01 00 00 00 02 00 00 00 05
//	//3比5小，所以返回-1
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,5,4,3 };
//	int ret = memcmp(arr1, arr2, 9);
//	printf("%d\n", ret);
//	return 0;
//}



//memset (Sets buffers to a specified character.) - 内存设置

//void *memset( void *dest, int c, size_t count );

//int main()
//{
//	char arr[10] = "";
//	memset(arr, '#', 10);
//	//用#替换10个字节的空格
//	//调试出来的#左边的35是#的ASCLL码值
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	memset(arr, 1, 10);
//	//16843009
//	//16843009
//	//257
//	//这是打印出来的三个值
//	//因为:
//	//int arr 中有40个字节
//	//01 01 01 01 01 01 01 01 01 01 00 00 00 00 ......
//	//01 01 01 01//一个int只能存4个字节，所以只能存下这个，但这个存下是16进制的
//	//转换成10进制就是16843009
//	//最后就剩下两个01 01 了
//	return 0;
//}