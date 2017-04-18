#include <termios.h>
#include <unistd.h>

void enable_raw_mode() {
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw);

    // = AND complement(echo)
    raw.c_lflag &= ~(ECHO);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}


int main() {
    enable_raw_mode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    return 0;
}