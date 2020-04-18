#!/bin/sh

Y=8
vol_rect="\$cs\$s1^c#888888^^r0,$(($Y - 1)),54,4^^c#000000^^r2,$Y,50,2^"
if which pactl; then
	cat >> ddblocks << EOF
uVolume () {
	volume=\`pactl list sinks | grep -v 'Base Volume' | grep Volume | head -1 | awk '{print \$5}' | tr -d "%"\`
	mute=\`pactl list sinks | grep Mute | awk '{print \$2}'\`
	if [ \$mute = "no" ]; then
		if [ "\$volume" -gt 100 ]; then
			volume="$vol_rect^c#55FF77^^r2,$Y,50,2^^c#FF5577^^r2,$Y,\$(expr \$(expr \$volume - 100) / 2),2^^f54^\$s2"
		elif [ "\$volume" -ge 50 ]; then
			volume="$vol_rect^c#55FF77^^r2,$Y,\$((\$volume / 2)),2^^f54^\$s2"
		elif [ "\$volume" -ge 0 ]; then
			volume="$vol_rect^c#FFFF77^^r2,$Y,\$((\$volume / 2)),2^^f54^\$s2"
		fi
	else
			volume="$vol_rect^c#AAAAAA^^r2,$Y,\$((\$volume / 2)),2^^f54^\$s2"
	fi

	updateRoot=1
}

iVolume=2
uVolume

trap "sVolume=1;" USR1
sVolume=0

EOF

	cat >> udblocks << EOF
	if [ "\$((\$time % \$iVolume))" -eq "0" ] || [ \$sVolume -eq "1" ]; then
		printf "volume.."
		uVolume
		sVolume=0
	fi
EOF

	printf "\$volume" >> rootVars

elif which amixer; then
	cat >> ddblocks << EOF
uVolume () {
	volume=\`amixer get Master | grep 'Mono: Playback' | awk '{print \$4}' | tr -d "[\[\]]" | tr -d '%'\`
	mute=\`amixer get Master | grep "\[off\]"\`
	if [ -z \$mute ]; then
		if [ "\$volume" -eq "0" ]; then
			volume="\$cn\$s1\$volume%\$s2"
		elif [ "\$volume" -gt "100" ]; then
			volume="\$cw\$s1\$volume%\$s2"
		elif [ "\$volume" -gt "20" ]; then
			volume="\$cs\$s1\$volume%\$s2"
		elif [ "\$volume" -gt "0" ]; then
			volume="\$cw\$s1\$volume%\$s2"
		fi
	else
		volume="\$cn\$s1"MUTE"\$s2"
	fi

	updateRoot=1
}

iVolume=2
uVolume

trap "sVolume=1;" USR1
sVolume=0

EOF

	cat >> udblocks << EOF
	if [ "\$((\$time % \$iVolume))" -eq "0" ] || [ \$sVolume -eq "1" ]; then
		printf "volume.."
		uVolume
		sVolume=0
	fi
EOF
 
	printf "\$volume" >> rootVars

fi
