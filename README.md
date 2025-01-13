
## 📚 The `printf` Function in C :

The `printf` function is an essential tool in C, used for formatted output. It belongs to the Standard Input/Output Library (`stdio.h`) and allows printing data to the console in a specified format. It is a key tool for displaying information and debugging programs.

![Ajouter un titre](https://github.com/user-attachments/assets/a57b0f0d-e6e9-45dd-8dd9-9c804733fd71)

### The Format String

At the heart of `printf` lies the format string, which combines text with format specifiers. These placeholders, beginning with a `%`, define how the corresponding values should be printed (e.g., `%d` for integers, `%s` for strings).

Example:
```c
char *name = "soukaina";
printf("I am %s .", name);
```
In this case, the format string is `"I am %s ."`, where `%s` will be replaced by the value of `name`.

### Argument Handling

A unique feature of `printf` is its ability to accept a variable number of arguments, which it handles using variadic functions in C. This is facilitated by the `stdarg.h` library, allowing `printf` to process different types and numbers of arguments dynamically.

Example:
```c
int sc = 1337;
char name[] = "soukaina";
printf("Name: %s, school: %d", name, sc);
```
Here, `printf` processes two format specifiers (`%s` and `%d`), requiring two arguments (`name` and `sc`).

### Variadic Functions

To handle multiple arguments, `printf` uses macros like `va_list`, `va_start`, and `va_arg` from the `stdarg.h` library. These allow `printf` to access the arguments one by one, even if the total number is unknown at compile time.

### Format Specifiers

`printf` supports several format specifiers to control how data is printed:

- `%d`: Signed decimal integer
- `%u`: Unsigned decimal integer
- `%i`: Integer in base 10
- `%s`: Null-terminated string
- `%c`: Character
- `%x`: Hexadecimal number (lowercase)
- `%X`: Hexadecimal number (uppercase)
- `%p`: Pointer address (in hexadecimal)
- `%%`: Percent sign

### Authorized Functions and Macros

- `write` (man 2 write)
- `malloc` (man 3 malloc)
- `free` (man 3 free)
- `va_start`, `va_end`, `va_copy`, `va_arg` (man 3)

![image](https://github.com/user-attachments/assets/9461f1b2-a514-4e5c-a550-405788ed5418)
</br>

## The `ft_printf` Function in c :

The `ft_printf` function prints formatted output to the standard output according to the provided format specifier. Let's break down the implementation with helper functions to organize the code.

### Helper Functions

```c
#include "ft_printf.h"

int ft_check(va_list args, char c)
{
    int re = 0;

    if (c == 'd' || c == 'i') re = ft_putnbr(va_arg(args, int));
    else if (c == 'c') re = ft_putchar(va_arg(args, int));
    else if (c == 's') re = ft_putstr(va_arg(args, char *));
    else if (c == 'x') re = ft_puthex(va_arg(args, unsigned int));
    else if (c == 'X') re = ft_puthex_m(va_arg(args, unsigned int));
    else if (c == 'p') {
        re = ft_putstr("0x");
        re += ft_putadress(va_arg(args, unsigned long long));
    }
    else if (c == 'u') re = ft_putunbr(va_arg(args, unsigned int));
    else if (c == '%') return (ft_putchar('%'));
    
    return re;
}
```
### `ft_printf` Implementation

```c
int ft_printf(const char *str, ...)
{
    int i = 0, re = 0;
    va_list args;
    
    va_start(args, str);
    
    while (str[i]) {
        if (str[i] == '%') {
            if (str[i + 1] != '\0') re += ft_check(args, str[++i]);
        } else {
            re += ft_putchar(str[i]);
        }
        i++;
    }
    
    va_end(args);
    return re;
}
```
### Key Helper Functions

- **`ft_putchar`**: Prints a character to the standard output.
- **`ft_putstr`**: Prints a null-terminated string to the standard output.
- **`ft_putnbr`**: Prints an integer to the standard output.
- **`ft_putunbr`**: Prints an unsigned integer.
- **`ft_puthex`**: Prints a hexadecimal number in lowercase.
- **`ft_puthex_m`**: Prints a hexadecimal number in uppercase.
- **`ft_putadress`**: Prints a pointer address in hexadecimal format.
