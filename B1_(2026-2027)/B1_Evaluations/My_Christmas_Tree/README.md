<p align="center">
<img src="./Banner.svg" alt= "Banner" width="800" height="200" />
</p>

<br />

<div align="center">

<a href="" target="_blank" rel="noopener">
  <img src="Badge.svg" alt="Badge" width="250" height="49" />
</a>

</div>

<br />
<br />
<br />
<br />
<br />
<br />

<div align="center">

# Christmas Tree

<br />

<img src="ReadmeRessource.jpg" alt="error message" width="200" align="center">

<br/>

*"Picture of a Christmas Tree"*

</div>

<br />
<br />

<div align="center">

## {🗂️}\ Summary

<br />

<h3>
  <a href="#context" style="text-decoration: none;">
    <kbd style="font-size: 0.9em; padding: 0.3em 0.6em; font-weight: bold;">Context</kbd>
  </a>
</h3>


<br />

<h3>
  <a href="#guide" style="text-decoration: none;">
    <kbd style="font-size: 0.9em; padding: 0.3em 0.6em; font-weight: bold;">Guide</kbd>
  </a>
</h3>

<br />

<h3>
  <a href="#more-information" style="text-decoration: none;">
    <kbd style="font-size: 0.9em; padding: 0.3em 0.6em; font-weight: bold;">More Information</kbd>
  </a>
</h3>

<br />

<h3>
  <a href="#download" style="text-decoration: none;">
    <kbd style="font-size: 0.9em; padding: 0.3em 0.6em; font-weight: bold;">Download</kbd>
  </a>
</h3>

<br />

<h3>
  <a href="#future" style="text-decoration: none;">
    <kbd style="font-size: 0.9em; padding: 0.3em 0.6em; font-weight: bold;">Future</kbd>
  </a>
</h3>

<br />

<h3>
  <a href="#credits" style="text-decoration: none;">
    <kbd style="font-size: 0.9em; padding: 0.3em 0.6em; font-weight: bold;">Credits</kbd>
  </a>
</h3>

<br />
<br />

> Clickable Buttons !

</div>

<br />
<br />


<div align="center">

<h2 id="context">{📚}\ Context</h2>

</div>

<br />

> ---
> 
> "Text".
>
> ---

<br />

<div align="center">

<img src="ReadmeRessource1.jpg" alt="Language C logo" width="200" align="center">

<br>

*"Language C logo"*


<br />
<br />

<h2 id="guide">{📖}\ Guide</h2>

</div>

<br />

><a href="" target="_blank" rel="noopener">
>  <img src=".svg" alt="Badge" width="250" height="50" />
> </a>
>
> <br />
>
>  ### " my_christmas_tree.c " : 
> <br>
> <br>
> 
> #### 1. Utility Functions:
> <br>
> 
> **ft_putchar(char c)**: This **function** uses the **low-level system call write(1, &c, 1)** to **print a single character** to **standard output** (**`STDOUT_FILENO`, represented by `1`**). It is a **manual implementation of putchar**.
> <br>
> 
> **print_line(int spaces, int stars, char c)**: This **helper function simplifies printing** a **full line** to avoid **code duplication**. It first prints the **required number of spaces (spaces)** to ensure **proper horizontal alignment and centering**. It then **prints the specified character (c**, which will be **`*` for foliage or `|` for the trunk**) the given number of **times (stars)**. Finally, it **ends the line** with a **newline character (\n)**.
> <br>
> <br>
> #### 2. Main Entry Point and Argument Validation:
> <br>
> 
> **Argument Count Check (argc != 2)**: The program requires exactly **one argument** (**the size of the tree**). If the user **runs the program incorrectly** (**./my_christmas_tree with no arguments or multiple arguments**), the **program exits quietly by returning 0**.
> <br>
>
> **Size Validation (size <= 0)**: The **argument is converted to an integer** using **atoi()**. If the **size is 0 or negative**, the **program terminates immediately** without **printing anything**, matching the **requirements for Example 0** and **negative inputs**.
> <br>
> <br>
> 
> #### 3. Calculating Maximum Width (max_width):
> <br>
> 
> To **center the tree perfectly**, the **program needs** to know the exact **length** of the **very bottom row** (**the base of the tree**).
> 
> A **preliminary loop simulates** the **structure** of each **tier (t)** from **top to bottom** to determine the **row count** and **star count**. 
> 
> The **variable max_width** stores the **length of the final row**, which acts as the reference **point to calculate the left indentation (spaces)** for all **preceding lines and the trunk**.
> <br>
> <br>
> 
> #### 4. Drawing the Foliage (Tiers):
> <br>
> 
>The **program loops** through each **tier (t)** and each **row (r)** within that tier.
>
> **For every row, it calculates**:
>
> * The **number of stars (stars)** based on the **current progression**.
> 
> * The **number of leading spaces**: **`(max_width - stars) / 2`** ensuring **symmetrical centering** relative to the **base**.
>
> * It then calls **print_line(spaces, stars, `*`)** to output the line.
> <br>
> <br>
>
> #### 5. Drawing the Trunk
> <br>
> 
> Trunk Width (**trunk_width**):
>
> ```C
> int trunk_width = (size % 2 == 0) ? size + 1 : size;
> ```
>
>If the **size** is even, the **trunk width is adjusted to an odd number** to maintain **symmetry** with the **center of the tree**.
>
> **Height and Display**: The **height** of the **trunk** is exactly equal to size (**`5`** lines of **`|||||`** for a size of **`5`**). It is **centered** using the same **spacing formula: `(max_width - trunk_width) / 2`**.

```C
#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c) {
    write(1, &c, 1);
}

void print_line(int spaces, int stars, char c) {
    for (int i = 0; i < spaces; i++) {
        ft_putchar(' ');
    }
    for (int i = 0; i < stars; i++) {
        ft_putchar(c);
    }
    ft_putchar('\n');
}

int main(int argc, char **argv) {
    if (argc != 2) {
        return 0;
    }
    
    int size = atoi(argv[1]);
    if (size <= 0) {
        return 0;
    }

    
    int current_start = 1;
    int last_rows = 0;
    for (int t = 0; t < size; t++) {
        last_rows = 4 + t;
        if (t + 1 < size) {
            current_start = current_start + 2 * last_rows - 4;
        }
    }
    int max_width = current_start + 2 * (last_rows - 1);

    
    current_start = 1;
    for (int t = 0; t < size; t++) {
        int rows = 4 + t;
        for (int r = 0; r < rows; r++) {
            int stars = current_start + 2 * r;
            int spaces = (max_width - stars) / 2;
            print_line(spaces, stars, '*');
        }
        if (t + 1 < size) {
            current_start = current_start + 2 * rows - 4;
        }
    }

    
    int trunk_width = (size % 2 == 0) ? size + 1 : size;
    for (int i = 0; i < size; i++) {
        int spaces = (max_width - trunk_width) / 2;
        print_line(spaces, trunk_width, '|');
    }

    return 0;
}
```

<br />
<br />
<br />
<br />

<div align="center">

<h2 id="more-information">{🗞️}\ More Information</h2>

<br />

</div>

> ---
>
> "text".
> 
> ---

<br>
<br>

> [!WARNING]
> 

<br />
<br />

<div align="center">

<h2 id="download">{📥}\ Download</h2>

</div>

<br />

> ---
>
> #### Prerequisites:
> **Make sure** you have **installed** on your **system**:
>
> <br>
> 
> <a href="https://code.visualstudio.com/docs/cpp/config-mingw" target="_blank" rel="noopener">
>  <img src="GccBadge.svg" alt="GCC Badge" width="80" height="50" /> 
> </a>
> 
> <br>
> <br>
> <br>
> <br>
> 
> To **compile the project**, run the **terminal command**:
> * **" `gcc -Wall -Wextra -Werror my_christmas_tree.c -o my_christmas_tree` "**. 
> 
> To **execute** the **program**:
> * **" `./my_christmas_tree <size>` "** or **" `./my_cristmas_tree.exe <size>` "**.
> 
> The **project** can be directly downloaded on **GitHub**.
>
> ---

<br />
<br />
<br />

| File | Description | 
|:---:|:---:|
|**my_christmas_tree**| The **main file** it countains the **program** which will draw the **christmas tree** on the **console**.|

<br />
<br />
<br />

<div align="center">

```mermaid
flowchart TB

    Executable(("Text".))

    style Executable fill:#000,stroke:#F5F5F0,stroke-width:2px,color:#fff

```

*"Project Composition"*

</div>

<br />
<br />

<div align="center">

<h2 id="future">{🌌}\ Future</h2>

</div>

</div>

<br />

> ---
>
> "Text".
>
> ---

<br />
<br />

<div align="center">

<h2 id="credits">{📌}\ Credits</h2>

</div>

<br />

<p align="center">

<a href="https://github.com/EliasFCS" target="_blank" rel="noopener">
  <img src="CreditBadge.svg" alt="EliasFCS Badge" width="450" height="54" />
</a>