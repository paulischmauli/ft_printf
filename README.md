*This project has been created as part of the 42 curriculum by paziehen.*

# ft_printf

## Description

`ft_printf` is a simplified re-implementation of libc's `printf`, built as the
static library `libftprintf.a`. The goal of the project is to learn how
variadic functions work in C (`stdarg.h`) and how to turn values into text
using only `write`.

Prototype:

```c
int ft_printf(const char *format, ...);
```

The function writes to standard output and returns the number of characters
printed.

### Supported conversions

| Specifier | Output |
|-----------|--------|
| `%c` | a single character |
| `%s` | a string (`(null)` for a null pointer) |
| `%p` | a `void *` in hexadecimal with a `0x` prefix (`(nil)` for a null pointer) |
| `%d`, `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x`, `%X` | an unsigned hexadecimal integer, lowercase or uppercase |
| `%%` | a percent sign |

Flags, field width, precision and length modifiers are not supported.

## Instructions

Build the library (the Makefile uses `cc -Wall -Wextra -Werror` and `ar`):

```sh
make
```

This creates `libftprintf.a` at the root of the repository. Other rules:

```sh
make clean    # remove object files
make fclean   # remove object files and libftprintf.a
make re       # fclean, then build again
```

Use it in your own program:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("%s has %d items (%x)\n", "cart", 42, 42);
    return (0);
}
```

```sh
cc main.c -L. -lftprintf -o demo
./demo
```

## Technical choices

### Algorithm and data structure

- **No output buffer.** The subject forbids re-implementing the buffer
  management of the original `printf`. Every conversion is written directly
  with `write`, and nothing is kept between conversions or between calls.
- **One number routine.** All numeric conversions go through a single
  recursive function that takes an `unsigned long` value and a base (10 or
  16). It prints the higher digits first by recursing on `value / base`, then
  writes the last digit. The recursion depth is bounded by the digit count
  (at most 20 for a 64-bit value).
- **Digit tables.** The only data structures are two constant strings,
  `"0123456789abcdef"` and `"0123456789ABCDEF"`, indexed by the digit value.
  Recursion avoids an intermediate buffer and any dynamic allocation, so there
  is nothing to free.
- **Sign handled separately.** For `%d` and `%i` the sign is written first,
  and the magnitude is computed in unsigned arithmetic (`-(unsigned long)n`).
  This avoids signed overflow for `INT_MIN`.
- **Pointers.** `%p` reads its argument as `void *` and converts it to
  `unsigned long`.

### Deliberate decisions and assumptions

- **`write` errors are not checked.** If `write` fails, the failure is not
  reported and the returned count may be lower than the length of the
  intended output. This is a conscious trade-off in order to keep
  the focus on learning variadic functions and not drifting off to far.
- **Unsupported specifiers.** An unknown conversion character, or a `%` at the
  end of the format string, makes `ft_printf` stop and return `-1`. Output
  already written stays written.
- **Null pointers.** `%s` with `NULL` prints `(null)` and `%p` with `NULL`
  prints `(nil)`, matching glibc. Passing `NULL` to `%s` is undefined in
  standard C, so this follows glibc rather than the standard.
- **Platform.** `(unsigned long)pointer` is implementation-defined. The code
  assumes a platform where `unsigned long` can hold a pointer, such as LP64
  Linux or macOS. It isn't portable to LLP64 systems such as 64-bit Windows.
- **Output compared with libc.** Behaviour was compared against the system
  `printf` for return values and output bytes.
  [You can look up my test cases and program on my Github.](https://github.com/paulischmauli/ft_printf_tester)

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- [understanding ft_printf by nikito](https://www.youtube.com/watch?v=Hb2m7htiKWM)

### Use of AI

AI was used to break down new concepts and as a researching shortcut.
I also used it for
- suggesting edge cases for testing (`INT_MIN`, `(void *)-1`, a trailing `%`)
- checking the project against the Norm
- generating the skeleton and lists/boxes for this README.

All code was written and tested by me.
