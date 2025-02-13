function check_outputs
    for i in (find . -name "*.out")
        printf "\n%s\n---------\n" $i
        ./$i
        printf "\n"
    end
end

function check_includes
    for i in (find . -name "ft*")
        printf "\n%s\n---------\n" $i    
        cat $i | grep "#include"
        printf "\n" 
    end
end

function check_ft_nomain
    for i in (find . -name "ft*")
        printf "\n%s\n---------\n" $i    
        cat $i | grep "main"
        printf "\n" 
    end
end

function check_header
    for i in (find . -name "ft*")
        printf "\n%s\n---------\n" $i    
        cat $i | grep "By"
        printf "\n" 
    end
end

function check_ftnames
    for i in (find . -name "ft*")
        printf "\n%s\n---------\n" $i    
        cat $i | grep "ft_"
        printf "\n" 
    end
end

function manclip
    if test (count $argv) -eq 0
        echo "Uso: manclip <comando>"
        return 1
    end
    man $argv[1] | sed -n '/^DESCRIPTION/,/^[A-Z]/{ /^[A-Z][a-z]/!p }' | sed 's/^ *//' | fold -w 80 | xclip -selection clipboard
    echo "Sección DESCRIPTION de '$argv[1]' copiada al portapapeles con líneas de 80 caracteres y sin sangría."
end



funcsave check_outputs
funcsave check_includes
funcsave check_ft_nomain
funcsave check_header
funcsave check_ftnames
funcsave manclip

