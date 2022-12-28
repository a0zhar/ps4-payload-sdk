#include "../include/kernel.h"
#include "../include/module.h"

#include "../include/libc.h"

void* (*malloc)(size_t size);
void (*free)(void* ptr);
void* (*calloc)(size_t num, size_t size);
void* (*realloc)(void* ptr, size_t size);
void* (*memalign)(size_t boundary, size_t size);
void* (*memset)(void* destination, int value, size_t num);
void* (*memcpy)(void* destination, const void* source, size_t num);
int (*memcmp)(const void* s1, const void* s2, size_t n);
char* (*strcpy)(char* destination, const char* source);
char* (*strncpy)(char* destination, const char* source, size_t num);
char* (*strcat)(char* dest, const char* src);
char* (*strncat)(char* dest, const char* src, size_t n);
size_t(*strlen)(const char* s);
int (*strcmp)(const char* s1, const char* s2);
int (*strncmp)(const char* s1, const char* s2, size_t n);
int (*sprintf)(char* str, const char* format, ...);
int (*snprintf)(char* str, size_t size, const char* format, ...);
int (*sscanf)(const char* str, const char* format, ...);
char* (*strchr)(const char* s, int c);
char* (*strrchr)(const char* s, int c);
char* (*strstr)(char* str1, char* str2);
char* (*strdup)(const char* s);
char* (*index)(const char* s, int c);
char* (*rindex)(const char* s, int c);
int (*isdigit)(int c);
int (*atoi)(const char* s);
size_t(*strlcpy)(char* dst, const char* src, size_t size);
char* (*strerror)(int errnum);
void* (*_Getpctype)();
unsigned long (*_Stoul)(const char*, char**, int);
void (*bcopy)(const void* s1, void* s2, size_t n);

void (*srand)(unsigned int seed);
int (*rand)(void);

char* (*asctime)(const struct tm* tm);
char* (*asctime_r)(const struct tm* tm, char* buf);
char* (*ctime)(const time_t* timep);
char* (*ctime_r)(const time_t* timep, char* buf);
time_t(*time)(time_t* tloc);
struct tm* (*gmtime)(const time_t* timep);
struct tm* (*gmtime_s)(const time_t* timep, struct tm* result);
struct tm* (*localtime)(const time_t* timep);
struct tm* (*localtime_r)(const time_t* timep, struct tm* result);
time_t(*mktime)(struct tm* tm);

DIR* (*opendir)(const char* filename);
struct dirent* (*readdir)(DIR* dirp);
int (*readdir_r)(DIR* dirp, struct dirent* entry, struct dirent** result);
long (*telldir)(const DIR* dirp);
void (*seekdir)(DIR* dirp, long loc);
void (*rewinddir)(DIR* dirp);
int (*closedir)(DIR* dirp);
int (*dirfd)(DIR* dirp);
char* (*getprogname)();

FILE* (*fopen)(const char* filename, const char* mode);
size_t(*fread)(void* ptr, size_t size, size_t count, FILE* stream);
size_t(*fwrite)(const void* ptr, size_t size, size_t count, FILE* stream);
int (*fseek)(FILE* stream, long int offset, int origin);
long int (*ftell)(FILE* stream);
int (*fclose)(FILE* stream);
int (*fprintf)(FILE* stream, const char* format, ...);

void initLibc(void) {
  int libc = sceKernelLoadStartModule("libSceLibcInternal.sprx", 0, NULL, 0, 0, 0);

  getFunctionAddressByName(libc, "malloc", &malloc);
  getFunctionAddressByName(libc, "free", &free);
  getFunctionAddressByName(libc, "calloc", &calloc);
  getFunctionAddressByName(libc, "realloc", &realloc);
  getFunctionAddressByName(libc, "memalign", &memalign);
  getFunctionAddressByName(libc, "memset", &memset);
  getFunctionAddressByName(libc, "memcpy", &memcpy);
  getFunctionAddressByName(libc, "memcmp", &memcmp);
  getFunctionAddressByName(libc, "strcpy", &strcpy);
  getFunctionAddressByName(libc, "strncpy", &strncpy);
  getFunctionAddressByName(libc, "strcat", &strcat);
  getFunctionAddressByName(libc, "strncat", &strncat);
  getFunctionAddressByName(libc, "strlen", &strlen);
  getFunctionAddressByName(libc, "strcmp", &strcmp);
  getFunctionAddressByName(libc, "strncmp", &strncmp);
  getFunctionAddressByName(libc, "sprintf", &sprintf);
  getFunctionAddressByName(libc, "snprintf", &snprintf);
  getFunctionAddressByName(libc, "sscanf", &sscanf);
  getFunctionAddressByName(libc, "strchr", &strchr);
  getFunctionAddressByName(libc, "strrchr", &strrchr);
  getFunctionAddressByName(libc, "strstr", &strstr);
  getFunctionAddressByName(libc, "strdup", &strdup);
  getFunctionAddressByName(libc, "index", &index);
  getFunctionAddressByName(libc, "rindex", &rindex);
  getFunctionAddressByName(libc, "isdigit", &isdigit);
  getFunctionAddressByName(libc, "atoi", &atoi);
  getFunctionAddressByName(libc, "strlcpy", &strlcpy);
  getFunctionAddressByName(libc, "strerror", &strerror);
  getFunctionAddressByName(libc, "_Getpctype", &_Getpctype);
  getFunctionAddressByName(libc, "_Stoul", &_Stoul);
  getFunctionAddressByName(libc, "bcopy", &bcopy);

  getFunctionAddressByName(libc, "srand", &srand);
  getFunctionAddressByName(libc, "rand", &rand);

  getFunctionAddressByName(libc, "asctime", &asctime);
  getFunctionAddressByName(libc, "asctime_r", &asctime_r);
  getFunctionAddressByName(libc, "ctime", &ctime);
  getFunctionAddressByName(libc, "ctime_r", &ctime_r);
  getFunctionAddressByName(libc, "time", &time);
  getFunctionAddressByName(libc, "gmtime", &gmtime);
  getFunctionAddressByName(libc, "gmtime_s", &gmtime_s);
  getFunctionAddressByName(libc, "localtime", &localtime);
  getFunctionAddressByName(libc, "localtime_r", &localtime_r);
  getFunctionAddressByName(libc, "mktime", &mktime);

  getFunctionAddressByName(libc, "opendir", &opendir);
  getFunctionAddressByName(libc, "readdir", &readdir);
  getFunctionAddressByName(libc, "readdir_r", &readdir_r);
  getFunctionAddressByName(libc, "telldir", &telldir);
  getFunctionAddressByName(libc, "seekdir", &seekdir);
  getFunctionAddressByName(libc, "rewinddir", &rewinddir);
  getFunctionAddressByName(libc, "closedir", &closedir);
  getFunctionAddressByName(libc, "dirfd", &dirfd);
  getFunctionAddressByName(libc, "getprogname", &getprogname);

  getFunctionAddressByName(libc, "fopen", &fopen);
  getFunctionAddressByName(libc, "fread", &fread);
  getFunctionAddressByName(libc, "fwrite", &fwrite);
  getFunctionAddressByName(libc, "fseek", &fseek);
  getFunctionAddressByName(libc, "ftell", &ftell);
  getFunctionAddressByName(libc, "fclose", &fclose);
  getFunctionAddressByName(libc, "fprintf", &fprintf);




  /*
  RESOLVE(libc, malloc);
  RESOLVE(libc, free);
  RESOLVE(libc, calloc);
  RESOLVE(libc, realloc);
  RESOLVE(libc, memalign);
  RESOLVE(libc, memset);
  RESOLVE(libc, memcpy);
  RESOLVE(libc, memcmp);
  RESOLVE(libc, strcpy);
  RESOLVE(libc, strncpy);
  RESOLVE(libc, strcat);
  RESOLVE(libc, strncat);
  RESOLVE(libc, strlen);
  RESOLVE(libc, strcmp);
  RESOLVE(libc, strncmp);
  RESOLVE(libc, sprintf);
  RESOLVE(libc, snprintf);
  RESOLVE(libc, sscanf);
  RESOLVE(libc, strchr);
  RESOLVE(libc, strrchr);
  RESOLVE(libc, strstr);
  RESOLVE(libc, strdup);
  RESOLVE(libc, index);
  RESOLVE(libc, rindex);
  RESOLVE(libc, isdigit);
  RESOLVE(libc, atoi);
  RESOLVE(libc, strlcpy);
  RESOLVE(libc, strerror);
  RESOLVE(libc, _Getpctype);
  RESOLVE(libc, _Stoul);
  RESOLVE(libc, bcopy);

  RESOLVE(libc, srand);
  RESOLVE(libc, rand);

  RESOLVE(libc, asctime);
  RESOLVE(libc, asctime_r);
  RESOLVE(libc, ctime);
  RESOLVE(libc, ctime_r);
  RESOLVE(libc, time);
  RESOLVE(libc, gmtime);
  RESOLVE(libc, gmtime_s);
  RESOLVE(libc, localtime);
  RESOLVE(libc, localtime_r);
  RESOLVE(libc, mktime);

  RESOLVE(libc, opendir);
  RESOLVE(libc, readdir);
  RESOLVE(libc, readdir_r);
  RESOLVE(libc, telldir);
  RESOLVE(libc, seekdir);
  RESOLVE(libc, rewinddir);
  RESOLVE(libc, closedir);
  RESOLVE(libc, dirfd);

  RESOLVE(libc, getprogname);

  RESOLVE(libc, fopen);
  RESOLVE(libc, fread);
  RESOLVE(libc, fwrite);
  RESOLVE(libc, fseek);
  RESOLVE(libc, ftell);
  RESOLVE(libc, fclose);
  RESOLVE(libc, fprintf);*/
}