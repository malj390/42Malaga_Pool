# Vim

## Shortcuts

### Insert Mode

```
Ctrl + N - Autocomplete

```
### Normal Mode (ESC)

```
:q - Exit
:q! - Exit 
:w - write
:wq or :x - write and exit
gg - Go to the beggining of a document
G - go to the end
0 - go to the beggining of the line
a - go to the end and Enter in INSERT MODE

dd - remove line
d2d - remove 2 lines under cursor
yy - copy line
y2y - copy 2 lines under cursor
p - paste line/block under cursor

```
## Settings

### Adviced to have in .vimrc

```
set number
set mouse=a

```

### Others

```
:set list
:set invnumber
:set autoindent (or set ai)

```
# BASH (basic commands)

```
man
pwd
ls
cd
cat
echo
mv
head
tail
touch
truncate
chmod
grep
tr
find
rm 
sed
awk
sort
cut
rev
paste
bc
basename
xargs : Example >> find . -name "*nbr*" | xargs cat
```
# 42 Header

For bash add to ~/.bashrc
```
export USER=name
export MAIL=email
```

For zsh add to ~/.zshrc
```
export USER=name
export MAIL=email
```

For fish add to ~/.config/fish/config.fish
```
if status is-interactive
    # Commands to run in interactive sessions can go here
	set -x USER name
	set -x MAIL email
end
```


# GIT
```
git add --all
git commit -m "Message"
git push
git status
git pull
git reset --hard: useful when local changes must be discarded
rm -rf : to remove git folders from evaluations
git config --global user.name "name"
git config --global user.email "name@email.com"
```

# Checks and Compilation

```
Norminette -R [file or folder with exercises]
cc -Wall -Wextra -Werror ft_files.c main.c    OR    *.c
./a.out

Optional: cc -Wall -Wextra -Werror ft_files.c main.c -o program.out
./program.out

valgrind --leak-check=full ./a.out
```


# Tricks

## Execute all a.out files from all ex directories (FISH)

```
for i in (find . -name "*.out")
	printf "\n%s\n---------\n" $i
    ./$i
    printf "\n"
end
```

## Search all includes from the ft files (FISH)

```
for i in (find . -name "ft*")
	printf "\n%s\n---------\n" $i    
    cat $i | grep "#include"
    printf "\n" 
end
```

## Search all main from ft files IT SHOULD BE EMPTY (FISH)

```
for i in (find . -name "ft*")
	printf "\n%s\n---------\n" $i    
    cat $i | grep "main"
    printf "\n" 
end
```

# Terminal fun

```
cmatrix

curl parrot.live
```
