## 字符串

`String`字符串仿Redis sds实现，有以下几个特点：

- 使用简单，操作方便，操作更有效率
- 二进制安全，能存储任何二进制化的数据
- 减少内存分配
- 兼容部分c库字符串操作函数
- 但是以上优势的代价是多占一些内存，而且不会主动释放

其定义结构体如下：

```C
typedef char* String;
//字符串结构头
typedef struct StringHdr_{
	Int32 len;
    Int32 alloc;
    char buf[];
}StringHdr;
//字符串使用长度
static inline size_t StringLen(const String s) {
    StringHdr *sh = (void*)(s-(sizeof(StringHdr)));
    return sh->len;
}
//字符串空闲长度
static inline size_t StringAvail(const String s) {
    StringHdr *sh = (void*)(s-(sizeof(StringHdr)));
    return (sh->alloc - sh->len);
}
```

### 接口总览

| 分类             | 接口                  | 参数                                                         | 返回值  | 描述                                                         |
| ---------------- | --------------------- | ------------------------------------------------------------ | ------- | ------------------------------------------------------------ |
| 创建新字符串     | StringNewLen          | const void *init, size_t initlen                             | String  | 创建一个指定长度的 `String` ，接受一个 C 字符串作为初始化值  |
| 创建新字符串     | StringNew             | const char *init                                             | String  | 根据给定 C 字符串，创建一个相应的 `String`                   |
| 创建新字符串     | StringEmpty           | void                                                         | String  | 创建一个只包含空白字符串 `""` 的 `String`                    |
| 创建新字符串     | StringDup             | const String s                                               | String  | 复制给定 `String`                                            |
| 删除字符串       | StringFree            | String s                                                     | void    | 释放给定 `String`                                            |
| 修改字符串       | StringGrowZero        | String s, size_t len                                         | String  | 用空字符将`String`扩展至给定的长度                           |
| 连接字符串       | StringCatLen          | String s, const void *t, size_t len                          | String  | 按给定长度对 `String` 进行扩展，并将一个 C 字符串追加到 `String` 的末尾 |
| 连接字符串       | StringCat             | String s, const char *t                                      | String  | 将一个 C 字符串追加到 `String` 末尾                          |
| 连接字符串       | StringCatString       | String s, const String t                                     | String  | 将一个 `String` 追加到另一个 `String` 末尾                   |
| 复制字符串       | StringCpyLen          | String s, const char *t, size_t len                          | String  | 将一个 C 字符串的部分内容复制到另一个 `String` 中，需要时对 `String` 进行扩展 |
| 复制字符串       | StringCpy             | String s, const char *t                                      | String  | 将一个 C 字符串复制到 `String`                               |
| 格式化字符串     | StringCatVPrintf      | String s, const char *fmt, va_list ap                        | String  | 格式化字符串，使用列表替换传入多个参数的方式来格式化指定的字符串 |
| 格式化字符串     | StringCatPrintf       | String s, const char *fmt, ...                               | String  | 格式化字符串，`...`代表可传入多个参数，其参数个数与`fmt`中格式符个数相同，内部调用`StringCatVPrintf` |
| 格式化字符串     | StringCatFmt          | String s, char const *fmt, ...                               | String  | 格式化字符串，用`while`方式逐一匹配实现，拜托了对libc中较慢的`sprintf`的依赖。 |
| 裁剪字符串       | StringTrim            | String s, const char *cset                                   | String  | 移除`s`串两边由`cset`指定的所有字符                          |
| 裁剪字符串       | StringRange           | String s, Int32 start, Int32 end                             | void    | 取`s`指定范围的子串并将其放到`s`所指内存区域，实现过程是移除`s`串两边的子串即可 |
| 手动修改字符串   | StringUpdateLen       | String s                                                     | void    | 更新给定 `String` 所对应 `StringHdr` 结构的 `alloc` 和 `len`,（在可能手动修改过`s`的值之后，如`s[2]=''`这样直接赋值操作），更新字符串的实际长度为`strlen`（如果有多个`\0`，将取到第一个出现的位置结束）获取到的长度 |
| 清空字符串       | StringClear           | String s                                                     | void    | 清除给定 `String` 的内容，将它初始化为 `""`                  |
| 比较字符串       | StringCmp             | const String s1, const String s2                             | Int32   | 比较两个 `String`是否相等                                    |
| 单元化字符串     | StringSplitLen        | const char *s, Int32len, const char *sep, Int32 seplen, Int32 *count | String* | 按`sep`分割`s`串并返回分割后的数组，`count`为数组个数        |
| 单元化字符串     | StringFreeSplitRes    | String *tokens, int count                                    | void    | 释放由`StringSplitLen`分割出来的`tokens`数组                 |
| 大小写转换       | StringToLower         | String s                                                     | void    | `s`串转成小写                                                |
| 大小写转换       | StringToUpper         | String s                                                     | void    | `s`串转成大写                                                |
| 数字转字符串     | StingFromLongLong     | Int64 value                                                  | String  | 将64位整形数据转成`String`串存储，替代StringCatPrintf(StringEmpty(),"%lld\n", value) |
| 命令行单元化     | StringSplitArgs       | const char *line, Int32 *argc                                | String* | 解析命令行参数并返回`String`数组，并写入参数个数到`argc`里   |
| 引用字符串       | StringCatRepr         | String s, const char *p, size_t len                          | String  | 把`String`串与给定的字符表达式聚合到一起，用字符表达式替换`String`对应位置的字符 |
| 引用字符串       | StringMapChars        | String s, const char *from, const char *to, size_t setlen    | String  | 用`to`里每个字符，替换`s`里所有的由`from`指按顺序定的所有字符，如s="fHemo prut!", from="HH", to="01", 最终s="f1emo prut!"。因为H被最终匹配到的值计算 |
| 逆向单元化字符串 | StringJoin            | char **argv, Int32 argc, char *sep                           | String  | 把c字符串数组按指定的`sep`连接符连接起来                     |
| 逆向单元化字符串 | StringJoinString      | String *argv, Int32 argc, const char *sep, size_t seplen     | String  | 把`String`字符串数组按指定的`sep`连接符连接起来              |
| 改变长度         | StringMakeRoomFor     | String s, size_t addlen                                      | String  | 增加`String`的总分配内存`alloc`                              |
| 改变长度         | StringIncrLen         | String s, Int32 incr                                         | void    | 增加`s`的实际长度。`s`被其他函数调用后可能需要改变长度       |
| 改变长度         | StringRemoveFreeSpace | String s                                                     | String  | 删除空闲空间，重新整理一个`String`，alloc=len                |
| 获取长度         | StringAllocSize       | String s                                                     | size_t  | 分配的所有内存大小，包括结构体头部+ `alloc`（实际字符串+空闲部分）+1个结束符 |
| 获取地址         | StringAllocPtr        | String s                                                     | void*   | 返回`s`的控制结构的起始地址                                  |
| 内存分配         | StringMallocImpl      | size_t size                                                  | void*   | 申请给定大小的内存，返回指针地址（绑定到`String`上）         |
| 内存分配         | StringReallocImpl     | void *ptr, size_t size                                       | void*   | 给指定指针，重新分配内存，并返回新分配的内存指针             |
| 释放内存         | StringFreeImpl        | void *ptr                                                    | void    | 释放指定指针的内存，此指针一释放意味着变量内存找不着了，也就释放了变量的内存 |
| 测试             | StringTest            | Int32 argc, char *argv[]                                     | Int32   | 测试                                                         |

### 函数原型



## 时间

提供获取和设置系统时间，以及时间转换的相关接口，时间精度为ms

定义相关结构体如下：

```C
typedef UInt64 DateTime;
typedef struct DateTimeStruct_{
    UInt16 milliSec;
    UInt16 sec;
    UInt16 minute;
    UInt16 hour;
    UInt16 day;
    UInt16 month;
    UInt16 year;
}DateTimeStruct;
#define DATETIME_STRING_FORMAT "%04d-%02d-%02d %02d:%02d:%02d:%03d"
#define DATETIME_STRING_LENGTH 24
```

### 接口总览

| 分类                 | 接口                              | 参数                                                  | 返回值   | 描述                                                         |
| -------------------- | --------------------------------- | ----------------------------------------------------- | -------- | ------------------------------------------------------------ |
| 获取系统时间         | GetSystemUTCTime                  | DateTimeStruct *datetime                              | void     | 获取系统的UTC时间                                            |
| 获取系统时间         | GetSystemLocalTime                | DateTimeStruct *datetime                              | void     | 获取系统的本地时间                                           |
| 获取系统时间         | GetSystemUTCMillisecondsSince1970 | void                                                  | DateTime | 获取系统UTC时间毫秒数（1970年1月1日 0时0分0秒至今）          |
| 时间转换             | CovertMillSecondsToUTCDateTime    | const DateTime milliseconds, DateTimeStruct *datetime | void     | 将毫秒数时间转换为UTC时间                                    |
| 时间转换             | CovertMillSecondsToLocalDateTime  | const DateTime milliseconds, DateTimeStruct *datetime | void     | 将毫秒数时间转换为本地时间                                   |
| 时间转换             | CovertToAsctimeString             | const struct tm *tmptr, char *strbuffer               | void     | 将C库tm结构的时间转换为asctime时间格式写入`strbuffer`中      |
| 时间转换             | CovertToCtimeString               | const time_t *timer, char *strbuffer                  | void     | 将C库time_t 结构的时间转换为asctime时间格式写入`strbuffer`中 |
| 时间转换             | StringToDatetimeFormat            | const char* strtime, DateTimStruct *datetime          | void     | 将`DATETIME_STRING_FORMAT`格式的时间转化为`DateTimeStruct` 的结构 |
| 时间转换             | DateTimeToStringFormat            | const DateTimStruct *datetime, char *strtime          | void     | 将`DateTimeStruct` 的结构的时间转化为`DATETIME_STRING_FORMAT`格式 |
| 设置系统时间         | SetSystemUTCTime                  | const DateTimStruct *datetime                         | Boolean  | 设置系统时间，传入的`datetime`被认为是UTC时间                |
| 设置系统时间         | SetSystemLocalTime                | const DateTimStruct *datetime                         | Boolean  | 设置系统时间，传入的`datetime`被认为是本地时间               |
| 获取系统启动经过时间 | GetSystemStartupElapsedTicks      | void                                                  | Uint32   | 获取系统启动至今经过的时间，返回的时间单位ms                 |

### 函数原型



## 定时器

定时器，顾名思义就是用来定时的，通俗的可以将其看作一个闹钟。在实现下列几项功能时，可考虑使用定时器

- 周期性执行某一项任务；
- 在指定时间去执行某一项任务；

此处自定义实现定时器，在WIN32下，采用Waitable Timer实现，在Unix下，采用POSIX定时器实现，定义其结构体如下：

```C
typedef void (*FuncTimerProc)(Int32 id, void* arg); /* 定时器事件处理函数 */
typedef struct Timer_{
#ifdef OS_WINDOWS
    HANDLE event;
	#ifdef WINNT_VERSION_OVER0600
    	PTP_TIMER timer;
	#else
    	HANDLE timer; /* Waitable Timer Handler */
    	HANDLE thread;
    #endif
#else
    timer_t timer; /* POSIX Timer */
    sigset_t oldSigset;
    sem_t event;
#endif
    Int32 tid;
    Int32 ticket;
    FuncTimerProc proc;
    void *arg;
}Timer;
```

### 接口总览

| 分类       | 接口         | 参数                                                  | 返回值  | 描述                                                         |
| ---------- | ------------ | ----------------------------------------------------- | ------- | ------------------------------------------------------------ |
| 创建定时器 | CreateTimer  | const Int32 tid,  Timer *timer                        | Boolean | 创建定时器，传入定时器ID，返回创建成功的定时器指针，成功返回TRUE，失败返回FALSE |
| 设置定时器 | SetTimer     | Timer *timer, Int32 ms, FuncTimerProc proc, void *arg | Boolean | 设置定时器，传入CreateTimer创建的定时器指针，设置定时器的定时时间，定时事件处理函数 |
| 等待定时器 | WaitTimer    | const Timer *timer                                    | Boolean | 等待定时器事件，此函数将阻塞调用线程，直到定时事件发生       |
| 删除定时器 | DestoryTimer | Timer *timer                                          | Boolean | 删除定时器，释放定时器占用的资源                             |

### 函数原型



## 网络套接字

Unix与Windows下的socket接口基本相同, 部分有差异，差异不大，为方便使用，此处封装成一套接口

```C
#ifdef OS_WINDOWS
#else
	typedef Int32 SOCKET;
	#define INVAILD_SOCKET
	#define SOCKET_ERROR
#endif
```

### 接口总览

| 分类           | 接口      | 参数 | 返回值 | 描述 |
| -------------- | --------- | ---- | ------ | ---- |
| 网络资源初始化 | SockSetup | void | Int32  |      |
| 网络资源释放   |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |
|                |           |      |        |      |

### 函数原型



## IO管道

提供IO管道的统一封装接口

### 接口总览

| 分类         | 接口         | 参数                              | 返回值  | 描述                                                         |
| ------------ | ------------ | --------------------------------- | ------- | ------------------------------------------------------------ |
| 创建管道     | IOPopen      | const char *cmd, const char *type | FILE*   | 创建管道并执行命令：`cmd`指定命令，`type`指定返回的FILE类型；成功返回有效`FILE*`，失败返回`NULL` |
| 关闭管道     | IOClose      | FILE* stream                      | Int32   | 关闭管道及文件指针，参数`stream`为先前由`IOPopen`所返回的文件指针 |
| 更改文件大小 | IOResizeFile | Int32 fd, Int32 length            | Boolean | 更改文件大小：`fd`指定文件句柄，`length`指定更改长度；成功返回`TRUE`，失败返回`FALSE` |

### 函数原型



## 动态库加载

