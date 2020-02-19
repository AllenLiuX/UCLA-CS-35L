#!/bin/sh

grep -E '<td[^>]*>.+'|\
sed -n '1~2p' |\
sed 's/<[^>]*>//g' | \
sed -e "s/\`/\'/g" | \
sed -e "s/\,/\n/g" | \
sed -e "s/ /\n/g" | \
sed '/^$/d' | \
sed -e 's/\(.*\)/\L\1/' | \
sed '/b\|c\|d\|f\|g\|j\|q\|r\|s\|t\|v\|x\|y\|z/d' | \
sed "/[^a-z^A-Z^\']/d" | \
sort -u
