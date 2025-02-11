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
