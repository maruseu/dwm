#!/bin/sh

cat >> ddblocks << EOF

uCorona () {
	corona=\`curl https://corona-stats.online/BR | grep Brazil | awk '{print \$6}' | sed 's/\[..m//g'\`
	corona="\${s1}Corona-chan: \$corona\$s2"
	updateRoot=1
}
iCorona=30
uCorona

EOF

cat >> udblocks << EOF

	if [ "\$( expr \$time % \$iCorona )" -eq "0" ]; then
		printf "corona.."
		uCorona
	fi

EOF

printf "\$corona" >> rootVars
