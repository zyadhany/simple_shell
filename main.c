#include "s_shell.h"



int main(int argc, char *argv[]){

	signal(SIGINT, SIG_IGN);

	// getting from ouu of shell
	if(argc == 2){

	}

	do
	{
		s_shell();
	} while (1);
	
	return (0);
}
