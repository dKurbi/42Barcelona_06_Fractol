# 42Barcelona_06_Fractol
This project is about creating graphically beautiful fractals

## Introduction

The term fractal was first used by mathematician Benoit Mandelbrot in 1974. He based
it on the Latin word fractus which means "broken" or "fractured".
A fractal is an abstract mathematical object, like a curve or a surface, which pattern
remains the same at every scale.
Various natural phenomena – like the romanesco cabbage – have some fractal features.
<p align="center">
  <img src="https://github.com/dKurbi/42Barcelona_06_Fractol/assets/110189061/9bb69188-205d-41f4-ad00-9e753b1df536" >
</p>
I used the school graphical library: the MiniLibX! This library included the basic necessary tools to open a window, create images, and deal with keyboard and mouse events.

## Features

- The program offers functionality for both the Julia set and the Mandelbrot set.
- It already includes the ability to zoom in and out infinitely using the mouse wheel, staying within the limits of the computer, as this is a fundamental aspect of fractals.
- It is capable of creating various Julia sets by accepting different parameters as input.
- The program accepts a parameter via the command line to specify the type of fractal to display in a window.
  - In case no parameter is provided or an invalid one is used, the program will display a list of available parameters and exit gracefully.
- The program already utilizes multiple colors to depict the depth of each fractal, and it even incorporates psychedelic effects for enhanced visuals.
- When compiled with the "make bonus" command, it also provides the option to visualize the Burningship fractal.

### Mandelbrot
<p align="center">
  <img src="https://github.com/dKurbi/42Barcelona_06_Fractol/assets/110189061/6bddbb2a-2035-4d60-a72e-1a8e6dc58502"  width="750">
</p>

### Julia set
<p align="center">
 <img src="https://github.com/dKurbi/42Barcelona_06_Fractol/assets/110189061/e502427c-2331-4385-b00d-f7626387d021" width="750">
</p>

