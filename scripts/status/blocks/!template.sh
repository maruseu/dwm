#!/bin/sh

if which pactl; then
	cat >> ddblocks << EOF

EOF

	cat >> udblocks << EOF

EOF

	printf "\$mpd" >> rootVars

fi
