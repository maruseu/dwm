#!/bin/sh
Y=6


cat >> ddblocks << EOF

uBat () {
	for i in /sys/class/power_supply/BAT?/ ; do
		if [ -e \$i ]; then
			bat=\`cat \$i/capacity\`
			
			if grep 'Discharging' \$i/status > /dev/null; then
				bat="^c#FFFFFF^^r0,0,30,30^^c#888888^^r0,$(expr $Y + 1),1,4^^r1,$(expr $Y - 1),21,8^^c#000000^^r2,$Y,19,6^^c#FF5577^^r2,$Y,\$(expr \$bat / 5),6^^f22^"
			else
				bat="^c#FFFFFF^^r0,0,30,30^^c#888888^^r0,$(expr $Y + 1),1,4^^r1,$(expr $Y - 1),21,8^^c#000000^^r2,$Y,19,6^^c#55FF77^^r2,$Y,\$(expr \$bat / 5),6^^f22^"
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

