/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolaforg <rolaforg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:03:12 by rolaforg          #+#    #+#             */
/*   Updated: 2020/03/27 12:03:04 by rolaforg         ###   ########lyon.fr   */
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
	printf("\033[4;33m				By rolaforg\033[0m\n");
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
	char *sep = "------------------------------------------------------------------------";
	if (one == two)
	{
		size = strlen(sep) - one - two - 2;
		while (size--)
			printf(" ");
		printf("\033[0;32m");
		printf("OK\n");
	}
	else
	{
		size = strlen(sep) - one - one - 4;
		while (size--)
			printf(" ");
		printf("\033[0;31m");
		printf("FAIL\n");
	}
	printf("\033[0m");
	printf("%s\n", sep);
}

void testing(char *str)
{
	//char *sep = "-----------------------------------------------------------";
	//printf("%s\n", sep);
	printf("\033[4;95mTesting %s :\033[0m\n", str);
	//printf("%s\n", sep);
	printf("\n");
}

int main(void)
{
	header();
	//char *n = NULL;
	char *str = "test";
	int nb = 1337;
	char **ptr1 = &str;
	int	 *ptr2 = &nb;
	unsigned int one = 42;
	unsigned int two = 1337;

	testing("%d");
	test(printf("[%d]", 4), ft_printf("'%d'", 4));
	test(printf("[%d]", 42), ft_printf("'%d'", 42));
	test(printf("[%d]", 420), ft_printf("'%d'", 420));

	testing("%i");
	test(printf("[%i]", 4), ft_printf("'%i'", 4));
	test(printf("[%i]", 42), ft_printf("'%i'", 42));
	test(printf("[%i]", 420), ft_printf("'%i'", 420));

	testing("%c");
	test(printf("[%c]", '!'), ft_printf("'%c'", '!'));
	test(printf("[%c, %c]", '!', '?'), ft_printf("'%c, %c'", '!', '?'));
	test(printf("[%c%c%c]", '$', '$', '$'), ft_printf("'%c%c%c'", '$', '$', '$'));

	testing("%s");
	test(printf("[%s]", "I"), ft_printf("'%s'", "I"));
	//test(printf("[%s]", n), ft_printf("'%s'", n));
	test(printf("[%s]", "Im"), ft_printf("'%s'", "Im"));
	test(printf("[%s]", "Im a string"), ft_printf("'%s'", "Im a string"));
	test(printf("[%s %s %s]", "We", "are", "strings"), ft_printf("'%s %s %s'", "We", "are", "strings"));

	testing("string only");
	test(printf("[I]"), ft_printf("'I'"));
	test(printf("[Im a str]"), ft_printf("'Im a str'"));

	testing("%x");
	test(printf("[%x]", 4), ft_printf("'%x'", 4));
	test(printf("[%x]", 42), ft_printf("'%x'", 42));
	test(printf("[%x]", 420), ft_printf("'%x'", 420));
	test(printf("[%x]", 4200), ft_printf("'%x'", 4200));
	test(printf("[%x]", -1), ft_printf("'%x'", -1));

	testing("%X");
	test(printf("[%X]", 4), ft_printf("'%X'", 4));
	test(printf("[%X]", 42), ft_printf("'%X'", 42));
	test(printf("[%X]", 420), ft_printf("'%X'", 420));
	test(printf("[%X]", 4200), ft_printf("'%X'", 4200));
	test(printf("[%X]", -5), ft_printf("'%X'", -5));
	// -1337000000

	testing("%p");
	test(printf("[%p]", ptr1), ft_printf("'%p'", ptr1));
	test(printf("[%p]", ptr2), ft_printf("'%p'", ptr2));
	test(printf("[%p, %p]", ptr1, ptr2), ft_printf("'%p, %p'", ptr1, ptr2));

	testing("%u");
	test(printf("[%u]", one), ft_printf("'%u'", one));
	test(printf("[%u]", two), ft_printf("'%u'", two));
	test(printf("[%u, %u]", one, two), ft_printf("'%u, %u'", one, two));

	// testing("%5s");
	// test(printf("[%5s]", one), ft_printf("'%5s'", one));
	return (0);
}
