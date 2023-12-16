#include<bits/stdc++.h>
using namespace std;
typedef vector<char>  vc;
typedef vector<int>  vi;
typedef vector<bool> vb;
typedef vector<vc>  vvc;

void build_board(vvc &grid){
    char hor = '-'; 
    char ver = '|'; 
    char connect = '+';

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            if(i % 2 == 0){
                if(j % 2 == 0) grid[i][j]=connect;
                else grid[i][j]=hor;
            } else {
                if(j % 2 == 0) grid[i][j]=ver;
                else grid[i][j]=' ';
            }
        }
    }
}

void show(vvc &grid){
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            cout << grid[i][j];
        }cout<<endl;
    }
}

void Menu(){
    cout<<"1. Want to play!"<<endl; 
    cout<<"2. Exit!"<<endl; 
}


bool insertIt(int pos, int player, vb &vis, vvc &grid){
    if(vis[pos]){
        return false;
    }
    vis[pos] = true;

    if(pos==1){
        if(player==1) grid[1][1] = '#';
        else grid[1][1] = 'O';
    }
    else if(pos==2){
        if(player==1) grid[1][3] = '#';
        else grid[1][3] = 'O';
    }
    else if(pos==3){
        if(player==1) grid[1][5] = '#';
        else grid[1][5] = 'O';
    }
    else if(pos==4){
        if(player==1) grid[3][1] = '#';
        else grid[3][1] = 'O';
    }
    else if(pos==5){
        if(player==1) grid[3][3] = '#';
        else grid[3][3] = 'O';
    }
    else if(pos==6){
        if(player==1) grid[3][5] = '#';
        else grid[3][5] = 'O';
    }
    else if(pos==7){
        if(player==1) grid[5][1] = '#';
        else grid[5][1] = 'O';
    }
    else if(pos==8){
        if(player==1) grid[5][3] = '#';
        else grid[5][3] = 'O';
    }
    else if(pos==9){
        if(player==1) grid[5][5] = '#';
        else grid[5][5] = 'O';
    }

    return true;
}


bool checkWin(vvc &grid){
    //rows
    for (int i = 1; i <= 5; i += 2) {
        if (grid[i][1]!=' ' && grid[i][1]==grid[i][3] && grid[i][3]==grid[i][5])
            return true;
    }
    //columns
    for (int i = 1; i <= 5; i += 2) {
        if (grid[1][i]!=' ' && grid[1][i]==grid[3][i] && grid[3][i]==grid[5][i])
            return true;
    }
    //diagonals
    if (grid[1][1]!=' ' && grid[1][1]==grid[3][3] && grid[3][3]==grid[5][5])
        return true;

    if (grid[5][1]!=' ' && grid[5][1]==grid[3][3] && grid[3][3]==grid[1][5])
        return true;

    return false;
}


int main()
{
    vvc grid(7, vc(7));

    while(true){
        build_board(grid);
        vb vis(10,false);
        
        Menu();
        cout<<"Choose Option: ";
        int n; cin>>n;
        if(n==2) break;

        else{
            int t=0;
            vi players = {1,2,1,2,1,2,1,2,1};
            bool flagwin = false;

            while (t<9)
            {
                int player = players[t];
                cout<<endl;  show(grid);
                cout<<"Player " << player << " : ";
                int x; cin>>x;
                bool chkinsert = insertIt(x, player, vis, grid);
                if(chkinsert){
                    flagwin = checkWin(grid);
                    if(flagwin){
                        int otherplayer;
                        if(player==1) otherplayer=2; else otherplayer=1;
                        cout<<endl;
                        show(grid);
                        cout <<"\nPlayer "<<player<<" is the Winner! Congrats!!";
                        cout <<"\nPlayer "<<otherplayer<<" is the LOOSER! Cry More!!\n\n";
                        break;
                    }
                    t++;
                }
                else cout<<"Position "<< x <<" has already been taken!"<<endl<<"Insert Again!"<<endl;
            }
            if(t>=9 || !flagwin){
                cout<<endl;
                show(grid);
                cout<<"=====DRAW====="<<endl<< endl;
            } 
        }
    }
    return 0;
}