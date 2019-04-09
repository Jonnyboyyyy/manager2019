#include "user.h"
#include "menu.h"

int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)
  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
  int count=0;
  char command[20];
  int makeFile=0;
  //int menu_id;
  if (argc != 2) {
    printf("Usage : manager <datafile>\n");
    return 0;
  }
  if(strcmp(argv[1], "users.txt")==0){ 
	count = load_file(userlist, argv[1]);}
  else{ 
	printf("%s file does not exist! make anyway? (Yes 1, No 2) >> \n",argv[1]);
	scanf("%d",&makeFile);
	if (makeFile == 1){
		make_file(argv[1]);
		count = load_file(userlist, argv[1]);
	}
	else return 0;}
  printf("> Welcome!!\n");
  //while(1){
    while(1){
	if (is_login == 0){
    		printf("> ");
    		scanf("%s",command);
   		if(strcmp(command, "login")==0){
   			if(is_login==0){
				is_login = login(userlist, count);
				if(is_login == 1)
					printf("success!\n");	
				else is_login=0;
			}
			else if(is_login!=0){
				is_login=0;
				break;
			}
    		}
		else if(strcmp(command, "join")==0){
			count +=  join(userlist, count);
			save_file(userlist, count, argv[1]);
		}
		else if(strcmp(command, "list")==0) showListr(userlist, count);
		else if(strcmp(command, "exit")==0) break; 
    		else printf("No such command!\n");
        }
	else if(is_login == 1){
		printf("# ");
		scanf("%s",command);
		if(strcmp(command, "logout")==0){
			is_login = 0;
		}
		else printf("%s\n",command);
	}
    }
    //menu_id = ask_menu(is_login); // 현재 로그인 되었는지의 여부를 파라미터로 알려야 한다.
   //if(menu_id==1) join(userlist, count,argv[1]);
    //else if (menu_id==2) is_login = login(userlist, count);
    //else if (menu_id==3) logout(&is_login);
    //else break;
 // }
  save_file(userlist, count, argv[1]);
  return 0;
}
