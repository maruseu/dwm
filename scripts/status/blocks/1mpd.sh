#!/bin/sh

if which mpc; then
	cat >> ddblocks << EOF

uMpd () {
	mpd=\`mpc current -f "\$ci\$s1%artist% - %title%\$s2"\`
	if [ -z "\$mpd" ]; then
		mpd="\$cn"
	fi
	updateRoot=1
}
iMpd=60
uMpd

trap "sMpd=1;" USR2
sMpd=0

EOF

	cat >> udblocks << EOF

	if [ "\$( expr \$time % \$iMpd )" -eq "0" ] || [ \$sMpd -eq "1" ]; then
		printf "mpd.."
		uMpd
		sMpd=0
	fi

EOF

	printf "\$mpd" >> rootVars

fi
