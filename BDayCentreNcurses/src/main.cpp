#include <ncursesw/ncurses.h> // Draw text in terminal screen (changed from <ncurses.h>)

int main() {
 initscr(); // initialize ncurses window
 mvaddstr(LINES/2, COLS/3, "The chance that 2 out of 23 have");
 mvaddstr(LINES/2+1, COLS/3, "the same birthday is about 0.5. wow.");
 getch(); // capture the user's pressed key
 endwin(); // close the ncurses window
 return 0;
}