# 42_cub3d

Inspired by Wolfenstein 3D, this project is my first implementation of **raycasting**, a method to represent a coordinate array as a 3D map!

<img src="https://raw.githubusercontent.com/julien-ctx/42_cub3d/master/assets/jungle.png">

## Raycasting and 3D model

> The idea behind raycasting is to trace rays from the eye, one per pixel, and find the closest object blocking the path of that ray (walls).

To do so, I chose to use a **60 degrees field of view** which allows to have an immersive gameplay. In comparison, Wolfenstein uses a 72 degrees FOV.

From the player's eyes, I trace rays from left to right, on the whole width of the window.

In order not to miss any wall in front of the player, I use the **Digital Differential Analysis algorithm** (DDA) which allows me to move diagonally in the 2D map by traversing all the walls on the path.

Thanks to this, I know where the walls in front of the player are, and their distance from the current position.

Now, all I have to do is to display the textures on the screen.

Each of my textures is 64x64 pixels. If the size of the wall on the screen is bigger, I **multiply** by a coefficient each pixel of the image, and I **divide** it in the opposite case.

## Features

You can compile the code using `make` for mandatory part and `make bonus` for bonus part. Here's a list of all Makefile commands to display maps:

- `make clusters`
- `make bocal`
- `make jungle`
- `make amongus`
- `make library`
- `make mine`
- `make village`

Bonus part is an upgraded version of mandatory part and contains the following features:

- Minimap to show your current position on the map. You can press `M` key to make it appear/disappear.
- Mouse rotation. You can click on the screen to make the cursor appear/disappear.
- Wall collision, a must-have on any games!

## Maps

<img src="https://raw.githubusercontent.com/julien-ctx/42_cub3d/master/assets/clusters.png">

<img src="https://raw.githubusercontent.com/julien-ctx/42_cub3d/master/assets/amongus.png">
