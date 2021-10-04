# FdF | vifernan42

The goal of this project is to create a 3d map with the coordinates read from a text file (in this case will be a .fdf file). As a bonus part I made the posibility of changing the perspectives, make zoom, move from the screen, etc. (here you can see what else can you do).

![france](https://espaciodron.es/france_map.png)

### Index
* [Read map](#Read-map)
* [Draw_map](#Draw-map)
* [Colors](#Colors)
* [How to use](#How-to-use)
* [Check_errors](#Check-errors)

### Read map

The map is given in a text format (example below). As you can see its a rectangle or a square. The number on it is the z value of the coordenates saved on the following variable ````select->map[y][x]```` inside the select struct.
![img_read](https://espaciodron.es/read_m.png)
