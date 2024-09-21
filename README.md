# Onegin

Onegin is a program that is sorting strings from input text file.

The output file includes:

1. Normally sorted strings.
2. Strings sorted by comparing from the end to beginning.
3. Input text without any editing.

While sorting we skip no-letter symbols (such as ",:_ etc.). Also Onegin is not case-specific (*'A' = 'a'*).

## Installation

Clone this repository:

```bash
git clone https://github.com/crefr/onegin
```
In the folder with cloned repository use `make` to compile it:

```bash
make
```

In the folder should appear file `run.exe`.

## Usage

As the program is compiled you can use it.
There are several flags that you can use:
1. `-h` or `--help` program prints help message and exits. Usage:
```bash
./run.exe --help
./run.exe -h
```
2. `-i` and `-o` defines input and output file. Usage:
```bash
./run.exe -i input.txt -o output.txt
```
3. `-t` switches program into time measurement mode.
```bash
./run.exe -i input.txt -t
```


