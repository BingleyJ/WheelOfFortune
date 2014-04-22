
#include <iomanip>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

void pause(int ms);

string get_person();
string get_phrase();
string get_thing();
string get_bonus();
string get_bonusprize();

int spin();

void pretend_hack();

main(){

string player1_name , player2_name , player3_name;
int player1_score = 0, player2_score = 0, player3_score = 0;
int current_prize = 0;
int counter = 0;
bool game_over = false;
bool solved = false;
int who_turn = 1;
int bonus_whoturn = 0;
char bonus1;
char bonus2;
char bonus3;
char bonusv;
int round = 1;
int temp_num = 0;
int person_size = 0, phrase_size = 0, thing_size = 0, bonus_size = 0, bonusprize_size = 0;;
string person_, phrase_, thing_, bonus_, bonusprize_;
char blank = 219;
string temp_str;
char player_choice = '0';
char cons[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
bool cons_board[21] = {false};
//char cons_track[21] = {' '};
char vowels[5] = {'a','e','i','o','u'};
bool vowels_board[5] = {false};
char vowels_track[5] = {' '};
int vowel_count = 0;
char vowel_choice = '0';
bool good_pick = false;

srand ( time(NULL) );

temp_str = get_person();
person_ = temp_str;
temp_num = temp_str.size();
char person[temp_num];
bool person_board[temp_num];
person_size = temp_num;
for (int a = 0; a < temp_num; a++){
    person[a] = temp_str[a];
    if (person[a] == ' ')
        person_board[a] = 1;
    if (person[a] != ' ')
        person_board[a] = 0;
    }

temp_str = get_phrase();
phrase_ = temp_str;
temp_num = temp_str.size();
char phrase[temp_num];
bool phrase_board[temp_num];
phrase_size = temp_num;
for (int a = 0; a < temp_num; a++){
    phrase[a] = temp_str[a];
    if (phrase[a] == ' ')
        phrase_board[a] = 1;
    if (phrase[a] != ' ')
        phrase_board[a] = 0;
    }

temp_str = get_thing();
thing_ = temp_str;
temp_num = temp_str.size();
char thing[temp_num];
bool thing_board[temp_num];
thing_size = temp_num;
for (int a = 0; a < temp_num; a++){
    thing[a] = temp_str[a];
    if (thing[a] == ' ')
        thing_board[a] = 1;
    if (thing[a] != ' ')
        thing_board[a] = 0;
    }

temp_str = get_bonus();
bonus_ = temp_str;
temp_num = temp_str.size();
char bonus[temp_num];
bool bonus_board[temp_num];
bonus_size = temp_num;
for (int a = 0; a < temp_num; a++){
    bonus[a] = temp_str[a];
    if ((bonus[a] == ' ') || (bonus[a] == 'r') || (bonus[a] == 's') || (bonus[a] == 't') || (bonus[a] == 'l') || (bonus[a] == 'e') ){
        bonus_board[a] = 1;

    }
    else
        bonus_board[a] = 0;
    }

bonusprize_ = get_bonusprize();


////             ----------------------------             YEEEW!
//pretend_hack();
system("CLS");
//////////////////////////---Collect Player Names
cin.clear();
//cin.ignore( 1000, '\n' );
cout<<"[--------] WELCOME TO WHEEL OF FORTUNE [---------]"<<endl<<endl;
pause(20);
cout<<"[---] Player #1 please type your name ..;:";
cin>>player1_name;
cout<<endl<<"[---] Player #2 please type your name ..;:";
cin>>player2_name;
cout<<endl<<"[---] Player #3 please type your name ..;:";
cin>>player3_name;



////Round #1
while (player_choice != 'q'){
    //player_choice = '0';
    system("CLS");
    if (bonus_whoturn == 1)
        who_turn = 1;
    if (bonus_whoturn == 2)
        who_turn = 2;
    if (bonus_whoturn == 3)
        who_turn = 3;
    if (round == 1)
        cout<<"[- - ---- -- -  ROUND  1  PERSON  - -- ---- - -]"<<endl<<endl;
    if (round == 2)
        cout<<"[- - ---- -- -  ROUND  2  PHRASE  - -- ---- - -]"<<endl<<endl;
    if (round == 3)
        cout<<"[- - ---- -- -  ROUND  3  THING  - -- ----  - -]"<<endl<<endl;
    if (round == 4){
        cout<<" PLAYING FOR "<<bonusprize_ << " -- WOW!!"<<endl;
        cout<<endl<<"[- - ---- -- -  ROUND  4  BONUS  - -- ----  - -]"<<endl;
        cout<<"[- - ---- - PROGRAMMING  LANGUAGES - - ---  - -]"<<endl<<endl;
    }
    //print letter board
    if (round == 1){
        for (int a = 0; a < person_size; a++){
            if (person_board[a] == false)
                cout<<blank;
            if (person_board[a] == true)
                cout<<person[a];
        cout<<" ";
        }
    }
    if (round == 2){
        for (int a = 0; a < phrase_size; a++){
            if (phrase_board[a] == false)
                cout<<blank;
            if (phrase_board[a] == true)
                cout<<phrase[a];
        cout<<" ";
        }
    }
    if (round == 3){
        for (int a = 0; a < thing_size; a++){
            if (thing_board[a] == false)
                cout<<blank;
            if (thing_board[a] == true)
                cout<<thing[a];
        cout<<" ";
        }
    }
    if (round == 4){
        cons_board[13] = true; //r
        cons_board[14] = true; //s
        cons_board[15] = true;  //t
        cons_board[8] = true;  //l
        vowels_board[1] = true; //e
    for(int a = 0; a < 21; a++){
        if ((cons[a] == bonus1) || (cons[a] == bonus2) || (cons[a] == bonus3))
            cons_board[a] = true;
    }
    for(int a = 0; a < 5; a++){
        if(vowels_board[a] == bonusv)
            vowels_board[a] = true;

    }
        for (int a = 0; a < bonus_size; a++){
            if (bonus_board[a] == false)
                cout<<blank;
            if (bonus_board[a] == true){
                cout<<bonus[a];
            }
            //
        cout<<" ";
        }
    }
    cout<<endl<<endl<<"[----------------Letters.Used------------------]"<<endl<<endl;

    for(int a = 0; a < 21; a++){
        if (cons_board[a] == true)
            cout<<cons[a]<<" ";
    }
    cout<<endl<<endl<<"[----------------Vowels..Used------------------]"<<endl<<endl;
    for(int a = 0; a < 5; a++){
        if (vowels_board[a] == true){
            vowel_count++;
            cout<<vowels[a]<<" ";
        }
    }
    if (round != 4){
        cout<<endl<<endl<<"[---------------Player..Scores-----------------]"<<endl<<endl;
        cout<<"# 1 "<<player1_name<<" - $"<<player1_score<<endl;
        cout<<"# 2 "<<player2_name<<" - $"<<player2_score<<endl;
        cout<<"# 3 "<<player3_name<<" - $"<<player3_score<<endl<<endl;
        cout<<"[------------------Options---------------------]"<<endl;
        cout<<"[Player "<<who_turn<<"] ___.;[s]pin___.;[v]owel___.;s[o]lve__"<<endl;
        cout<<"[----------------------------------------------]"<<endl;
        cout<<"[Your Choice :------>";
        cin>>player_choice;
    }
    if (round == 4 ){
        player_choice = 'o';
        cout<<endl<<endl;

        if (game_over == true)
            player_choice = 'q';
    }

        if ((vowel_count == 5) && (player_choice == 'v'))
            player_choice = 'w';
        while ((player_choice != char(168)) &&(player_choice != 's') && (player_choice != 'v') && (player_choice != 'o') && (player_choice != 'q') && (vowel_choice !=5)){

        if ((vowel_count == 5) && (player_choice == 'v'))
            player_choice = 'w';
        cout<<"[--INVALID CHOICE--]"<<endl;
        cout<<"[Your Choice :------>";
        cin>>player_choice;
        if ((vowel_count == 5) && (player_choice == 'v'))
            player_choice = 'w';
        }
//// ENOUGH MONEY TO PICK V?
        good_pick = true;
        if ((who_turn == 1) && (player1_score < 250))
            good_pick = false;
        if ((who_turn == 2) && (player2_score < 250))
            good_pick = false;
        if ((who_turn == 3) && (player3_score < 250))
            good_pick = false;

        while ((good_pick == false) && (player_choice == 'v')){
                if ((who_turn == 1) && (player1_score < 250))
                    good_pick = false;
                if ((who_turn == 2) && (player2_score < 250))
                    good_pick = false;
                if ((who_turn == 3) && (player3_score < 250))
                    good_pick = false;

                cout<<"-[ YOU DON'T HAVE ENOUGH CHEDDER FOO! ]-"<<endl;
                cout<<"[Your Choice :------>";
                cin>>player_choice;
                if ((who_turn == 1) && (player1_score > 250) || (player_choice == 's') ||(player_choice == 'o') || (player_choice == 'q'))
                    good_pick = true;
                if ((who_turn == 2) && (player2_score > 250) || (player_choice == 's') || (player_choice == 'o') || (player_choice == 'q'))
                    good_pick = true;
                if ((who_turn == 3) && (player3_score > 250) || (player_choice == 's') || (player_choice == 'o') || (player_choice == 'q'))
                    good_pick = true;
         }
//// END ENOUGH MONEY TO PICK vowel

        if(player_choice == 'q')
            break;
// -------------------------- SPIN
        if(player_choice == 's')
        {
            good_pick = false;
            //player_choice = ' ';
            player_choice = '0';
            current_prize = spin();
            while((player_choice != 'b') && (player_choice != 'c') && (player_choice != 'd')  && (player_choice != 'f') && (player_choice != 'g') && (player_choice != 'h') && (player_choice != 'j') && (player_choice != 'k') && (player_choice != 'l') && (player_choice != 'm') && (player_choice != 'n') && (player_choice != 'p') && (player_choice != 'q') && (player_choice != 'r') && (player_choice != 's') && (player_choice != 't') && (player_choice != 'v') && (player_choice != 'w') && (player_choice != 'x') && (player_choice != 'y') && (player_choice != 'z')){
                while ( good_pick == false){
                    good_pick = true;
                    cout<<endl<<"[ -- Please Enter A Constanant___,;";
                    cin>>player_choice;

                    for(int a = 0; a < 21; a++){
                        //counter = 0;

                        if ((cons[a] == player_choice)  && (cons_board[a] == true)){
                            cout<<endl<<"[!Letter already chosen -- Please Try Again!]"<<endl;
                            good_pick = false;
                            //player_choice = '0';
                        }
                        if ((cons[a] == player_choice) && (cons_board[a] == false) )
                                good_pick = true;
                    }
                    if ((player_choice == 'a') ||(player_choice == 'e') ||(player_choice == 'i') ||(player_choice == 'o') ||(player_choice == 'u')){
                            cout<<"Vowels are not allowed at this time, Please try again."<<endl;
                            good_pick = false;
                    }
                }
            }


           // good_pick = false;
            switch (player_choice){
                case 'b': cons_board[0] = true; break;
                case 'c': cons_board[1] = true; break;
                case 'd': cons_board[2] = true; break;
                case 'f': cons_board[3] = true; break;
                case 'g': cons_board[4] = true; break;
                case 'h': cons_board[5] = true; break;
                case 'j': cons_board[6] = true; break;
                case 'k': cons_board[7] = true; break;
                case 'l': cons_board[8] = true; break;
                case 'm': cons_board[9] = true; break;
                case 'n': cons_board[10] = true; break;
                case 'p': cons_board[11] = true; break;
                case 'q': cons_board[12] = true; break;
                case 'r': cons_board[13] = true; break;
                case 's': cons_board[14] = true; break;
                case 't': cons_board[15] = true; break;
                case 'v': cons_board[16] = true; break;
                case 'w': cons_board[17] = true; break;
                case 'x': cons_board[18] = true; break;
                case 'y': cons_board[19] = true; break;
                case 'z': cons_board[20] = true; break;
            }

////////////////////////////        // UNCOVER LETTERS CHOSEN
        if (round == 1){
            temp_num = 0 ;
            for (int a = 0; a < person_size; a++){
                if (person[a] == player_choice){
                    person_board[a] = true;
                    temp_num++;
                }
            }
        }
        if (round == 2){
            temp_num = 0 ;
            for (int a = 0; a < phrase_size; a++){
                if (phrase[a] == player_choice){
                    phrase_board[a] = true;
                    temp_num++;
                }
            }
        }
        if (round == 3){
            temp_num = 0 ;
            for (int a = 0; a < thing_size; a++){
                if (thing[a] == player_choice){
                    thing_board[a] = true;
                    temp_num++;
                }
            }
        }
        if (round == 4){
            temp_num = 0 ;
            for (int a = 0; a < bonus_size; a++){
                if (bonus[a] == player_choice){
                    bonus_board[a] = true;
                    temp_num++;
                }
            }
        }
        /////////////////////////////////////////// END UNCOVER

        current_prize = current_prize * temp_num;
        cout<<"[--- There are "<<temp_num<<" Letter "<<player_choice<<endl;
        cout<<"[--- Player #"<<who_turn<<" you just added $"<<current_prize<<" to your score."<<endl;

        //add new score to old score
        switch (who_turn){
            case 1:player1_score = player1_score + current_prize;break;
            case 2:player2_score = player2_score + current_prize;break;
            case 3:player3_score = player3_score + current_prize;break;
        }
        if (current_prize > 0){
            cout<<"[--- Congrats Player "<<who_turn<<" You get to play again!"<<endl;
            who_turn = who_turn - 1;
        }
        if (who_turn == 0)
            who_turn = 3;
        system("pause");
    player_choice = ' ';
    }


    //-----------------------------------VOWELS

    if (player_choice == 'v'){
        good_pick = false;
        while((vowel_choice != 'a') &&(vowel_choice != 'e') && (vowel_choice!='i')&&(vowel_choice != 'o') && (vowel_choice != 'u')){


                good_pick = true;
                cout<<endl<<"[ -- Please Enter A Vowel___,;";
                cin.clear();
                cin>>vowel_choice;


                for(int a = 0; a < 5; a++){
                    if ((vowels[a] == vowel_choice) && (vowels_board == false)){
                        cout<<endl<<"[!Vowel already chosen -- Please Try Again!]"<<endl;
                        good_pick = false;
                        vowel_choice = '0';
                    }
                }

            }
                    if (round == 1){
                        temp_num = 0 ;
                        for (int a = 0; a < person_size; a++){
                            if (person[a] == vowel_choice){
                                person_board[a] = true;
                                temp_num++;
                            }
                        }
                    }
                    if (round == 2){
                        temp_num = 0 ;
                        for (int a = 0; a < phrase_size; a++){
                            if (phrase[a] == vowel_choice){
                                phrase_board[a] = true;
                                temp_num++;
                            }
                        }
                    }
                    if (round == 3){
                        temp_num = 0 ;
                        for (int a = 0; a < thing_size; a++){
                            if (thing[a] == player_choice){
                            thing_board[a] = true;
                            temp_num++;
                            }
                        }
                    }

                    switch (who_turn){
                        case 1: player1_score = player1_score - 250;break;
                        case 2: player2_score = player2_score - 250;break;
                        case 3: player3_score = player3_score - 250;break;
                    }


                    if (temp_num > 0){
                        cout<<"[---]"<<endl;
                        cout<<"[---]"<<endl;
                        cout<<"[---]";
                        cout<<endl<<"[--- There Were "<<temp_num<<" "<<vowel_choice<<"'s"<<endl;
                        cout<<endl<<"[--- Congrats Player #"<<who_turn<<" "<<"you get to play again!"<<endl;
                        who_turn = who_turn - 1;
                        if (who_turn == 0)
                            who_turn = 3;
                        system("pause");
                    }
                    if (temp_num == 0){
                        cout<<"[---]"<<endl;
                        cout<<"[---]"<<endl;
                        cout<<"[---]"<<endl;

                        cout<<"[--- Sorry Player #"<<who_turn<<" There is no "<<vowel_choice<<" in the puzzle"<<endl;
                        system("pause");

                    }

    switch (vowel_choice){
                        case 'a':vowels_board[0] = true;break;
                        case 'e':vowels_board[1] = true;break;
                        case 'i':vowels_board[2] = true;break;
                        case 'o':vowels_board[3] = true;break;
                        case 'u':vowels_board[4] = true;break;
                    }
    }

if (player_choice == 'o'){

    cout<<"[--ENTER YOUR PUZZLE SOLUTION ---:";
    cin.ignore();
    getline(cin,temp_str);
    ///cheat
    if ((temp_str == "cool") && (round == 1))
        temp_str = person_;
    if ((temp_str == "cool") && (round == 2))
        temp_str = phrase_;
    if ((temp_str == "cool") && (round == 3))
        temp_str = thing_;
    ///END CHEAT
    if (round == 1){
        if(temp_str == person_){
            cout<<"[-------CONGRATULATIONS YOU PLAYER "<<who_turn<<" YOU JUST SOLVED THE PUZZLE!!!-------]"<<endl<<"[-- YOU GET TO START THE NEXT ROUND :) --]"<<endl;
            who_turn = who_turn -1;
            system("pause");
            for (int a = 0; a < person_size; a++){
                person_board[a] = true;
            }
            for (int a = 0; a < 21; a++){
                cons_board[a] = false;
            }
            for (int a = 0; a < 5; a++){
                vowels_board[a] = false;
            }
        round++;
        }

    }
    if (round == 2){
        if(temp_str == phrase_){
            cout<<"[-------CONGRATULATIONS YOU PLAYER "<<who_turn<<" YOU JUST SOLVED THE PUZZLE!!!-------]"<<endl<<"[-- YOU GET TO START THE NEXT ROUND :) --]"<<endl;
            who_turn = who_turn -1;
            system("pause");
            for (int a = 0; a < phrase_size; a++){
                phrase_board[a] = true;
            }
            for (int a = 0; a < 21; a++){
                cons_board[a] = false;
            }
            for (int a = 0; a < 5; a++){
                vowels_board[a] = false;
            }
        round++;
        }
    }
    if ((round == 4)){
        if(temp_str == bonus_){
            cout<<"[--CONGRATULATIONS PLAYER #"<<who_turn<<" YOU JUST WON THE GAME!--]"<<endl;


            game_over = true;
        }
        if(temp_str != bonus_){
            cout<<"[---TOO BAD PLAYER #"<<who_turn<<" YOU LOST THE BONUS ROUND---]"<<endl;
            cout<<endl<<"[---------------BUT YOU DID WIN THE GAME!----------------]"<<endl;
            cout<<endl<<"THE SOLUTION WAS :"<<bonus_<<endl;
            game_over = true;
        }
    cout<<endl<<"[----------------FINAL..SCORES------------------]"<<endl;
    cout<<"# 1 "<<player1_name<<" - $"<<player1_score<<endl;
    cout<<"# 2 "<<player2_name<<" - $"<<player2_score<<endl;
    cout<<"# 3 "<<player3_name<<" - $"<<player3_score<<endl;
    system("pause");
    }

    if (round == 3){
        if(temp_str == thing_){
            cout<<"[-------CONGRATULATIONS YOU PLAYER "<<who_turn<<" YOU JUST SOLVED THE PUZZLE!!!-------]"<<endl;
            who_turn = who_turn -1;
            for (int a = 0; a < thing_size; a++){
                thing_board[a] = true;
            }
            for (int a = 0; a < 21; a++){
                cons_board[a] = false;
            }
            for (int a = 0; a < 5; a++){
                vowels_board[a] = false;
            }
        if ((player1_score > player2_score) && (player1_score > player3_score))
            bonus_whoturn = 1;
        if ((player2_score > player1_score) && (player2_score > player3_score))
            bonus_whoturn = 2;
        if ((player3_score > player2_score) && (player1_score > player2_score))
            bonus_whoturn = 3;
        cout<<"[-------CONGRATULATIONS PLAYER "<<bonus_whoturn<<" YOU GO ON TO THE BONUS ROUND!!!-------]"<<endl<<" [- - :) --]"<<endl;
        system("pause");
        system("cls");
        cout<<"[------------ATTENTION PLAYER #"<<bonus_whoturn<<" LISTEN UP!!!!! --------------]"<<endl<<endl;
        cout<<"[-- You Will be givin r,s,t,l,e for free in the bonus round --]"<<endl;
        cout<<"[-- ---- - -You get to choose three const and 1 vowel - --- --]"<<endl<<endl;
        cout<<"Enter const #1 :";
        cin>>bonus1;
        cout<<endl<<"Enter const #2 :";
        cin>>bonus2;
        cout<<endl<<"Enter const #3 :";
        cin>>bonus3;
        cout<<endl<<"Enter vowel #1 :";
        cin>>bonusv;
        for (int a = 0; a < bonus_size; a++){
            //bonus[a] = bonus_size[a];
            if ((bonus[a] == bonus1) || (bonus[a] == bonus2) || (bonus[a] == bonus3) || (bonus[a] == bonusv)){
                bonus_board[a] = 1;
            }
        }
        round++;
        }
    }

}

if (player_choice == char(168)){
    cout<<endl<<":";
    cin>>temp_num;
    switch (who_turn){
        case 1:player1_score = player1_score + temp_num;who_turn = 3;break;
        case 2:player2_score = player2_score + temp_num;who_turn = 1;break;
        case 3:player3_score = player3_score + temp_num;who_turn = 2;break;
    }
}



who_turn = who_turn + 1;
    if (who_turn == 4)
        who_turn = 1;

vowel_choice ='0';
vowel_count = 0;
}
//who_turn


///////////////////////////////////////////-----]test person puzzle print.[-------
//for (int a = 0; a < person_size; a++){
//    if (person_board[a] == false)
//        cout<<blank;
//    if (person_board[a] == true)
//        cout<<person[a];
//    cout<<" ";
//}
//cout<<endl<<"PERSON!!!!!";


//current_prize = spin();
//cout<<"PRIZE -----]"<<current_prize;

return 0;
}

string get_person(){
    int counter = 0;
    int rand_line = rand() % 10;
    int a=0;
    string tempstring;

    ifstream infile;
    infile.open ("people.txt");

    while(a<1)
    {
        getline(infile, tempstring);
        counter++;
        if (counter == rand_line)
            break;
    }
    infile.close();
    return(tempstring);
}

string get_phrase(){
    int counter = 0;
    int rand_line = rand() % 10;
    int a=0;
    string tempstring;

    ifstream infile;
    infile.open ("phrase.txt");

    while(a<1)
    {
        getline(infile, tempstring);
        counter++;
        if (counter == rand_line)
            break;
    }
    infile.close();
    return(tempstring);
}

string get_thing(){
    int counter = 0;
    int rand_line = rand() % 10;
    int a=0;
    string tempstring;

    ifstream infile;
    infile.open ("thing.txt");

    while(a<1)
    {
        getline(infile, tempstring);
        counter++;
        if (counter == rand_line)
            break;
    }
    infile.close();
    return(tempstring);
}

string get_bonus(){
    int counter = 0;
    int rand_line = rand() % 10;
    int a=0;
    string tempstring;

    ifstream infile;
    infile.open ("bonus.txt");

    while(a<1)
    {
        getline(infile, tempstring);
        counter++;
        if (counter == rand_line)
            break;
    }
    infile.close();
    return(tempstring);
}

string get_bonusprize(){
    int counter = 0;
    int rand_line = rand() % 10;
    int a=0;
    string tempstring;

    ifstream infile;
    infile.open ("bonusprize.txt");

    while(a<1)
    {
        getline(infile, tempstring);
        counter++;
        if (counter == rand_line)
            break;
    }
    infile.close();
    return(tempstring);
}


void pause(int ms){

    int temp = time(NULL) + (ms * 0.1);
    while(temp > time(NULL));
}

int spin(){

    int ran_spin = 1;
    char spin_screen[21][21] = {' '};
    // yx for astrix animation
    int spin_astrix_yx[48] = {0,10,5,10 ,1,15,5,11, 2,17,6,13, 6,13,6,20, 6,13,10,17, 7,11,11,15, 7,10,12,10, 7,9,11,5, 6,7,10,3, 6,0,6,7, 2,3,6,7, 1,5,5,9 };

    int spin_count = 0;
    int prize = 0;

    //prizes
    spin_screen[1][10] = '5';spin_screen[2][10] = '0';spin_screen[3][10] = '0';spin_screen[4][10] = '0';
    spin_screen[11][10] = '2';spin_screen[10][10] = '0';spin_screen[9][10] = '0';spin_screen[8][10] = '0';

    spin_screen[2][6] = '2';spin_screen[3][7] = '0';spin_screen[4][8] = '0';
    spin_screen[10][6] = '8';spin_screen[9][7] = '5';spin_screen[8][8] = '0';

    spin_screen[3][4] = '4';spin_screen[4][5] = '5';spin_screen[5][6] = '0';
    spin_screen[9][4] = '7';spin_screen[8][5] = '5';spin_screen[7][6] = '0';

    spin_screen[6][2] = '2';spin_screen[6][3] = '5';spin_screen[6][4] = '0';spin_screen[6][5] = '0';

    spin_screen[2][14] = '1';spin_screen[3][13] = '5';spin_screen[4][12] = '0';
    spin_screen[10][14] = '3';spin_screen[9][13] = '5';spin_screen[8][12] = '0';

    spin_screen[3][16] = '8';spin_screen[4][15] = '0';spin_screen[5][14] = '0';
    spin_screen[9][16] = '1';spin_screen[8][15] = '0';spin_screen[7][14] = '0';

    spin_screen[6][15] = '3';spin_screen[6][16] = '5';spin_screen[6][17] = '0';spin_screen[6][18] = '0';
    system("CLS");

    while ( ran_spin < 20){
        ran_spin = rand() % 120;}

    spin_count = -4;
    for (int temp_spin = 0; temp_spin < ran_spin; temp_spin++){

        spin_count = spin_count + 4;
        if (spin_count == 48)
            spin_count = 0;

        spin_screen[spin_astrix_yx[spin_count]][spin_astrix_yx[spin_count+1]] = '*';
        spin_screen[spin_astrix_yx[spin_count+2]][spin_astrix_yx[spin_count+3]] = '*';


        for(int a = 0; a < 21; a++){
            for(int b = 0; b < 21; b ++){
                cout<<spin_screen[a][b];
            }
            cout<<endl;
        }

        spin_screen[spin_astrix_yx[spin_count]][spin_astrix_yx[spin_count+1]] = ' ';
        spin_screen[spin_astrix_yx[spin_count+2]][spin_astrix_yx[spin_count+3]] = ' ';


        //cin.get();
        if (temp_spin < ran_spin - 1){
           // BEEP  cout<<char(7);

            system("CLS");
        }
    }
    switch (spin_count)
        {
            case 0: prize = 5000; break;
            case 4: prize = 150; break;
            case 8: prize = 800; break;
            case 12: prize = 3500; break;
            case 16: prize = 100; break;
            case 20: prize = 350; break;
            case 24: prize = 2000; break;
            case 28: prize = 850; break;
            case 32: prize = 750; break;
            case 36: prize = 2500; break;
            case 40: prize = 450; break;
            case 44: prize = 200; break;
        }

    return(prize);
 //   for (int a = 0; a < ran_spin; a++){
 //   }
}

void pretend_hack(){
int ran_spin = 0;
int temp;
//system("CLS");
cout<<endl;
cout<<char(7);
for (int a = 0; a < 60000; a++){
//    while (ran_spin = temp){
        ran_spin = 1;
        ran_spin = rand() % 240;
   // }
    temp = ran_spin;
    if (temp == char(7))
        ran_spin=char(8);
    cout << char(ran_spin);
    //cout << char(65);
    pause(7);
    }
    cout<<char(7);
system("CLS");
cout<<endl<<endl<<"C:\>FORMAT C: ";
cout<<endl<<"ARE YOU SURE <Y/N> :";
pause(15);
cout<<"Y";
pause(25);

ran_spin = 0;

    cout<<endl<<"Checking existing disk format."<<endl;
    pause(10);
    cout<<"Verifying Hard Disk"<<endl;
    pause(10);

    system("CLS");
for (int a = 0; a < 101; a++){
    cout<<endl<<endl<<"C:\>FORMAT C: ";
    cout<<endl<<"ARE YOU SURE <Y/N> :Y"<<endl;
    cout<<"Checking existing disk format."<<endl;
    cout<<"Verifying Hard Disk"<<endl;
    cout<<"Formatting C:"<<endl;
    cout<<a<<"% Complete.";
    pause(8);
    if (a < 100)
        system("CLS");
}
cout<<endl<<"Format Complete."<<endl;
system("pause");

cout<<endl<<"["<<endl<<"["<<endl<<"["<<endl<<"[------- Just Joking :) Ready To play Wheel Of Fortune?"<<endl;
system("pause");

}
