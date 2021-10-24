#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "mapping.c"
#include "string_helper.c"

void convert(char *line, FILE *writeStream) {
    if (prefix("//", line)) {
        printf("Ignoring line: %s\n", line);
        fputs(line, writeStream);
        return;
    }

    char *newline = NULL;
    unsigned int i;
    CVARMapping *cv;
    for (i = 0, cv = cvarMapping; i < cvarMappingSize; i++, cv++) {
        if (cv->key == NULL) {
            break;
        }

        if (strstr(line, cv->key) != NULL) {
            printf("Found line: %s\n", line);
            newline = replaceWord(line, cv->key, cv->value);
            break;
        }
    }

    if (newline) {
        fputs(newline, writeStream);
    } else {
        fputs(line, writeStream);
    }

}

FILE *open_file(char *file_path, char *mode) {
    FILE *file_stream;
    int error_code;

    _set_errno(0);
    fopen_s(&file_stream, file_path, mode);
    if (_get_errno(&error_code) && error_code) {
        printf("Cannot open file: %s\n", file_path);
        exit(EXIT_FAILURE);
    }
    _set_errno(0);

    return file_stream;
}

char *file_from_path(char *path) {
    char *file_name;
    if (!path) {
        printf("Please provide a config file to convert.\n");
        exit(EXIT_FAILURE);
    }
    if (strstr(path, "\\")) {
        (file_name = strrchr(path, '\\')) ? ++file_name : (file_name = path);
        return file_name;
    }
    if (strstr(path, "/")) {
        (file_name = strrchr(path, '/')) ? ++file_name : (file_name = path);
        return file_name;

    }
    return path;
}

void print_help() {
    printf(
            "Enemy Territory: Legacy config converter\n"
            "\n"
            "This program converts a ETPro config to a legacy compatible config. It does this by mapping the ETPro/2.60b cvars to the legacy variant. "
            "If there is no viable mapping the cvar gets deleted from the config. This convert creates a new file with the '-converted' postfix to the filename as name.\n"
            "\n"
            "Useable options:\n"
            "etl_config_converter                   : Running without any arguments will display this help output.\n"
            "etl_config_converter -h                : Will display this help output.\n"
            "etl_config_converter Autoexec.cfg      : A path to the filename or the filename itself to parse.\n"
            "etl_config_converter -a                : Instead of specifying a file to convert it will convert all '.cfg' files in the current directory.\n");
            //"etl_config_converter -a [path_to_dir]  : Same as '-a', but accept a path to a directory to convert '.cfg' files in instead of the current directory.\n");
}

void convert_config(char* path) {
    // TODO: Implement detection when the file has nothing to convert.
    char *config_name = file_from_path(path);
    char *config_path = substr_of(path, config_name);
    char *substr = substr_of(config_name, ".cfg");
    char *converted_config = concat(3, config_path, substr, "-converted.cfg");

    FILE *stream = open_file(path, "r");
    if (!stream) {
        printf("Config file not found: %s\n", path);
        exit(EXIT_FAILURE);
    }
    FILE *check = open_file(converted_config, "r");
    if (check) {
        printf("Provided config file has already been converted. Delete '%s' if you want to convert it again.\n",
               converted_config);
        exit(EXIT_FAILURE);
    }
    FILE *writeStream = open_file(converted_config, "w");

    char line[1024];
    while (fgets(line, 1024, stream)) {
        char *tmp = _strdup(line);
        convert(tmp, writeStream);
    }

    fclose(stream);
    fclose(writeStream);
}

int main(int argc, char *argv[]) {
    if (argc <= 1 || !strcmp(argv[1], "-h")) {
        print_help();
        exit(EXIT_SUCCESS);
    } else if (string_ends_with(argv[1], ".cfg")) {
        convert_config(argv[1]);
        exit(EXIT_SUCCESS);
    } else if (!strcmp(argv[1], "-a")) {
        // for all files in current or supplied dir
        printf("not yet implemented");
        exit(EXIT_SUCCESS);
    } else {
        printf("'%s' is not a valid argument. See help with '-h'.\n", argv[1]);
        print_help();
        exit(EXIT_FAILURE);
    }
}


