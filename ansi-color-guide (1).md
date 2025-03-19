# Using Colors in C with ANSI Escape Codes

## Introduction

ANSI escape codes allow you to add colors and text formatting to your terminal output in C programs. This guide will explain how to use them effectively for more readable and visually appealing command-line interfaces.

## Basic Syntax

ANSI color codes follow this format:
```
\033[<style>;<foreground>;<background>m
```

Where:
- `\033[` is the escape sequence (sometimes written as `\e[`)
- `<style>` is for text effects (bold, underline, etc.)
- `<foreground>` sets the text color
- `<background>` sets the background color
- `m` ends the sequence

## Color Codes Reference

### Text Styles
- `0`: Reset/Normal
- `1`: Bold
- `2`: Dim
- `3`: Italic
- `4`: Underline
- `5`: Blinking
- `7`: Reverse (swap foreground/background)
- `8`: Hidden

### Foreground Colors (Text)
- `30`: Black
- `31`: Red
- `32`: Green
- `33`: Yellow
- `34`: Blue
- `35`: Magenta/Purple
- `36`: Cyan
- `37`: White
- `90-97`: Bright versions (90=Bright Black/Gray, 91=Bright Red, etc.)

### Background Colors
- `40`: Black
- `41`: Red
- `42`: Green
- `43`: Yellow
- `44`: Blue
- `45`: Magenta/Purple
- `46`: Cyan
- `47`: White
- `100-107`: Bright backgrounds

## Basic Examples

```c
#include <stdio.h>

int main() {
    // Simple colored text
    printf("\033[31mThis is red text\033[0m\n");
    
    // Bold blue text
    printf("\033[1;34mThis is bold blue text\033[0m\n");
    
    // Green text on yellow background
    printf("\033[32;43mGreen on yellow\033[0m\n");
    
    return 0;
}
```

## Best Practices

### 1. Always Reset After Colored Text

Always terminate your colored output with the reset code `\033[0m` to avoid the color "bleeding" into subsequent output:

```c
printf("\033[32mThis is green\033[0m and this is normal\n");
```

### 2. Define Color Constants

For better readability, define macros or constants for your colors:

```c
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

printf(RED "Error: " RESET "Something went wrong\n");
```

### 3. Create Helper Functions

For more complex applications, create helper functions:

```c
void print_colored(const char* text, const char* color) {
    printf("%s%s%s", color, text, RESET);
}

print_colored("Success!", GREEN);
```

## Advanced Usage Examples

### Error/Warning/Success Messages

```c
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define RESET   "\033[0m"

void print_error(const char* message) {
    printf("%sERROR: %s%s\n", RED, message, RESET);
}

void print_warning(const char* message) {
    printf("%sWARNING: %s%s\n", YELLOW, message, RESET);
}

void print_success(const char* message) {
    printf("%sSUCCESS: %s%s\n", GREEN, message, RESET);
}
```

### Progress Bar

```c
void progress_bar(int progress, int total) {
    int bar_width = 50;
    float percent = (float)progress / total;
    int filled = percent * bar_width;
    
    printf("\033[0;36m[");
    for (int i = 0; i < bar_width; i++) {
        if (i < filled) {
            printf("█");
        } else {
            printf(" ");
        }
    }
    printf("] %.1f%%\033[0m\r", percent * 100);
    fflush(stdout);
}
```

### Complete Example: Logger

```c
#include <stdio.h>
#include <time.h>
#include <stdarg.h>

#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"

enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

void log_message(enum LogLevel level, const char* format, ...) {
    time_t now;
    char time_buffer[26];
    const char* level_str;
    const char* color;
    
    time(&now);
    ctime_r(&now, time_buffer);
    time_buffer[24] = '\0'; // Remove newline
    
    switch (level) {
        case DEBUG:
            level_str = "DEBUG";
            color = CYAN;
            break;
        case INFO:
            level_str = "INFO";
            color = GREEN;
            break;
        case WARNING:
            level_str = "WARNING";
            color = YELLOW;
            break;
        case ERROR:
            level_str = "ERROR";
            color = RED;
            break;
        case CRITICAL:
            level_str = "CRITICAL";
            color = BOLD RED;
            break;
        default:
            level_str = "UNKNOWN";
            color = WHITE;
    }
    
    printf("%s[%s] [%s%s%s]: ", BLUE, time_buffer, color, level_str, RESET);
    
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    
    printf("\n");
}

int main() {
    log_message(DEBUG, "This is a debug message");
    log_message(INFO, "System initialized with %d threads", 4);
    log_message(WARNING, "Low memory: %d MB remaining", 100);
    log_message(ERROR, "Failed to open file: %s", "data.txt");
    log_message(CRITICAL, "System shutting down!");
    
    return 0;
}
```

## Compatibility Notes

1. ANSI colors work in most Unix/Linux terminals, macOS Terminal, Windows Terminal, and modern Windows 10/11 command prompt.

2. For older Windows systems, you may need to:
   - Use the Windows API with functions like `SetConsoleTextAttribute()`
   - Enable ANSI support with `system("color")`
   - Use libraries like PDCurses or ncurses

3. Some terminals support 256 colors and RGB using extended codes:
   ```c
   // 256 colors
   printf("\033[38;5;208mOrange text\033[0m\n");
   
   // RGB (24-bit color)
   printf("\033[38;2;255;128;0mCustom orange\033[0m\n");
   ```

## Conclusion

ANSI escape codes provide a simple way to enhance your terminal applications with color and style. By using these codes effectively, you can create more intuitive and visually appealing interfaces for your C programs.
