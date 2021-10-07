# FdF | vifernan42

The goal of this project is to create a 3d map with the coordinates read from a text file (in this case will be a .fdf file). As a bonus part I made the posibility of changing the perspectives, make zoom, move from the screen, etc. [(here you can see what else can you do)](#How-to-use).

![france](https://espaciodron.es/france_map.png)

### Index
* [Read map](#Read-map)
* [Colors](#Colors)
* [Draw_map](#Draw-map)
* [How to use](#How-to-use)

### Read map

The map is given in a text format (example below). As you can see its a rectangle or a square. The number on it is the z value of the coordenates saved on the following int variable ````select->map[y][x]```` inside the select struct.

![img_read](https://espaciodron.es/read_m.png)

### Read map

Its also allow to give color values for the pixels points in the map. In this case I conteplate to options:
  - The map doesn´t have colors but it has different levels of z (example above).
  - The map has colors.
  ![img_read](https://espaciodron.es/colors.png)
In the first case I print the line where z_from and z_to are diferent whit a degradate color from white the lower value to red the highest. Using the following funtion:

````c
float	ft_remap(t_iso isome, float newFrom, float newTo)
{
	return ((isome.dis - 0) / (isome.hipo - 0) * (newTo - newFrom) + (newFrom));
}
````
With the second case I save the value given (0,0xffffff) in the following variable ````select->color_z[y][x]````.

![img_read](https://espaciodron.es/comparation.png)

### Draw map

For draw the map I use the [Bresenham algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm#:~:text=Bresenham's%20line%20algorithm%20is%20a,straight%20line%20between%20two%20points.&text=It%20is%20one%20of%20the,the%20field%20of%20computer%20graphics.) that it makes a grid to which yo've to change its perspective with the following function:

````c
void	ft_isometric(float *x, float *y, int z, t_vari *select)
{
	*x = (*x - *y) * cos(select->iso);
	*y = (*x + *y) * sin(select->iso) - z;
}
````

*````select->iso```` is the value to change it perspective with the hooks.

### How to use

| Rule | Function |
| - | - |
| ``make`` | Generates _fdf_ and an object file for each .c. |
| ``make clean`` | Deletes all object files. |
| ``make fclean`` | Deletes the object files and the _fdf_. |
| ``make re`` | makes ``fclean`` and ``make`` again. |
| `` make test`` | Allows you to select a map to execute de _fdf_ |

![france](https://espaciodron.es/make.png)

| Character | Object |
| - | - |
| esc | exit |
| + | Zoom in |
| - | Zoom out |
| a | Move left |
| d | Move right |
| s | Move down |
| w | Move up |
| up | Change perspective > iso|
| down | Change perspective < iso |
| c | original map colors on/off |
