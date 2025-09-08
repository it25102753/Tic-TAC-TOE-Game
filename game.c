#include <stdio.h>

void showboard(int n, char board[n][n]);
int makemove(int n, char board[n][n], int row, int col, char player);
int checkwin(int n, char board[n][n], char player);
int checkdraw(int n, char board[n][n]);
void computerMove(int n, char board[n][n], char player, FILE *f);
void logMove(FILE *f, char player, int row, int col);



int main()  {
    int ch;
    int n;
    printf("user  vs user game - 1\n");
    printf("Player vs computer - 2 \n");
    printf("Multi player       - 3 \n");
    printf(" \n");
    printf("Enter your  choice : ");
    scanf("%d", &ch);

    if(ch < 1 || ch > 3){
        printf("re - Enter your  choice : ");
        scanf("%d", &ch);
    }
}
	//Show board in display function
void sheowboard(int n , char board[n][n]){
    int i , j;
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%c",board[i][j]);
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
    printf("\n");
    }
}
    //palyers move draw function
int makemove(int n, char board[n][n], int row, int col, char player){
    if(board[row][col]== ' '){
        board[row][col]= player;
        return 1;
    }
        return 0;
}


    //win check function
int checkwin(int n, char board[n][n], char player){
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
int checkdraw(int n, char board[n][n]){
    int i,j;
    for(i =0;i<n;i++){
        for(j=0;j<n;j++){
            if(board[i][j] == ' '){
            return 1;
             }
        }
    }
    return 0;
}

//get computer move function

void computerMove(int n, char board[n][n], char player, FILE *f){
    int row,col;
    row = rand() % n;
    col = rand() % n;
    for(;;)
    if(board[row][col] == ' '){
        board[row][col] = player;
        break;
    } else{
        row = rand() % n;
        col = rand() % n;

    } 

}
//create fuction for Record every valid move
void logMove(FILE *f, char player, int row, int col){
    fprintf(f,"Player %c is move ---- (%d,%d)\n",player,row,col);
}
