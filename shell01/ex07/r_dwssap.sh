cat /etc/passwd | sed -n 'n;p' | awk -F ':' '{print $1}' | rev | sort -r | tr '\n' ','
