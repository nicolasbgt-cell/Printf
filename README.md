*This activity has been created as part of the 42 curriculum by nbigot.*

# ft-printf

## Description

`ft_printf` is a C library that reimplements the standard `printf()` function from libc. The goal is to understand variadic functions, type conversions, and low-level string formatting by building the function from scratch using only `write`, `malloc`, and `free`.

The library handles the following format specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`.

## Instructions

### Compilation

```bash
make
```

This produces `libftprintf.a` at the root of the repository.

### Usage

Include the header in your source file:

```c
#include "ft_printf.h"
```

Then compile with the library:

```bash
gcc main.c libftprintf.a -o my_program
```

### Cleanup

```bash
make clean   # removes object files
make fclean  # removes object files and libftprintf.a
make re      # fclean + all
```

## Algorithm and Data Structure

The core of `ft_printf` is a loop that iterates over the format string character by character. When a `%` is encountered, the next character is read to determine which conversion to apply. A `va_list` is used to access the variadic arguments in order via `va_arg`.

Each conversion is handled by a dedicated function:

- **`%c`** — writes a single character with `write`.
- **`%s`** — iterates over the string and writes each character; handles `NULL` by printing `(null)`.
- **`%d` / `%i`** — converts a signed integer to a string using a helper similar to `ft_itoa`, then writes it. Handles `INT_MIN` by casting to `long` before negation.
- **`%u`** — same as `%d` but treats the value as `unsigned int`, so no sign handling needed.
- **`%x` / `%X`** — recursive or iterative base-16 conversion using a charset string (`"0123456789abcdef"` or uppercase).
- **`%p`** — casts the pointer to `unsigned long`, prints `0x` prefix, then formats as lowercase hex.
- **`%%`** — writes a literal `%`.

Every function returns the number of characters written, which `ft_printf` accumulates and returns as its final result. No buffer is used — each character is written immediately via `write`.

## Resources

- [Linux man page — printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Linux man page — stdarg(3)](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [42 Docs — ft-printf hints](https://harm-smits.github.io/42docs/projects/ft_printf)
- [cppreference — printf format](https://en.cppreference.com/w/c/io/fprintf)

### AI usage

AI (Claude) was used to:
- Check Makefile correctness (library name, `ar rcs` flags).

No AI was used to write the core logic of `ft_printf` or its conversion functions.
