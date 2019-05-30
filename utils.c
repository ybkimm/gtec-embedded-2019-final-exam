#include <stdio.h>
#include <wchar.h>

void cls() {
	wprintf(L"\e[1;1H\e[2J");
}
