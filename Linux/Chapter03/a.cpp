#include "../Common.h"

int main(int argc, char *argv[]){
	struct hostent *ptr = gethostbyname(argv[1]);
	/*char **ptr1 = ptr->h_aliases;
	while(*ptr1){
		printf("%s\n", **ptr1);
		++*ptr1;
	}*/
	struct in_addr ipv4addr;
	char ipv4str[INET_ADDRSTRLEN];
	char **ptr2 = ptr->h_addr_list;
	while(*ptr2){
		memcpy(&ipv4addr, *ptr2, ptr->h_length);
		inet_ntop(AF_INET, &ipv4addr, ipv4str, sizeof(ipv4str));
		printf("%s\n", *ptr2);
	++*ptr2;
	}
}
