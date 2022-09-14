# FILLIT 🧩

This is a project that resembles the popular game Tetris.
Here, the pieces are called tetriminos, and the goal is to position the given shapes in the smallest possible square.

In this project we will read a file, check it for errors (invalid input), determine the given shapes, and place them in the smallest square possible.

When placing the pieces, the top-left corner is prioritized, and they are entered in the order of appearence in the file.


## Usage
1. To compile: ```make``` command will create a ```fillit``` executable.
2. To run it: ```./fillit maps/map_name```<br>
&ensp;Invalid maps will output an error message to the standart output, while valid ones will output the solution.


## Example
Giving the following map
```
....
..##
.##.
....

.##.
..#.
..#.
....

##..
##..
....
....

...#
..##
..#.
....

....
...#
..##
...# 
```

Will produce the following output, where the pieces are represented by letters, according to their order of appearance in the file.

````
.AABB
AA.DB
.EDDB
EEDCC
.E.CC
````
