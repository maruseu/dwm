#!/bin/sh

if which mpc; then
	cat >> ddblocks << EOF
while :; do
	current_mus=\$(mpc current --wait)

	notify-send "Now Playing" "\$current_mus"

	kill -USR2 \$\$
	pkill -P \$\$ sleep
done &

uMpd () {
	mpd="\$ci\$s1「 ♪  \$(mpc current)  」\$s2"
	if [ "\$mpd" = "\$ci\$s1「 ♪    」\$s2" ]; then
		mpd="\$cn"
	fi
	updateRoot=1
}
uMpd

trap "sMpd=1;" USR2
sMpd=0

EOF

	cat >> udblocks << EOF

	if [ \$sMpd -eq "1" ]; then
		printf "mpd.."
		uMpd
		sMpd=0
	fi

EOF

	printf "\$mpd" >> rootVars

fi
