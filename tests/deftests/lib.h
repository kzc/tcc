#pragma once
#ifdef __TINYC__
#  define NAME(S) (S "_tcc")
#elif defined(__GNUC__)
#  define NAME(S) (S "_gcc")
#elif defined(__clang__)
#  define NAME(S) (S "_clang")
#else
#  define NAME(S) (S "_cc")
#endif
int func_to(void);
int func_one(void);
int func_four(void);
int func_three(void);
const char *lib_name(void);
