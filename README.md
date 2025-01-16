# Custom Print Function in C

This is a simple C project that implements a custom print function, `printfm`, which mimics the standard `printf` function. The `printfm` function recognizes input data types (characters and integers) and prints them using the `putchar` function.

## Features

- `printfm` supports:
  - Printing characters (`%c`).
  - Printing integers (`%d`), including negative numbers.
- It processes format strings and prints the corresponding data.

## Code Overview

The main function demonstrates how to use `printfm`:

```c
#include <stdio.h>

int printfm(const char *format, void *argument);

int printfm(const char *format, void *argument) {  
    int i, j, k;
    
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            if (format[i] == 'c') {
                char c = (char*)argument;
                putchar(c);
            } else if (format[i] == 'd') {
                int d = (int)argument;
                if (d < 0) {
                    putchar('-');
                    d = -d;
                }
                int digit_count = 0;
                int tmp = d;
                do {
                    digit_count++;
                    tmp /= 10;
                } while (tmp > 0);
                for (j = digit_count - 1; j >= 0; j--) {
                    int divisor = 1;
                    for (k = 0; k < j; k++) {
                        divisor *= 10;
                    }
                    int digit = (d / divisor) % 10;
                    putchar('0' + digit);
                }
            } else {
                putchar('?');
            }
        } else {
            putchar(format[i]);
        }
    }
}

int main() {
    char ch = 'Z';
    int num = -434543524;
    printfm("%c\n\r", &ch);
    printfm("%d\n\r", &num);
    getch(0);
    return 0;
}
```


## How to Use

- Clone or download this repository.
- Open the project in your preferred C development environment.
- Compile the code.
- Run the program to see the output of the custom printfm function.

## License

This project is open-source and available under the MIT License.

This will serve as a helpful introduction to your code, explaining its purpose and how to use it. You can modify it if you add more features or need to update instructions.
