*This project has been created as part of the 42 curriculum by itakumi.*

## Description
The goal of this project is to create a 3D first-person perspective game inspired by the classic Wolfenstein 3D. 
Written in C, this project explores the raycasting technique to render a 3D environment from a 2D map. Building this from scratch provides a deeper practical understanding of basic computer graphics and mathematics.

## Instructions
### Prerequistes (package install)
This project uses the MiniLibX graphics library. Depending on your operating system, you must install the required dependencies before compiling this project.

## Directory structure
```
.
├── Makefile
├── README.md
├── include
│   ├── cub3d.h
│   ├── init.h
│   ├── parse.h
│   ├── status.h
│   └── utils.h
├── lib
│   ├── get_next_line
│   │   ├── Makefile
│   │   ├── get_next_line.c
│   │   ├── get_next_line.h
│   │   └── get_next_line_utils.c
│   ├── get_next_line_no_nl
│   │   ├── Makefile
│   │   ├── get_next_line_no_nl.c
│   │   ├── get_next_line_no_nl.h
│   │   └── get_next_line_no_nl_utils.c
│   └── libft
│       ├── Makefile
│       ├── ft_atoi.c
│       ├── ft_bzero.c
│       ├── ft_calloc.c
│       ├── ft_isalnum.c
│       ├── ft_isalpha.c
│       ├── ft_isascii.c
│       ├── ft_isdigit.c
│       ├── ft_isprint.c
│       ├── ft_itoa.c
│       ├── ft_memchr.c
│       ├── ft_memcmp.c
│       ├── ft_memcpy.c
│       ├── ft_memmove.c
│       ├── ft_memset.c
│       ├── ft_putchar_fd.c
│       ├── ft_putendl_fd.c
│       ├── ft_putnbr_fd.c
│       ├── ft_putstr_fd.c
│       ├── ft_split.c
│       ├── ft_strchr.c
│       ├── ft_strdup.c
│       ├── ft_striteri.c
│       ├── ft_strjoin.c
│       ├── ft_strlcat.c
│       ├── ft_strlcpy.c
│       ├── ft_strlen.c
│       ├── ft_strmapi.c
│       ├── ft_strncmp.c
│       ├── ft_strnstr.c
│       ├── ft_strrchr.c
│       ├── ft_strtrim.c
│       ├── ft_substr.c
│       ├── ft_tolower.c
│       ├── ft_toupper.c
│       └── libft.h
├── main.c
└── src
    ├── init
    │   └── init_view.c
    ├── parse
    │   ├── load_map
    │   │   ├── load_input_file.c
    │   │   └── validate_extension.c
    │   ├── parse_grid
    │   │   ├── parse_grid.c
    │   │   ├── validate_characters.c
    │   │   ├── validate_player.c
    │   │   └── validate_walls.c
    │   ├── parse_identifier
    │   │   ├── parse_identifiers.c
    │   │   └── set_identifier.c
    │   ├── parse_map.c
    │   └── parse_utils.c
    └── utils
        ├── exit_cub3d.c
        ├── free_array.c
        ├── free_map.c
        ├── free_view.c
        ├── ft_strequal.c
        ├── ft_strndup.c
        └── print_error.c
```

**For Linux (Ubuntu/Debian):**
You need to install the X11 and other related development libraries to compile MiniLibx. Run the follow command:
```bash
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev zlib1g-dev libbsd-dev
```
*(Note: If you encounter missing library errors, ensure you have `libx11-dev` and `libxrandr-dev` installed as well.)*

**For macOS:**
macOS natively supports the required frameworks (OpenGL/AppKit). Simply ensure that you have the Xcode Command Line Tools installed:
```bash
xcode-select --install
```

### Compilation
Once the dependencies are installed, you can compile the project using the provided Makefile.

Build the executable:
```bash
make
```

### Execution
To run the game, provide a `.cub` map file as an argument:
```bash
./cub3d maps/example.cub
```

## Resources
* [Raycasting (Lode Vandevenne)](https://lodev.org/cgtutor/raycasting.html) - Raycasting is a rendering technique to create a 3D perspective in a 2D map...

* **AI Usage:** I use Gemini to understand the reference materials contents.
