
Fdf is a small project for drawing a 3D representation of the landscape.

From task: 
>The representation in 3D of a landscape is a critical aspect of modern mapping. For
>example, in these times of spatial exploration, to have a 3D representation of Mars is a
>prerequisite condition to its conquest. As another example, comparing various 3D representations of an area of high tectonic activity will allow you to better understand these
>phenomenon and their evolution, and as a result be better prepared.

The target platform of the project is MacOS, but linux is also supported.

For Linux support read ```minilibx/man/man1/mlx.1``` and edit Makefile to X-Window support.

Use `make` for making a binary-file.

Use `./fdf *map_path*` to run the Fdf.

"Map" is a text file representing a height map with a top view.
For example, the map
```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```
will represented as

![screenshot of sample](https://i.ibb.co/LkmhvV1/Screen-Shot-2019-04-12-at-20-45-39.png)

Sample maps are located in the directory `test_maps` in project path.
