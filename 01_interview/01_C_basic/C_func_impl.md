<!--
 * @Descripttion: 
 * @version: 
 * @Author: Allen Zhuang
 * @Date: 2020-10-16 06:52:16
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-10-16 08:46:58
-->
```memcpy()
    void* simple_memcpy(void *dest, const void *src, size_t n){
        char *strDest = (char*)dest;
        char *strSrc = (char*)src;
        if(strSrc < strDest){
            strDest += n;
            strSrc += n;
            while(n--)  *--strDest = *--strSrc;
        }else{
            while(n--)  *strDest++ = *strSrc++; 
        }
        return strDest;
    }
```
```strcpy()
    
```