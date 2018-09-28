#include <curses.h>
#include <time.h>
#include <string.h>

char *usernames[] = { "Shein", "Victoria"};
char messages[200];
int messageLen;
int numUsers = 2;
int currentUser = 0;
int maxY, maxX;
bool displayMessage();
int getCursorPos(){
	return maxX - strlen(usernames[currentUser]) - 2;
}
void switchUser(){
	int oldx,oldy;
	getyx(stdscr,oldx,oldy);
	move(maxY-1, getCursorPos());
	for(int i = strlen(usernames[currentUser]); i !=0 ; i--)
		delch();
	currentUser++;
	currentUser=currentUser % numUsers;
	attron(A_STANDOUT);
	move(maxY-1, getCursorPos());
	addstr(usernames[currentUser]);
	attroff(A_STANDOUT);
	move(oldx,oldy);
}
bool handleInput(){
	int y, x;
	getyx(stdscr, y, x);
	int ch = getch();
	if(ch == '\n'){
		return displayMessage();
	}
	else if(ch == '\t'){
		move(y,x);
		switchUser();
	}
	else{
		messages[messageLen++] = ch;
	}
	return false;
}
bool displayMessage(){
	messages[messageLen] = '\0';
	if(strcmp(messages,"quit") == 0)
		return true;
	static int currentLine;
	time_t rt = time(NULL);
	struct tm *lt = localtime(&rt);
	mvprintw(currentLine, 0, "%s (%d:%d): %s", usernames[currentUser], lt->tm_hour % 12, lt->tm_min, messages);
	currentLine++;
	currentLine = currentLine % (maxY - 1);	
	messageLen = 0;
	move(maxY - 1,0);
	for(int i = 0; i < maxX; i++)
		delch();
	switchUser();
	switchUser();
	move(maxY - 1,0);
	return false;
}
int main()
{	
	initscr();			/* Start curses mode 		  */
	refresh();			/* Print it on to the real screen */
	raw();
	getmaxyx(stdscr, maxY, maxX);
	move(maxY-1,0);
	switchUser();
	//strcpy(messages, "HELLO");
	//displayMessage();
	bool exit;
	while(!exit){
		exit = handleInput();
	}
	endwin();			/* End curses mode		  */
	printf("%s", messages);
	return 0;
}
