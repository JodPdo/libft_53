/* main.c — local tests for libft */
#include "libft.h"

#include <stdio.h>   /* printf */
#include <string.h>  /* strnstr (ref), mem* refs for cross-checks */
#include <ctype.h>   /* is* refs */
#include <stdlib.h>  /* calloc, free */

#define PBOOL(b) ((b) ? "TRUE" : "FALSE")
#define SEP()    printf("--------------------------------------------------\n")

int	main(void)
{
	/* === ctype-like === */
	printf("isalpha('A')=%s, isalpha('1')=%s\n",
		PBOOL(ft_isalpha('A')), PBOOL(ft_isalpha('1')));
	printf("isdigit('9')=%s, isdigit('x')=%s\n",
		PBOOL(ft_isdigit('9')), PBOOL(ft_isdigit('x')));
	printf("isalnum('Z')=%s, isalnum('#')=%s\n",
		PBOOL(ft_isalnum('Z')), PBOOL(ft_isalnum('#')));
	printf("isascii(127)=%s, isascii(200)=%s\n",
		PBOOL(ft_isascii(127)), PBOOL(ft_isascii(200)));
	printf("isprint(' ')=%s, isprint('\\n')=%s\n",
		PBOOL(ft_isprint(' ')), PBOOL(ft_isprint('\n')));
	SEP();

	/* === strlen === */
	printf("strlen(\"hello\")=%zu\n", ft_strlen("hello"));
	SEP();

	/* === memset / bzero / memcpy / memmove === */
	{
		char buf1[16]; char buf2[16];
		ft_memset(buf1, 'A', 5); buf1[5] = '\0';
		printf("memset -> \"%s\"\n", buf1);

		ft_bzero(buf1, sizeof(buf1));
		printf("bzero -> first bytes: %d %d %d\n", buf1[0], buf1[1], buf1[2]);

		ft_memset(buf1, 'X', 8);
		ft_memcpy(buf2, buf1, 8);
		buf2[8] = '\0';
		printf("memcpy -> \"%s\"\n", buf2);

		/* overlap test for memmove */
		char movebuf[20] = "abcdefg";
		ft_memmove(movebuf + 2, movebuf, 5); /* expect "ababcde" */
		movebuf[7] = '\0';
		printf("memmove overlap -> \"%s\"\n", movebuf);
	}
	SEP();

	/* === strlcpy / strlcat === */
	{
		char d1[10] = "abc";
		char d2[10] = "abc";
		size_t r1 = ft_strlcpy(d1, "HELLO", sizeof(d1));
		size_t r2 = ft_strlcat(d2, "XYZ", sizeof(d2));
		printf("strlcpy->ret=%zu, dst=\"%s\"\n", r1, d1);
		printf("strlcat->ret=%zu, dst=\"%s\"\n", r2, d2);
	}
	SEP();

	/* === toupper / tolower === */
	printf("toupper('a')=%c, tolower('Q')=%c\n",
		ft_toupper('a'), ft_tolower('Q'));
	SEP();

	/* === strchr / strrchr === */
	{
		const char *s = "42Bangkok";
		printf("strchr('a')=\"%s\"\n", ft_strchr(s, 'a'));
		printf("strrchr('o')=\"%s\"\n", ft_strrchr(s, 'o'));
	}
	SEP();

	/* === strncmp === */
	printf("strncmp(\"abc\",\"abd\",2)=%d\n", ft_strncmp("abc", "abd", 2));
	printf("strncmp(\"abc\",\"abd\",3)=%d\n", ft_strncmp("abc", "abd", 3));
	SEP();

	/* === memchr / memcmp === */
	{
		const char *t = "hello\0world";
		const char *mc = ft_memchr(t, 'o', 5);
		printf("memchr 'o' in \"hello\" -> %s\n", mc ? mc : "(null)");
		printf("memcmp(\"abc\",\"abd\",2)=%d\n", ft_memcmp("abc", "abd", 2));
		printf("memcmp(\"abc\",\"abd\",3)=%d\n", ft_memcmp("abc", "abd", 3));
	}
	SEP();

	/* === strnstr === */
	{
		const char *hay = "foo bar baz";
		printf("strnstr(\"%s\",\"bar\",11) -> \"%s\"\n",
			hay, ft_strnstr(hay, "bar", 11));
		printf("strnstr(\"%s\",\"baz\",7) -> \"%s\"\n",
			hay, ft_strnstr(hay, "baz", 7) ? ft_strnstr(hay, "baz", 7) : "(null)");
	}
	SEP();

	/* === atoi === */
	printf("atoi(\"   -1234abc\")=%d\n", ft_atoi("   -1234abc"));
	printf("atoi(\"+42\")=%d, atoi(\"0\")=%d\n", ft_atoi("+42"), ft_atoi("0"));
	SEP();

	/* === calloc / strdup === */
	{
		char *dup = ft_strdup("Libft!");
		size_t *arr = (size_t *)ft_calloc(4, sizeof(size_t));
		printf("strdup -> \"%s\"\n", dup);
		printf("calloc zeros -> %zu %zu %zu %zu\n",
			arr[0], arr[1], arr[2], arr[3]);
		free(dup);
		free(arr);
	}
	SEP();

	return (0);
}
