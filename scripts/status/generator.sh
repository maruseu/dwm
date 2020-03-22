#!/bin/sh
cd $(echo $0 | sed -e 's/generator.sh//')
file=dstatus

rm rootVars ddblocks udblocks

which dash && echo '#!/bin/dash' > $file || echo '#!/bin/sh' > $file


cat >> $file << EOF

s1="   "; s2="   "
cn=""; ci=""; cw=""; ce=""
#cs="";
cs="";

echo \$\$ > /tmp/ram/dwmStat.pid

EOF

for f in blocks/[!\!]*; do

	sh $f

done

cat ddblocks >> $file

cat >> $file << EOF

while true; do
	time=\`date +%S\`

EOF

cat udblocks >> $file

cat >> $file << EOF
	if [ "\$updateRoot" -eq "1" ]; then
		xsetroot -name "$(cat rootVars)"
		updateRoot=0
	fi

	sleep 1
done
EOF
