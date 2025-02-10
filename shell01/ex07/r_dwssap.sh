cat /etc/passwd | \
grep -v '^#' | \
awk 'NR % 2 == 0' | \
cut -d ':' -f 1 | \
rev | \
sort -r | \
awk -v start="$FT_LINE1" -v end="$FT_LINE2" 'NR >= start && NR <= end' | \
paste -sd ', ' - | \
sed 's/$/./'