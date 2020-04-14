#!/bin/sh

cat >> ddblocks << EOF

uDisks () {
	disks=\`df -h | grep /dev/sda1 | awk '{print toupper(\$1)" "\$4}' | sed -e ':a' -e 'N' -e 's/\n/ \| /g' | sed 's/\/DEV\/SD//g'\`
	disks="\$cs\$s1\$disks\$s2"
	updateRoot=1
}
iDisks=30
uDisks

EOF

cat >> udblocks << EOF

	if [ "\$((\$time % \$iDisks))" -eq "0" ]; then
		printf "disks.."
		uDisks
	fi

EOF

printf "\$disks" >> rootVars

fi
