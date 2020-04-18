#!/bin/sh
Y=5


cat >> ddblocks << EOF

uBat () {
	tbat=""
	for i in /sys/class/power_supply/BAT?/ ; do
		if [ -e \$i ]; then
			bat=\`cat \$i/capacity\`
			
			if grep 'Discharging' \$i/status > /dev/null; then
				bat="^c#888888^^r0,$(($Y + 2)),1,4^^r1,$(($Y - 1)),12,10^^c#000000^^r2,$Y,10,8^^c#FF5577^^r2,$Y,\$((\$bat / 10)),8^^f13^"
			else
				bat="^c#888888^^r0,$(($Y + 2)),1,4^^r1,$(($Y - 1)),12,10^^c#000000^^r2,$Y,10,8^^c#55FF77^^r2,$Y,\$((\$bat / 10)),8^^f13^"
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

	if [ "\$((\$time % \$iBat ))" -eq "0" ]; then
		printf "bat.."
		uBat
	fi

EOF

printf "\$tbat" >> rootVars

