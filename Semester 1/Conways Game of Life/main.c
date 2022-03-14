/*

    *** Fardin Faiyaz
        ID : 200041111

    *** Tanvir Hossain Dihan
        ID: 200041144

    Section : 1 
    Department: CSE
    Course Code : CSE - 4107

*/

#include <stdio.h>
#include <stdlib.h>

#define R 20
#define C 60
#define dead '.'
#define live 'O'

// Preparing all cell to dead
void preparation(char grid[R][C])
{
    for(int i = 0;i < R;i++){
        for(int j = 0;j < C;j++)
            grid[i][j] = dead;
    }
}

// Initial live cell
void initialization(char grid[R][C])
{
    int x,y;
    printf("Enter initial live cells (x y) (-1 for termination):\n");
    while(1){
        scanf("%d",&x);
        if(x == -1)
            break;
        scanf("%d",&y);
        grid[y][x] = live;
    }
}

// Printing
void printing(char grid[R][C],int gen)
{
    system("cls");
    printf("Generaton : %d\n",gen);
    for(int i=0;i<R;i++){
        printf("(%2.2d) ||",i);
        for(int j=0;j<C;j++){
            printf("%c",grid[i][j]);
        }
        printf("\n");
    }
}

//Generation Change
void generationChange(char prevGen[R][C],char nextGen[R][C])
{
    int xAxis[] = {1,-1,0,0,1,1,-1,-1};
    int yAxis[] = {0,0,-1,1,1,-1,1,-1};

    // Iterate through all cell
    for(int i = 0;i < R;i++){
        for(int j = 0;j < C;j++){

            int liveCell = 0;
            // Checking Neighbour
            for(int k = 0;k < 8;k++){
                int xNew = j + yAxis[k];
                int yNew = i + xAxis[k];
                if(xNew == C || xNew < 0 || yNew == R || yNew<0)
                    continue;
                if(prevGen[yNew][xNew]== live)
                    liveCell++;
            }
            
            // preparing future generation
            if(prevGen[i][j] == dead && liveCell == 3)
                nextGen[i][j] = live;
            else if(prevGen[i][j] == live && (liveCell > 3 || liveCell < 2))
                nextGen[i][j] = dead;
            else if(prevGen[i][j] == live && (liveCell == 3 || liveCell == 2))
                nextGen[i][j] = live;
        }
    }
}

int main(){

    char gen1[R][C], gen2[R][C];
    //Preparation
    preparation(gen1);
    preparation(gen2); 

    //Initialize
    int generations;
    printf("Total generations :");
    scanf("%d",&generations);

    initialization(gen1);
    getchar();
    printing(gen1,0);
    getchar();

    // Generation Change
    for(int i = 1;i <= generations;i++){
        if(i % 2 == 1){
            preparation(gen2);
            generationChange(gen1,gen2);
            printing(gen2,i);
            getchar();
        }
        else{
            preparation(gen1);
            generationChange(gen2,gen1);
            printing(gen1,i);
            getchar();
        }
    }
}
