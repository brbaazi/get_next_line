# get_next_line 📖

**get_next_line** is a 42 School project where I created a function that reads a file **line by line**.

The goal is to understand **file descriptors, static variables, and memory management** in C.

## 🧠 Concepts

* File descriptors
* `read()`
* Static variables
* Memory management
* Buffers
* Strings
* Dynamic allocation

## 📦 Function

```c
char *get_next_line(int fd);
```

The function returns the next line from a file each time it is called.

Example:

```c
int fd = open("file.txt", O_RDONLY);

char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
```

## 🚀 Usage

Compile:

```bash
cc main.c get_next_line.c get_next_line_utils.c
```

Run:

```bash
./a.out
```

## 🛠️ Technologies

* C
* File Descriptors
* `read()`
* Static Variables
* Dynamic Memory

## 🎯 Goal

Learn how to read files efficiently **line by line** while managing memory correctly.
