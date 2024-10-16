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
The following lists all the directories where you should put corresponding asset types.
Make sure you use the exact file types each folder states to use below

### Maps [.json]
```maps/```

### Tilesets [.png]
```assets/tilesets/```

### Sprites [.png]
```assets/sprites/```

### Sounds [.ogg]
```assets/sounds/```

### Fonts [.ttf]
```assets/fonts/```

# Tilemaps
The maps are built using Tiled.
This engine contains the tiled templates for each object in the templates folder.
Example: Door, Wall, Trigger, etc.

The maps are saved as **.JSON**, same as the template files.

Get Tiled here: https://www.mapeditor.org/

### Layers
When using this engine the following tile, and object layers must be present with the correct object/template types on each layer
It goes in the following order, do not include the bracketed [type] in the name.
It is case sensitive.
```
tiles_above [tile layer]
triggers    [object layer]
walls       [object layer]
doors       [object layer]
objects     [object layer]
tiles_below [tile layer]
```

### Loading a tilemap in game
In the engine cpp
Create a nullptr to a TileMap* object
```cpp
TileMap* tilemap = nullptr;
```

In the create event init the tilemap
```cpp
tilemap = new TileMap("maps/level1/","level1","basement_tutorial2_empty");
```
### The parameters require the following:
- First enter the map directory (that also contains the following files)
- then the JSON filename, excluding the .json extension
- then the spritesheet filename, exlcluding the .png extension

In the engine Draw() event call the following to draw the tilemap
```cpp
tilemap->DrawBelow();

//draw player and other objects here

tilemap->DrawAbove();
```


### Libraries this project uses
sdl2, imgui, tileson

### Special thanks to the following
madsycode, sdl enthusiasts discord