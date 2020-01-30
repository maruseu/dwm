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
- Stacker

## Keybindings

`Super + { 1 .. 9 }` View tag

`Super + Control + { 1 .. 9 }` View tag add

`Super + Shift + { 1 .. 9 }` Tag current window

`Super + Shift + Control { 1 .. 9 }` Append tag current window

`Super + 0` View all tags

`Super + Shift + 0` Tag current window to all tags


`Super + ], [` View monitor

`Super + Shift + ], [` Tag current window to monitor


`Super + j, k` Change stack focus

`Super + Shift + j, k` Change window's position in stack

`Super + h, l` Separator size


`Super + Space` Replace master with current window

`Super + o` Promote current window to master

`Super + Shift + o` Demote current window to slave


`Super + Shift + Space` Toggle floating


`Super + Shift + q` Kill window


`Super + =, -` Volume

`Super + Shift + =, -` Resize gaps


`Super + b` Toggle bar

`Super + g` Toggle gaps

