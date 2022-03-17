#include <iostream>
#include <deque>
#include <vector>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#ifdef _WIN32
#define clear()    system("cls")
#else
#define clear()    system("clear")
#endif
using namespace std;
int Start(void);
int Cstart(void);
void Playgame(void);
void Shuffcard(int cards[]);
void Piccard(int num);

class Player_2
{
public:
    int x, y;
    Player_2(int width, int high) { x = width / 2; y = high - 1 ; }
};
class La
{
private:
    deque<bool> obstruction;
    bool right;
public:
    La(int width)
    {
        for (int i = 0; i < width; i++)
            obstruction.push_front(true);
        right = rand() % 2;
    }
    void Move(){
        
            if (rand() % 5 == 1)
                obstruction.push_back(true);
            else
                obstruction.push_back(false);
            obstruction.pop_front();
    }
    bool CheckPos(int pos) { return obstruction[pos]; }
};
class Playgame_2{
private:
    bool quit;
    int high;
    int width;
    int score;
    Player_2 * py_2;
    vector<La*> map;
public:
    Playgame_2(int w , int h )
    {
        high = h;
        width = w;
        quit = false;
        for (int i = 0; i < high; i++)
            map.push_back(new La(width));
        py_2 = new Player_2(width,high);
    }
        void Dw_();
    void keyboard();
    void wot();
    void Run();
};

int Cstart(void){
	string myText;
	ifstream MyReadFile("crh.txt");
	cout<<"How to play: \n";
	while (getline (MyReadFile, myText)) {
	cout << myText;
	}
		MyReadFile.close();
		char Ans='n';
	printf("\n\nWant to start playing now ? y|n : ");
	do{
		Ans = getchar();
	} while (Ans!='y' &&Ans!='n');
	if(Ans=='y'){
		return 1;
	}
    return 0;
}
double discount(double score1) {
   	return score1;
}	

double discount(double score1, double score2) {
    return score1 + score2;
}

double discount(double score1, double score2, double score3) {
    return score1 + score2 + score3;
}
int Start(void){
	printf("                       1111___11111\n");
	printf("                     11____111____11__111\n");
	printf("                   11___111____1111111___11\n");
	printf("                 111111111111111111111111111111111\n");
	printf("              11111__1__________________________11\n");
	printf("           1111__11__1___________________________1\n");
	printf("         111_11__1__111__________________________1\n");
	printf("      111_11_111_1_11_11_________1_______________1\n");
	printf("     1_11__1_1_1111_111__________11______________1\n");
	printf("   111_11111_111111_111_________111______________1\n");
	printf(" 11__11111111_11_11____________11111_____________1\n");
	printf("1_11__1__1111____11___________1111111____________1\n");
	printf("1__1111111111____11__________1111111111__________1\n");
	printf(" 111_1_11___11___11________1111111111111_________1\n");
	printf("  11_11_1___11___11______11111111111111111_______1\n");
	printf("   11____1___1___11____111111111111111111111_____1\n");
	printf("    11___11__11__11___111111111111111111111111___1\n");
	printf("     11___1__11__11__111111111111111111111111111_1\n");
	printf("      11___1__1__11_1111111111111111111111111111_1\n");
	printf("       11__11_1__11_1111111111111111111111111111_1\n");
	printf("        11__1_11_11__111111111111111111111111111_1\n");
	printf("         11__1_1_11__11111111111111111111111111__1\n");
	printf("          11_111_11___111111111__11__111111111___1\n");
	printf("            1_11_11_____11111____11____11111_____1\n");
	printf("             1_1111___________11111111___________1\n");
	printf("              11111__________1111111111______11__1\n");
	printf("               111____________11111111_______111_1\n");
	printf("                11__________________________11_1_1\n");
	printf("                 11__________________________11__1\n");
	printf("                 11__________________________111_1\n");
	printf("                  11__1111111111111111111111111111\n");
	printf("                   111111111111\n");
	printf("                     111111\n\n\n");
	
	string how;
	ifstream MyReadFile("h.txt");
	cout<<"How to play: \n";
	while (getline (MyReadFile, how)) {
	cout << how;
	}
		MyReadFile.close();
		char Ans='n';
	printf("\n\nWant to start playing now ? y|n : ");
	do{
		Ans = getchar();
	} while (Ans!='y' &&Ans!='n');
	if(Ans=='y'){
		return 1;
	}
    return 0;
}
void Playgame(void){
	typedef struct{
		int Pycards[3];
		int psum;
	}Player;
	Player Py={{0},0};
	typedef struct{
		int Dlcards[3];
		int bsum;
	}Dealer;
	Dealer Dl={{0},0};
	int i;
	int cards[52];
	int Pok=0;
	char j ='n';
	Shuffcard(cards);
	Py.Pycards[0]=cards[0];
	Py.Pycards[1]=cards[1];
	Py.Pycards[2]=cards[2];
	Dl.Dlcards[0]=cards[3];
	Dl.Dlcards[1]=cards[4];
	Dl.Dlcards[2]=cards[5];
	printf("Cards of Dealer : \n");
		printf(" _______\n");
		printf("|       |\n");
		printf("|       |\n");
		printf("|   ?   |\n");
		printf("|       |\n");
		printf("|       |\n");
		printf("|_______|\n");
		printf(" _______\n");
		printf("|       |\n");
		printf("|       |\n");
		printf("|   ?   |\n");
		printf("|       |\n");
		printf("|       |\n");
		printf("|_______|\n");		
	printf("\nCards of player :\n");
	Piccard(Py.Pycards[0]);
	Piccard(Py.Pycards[1]);
	i=0;
	for (i=0;i<2;i++){
		if(Py.Pycards[i]%100==11||Py.Pycards[i]%100==12||Py.Pycards[i]%100==13){
		 Py.psum=Py.psum+0;
		 }
		else {
			Py.psum=Py.psum+(Py.Pycards[i]%100);
		}
	}
	if(Py.psum>9)
	    Py.psum=Py.psum%10;
	for (i=0;i<2;i++){
		if(Dl.Dlcards[i]%100==11||Dl.Dlcards[i]%100==12||Dl.Dlcards[i]%100==13){
		 Dl.bsum=Dl.bsum+0;
		 }
		else {
			Dl.bsum=Dl.bsum+(Dl.Dlcards[i]%100);
		}
	}
	if(Dl.bsum>9)
		Dl.bsum=Dl.bsum%10;
	printf("Your score is : %d\n",Py.psum);	
	if (Dl.bsum>7||Py.psum>7){
		clear();
		printf("Your card is \n");
		Piccard(Py.Pycards[0]);
	    Piccard(Py.Pycards[1]);
		printf("Dealer card is \n");
		Piccard(Dl.Dlcards[0]);
	    Piccard(Dl.Dlcards[1]);
		printf("Your score is : %d\n",Py.psum);
		printf("Dealer score is : %d\n",Dl.bsum);
		i=0;
		for (i=8;i<=9;i++){
			if (Dl.bsum==i){
				printf("Dealer Poker %d\n",i);
				if(Dl.bsum>Py.psum){
					printf("!!!!Dealer Win!!!!\n");
					Pok=1;
				}
			}
			if (Py.psum==i){
				printf("Player Poker %d\n",i);
				if(Py.psum>Dl.bsum){
					printf("!!!!Player Win!!!!\n");
					Pok=1;
					}
			}
			if (Py.psum==Dl.bsum){
				printf("!!!!Draw!!!!\n");
				Pok=1;
			}
		}
	}
	if(Pok==0){
		printf("Want more cards? Input y or n:");
		do{
			j = getchar();
		} while (j!='y' &&j!='n');
		if(j=='y'){
			clear();
			printf("\nyour card 3 is  \n");
			Piccard(Py.Pycards[2]);
			if(Py.Pycards[2]%100==11||Py.Pycards[2]%100==12||Py.Pycards[2]%100==13){
				Py.psum=Py.psum+0;
				}
			else {
				Py.psum=Py.psum+(Py.Pycards[2]%100);
			}
			if(Py.psum>9)
				Py.psum=Py.psum%10;
			if(Dl.Dlcards[2]%100==11||Dl.Dlcards[2]%100==12||Dl.Dlcards[2]%100==13){
				Dl.bsum=Dl.bsum+0;
			}
			else {
				Dl.bsum=Dl.bsum+(Dl.Dlcards[2]%100);
			}
			if(Dl.bsum>9)
				Dl.bsum=Dl.bsum%10;
			printf("Your card is \n");
			Piccard(Py.Pycards[0]);
	    	Piccard(Py.Pycards[1]);
			Piccard(Py.Pycards[2]);
			printf("Dealer card is \n");
			Piccard(Dl.Dlcards[0]);
	    	Piccard(Dl.Dlcards[1]);
			Piccard(Dl.Dlcards[2]);
			printf("Your score is : %d\n",Py.psum);
			printf("Dealer score is : %d\n",Dl.bsum);
			if(Dl.bsum>Py.psum)
				{
				printf("!!!!Dealer Win!!!!\n");
				}
			else if(Dl.bsum<Py.psum){
				printf("!!!!Player Win!!!!\n");
				}
			else if (Py.psum==Dl.bsum){
				printf("!!!!Draw!!!!\n");
				}
			}
		else{
			clear();
			printf("Stand\n");
			printf("Your card is \n");
			Piccard(Py.Pycards[0]);
	    	Piccard(Py.Pycards[1]);
			printf("Dealer card is \n");
			Piccard(Dl.Dlcards[0]);
	    	Piccard(Dl.Dlcards[1]);
			printf("Your score is : %d\n",Py.psum);
			printf("Dealer score is : %d\n",Dl.bsum);			
			if(Dl.bsum>Py.psum){
				printf("!!!!Dealer Win!!!!\n");
			}
			else if(Dl.bsum<Py.psum){
				printf("!!!!Player Win!!!!\n");
				}
			else if (Py.psum==Dl.bsum){
				printf("!!!!Draw!!!!\n");
			}
		}		
	}
}
void Shuffcard(int cards[])
{
	int t;
	int i;
	int desk[52];	
	for (i=0;i<52;i++)
		desk[i] = (i/13+3)*100 + i%13 + 1;
	srand(time(NULL));
	for (i = 0; i < 52; i++)
	{
		do
		{
			t = rand()%52;
		}while (desk[t] == 0);
		cards[i] = desk[t];
		desk[t] = 0;
	}
}
void Piccard(int num)
{
	char fl;
	int Pnum;
	fl = num / 100;
	Pnum = num % 100;
	switch (Pnum)
	{
		case 1:
		{
			printf(" _______\n");
			printf("|A      |\n");
			printf("|       |\n");
			printf("|   %c   |\n",fl);
			printf("|       |\n");
			printf("|      A|\n");
			printf("|_______|\n");
			break;
		} 	
		case 2:		
		case 3:
		case 4:		
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
	{
			printf(" _______\n");
			printf("|%d      |\n",Pnum);
			printf("|       |\n");
			printf("|   %c   |\n",fl);
			printf("|       |\n");
			printf("|     %2d|\n",Pnum);
			printf("|_______|\n");
			break;
	  	}
		case 10:
		{
			printf(" _______\n");
			printf("|%d     |\n",Pnum);
			printf("|       |\n");
			printf("|   %c   |\n",fl);
			printf("|       |\n");
			printf("|     %d|\n",Pnum);
			printf("|_______|\n");
			break;
		}
		case 11:
		{
			printf(" _______\n");
			printf("|J      |\n");
			printf("|       |\n");
			printf("|   %c   |\n",fl);
			printf("|       |\n");
			printf("|      J|\n");
			printf("|_______|\n");
			break;
		}
		case 12:
		{
			printf(" _______\n");
			printf("|Q      |\n");
			printf("|       |\n");
			printf("|   %c   |\n",fl);
			printf("|       |\n");
			printf("|      Q|\n");
			printf("|_______|\n");
			break;
		}
		case 13:
		{
			printf(" _______\n");
			printf("|K      |\n");
			printf("|       |\n");
			printf("|   %c   |\n",fl);
			printf("|       |\n");
			printf("|      K|\n");
			printf("|_______|\n");
			break;
		}
	}
}

void Playgame_2::Dw_()
    {
    	char fl[]={06,04};
        clear();
        for (int i = 0; i < high; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i == 0 && (j == 0 || j == width - 1)) cout << "S";
                if (i == high - 1 && (j == 0 || j == width - 1)) cout << "F";
                if (map[i]->CheckPos(j) && i != 0 && i != high - 1)
                    cout << fl[1];
                else if (py_2->x == j && py_2->y == i)
                    cout << fl[0];
                else
                    cout << "_";
            }
            cout << endl;
        }
        cout << "Score : " << score << endl;
    }
void Playgame_2::keyboard()
    {
        if (kbhit())
        {
            char current = getch();
            if (current == 'a')
                py_2->x--;
            if (current == 'd')
                py_2->x++;
            if (current == 'w')
                py_2->y--;
            if (current == 's')
                py_2->y++;
        }
    }
void Playgame_2::wot()
    {
        for (int i = 1; i < high - 1; i++)
        {
            if (rand() % 5 == 1)
                map[i]->Move();
            if (map[i]->CheckPos(py_2->x) && py_2->y == i)
                quit = true;
        }
        if (py_2->y == high%high)
        {
            score++;
            py_2->y = high - 1 ;
        }
    }
void Playgame_2::Run()
    {
        while (!quit)
        {
            keyboard();
            Dw_();
            wot();
        }
    }
class question {
   public:
    void want() {
        cout << "Want to start playing now ? y|n :" << endl;
    }
};
class round : public question {
	public:
    void another() {
        cout << "Want to play another round y|n :" << endl;
    }
};

int main()
{
	round round1;
	clear();
   	char Ans,y,n,Y,N;
	re:
	cout<<" _______________________"<<endl;
	cout<<"|                       |"<<endl;
	cout<<"|                       |"<<endl;
	cout<<"|Welcome to Arcade game.|"<<endl;
	cout<<"|                       |"<<endl;
	cout<<"|_______________________|"<<endl;
	cout<<" "<<endl;
   	round1.want(); 
    cin>>Ans;
    if(Ans == ('y')||Ans == ('Y')){
		int Ans=0;
	    clear();
	    rech:
	    cout<<" "<<endl;
	    cout<<" "<<endl;
	    cout<<"Choose game         "<<endl;
	    cout<<"  "<<endl;
	    cout<<" __________________________________________"<<endl;
	    cout<<"|                                          |"<<endl;
	    cout<<"|1.Poker                                   |"<<endl;	
	    cout<<"|2.The journey of spade                    |"<<endl;
	    cout<<"|3.Exit                                    |"<<endl;
	    cout<<"|4.Check score The journey of spade        |"<<endl;
	    cout<<"|__________________________________________|"<<endl;
	    cout<<"Please choose 1|2|3|4:";
	    int choice;
	    cin >> choice;

	    if(choice == 1){
	    	clear();
	        cout<<"This game is Pokergame."<<endl;
		    Ans=Start();
		    if(Ans==1){
			clear();
			Playgame();
			char i='n';
			round1.another();
			do{		
					i = getchar();
				} while (i!='y' &&i!='n');
				if(i=='y'){
					main();
		 		}
		    }
		}
	        
		if(choice == 2){
			clear();
	        cout<<"This game is The journey of spade game."<<endl;
	    	Ans=Cstart();
	    	if(Ans==1){
			clear();
			Playgame_2 game(30, 8);
			game.Run();
	        char i='n';
	        round1.another();
			do{		
					i = getchar();
				} while (i!='y' &&i!='n');
				if(i=='y'){
					main();
		 		}
		    }
	    }
	    if(choice == 3){
	    	clear();
	    	printf("!!!! LET'S PLAY AGAIN NEXT TIME !!!!");
			return 0;
		}
		if(choice == 4){
	    	clear();
			cout << "\tScore Record" << endl;
   			cout << discount(12492) << endl;
    		cout << discount(12492, 1425) << endl;
    		cout << discount(12492, 1425, 14257) << endl;
    		return 0;
		}
		else{
			clear();
			cout<<"Please input only 1|2|3|4.!!!"<<endl;
			goto rech;
		}   
	}
    if(Ans == ('n')||Ans == ('N')){
    	cout<<"Bye bye see you next time.!!!"<<endl;
	}
	else{
    	clear();
		cout<<"Please input y|n.!!!"<<endl;
		goto re;
	}
}
