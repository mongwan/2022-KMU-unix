#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    int c;
    extern char *optarg;
    extern int optind;

    static struct option long_options[] = {
        {"pid", required_argument, 0, 0},
        {"signal", required_argument, 0, 0},
        {"fail", required_argument, 0, 0},
        {"recovery", required_argument, 0, 0},
        {"recovery-timeout", required_argument, 0, 0},
        {"threshold", required_argument, 0, 0},
        {"fault-signal", required_argument, 0, 0},
        {"success-signal", required_argument, 0, 0},
        {0, 0, 0, 0}
    };
    int long_optind = 0;

    int interval = 0;
    char script_fn[255];

    while (
        (c = getopt_long(argc, argv, "i:s:", long_options, &long_optind)) != -1
    ) {
        switch (c) {
        case 0: // Long option
            if (long_options[long_optind].flag != 0)
                break;
            printf("Option: %s", long_options[long_optind].name);
            printf(", Arg: %s\n", optarg);
            break;
        case 's': // Command 대신 Script 사용
            strcpy(script_fn, optarg);
            printf("Option: s, Script path: %s\n", script_fn);
            break;
        case 'i': // Interval 지정
            interval = atoi(optarg);
            printf("Option: i, Interval=%d\n", interval);
            break;
        }
    }

    return 0;
}