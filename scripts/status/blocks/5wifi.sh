#!/bin/sh

if grep wlp3s0 /proc/net/wireless; then
	cat >> ddblocks << EOF

uWifi () {
	wifi=\`grep wlp3s0 /proc/net/wireless | awk '{ print int(\$3 * 100 / 70) }'\`
	if [ \$wifi -ge 80 ]; then
	    wifi="\$cs\$s1◎\$s2"
	elif [ \$wifi -ge 60 ]; then
	    wifi="\$ci\$s1◎\$s2"
	elif [ \$wifi -ge 40 ]; then
	    wifi="\$cw\$s1◯\$s2"
	elif [ \$wifi -gt 0 ]; then
	    wifi="\$ce\$s1○\$s2"
	else
	    wifi="\$ce\$s1◌\$s2"
	fi
	updateRoot=1
}
iWifi=3
uWifi

EOF

	cat >> udblocks << EOF

	if [ "\$( expr \$time % \$iWifi )" -eq "0" ]; then
		printf "wifi.."
		uWifi
	fi

EOF

	printf "\$wifi" >> rootVars

fi
