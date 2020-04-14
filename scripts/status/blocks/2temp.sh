#!/bin/sh

if which sensors; then
	cat >> ddblocks << EOF

uTemp () {
	temp=\`sensors | grep "Package id 0:" | sed -e "s/+//" -e "s/ /\n/g" -e "s/\.0//" | grep -v "+" | grep °C\`
	temp="\$cs\$s1\$temp\$s2"
	updateRoot=1
}
iTemp=1
uTemp

EOF

	cat >> udblocks << EOF

	if [ "\$((\$time % \$iTemp))" -eq "0" ]; then
		printf "temp.."
		uTemp
	fi

EOF

	printf "\$temp" >> rootVars

else
	cat >> ddblocks << EOF

uTemp () {
	temp=\`sysctl -a | grep temperature | awk '{print \$NF}'\`
	temp="\$cs\$s1\$temp\$s2"
	updateRoot=1
}
iTemp=1
uTemp

EOF

	cat >> udblocks << EOF

	if [ "\$((\$time % \$iTemp))" -eq "0" ]; then
		printf "temp.."
		uTemp
	fi

EOF

	printf "\$temp" >> rootVars

fi
