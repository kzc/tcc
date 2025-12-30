// When tcc converts -Dsym=value to source form if the value ends with a
// backslash it must append an additional backslash followed by a newline
// so that it is not parsed as a line continuation character.

#define UNQUOTED_CHAR1 \\\

#define UNQUOTED_STR1 \\Unquoted\\Str1\\\
With\\Continuation\\Line\\\

#define UNQUOTED_STR2 \\Unquoted\\Str2\\\

#define Q(x) #x
#define QUOTE(x) Q(x)

#define CQ(x) (#x[0])
#define CQUOTE(x) CQ(x)

// tcc `cat 90.cflags` -DRUN_TEST -run 90.c
#ifdef RUN_TEST
#include <assert.h>
#include <stdio.h>
#endif

int main() {
char src_char = CQUOTE(UNQUOTED_CHAR1);
assert(src_char == '\\');

char cli_char = CQUOTE(UNQUOTED_CHAR2);
assert(cli_char == '\\');

puts(QUOTE(UNQUOTED_STR1));
puts(QUOTE(UNQUOTED_STR2));
puts(QUOTE(UNQUOTED_STR3));
return 0;
}
