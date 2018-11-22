# SDT-example-vddioh

## 1. Getting started

PMIC example for Mbed OS

### 1-1. Supported board
- SDT32620B
- SDT32625B

### 1-2. Import the example code

From the command-line, import the example:

```
mbed import https://github.com/SigmaDeltaTechnologiesInc/SDT-example-vddioh
cd SDT-example-vddioh
```

### 1-3. Compile

Invoke `mbed compile`, and specify the name of your favorite toolchain (`GCC_ARM`, `ARM`, `IAR`) and your platform. 
For example, for the GCC_ARM and SDT32620B:

```
mbed compile -t GCC_ARM -m SDT32620B
```

Your PC may take a few minutes to compile your code. 
At the end, you see the following result:

```
[snip]
+------------------+-------+-------+------+
| Module           | .text | .data | .bss |
+------------------+-------+-------+------+
| [fill]           |   112 |     4 | 2496 |
| [lib]\c.a        | 31907 |  2472 |   89 |
| [lib]\gcc.a      |  3168 |     0 |    0 |
| [lib]\misc       |   248 |     8 |   28 |
| [lib]\nosys.a    |    32 |     0 |    0 |
| main.o           |   314 |     0 |  372 |
| mbed-os\drivers  |  1197 |     0 |    0 |
| mbed-os\features |    42 |     0 |  184 |
| mbed-os\hal      |  1669 |     4 |   68 |
| mbed-os\platform |  4503 |   260 |  217 |
| mbed-os\rtos     |  8946 |   168 | 6073 |
| mbed-os\targets  |  9153 |    12 |  409 |
| Subtotals        | 61291 |  2928 | 9936 |
+------------------+-------+-------+------+
Total Static RAM memory (data + bss): 12864 bytes
Total Flash memory (text + data): 64219 bytes

Image: .\BUILD\SDT32620B\GCC_ARM\SDT-example-vddioh.bin
```

### 1-4. Program your board

1. Connect your mbed device to the computer over USB.
1. Copy the binary file(SDT-example-vddioh.bin) to the mbed device.
1. Press the reset button to start the program.

The LED on your platform turns on and off.

## 2. Troubleshooting

If you have problems, you can review the [documentation](https://os.mbed.com/docs/latest/tutorials/debugging.html) for suggestions on what could be wrong and how to fix it.
