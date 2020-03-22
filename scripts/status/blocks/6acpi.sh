#!/bin/sh

if which acpi; then
	cat >> ddblocks << EOF

uAcpi () {
#	acpi=\`acpi -b | tr "[, ]" "\n" | grep "%" | tr -d "%"\`
	acpi=\`bar.lua \$(echo "\$(acpi -b | tr "[, ]" "\n" | grep "%" | tr -d "%") / 100" | bc -l)\`
	if acpi --ac-adapter | grep 'on-line' > /dev/null; then
		acpi="\$cs ▕\$acpi▏ "
	else
		acpi="\$ci ▕\$acpi▏ "
	fi
	updateRoot=1
}
iAcpi=4
uAcpi

EOF

	cat >> udblocks << EOF

	if [ "\$( expr \$time % \$iAcpi )" -eq "0" ]; then
		printf "acpi.."
		uAcpi
	fi

EOF

	printf "\$acpi" >> rootVars

fi
