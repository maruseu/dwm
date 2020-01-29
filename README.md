![dwm logo](dwm.png)
# Marusa's dwm build

dwm is an extremely fast, small, and dynamic window manager for X.


## Requirements

In order to build dwm you need the Xlib header files.

Optional:

- MPC, pulseaudio and ibus for the statusbar
- Compositor for transparency

## Building dwm

`make`

`sudo make install`

A script `build.sh` is included to quickly rebuild, install and restart dwm for when you're tweaking dwm.

## Running dwm

Add the following line to your .xinitrc to start dwm using startx:

`exec dsession`

## Patches

- Alpha
- Vanity gaps
- Statusbar on all monitors
