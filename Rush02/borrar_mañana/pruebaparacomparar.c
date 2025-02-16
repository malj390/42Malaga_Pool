#include <unistd.h>

#define BUFFER_SIZE 4096

typedef struct s_dict_entry {
    char *number;
    char *word;
} t_dict_entry;

void ft_putstr(char *str) {
    while (*str)
        write(1, str++, 1);
}

int ft_strlen(char *str) {
    int len = 0;
    while (str[len])
        len++;
    return len;
}

char *ft_strdup(char *src) {
    int len = ft_strlen(src);
    char *dup = sbrk(len + 1);
    if (dup == (void *)-1)
        return NULL;
    for (int i = 0; i < len; i++)
        dup[i] = src[i];
    dup[len] = '\0';
    return dup;
}

int ft_is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int ft_is_valid_number(char *str) {
    if (!str || !*str)
        return 0;
    while (*str) {
        if (!ft_is_digit(*str))
            return 0;
        str++;
    }
    return 1;
}

t_dict_entry *parse_dict(int fd, int *size) {
    char buffer[BUFFER_SIZE];
    int bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytes_read <= 0)
        return NULL;
    buffer[bytes_read] = '\0';
    
    t_dict_entry *dict = sbrk(sizeof(t_dict_entry) * 100);
    if (dict == (void *)-1)
        return NULL;
    *size = 0;
    
    char *line = buffer;
    while (*line) {
        char *num_start = line;
        while (*line && *line != ':')
            line++;
        if (*line != ':')
            break;
        *line++ = '\0';
        while (*line == ' ')
            line++;
        char *word_start = line;
        while (*line && *line != '\n')
            line++;
        if (*line == '\n')
            *line++ = '\0';
        dict[*size].number = ft_strdup(num_start);
        dict[*size].word = ft_strdup(word_start);
        (*size)++;
    }
    return dict;
}

char *find_word(t_dict_entry *dict, int size, char *number) {
    for (int i = 0; i < size; i++) {
        if (!ft_strlen(dict[i].number))
            continue;
        int j = 0;
        while (dict[i].number[j] && dict[i].number[j] == number[j])
            j++;
        if (!dict[i].number[j] && !number[j])
            return dict[i].word;
    }
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2 || argc > 3) {
        ft_putstr("Error\n");
        return 1;
    }
    
    char *dict_path = (argc == 3) ? argv[1] : "default_dict.txt";
    if (!ft_is_valid_number(argv[argc - 1])) {
        ft_putstr("Error\n");
        return 1;
    }
    
    int fd = open(dict_path, 0);
    if (fd < 0) {
        ft_putstr("Dict Error\n");
        return 1;
    }
    
    int dict_size;
    t_dict_entry *dictionary = parse_dict(fd, &dict_size);
    close(fd);
    if (!dictionary) {
        ft_putstr("Dict Error\n");
        return 1;
    }
    
    char *word = find_word(dictionary, dict_size, argv[argc - 1]);
    if (word)
        ft_putstr(word);
    else
        ft_putstr("Dict Error\n");
    
    ft_putstr("\n");
    return 0;
}

