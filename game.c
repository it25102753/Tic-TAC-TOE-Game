#include <stdio.h>
#include <stdlib.h>

//Function declarations
void showboard(int n, char **board);
int makemove(int n, char **board, int row, int col, char player);
int checkwin(int n, char **board, char player);
int checkdraw(int n, char **board);
void computerMove(int n, char **board, char player, FILE *f);
void logMove(FILE *f, char player, int row, int col);



int main()  {
    int choice;
    int n;
    printf("\n"); //get game type usr going to play 
    printf("user  vs user game - 1\n");
    printf("Player vs computer - 2 \n");
    printf("Multi player       - 3 \n");
    printf(" \n");
    printf("Enter your  choice : ");
    scanf("%d", &choice);

        for(;;){
        if(choice >= 1 && choice <= 3){
                break;  
            } else {                    //cheack input are valid 
                printf("Re - Enter your  choice : ");
                scanf("%d", &choice);
            }
        }
    //user vs user game code
    if(choice == 1){
        printf("\n");
        printf("Enter the board size 3 -10 :");
        scanf("%d",&n);

        //cheack input are valid 
        for(;;){
            if(n >= 3 && n <= 10){
                break;
            } else {
                printf("Re enter size 3 - 10 : ");
                scanf("%d", &n);
            }
        }
             // Dynamically  memory allocate 
        char **board = malloc(n * sizeof(char*));
         for (int i = 0; i < n; i++)
             board[i] = malloc(n * sizeof(char));

        int i, j;

        char currentplayer  = 'X';
        int row, col;
        int game_over = 1;

      //filling the board with space
    for(i = 0; i < n; i++)   {
        for(j = 0; j < n; j++) {
            board[i][j] = ' ';
             }
        }
        FILE *f = fopen("game_(user_vs_User).txt", "w"); //Open log file
    while(game_over){
        showboard(n, board);

        printf("player %c enter your move row col - please add space : ",currentplayer);
        scanf("%d %d",&row,&col);

        //cheack input are valid 
        for(;;){
            if(row >= 1 && row <= n && col >=1 && col <= n){
                break;
            } else {
                printf("player %c Re - enter your move row col - please add space : ",currentplayer);
                scanf("%d %d",&row,&col);
            }
        }

        if(!makemove(n, board, row -1,col-1,currentplayer)){
            printf("\n");
            printf("sell already taken Try again.\n");
            continue;
        }
        //print movement in log file
        logMove(f,currentplayer,row,col);

        if(checkwin(n, board, currentplayer)){ //check game is win
            showboard(n, board);
            printf("player %c win the game \n",currentplayer);
            fprintf(f,"Player %c is Win the game \n",currentplayer);
            game_over = 0;
        } else if(checkdraw(n,board)){
            showboard(n,board);       //check game is draw
            printf("game is draw \n");
            fprintf(f,"Game is draw \n");
            game_over = 0;

        }
        else if(currentplayer == 'X'){
            currentplayer = 'O';
        } else {
            currentplayer = 'X';
        }
    }
      fclose(f);
        return 0;

    }

    //player vs computer game code
    if(choice == 2){
          printf("\n");
	printf("Enter the board size 3 -10 :");
        scanf("%d",&n);

        //cheack input are valid 
        for(;;){
            if(n >= 3 && n <= 10){
                break;
            } else {
                printf("Re enter size 3 - 10 : ");
                scanf("%d", &n);
            }
        }
         // Dynamically  memory allocate 
        char **board = malloc(n * sizeof(char*));
         for (int i = 0; i < n; i++)
             board[i] = malloc(n * sizeof(char));

        int i, j;
        char currentplayer  = 'X';
        int row, col;
        int game_over = 1;

       //filling the board with space
    for(i = 0; i < n; i++)   {
        for(j = 0; j < n; j++) {
            board[i][j] = ' ';
             }
        }
    FILE *f = fopen("game_(user_vs_computer).txt", "w"); //Open log file
        while(game_over){
            showboard(n, board);

            if(currentplayer == 'X'){
            printf("Enter your move row col - please add space : ");
            scanf("%d %d",&row,&col);

                //cheack input are valid 
            for(;;){
                if(row >= 1 && row <= n && col >=1 && col <= n){
                    break;
                } else {
                    printf("Re - enter your move row col - please add space : ");
                    scanf("%d %d",&row,&col);
                }
            }

            if(!makemove(n,board,row-1,col-1,currentplayer)){
                printf("sell already taken try again \n");
                continue;
            }

            //print movement in log file
            logMove(f,currentplayer,row,col);

          }else {
              computerMove(n, board,  currentplayer, f);
              }
            if(checkwin(n,board,currentplayer)){ //check game is win
                showboard(n,board);
                printf("palyer %c win the game \n",currentplayer);
                fprintf(f,"Player %c is Win the game \n",currentplayer);
                game_over = 0;
            }
             else if(checkdraw(n, board)) {
            showboard(n,board);         //check game is draw
            printf("It's  a draw!\n");
            fprintf(f,"Game is draw \n");
            game_over = 0;
                 } else {

            //change the_player
                if(currentplayer == 'X'){
                    currentplayer = 'O';
                 } else {
                    currentplayer = 'X';
                }
            }
        }
        fclose(f);
    }

    //multi player game code
    if(choice == 3){
    int n;
    int i,j;

    #define PLAYER1 'X'
    #define PLAYER2 'O'
    #define PLAYER3 'Z'

   printf("\n");
    printf("Enter  the board size (3 to 10): ");
    scanf("%d",&n);

        //cheack input are valid 
    for(;;){
        if(n >=3 && n <= 10){
            break;

        }
        else{
            printf("Re enter board size 3 - 10 :");
            scanf("%d",&n);
        }
    }
      // Dynamically  memory allocate 
    char **board = malloc(n * sizeof(char*));
         for (int i = 0; i < n; i++)
             board[i] = malloc(n * sizeof(char));

   //filling the board with space
    for(i = 0; i < n; i++)   {
        for(j = 0; j < n; j++) {
            board[i][j] = ' ';
             }
        }
    FILE *f = fopen("game_log_multi_ply.txt", "w"); //Open log file

    // Player role setup
    int playerType[3]; // 0 = human, 1 = computer

    printf("\nConfigure  players:\n");
    printf("Player %c (0 = Human, 1 = Computer): ", PLAYER1);
    scanf("%d", &playerType[0]);
    printf("Player %c (0 = Human, 1 = Computer): ", PLAYER2);
    scanf("%d", &playerType[1]);
    printf("Player %c (0 = Human, 1 = Computer): ", PLAYER3);
    scanf("%d", &playerType[2]);

        //check At least one is  human user
    while(playerType[0] == 1 && playerType[1] == 1 && playerType[2] == 1){
    printf("\n");
    printf("At least one player must be human!\n");
    printf("\n\n");
    printf("Player %c (0 = Human, 1 = Computer): ", PLAYER1);
    scanf("%d", &playerType[0]);
    printf("Player %c (0 = Human, 1 = Computer): ", PLAYER2);
    scanf("%d", &playerType[1]);
    printf("Player %c (0 = Human, 1 = Computer): ", PLAYER3);
    scanf("%d", &playerType[2]);
    }


    int turn = 0;
    int row, col;
    int game_over =1;

    while(game_over){
    showboard(n, board);
    char currentPlayer;

        if(turn == 0)      currentPlayer = PLAYER1;
        else if(turn == 1) currentPlayer = PLAYER2;
        else               currentPlayer = PLAYER3;

        if(playerType[turn] == 0){
            printf("Player %c, enter your move row col - please add space : ", currentPlayer);
            scanf("%d %d",&row,&col);

            //cheack input are valid 
            for(;;){
                if(row >= 1 && row <=n && col >=1 && col <=n){
                    break;;
                }
                else{
                    printf("Re enter your move Row col - please add space :");
                    scanf("%d %d",&row, &col);
                }
            }


         if(!makemove(n, board, row - 1, col - 1, currentPlayer)) {
                printf("\n");
                printf("Cell already taken. Try again.\n");
                continue;
            }

            //print movement in log file
            logMove(f, currentPlayer, row, col);
        }
            else {
                computerMove(n, board,currentPlayer, f);
            }
        if(checkwin(n, board, currentPlayer)) {  //check game is win
            showboard(n, board);
            printf("Player %c wins!\n",currentPlayer);
            fprintf(f,"Player %c is Win the game \n",currentPlayer);
            game_over = 0;
        }

        else if(checkdraw(n, board)) {  //check game is draw
            showboard(n, board);
            printf("It's a draw!\n");
            fprintf(f,"Game is draw \n");
            game_over = 0;
         } else {
            turn++;
            if (turn > 2)
             turn = 0;  //cheack the turn of player
        }
      }
      fclose(f);
    }
}
	//Show board in display function
void showboard(int n , char **board) {
    int i , j;
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf(" %c ",board[i][j]);
            if(j<n-1)
            printf("|");
        }
        printf("\n");

        if(i<n-1){
            for(j=0;j<n;j++){
            printf("----");
            }
            printf("\n");
        }
    }
    printf("\n");
}
    //palyers move draw function
int makemove(int n, char **board, int row, int col, char player){
    if(board[row][col]== ' '){
        board[row][col]= player;
        return 1;
    }
        return 0;
}


    //win check function
int checkwin(int n, char **board, char player){
    int win;
    int i,j;
    //check rows
    for( i=0;i<n;i++){
        win =1;
         for (int j =0;j<n;j++){
            if(board[i][j] != player)
            win =0;
        }
        if(win == 1)
        return 1;
    }

    //check coloms
    for(j=0;j<n;j++){
        win =1;

        for(int i=0;i<n;i++){
            if(board[i][j] != player)
                win =0;
        }
        if(win == 1)
        return 1;
    }
    // check diagonal 1
    win =1;
    for(i =0;i<n;i++){
        if(board[i][i] != player)
             win = 0;
    }
    if(win == 1){
        return 1;
    }

    //check diagonal 2
    win =1;
    for(i =0;i<n;i++){
        if(board[i][n-i-1] != player)
            win =0;
    }
    if(win == 1){
        return 1;
    }

    //cheack No one is win
    return 0;
}

    //check game is draw
int checkdraw(int n, char **board){
    int i,j;
    for(i =0;i<n;i++){
        for(j=0;j<n;j++){
            if(board[i][j] == ' '){
            return 0;
             }
        }
    }
    return 1;
}

//get computer move function

void computerMove(int n, char **board, char player, FILE *f){
    int row,col;
    row = rand() % n;
    col = rand() % n;
    for(;;)
    if(board[row][col] == ' '){
        board[row][col] = player;
        printf("Computer Player %c is move ---- (%d - %d)\n",player,row+1,col+1);
        fprintf(f,"Player %c is move ---- (%d,%d)\n",player,row+1,col+1);
        break;
    } else{
        row = rand() % n;
        col = rand() % n;

    }


}
//fuction for Record every valid move in txt file
void logMove(FILE *f, char player, int row, int col){
    fprintf(f,"Player %c is move ---- (%d,%d)\n",player,row,col);
}
