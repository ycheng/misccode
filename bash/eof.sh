#!/bin/bash

A=20

sh <<EOF

echo EOF without quote

A=10

echo $A    # 20
echo \$A   # 10
echo \\$A  # 20
echo \\\$A # $A
EOF

sh <<'EOF'

echo EOF with single quote
A=10
echo $A
echo \$A
echo \\$A
echo \\\$A

EOF

sh <<"EOF"

echo EOF with double quote
A=10
echo $A
echo \$A
echo \\$A
echo \\\$A

EOF
