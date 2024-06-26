
## Fdf is a small project for drawing a 3D representation of the landscape.

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

![screenshot of sample](https://github.com/heybellakrim/fdf/blob/d3d20fceba1e3935ed3fef5bb3d7daaf2cc750c7/Screen%20Shot%202022-02-27%20at%209.07.56%20PM.png)
![screenshot of sample](https://github.com/heybellakrim/fdf/blob/38c68d20a1ccaab7332877a1a5bfeb2e067535f7/Screen%20Shot%202022-03-03%20at%206.10.02%20PM.png)

Sample maps are located in the directory `test_maps` in project path.
