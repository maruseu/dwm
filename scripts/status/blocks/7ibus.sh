#!/bin/sh

if which ibus; then
	cat >> ddblocks << EOF

uIbus () {
	ibus=\`ibus engine | sed 's/:/ /g' | sed 's/-/ /g' | awk '{print toupper(\$2)}'\`
	ibus="\$cs\$s1\$ibus\$s2"
	updateRoot=1
}
iIbus=10
uIbus

trap "sIbus=1;"   RTMIN
sIbus=0

EOF

	cat >> udblocks << EOF

	if [ "\$( expr \$time % \$iIbus )" -eq "0" ] || [ \$sIbus -eq "1" ]; then
		printf "ibus.."
		uIbus
		sIbus=0
	fi

EOF

	printf "\$ibus" >> rootVars

fi
