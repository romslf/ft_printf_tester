# ft_printf_tester
A simple ft_printf project tester for 42 school

## How to use
Simply edit "path" (Line 3) and "libname" (Line 4) in run.sh, then:
``` bash
sh run.sh
```
## Currently testing
%d, %i, %c, %s, %x, %X, %p, %u, and string only.
(Please keep in mind that this is very basics test, more will be added soon)

## Add test
Open tester.c, and for example add this in main:
```c
testing("My own test");
test(printf("[%p]", ptr1), ft_printf("'%p'", ptr1));
```

## Preview
![Screen Shot](https://github.com/romslf/ft_printf_tester/blob/master/screenshot.PNG?raw=true)
