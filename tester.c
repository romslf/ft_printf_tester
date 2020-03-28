/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:03:12 by rolaforg          #+#    #+#             */
/*   Updated: 2020/03/28 18:39:37 by rolaforg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "printf.h"

int	ft_printf(const char *, ...);

void header(void)
{
	printf("\033[1;36m");
	printf("------------------------------------------------------------------------\n");
	printf(" 	 	 _____  _____  _____ _   _ _______ ______\n");
	printf("		|  __ \\|  __ \\|_   _| \\ | |__   __|  ____|\n		| |__) | |__) | | | |  \\| |  | |  | |__   \n		|  ___/|  _  /  | | | . ` |  | |  |  __|  \n		| |    | | \\ \\ _| |_| |\\  |  | |  | |     \n		|_|    |_|  \\_\\_____|_| \\_|  |_|  |_|     \n");
	printf("\033[4;33mBy rolaforg\033[0m\n");
	printf("\033[1;36m");
	printf("------------------------------------------------------------------------\n");
	printf("\033[0m");
	printf("\n");
	printf("\033[7;49m");
	printf("Légende: ");
	printf("\033[0m");
	printf("[]: printf, '': ft_printf\n\n");

}

void test(int one, int two)
{
	int size = 0;
	int sepSize = 50;
	if (one == two)
	{
		size = sepSize - one - two - 2;
		printf("%*s", size, "\033[0;32m OK \033[0m\n");
	}
	else
	{
		size = sepSize - one - one - 4;
		printf("%*s", size, "\033[0;31m FAIL \033[0m\n");
	}
}

void testing(char *str)
{
	printf("\033[4;95mTesting %s :\033[0m\n", str);
}

int main(void)
{
	header();
	char *str = "test";
	int nb = 1337;
	char **ptr1 = &str;
	int	 *ptr2 = &nb;
	unsigned int one = 42;
	unsigned int two = 1337;
	testing("String only");
	test(printf("[\u0243 \u0243 \u0243 \u0243 \u0243 \u0243 \u0243 ]"), ft_printf("'\u0243 \u0243 \u0243 \u0243 \u0243 \u0243 \u0243 '"));
	test(printf("[I]"), ft_printf("'I'"));
	test(printf("[Im a str]"), ft_printf("'Im a str'"));

	testing("%d");
	test(printf("[%d]", NULL), ft_printf("'%d'", NULL));
	test(printf("[%d]", 0), ft_printf("'%d'", 0));
	test(printf("[%d]", -0), ft_printf("'%d'", -0));
	test(printf("[%d]", 2147483647), ft_printf("'%d'", 2147483647));
	test(printf("[%d]", -2147483647), ft_printf("'%d'", -2147483647));
	test(printf("[%d]", 4), ft_printf("'%d'", 4));
	test(printf("[%d]", 42), ft_printf("'%d'", 42));
	test(printf("[%d]", 420), ft_printf("'%d'", 420));

	testing("%i");
	test(printf("[%i]", NULL), ft_printf("'%i'", NULL));
	test(printf("[%i]", 0), ft_printf("'%i'", 0));
	test(printf("[%i]", -0), ft_printf("'%i'", -0));
	test(printf("[%i]", 2147483647), ft_printf("'%i'", 2147483647));
	test(printf("[%i]", -2147483647), ft_printf("'%i'", -2147483647));
	test(printf("[%i]", 4), ft_printf("'%i'", 4));
	test(printf("[%i]", 42), ft_printf("'%i'", 42));
	test(printf("[%i]", 420), ft_printf("'%i'", 420));

	testing("%c");
	test(printf("[%c]", NULL), ft_printf("'%c'", NULL));
	test(printf("[%c]", 3000), ft_printf("'%c'", 3000));
	test(printf("[%c]", -300), ft_printf("'%c'", -300));
	test(printf("[%c]", '!'), ft_printf("'%c'", '!'));
	test(printf("[%c, %c]", '!', '?'), ft_printf("'%c, %c'", '!', '?'));
	test(printf("[%c%c%c]", '$', '$', '$'), ft_printf("'%c%c%c'", '$', '$', '$'));

	testing("%s");
	test(printf("[%s]", NULL), ft_printf("'%s'", NULL));
	test(printf("[%s]", "I"), ft_printf("'%s'", "I"));
	test(printf("[%s]", "Im"), ft_printf("'%s'", "Im"));
	test(printf("[%s]", "Im a string"), ft_printf("'%s'", "Im a string"));
	test(printf("[%s %s %s]", "We", "are", "strings"), ft_printf("'%s %s %s'", "We", "are", "strings"));

	testing("%x");
	test(printf("[%x]", NULL), ft_printf("'%x'", NULL));
	test(printf("[%x]", 4), ft_printf("'%x'", 4));
	test(printf("[%x]", 42), ft_printf("'%x'", 42));
	test(printf("[%x]", 420), ft_printf("'%x'", 420));
	test(printf("[%x]", 4200), ft_printf("'%x'", 4200));
	test(printf("[%x]", -1), ft_printf("'%x'", -1));

	testing("%X");
	test(printf("[%X]", NULL), ft_printf("'%X'", NULL));
	test(printf("[%X]", 4), ft_printf("'%X'", 4));
	test(printf("[%X]", 42), ft_printf("'%X'", 42));
	test(printf("[%X]", 420), ft_printf("'%X'", 420));
	test(printf("[%X]", 4200), ft_printf("'%X'", 4200));
	test(printf("[%X]", -5), ft_printf("'%X'", -5));

	testing("%p");
	test(printf("[%p]", NULL), ft_printf("'%p'", NULL));
	test(printf("[%p]", ptr1), ft_printf("'%p'", ptr1));
	test(printf("[%p]", ptr2), ft_printf("'%p'", ptr2));
	test(printf("[%p, %p]", ptr1, ptr2), ft_printf("'%p, %p'", ptr1, ptr2));

	testing("%u");
	test(printf("[%u]", NULL), ft_printf("'%u'", NULL));
	test(printf("[%u]", one), ft_printf("'%u'", one));
	test(printf("[%u]", two), ft_printf("'%u'", two));
	test(printf("[%u, %u]", one, two), ft_printf("'%u, %u'", one, two));

	// testing("%5s");
	// test(printf("[%5s]", one), ft_printf("'%5s'", one));
	return (0);
}
