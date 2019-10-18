//
// Created by Ghost on 2019/9/19.
//

#include <stdio.h>
#include "opt/argparse.h"

OPT_STATE help_func(const char **args, int count, void *data);

OPT_STATE test_func(const char **args, int count, void *data);

const OPTION options[] = {
        {"help", 'h', 0, "",       "help", help_func},
        {"test", 't', 1, "<data>", "test", test_func},
};

OPT_STATE help_func(const char **args, int count, void *data) {

    printf("help function\n");
    print_arg_description(options, 2);
    return IGNORE;
}

OPT_STATE test_func(const char **args, int count, void *data) {

    int s = atoi(args[0]);
    if (s == 0) {
        return ERR;
    }
    printf("test function: %s %d\n", data, s);
    char *d = data;
    d[1] = 'a';
    return CONTINUE;
}

void argparse_test(int argc, char *argv[]) {

    OPT_RESULT result;
    char data[] = "test";
    parse_arg(options, 2, argc, (const char **) argv, data, &result);

    if (result.action == ACTION_ERR || result.action == ACTION_USER_ERR)
        printf("opt err message: %s\n", result.err_reason);
    else printf("%s", data);
}

int main(int argc, char *argv[]) {
    argparse_test(argc, argv);
}