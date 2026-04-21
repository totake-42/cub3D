*This project has been created as part of the 42 curriculum by itakumi, totake.*

## Description
The goal of this project is to create a 3D first-person perspective game inspired by the classic Wolfenstein 3D. 
Written in C, this project explores the raycasting technique to render a 3D environment from a 2D map. Building this from scratch provides a deeper practical understanding of basic computer graphics and mathematics.

## Instructions
### Prerequistes (package install)
This project uses the MiniLibX graphics library. Depending on your operating system, you must install the required dependencies before compiling this project.

**For Linux (Ubuntu/Debian):**
You need to install the X11 and other related development libraries to compile MiniLibx. Run the follow command:
```bash
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```
*(Note: If you encounter missing library errors, ensure you have `libx11-dev` and `libxrandr-dev` installed as well.)*

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

* **itakumi AI Usage**
  * I use Gemini to understand the reference materials contents.
* **totake AI Usage**
  * Understanding the project subject and requirements
  * Supplementing mathematical knowledge
  * Code explanation and clarification
  * Code suggestions and auto-completion
  * Generating maps and textures for testing
  * Generating README.md
  * *Note: All implemented code has been fully understood and reviewed. No code was used without proper comprehension.*