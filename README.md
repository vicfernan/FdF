# FdF | vifernan42

The goal of this project is to create a 3d map with the coordinates read from a text file (in this case will be a .fdf file). As a bonus part I made the posibility of changing the perspectives, make zoom, move from the screen, etc. (here you can see what else can you do).

![france](https://espaciodron.es/france_map.png)

### Index
* [Read map](#Read-map)
* [Colors](#Colors)
* [Draw_map](#Draw-map)
* [How to use](#How-to-use)
* [Check_errors](#Check-errors)

### Read map

The map is given in a text format (example below). As you can see its a rectangle or a square. The number on it is the z value of the coordenates saved on the following int variable ````select->map[y][x]```` inside the select struct.

![img_read](https://espaciodron.es/read_m.png)

### Read map

Its also allow to give color values for the pixels points in the map. In this case I conteplate to options:
  - The map doesn´t have colors but it has different levels of z.
  - The map has colors.
In the first case I print the line where z_from and z_to are diferent whit a degradate color from white the lower value to red the highest. Using the following funtion:
````c
float	ft_remap(t_iso isome, float newFrom, float newTo)
{
	return ((isome.dis - 0) / (isome.hipo - 0) * (newTo - newFrom) + (newFrom));
}
````
With the second case I save the value given (0,0xffffff) in the following variable ````select->color_z[y][x]````.
![img_read](https://espaciodron.es/comparation.png)
