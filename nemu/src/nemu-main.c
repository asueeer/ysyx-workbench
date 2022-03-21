#include <common.h>
#include <string.h>

void init_monitor(int, char *[]);

void am_init_monitor();

void engine_start();

int is_exit_status_bad();

int main(int argc, char *argv[]) {
    /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
    am_init_monitor();
#else
    init_monitor(argc, argv);
#endif

    if (argc == 2 && strcmp(argv[1], "test-expr")==1) {
        printf("u r trying to test expr func.\n");
    }
    printf("u r trying to test expr func.\n");
    /* Start engine. */
    engine_start();

    return is_exit_status_bad();
}
