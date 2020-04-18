#!/bin/sh
Y=6


cat >> ddblocks << EOF

uBat () {
	for i in /sys/class/power_supply/BAT?/ ; do
		if [ -e \$i ]; then
			bat=\`cat \$i/capacity\`
			
			if grep 'Discharging' \$i/status > /dev/null; then
			bat="⇣ \$bat""%"
			else
			bat="⚡ \$bat""%"
			fi
			tbat="\$cs\$s1\$bat\$s2"
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

