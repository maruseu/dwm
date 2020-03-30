#!/bin/sh

cat >> ddblocks << EOF

uBat () {
	for i in /sys/class/power_supply/BAT?/ ; do
		if [ -e \$i ]; then
			bat=\`cat \$i/capacity\`
			if [ \$bat -lt 11 ]; then
				bat="░"
			elif [ \$bat -lt 22 ]; then
				bat="▁"
			elif [ \$bat -lt 33 ]; then
				bat="▂"
			elif [ \$bat -lt 44 ]; then
				bat="▃"	
			elif [ \$bat -lt 55 ]; then
				bat="▄"
			elif [ \$bat -lt 67 ]; then
				bat="▅"
			elif [ \$bat -lt 78 ]; then
				bat="▆"
			elif [ \$bat -lt 89 ]; then
				bat="▇"
			else
				bat="█"
			fi
			
			if grep 'Discharging' \$i/status > /dev/null; then
				tbat="\$ci ▕\$bat▏ "
			else
				tbat="\$cs ▕\$bat▏ "
			fi
		fi
	done
	[ -z "\$tbat" ] && tbat="\$cs"
	updateRoot=1
}
iBat=1
uBat

EOF

	cat >> udblocks << EOF

	if [ "\$( expr \$time % \$iBat )" -eq "0" ]; then
		printf "bat.."
		uBat
	fi

EOF

printf "\$tbat" >> rootVars

