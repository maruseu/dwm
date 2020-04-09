#!/bin/sh

cat >> ddblocks << EOF

uDate () {
	date=\`date +'%a %d/%m %H:%M'\`
	date="\$cs\$s1\$date\$s2"
	updateRoot=1
}
iDate=30
uDate

EOF

cat >> udblocks << EOF

	if [ "\$( expr \$time % \$iDate )" -eq "0" ]; then
		printf "time.."
		uDate
	fi

EOF

printf "\$date" >> rootVars

