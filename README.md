# skyesrc - 2d game engine
Welcome to my 2d game engine I am building in c++.

# Setup

### Install msys2 c++ mingw compiler
https://www.msys2.org/

Add enviornment variable of the compiler bin to PATH
```
C:\msys64\ucrt64\bin
```

### Building
To open with debugger, open the project with vscode and select "Run And Debug" button on the left sidebar, and select the following option then click the green play button.

Select the following task: ```g++.exe - Build and debug active file```

or run the makefile, there is also a make.sh file to do this task.

Simply run in the terminal to generate the .exe
```
./make.sh
```

# Assets
Make sure you use the exact file types each folder states to use below

### Maps [.tmx]
```maps/```

### Tilesets [.png]
```assets/tilesets/```

### Sprites [.png]
```assets/sprites/```

### Sounds [.ogg]
```assets/sounds/```

### Fonts [.ttf]
```assets/fonts/```

### Libraries this project uses
sdl2, imgui, tileson

### Special thanks to the following
madsycode, sdl enthusiasts discord