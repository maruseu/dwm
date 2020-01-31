#!/bin/bash
make clean
make && sudo make install && pkill dwm
