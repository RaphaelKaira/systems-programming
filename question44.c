#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    mode_t old_umask = umask(0);  // Get the current umask. By passing 0 to umask, you temporarily set the umask to 0, which means no permissions are masked.
    umask(old_umask);             // Restore the old umask

    printf("Current umask: %03o\n", old_umask);
    return 0;
}
