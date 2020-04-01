# ft_printf_tester
A simple ft_printf project tester for 42 school

## How to use
PATH = Your ft_printf project directory (Default: ../ft_printf)
LIB = Your ft_printf library name (Default: libftprintf.a)
TIMER = Time to wait after each setup log in seconds (Default: 0)
``` bash
sh run.sh PATH LIB TIMER
```

## Currently testing
%d, %i, %c, %s, %x, %X, %p, %u, %10s, %010s and string only.
(Please keep in mind that this is very basics test, more will be added soon)

## Add test
Open tester.c, and for example add this in main:
```c
testing("My own test");
test(printf("[%s !!!]", "my test value"), ft_printf("'%s !!!'", "my test value"));
```
Feel free to open a pull request to add tests !

## Preview
![Screen Shot](https://github.com/romslf/ft_printf_tester/blob/master/screenshot.PNG?raw=true)
