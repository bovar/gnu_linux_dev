#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>

#define DX 7
#define DY 3

#define ESC 27
#define SPACE 32

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("You have to enter file name: ./Show <filename>\n");
        exit(1);
    }
// very long striiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiing    
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("ERROR while opening file %s\n", argv[1]);
        exit(1);
    }

    WINDOW *frame, *win;
    int c = 0;

    setlocale(LC_ALL, "");
    initscr();
    noecho();
    cbreak();
    refresh();

    frame = newwin(LINES - 2*DY, COLS - 2*DX, DY, DX);
    box(frame, 0, 0);
    mvwaddstr(frame, 0, (int)((COLS - 2*DX - 5) / 2), argv[1]);
    wrefresh(frame);

    win = newwin(LINES - 2*DY - 2, COLS - 2*DX-2, DY+1, DX+1);
    keypad(win, TRUE);
    scrollok (win, TRUE);
    
    for(int i = 0; i < LINES - 2 * DY - 3; ++i) {
        if ((read = getline(&line, &len, fp)) != -1) {
            wprintw(win, "%s", line);
        } else {
            break;
        }
    }

    while((c = wgetch(win)) != ESC) {
        if (c == SPACE && (read = getline(&line, &len, fp)) != -1) {
            wprintw(win, "%s", line);
        }
    }
    delwin(win);
    delwin(frame);
    endwin();
    return 0;
}
