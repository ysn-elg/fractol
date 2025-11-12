# fract-ol
A graphical project that explores fractals using the MiniLibX library.  
This is the **fifth project at 1337 (42 Network) school**.

## 🧠 Goal
Render and explore famous fractals such as the **Mandelbrot** and **Julia** sets.  
The program uses complex numbers, mathematical iterations, and color gradients to generate detailed fractal visuals.

## ⚙️ Build
make          # builds the fract-ol executable  
make clean    # removes object files  
make fclean   # removes objects + binary  
make re       # rebuilds everything

## 🚀 Usage
./fractol mandelbrot  
./fractol julia  
./fractol julia <real> <imaginary>

### 🖱️ Controls
Zoom → Scroll up/down  
Move → Arrow keys  
Change colors → R,G,B \ T,H,N key  
Exit → ESC  

## 🧮 Notes
Uses **MiniLibX** for graphical rendering.  
Complex numbers are mapped to pixel coordinates.  
Smooth color transitions are achieved through iteration-based color gradients.
