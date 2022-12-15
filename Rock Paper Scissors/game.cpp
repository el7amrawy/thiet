#include <iostream>

using namespace std;

int genRandNum(int offset, int range);
string ro_pa_sc(int n);
void clearScreen(int n);
void userWon(int* userScore,int compScore);
void compWon(int userScore,int* compScore);

int main(){

    int userInp,userScore=0,compScore=0;

    while (1)
    {  
        int comp=genRandNum(1,3);
        cout<<"\n1) Rock\n2) Paper\n3) Scissors\n\n0) exit\n\nChoose: ";
        cin>>userInp;

        if (userInp==0)
            return 0;

        clearScreen(4);
        if(userInp>3||userInp<1){
            cout<<"\n** input is out of range **\n\n";
        } else{
            cout<<"\nyou chose: "<<ro_pa_sc(userInp)<<"\n"<<"computer chose: "<<ro_pa_sc(comp)<<"\n";
            if(userInp==comp){
                cout<<"\n  *** tie ***\n\n";
                cout<<"your score: "<<userScore<<"\t"<<"computer score: "<<compScore<<"\n";
            }
            else if(userInp<comp && comp-userInp==1){
                compWon(userScore,&compScore);
            }
            else if(userInp>comp && userInp-comp==1){
                userWon(&userScore,compScore);
            } else{
                if(userInp==1){
                    userWon(&userScore,compScore);
                }else{
                    compWon(userScore,&compScore);
                }
            }
        }
    }
}

int genRandNum(int offset, int range){
    srand((unsigned) time(NULL));
    int random=(rand()%range)+offset;
    return random;
}

string ro_pa_sc(int n){
    switch (n){
        case 1:
            return "Rock";
            break;
        case 2:
            return "Paper";
            break;
        default:
            return "Scissors";
    }
}

void clearScreen(int n){
    for(int i=0;i<n;i++){
        cout<<"\n\n";
    }
}

void userWon(int* userScore,int compScore){
    *userScore+=1;
    cout<<"\n  *** you won ***\n\n";
    cout<<"your score: "<<*userScore<<"\t"<<"computer score: "<<compScore<<"\n\n";
}

void compWon(int userScore,int* compScore){
    *compScore+=1;
    cout<<"\n  *** computer won ***\n\n";
    cout<<"your score: "<<userScore<<"\t"<<"computer score: "<<*compScore<<"\n\n";
}