<p align="center">
<img src="./ReadmeRessource2.svg" alt= "Banner" width="800" height="200" />
</p>

<br />

<div align="center">

# Printf

<br />

<img src="ReadmeRessource.jpg" alt="Picture of a Print" width="200" align="center">

<br/>

*"Picture of a Print"*

</div>

<br />
<br />

<div align="center">

## Summary

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

<h2 id="context">Context</h2>

</div>

<br />

> ---
>
> A client wants me to **recode a printf function** (who allow to **print a message to the console in "language C"**) without using **loops: while, for and if**. 
>
> Consequently, I decided to recode it.
>
> ---

<br />

<div align="center">

<img src="ReadmeRessource1.jpg" alt="Logo C" width="200" align="center">

<br />

*"C Language Logo"*


<br />
<br />

<h2 id="guide">Guide</h2>

</div>

<br />

> ### Makefile
> First, I created a **Makefile** to **compile the project cleanly** using **gcc** along with strict **warning flags** (**-Wall -Wextra -Werror**). This ensures the **code compiles without warnings** or **undetected bugs** before creating the final **"my_printf executable"**.
> <br>
>
> #### Compilation & Build
>
> The project includes a **Makefile** to handle compilation with **`gcc`**. To maintain high standards and prevent undefined behavior, the project is compiled using strict safety flags: **`-Wall -Wextra -Werror`**.
> <br>
>
> #### Available Rules:
>
> * **`make`** / **`make all`:** Compiles the project and generates the **`my_printf`** executable.
> <br>
>
> * **`make clean`:** **Removes object files** (`.o`).
> <br>
>
> * **`make fclean`:** **Removes object files** and the **generated executable**.
> <br>
> 
> * **`make re`:** Performs a **clean re-compilation** (`fclean` followed by `all`).

```Makefile
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = my_printf
SRCS = my_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

<br />
<br />
<br />

> ---
>
> Finally, I implemented the core game logic in **pure C**, focusing on **modularity**, **robust memory management**, and efficient **input validation**.
>
> ---

<br />

>

```C
Code
```

<br />
<br />
<br />
<br />

<div align="center">

<h2 id="more-information">More Information</h2>

<br />

</div>

> ---
>
> "Text".
> 
> ---

<br />

> [!NOTE]
> "Text".

<br />

> [!WARNING]
> "Text".

<br />
<br />

<div align="center">

<h2 id="download">Download</h2>

</div>

<br />

> ---
>
> #### Prerequisites:
>
> "Text".
>
> <br>
> 
> The **project** can be directly downloaded on **GitHub**.
>
> ---

<br />
<br />

<div align="center">

<h2 id="credits">Credits</h2>

</div>

<br />

<p align="center">

<a href="https://github.com/EliasFCS" target="_blank" rel="noopener">
  <img src="CreditBadge.svg" alt="EliasFCS Badge" width="450" height="54" />
</a>

<br />
<br />
<br />
<br />
<br />
<br />

<img src="License.svg" alt="License" width="450" height="54" />

</p>