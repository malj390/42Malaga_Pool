
printf "\n######### Executables\n\n"

for i in (find . -name "*.out")
	printf "\n%s\n---------\n" $i
    ./$i
    printf "\n"
end

printf "\n######### ft includes\n\n"


for i in (find . -name "ft*")
	printf "\n%s\n---------\n" $i    
    cat $i | grep "#include"
    printf "\n" 
end

printf "\n######### main in ft\n\n"


for i in (find . -name "ft*")
	printf "\n%s\n---------\n" $i    
    cat $i | grep "main"
    printf "\n" 
end



