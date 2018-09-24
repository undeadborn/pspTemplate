# VSCODE PSP HOMEBREW TEMPLATE

## Introduction
Visual Studio Code project template for PSP homebrew creation using MINPSP Windows SDK.

What's included in this template?
* This project uses the Microsoft VSCode C/C++ extension to have the Visual Studio C/C++ features in VSCode (such as IntelliSense), so it includes the `c_cpp_properties.json` VSCode properties file with the required configuration to be integrated with MINPSP SDK libraries and PSP GCC compiler. 
* Has been defined a folder structure for the project. Feel free to use it or modify for your project.
* Includes the `Makefile` file to easily build the resulting `EBOOT.PBP` file using `make` command.

## Project structure
This project implements a basic Hello World example, and follows the next folder structure:
```
.src/ # your main project source
.res/ # any asset, such as PSP icon, background and music (if any) for your homebrew
.lib/ # any 3rd party lib
Makefile # the makefile required to build your program
```

Remember that any new src file created needs the corresponding `*.o` file to be provided under `OBJS` property in `Makefile` (see main.o and callback.o as example). This is required until I improve the Makefile script.

## Requirements
* [MINPSP for Windows](https://sourceforge.net/projects/minpspw/files/latest/download)
* [Visual Studio Code (aka VSCode)](https://code.visualstudio.com/)
* [Microsoft C/C++ VSCode extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
* PSP with a CFW installed or [PPSSPP](https://www.ppsspp.org/) emulator.

## How to start
- Install MINPSP, VSCode and C/C++ extension from the Requirements section.
- Clone or download this repository.
- Inside root project folder, execute `make` to generate the EBOOT.PBP.
- Open the EBOOT.PBP with PPSSPP emulator or put the file in your PSP `/PSP/GAME/` folder.
- If you want to clean the generated binaries, use `make clean`.

## TODO
- Programatically add all `*.o` files from src in `Makefile` `OBJS` property.
- Specify a target folder (that would be created automatically, if not exists) for the binaries created by `make` command.
- Include a quick introduction on this readme of how to debug with PSPLink

## Why this ? Personal comments ...
I was playing around with PSPSDK, MINPSP... Didn't want to use Visual Studio because my laptop is quite slow and VSCode is very lightweight in comparison. 

My first attemp was to use Linux instead of Windows, so I tried to compile PSPSDK Toolchain in Ubuntu, but faced some errors while building dependencies (some users are facing the same problem as well, there are some issues in github repo about this). I noticed they have a Docker file, but didn't tried out because I prefer to have direct access to SDK libraries for IDE purposes ...

After some few more attemps, I decided to test the MINPSP SDK in Linux (in fact, MINPSP extends PSPSDK including more C libraries ported for PSPSDK), but faced errors with the .deb package installation as well. 

Finally I tested with MINPSP build for Windows, and didn't faced any problem with this.

In fact, you can use this template with whatever PSP SDK you use. You only need to update the `c_cpp_properties.json` with your configuration.