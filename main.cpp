#include<bits/stdc++.h>
using namespace std;


char * * create_board();

void print_board(char * * arr);

bool win_condition(char * * arr);

void player_move(char * * board);

bool board_full(char ** board);

void find_row_and_column(int x,int &row,int &column);

void play_move(char ** board,int row,int column,char sign);

int best_move(char * * board);

int minimax(char * * board,bool max);

void computers_move(char ** board);

int main()
{
    cout<<"press 1 if you want to play the first move"<<endl;
    int turn;
    cin>>turn;
    if(turn==1)
    {
    int n=9;
    char * * board=create_board();
    while(n--)
    {
        print_board(board);
        cout<<endl;
        if(n%2==0)
        {
            player_move(board);
            if(win_condition(board))
            {
                cout<<"Congratulations! You win"<<endl;
                return 0;
            }
            else
            {
                continue;
            }
        }
        else
        {
            computers_move(board);
            if(win_condition(board))
            {
                print_board(board);
                cout<<endl;
                cout<<"You lose! Better luck next time"<<endl;
                return 0;
            }
            else
            {
                continue;
            }
        }
    }
    cout<<"Tie"<<endl;
    return 0;
    }
    else
    {
        srand(time(NULL));
        int move=rand()%9+1;
        char * * board=create_board();
        int r,c;
        find_row_and_column(move,r,c);
        play_move(board,r,c,'O');
        int n=8;
        while(n--)
        {
            print_board(board);
            cout<<endl;
            if(n%2!=0)
            {
                player_move(board);
                if(win_condition(board))
                {
                    print_board(board);
                    cout<<"Congratulations! You win"<<endl;
                    return 0;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                computers_move(board);
                if(win_condition(board))
                {
                    print_board(board);
                    cout<<endl;
                    cout<<"You lose! Better luck next time"<<endl;
                    return 0;
                }
                else
                {
                    continue;
                }
            }
        }
        cout<<"Tie"<<endl;
        return 0;
    }
    
}

// max->0->AI


char * * create_board()
{
    char * * arr=new char * [3];
    cout<<"You are 'X'\n";
    for(int i=0;i<3;i++)
    {
        arr[i]=new char[3];
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr[i][j]=' ';
        }
    }
    return arr;
}

void print_board(char * * arr)
{
    for(int i=0;i<3;i++)
    {
        cout<<arr[i][0]<<" "<<"|"<<" "<<arr[i][1]<<" "<<"|"<<" "<<arr[i][2]<<endl;
    }
}

bool win_condition(char * * arr)
{
    for(int i=0;i<3;i++)
    {
        if((arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2])&&arr[i][0]!=' ')
        {
            return true;
        }
    }
    for(int i=0;i<3;i++)
    {
        if((arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i])&&arr[0][i]!=' ')
        {
            return true;
        }
    }
    if((arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2])&&arr[0][0]!=' ')
    {
        // cout<<"here\n";
        return true;
    }
    if((arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0])&&arr[0][2]!=' ')
    {
        return true;
    }
    return false;
}

void player_move(char * * board)
{
    char sign='X';
    while(1)
    {
    cout<<"Enter the position: ";
    int x;
    cin>>x;
    x--;
    int row;
    int column;
    find_row_and_column(x,row,column);
    if(board[row][column]==' ')
    {
        board[row][column]=sign;
        break;
    }
    else
    {
        cout<<"Invalid Move"<<endl;
    }
    }

}

void computers_move(char ** board)
{
    int cell=best_move(board);
    int row,column;
    find_row_and_column(cell,row,column);
    play_move(board,row,column,'O');
}

void play_move(char ** board,int row,int column,char sign)
{
    board[row][column]=sign;
}

int best_move(char * * board)
{
    int cell=-1;
    int max_profit=INT_MIN;
    for(int i=0;i<9;i++)
    {
        int row,column;
        find_row_and_column(i,row,column);
        if(board[row][column]==' ')
        {
            play_move(board,row,column,'O');
            int profit=minimax(board,false);
            if(profit>max_profit)
            {
                max_profit=profit;
                cell=i;
            }
            //undo move
            board[row][column]=' ';

        }
        else
        {
            continue;
        }
    }

    return cell;

}
int minimax(char * * board,bool max)
{
    if(win_condition(board))
    {
        if(max==true)
        {
            return -10;
        }
        else
        {
            return 10;
        }
    }
    if(!win_condition(board)&&board_full(board))
    {
        return 0;
    }
    if(max==true)
    {
        int max_profit=INT_MIN;
        for(int i=0;i<9;i++)
        {   
            int row,column;
            find_row_and_column(i,row,column);
            if(board[row][column]==' ')
            {
                play_move(board,row,column,'O');
                int profit=minimax(board,false);
                if(profit>max_profit)
                {
                    max_profit=profit;
                }
                //undo move
                board[row][column]=' ';

            }
            else
            {
                continue;
            }
            
        }
        return max_profit;
    }
    else
    {
        int min_profit=INT_MAX;
        for(int i=0;i<9;i++)
        {
            int row,column;
            find_row_and_column(i,row,column);

        
        if(board[row][column]==' ')
        {
            play_move(board,row,column,'X');
            int profit=minimax(board,true);
            if(profit<min_profit)
            {
                min_profit=profit;
            }
            //undo move
            board[row][column]=' ';

        }
        else
        {
            continue;
        }
        }
        return min_profit;
    }
}

bool board_full(char ** board)
{
    int count_empty=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==' ')
            {
                count_empty++;
            }
        }
    }
    if(count_empty==0)
    {
        return true;
    }
    return false;
}

void find_row_and_column(int x,int &row,int &column)
{
    row=x/3;
    column=x%3;
}

