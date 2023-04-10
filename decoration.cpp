#include "Decoration.h"
#include <windows.h>
#include <iostream>
using namespace std;

void Decoration::beep_start() {
	Beep(659.26, 200);
	Beep(659.26, 200);
	Sleep(200);
	Beep(659.26, 200);
	Sleep(100);
	Beep(523.26, 200);
	Beep(659.26, 200);
	Sleep(200);
	Beep(783.98, 200);
	Sleep(400);
	Beep(391.99, 200);
}

void Decoration::beep_end() {
	int a = 750;

	Beep(392, a);
	Beep(392, a);
	Beep(392, a);
	Beep(311, a * 0.75);
	Beep(466, a * 0.25);

	Beep(392, a);
	Beep(311, a * 0.75);
	Beep(466, a * 0.25);
	Beep(392, a * 2);

	Beep(587, a);
	Beep(587, a);
	Beep(587, a);
	Beep(622, a * 0.75);
	Beep(466, a * 0.25);

	Beep(369, a);
	Beep(311, a * 0.75);
	Beep(466, a * 0.25);
	Beep(392, a * 1.5);
}

void Decoration::start() {
    pic_start();
    beep_start();
    Sleep(4000);
    system("cls");
}


void Decoration::pic_start() {
    system("color 04");
    cout << " \t\t\t\t\t\t\t\t         WELCOME TO SURVIVAL GAME ";
    HANDLE soh = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(soh, (((0 << 4) | 5)));
   cout << R"(
                                                       	        .m.                                   ,_
                                                                ' ;M;                                ,;m `
                                                                  ;M;.           ,      ,           ;SMM;
                                                                 ;;Mm;         ,;  ____  ;,         ;SMM;
                                                                ;;;MM;        ; (.MMMMMM.) ;       ,SSMM;;
                                                              ,;;;mMp'        l  ';mmmm;/  j       SSSMM;;
                                                            .;;;;;MM;         .\,.mmSSSm,,/,      ,SSSMM;;;
                                                           ;;;;;;mMM;        .;MMmSSSSSSSmMm;     ;MSSMM;;;;
                                                          ;;;;;;mMSM;     ,_ ;MMmS;;;;;;mmmM;  -,;MMMMMMm;;;;
                                                         ;;;;;;;MMSMM;     \"*;M;( ( '') );m;*"/ ;MMMMMM;;;;;,
                                                        .;;;;;;mMMSMM;      \(@;! _     _ !;@)/ ;MMMMMMMM;;;;;,
                                                        ;;;;;;;MMSSSM;       ;,;.*o*> <*o*.;m; ;MMMMMMMMM;;;;;;,
                                                       .;;;;;;;MMSSSMM;     ;Mm;           ;M;,MMMMMMMMMMm;;;;;;.
                                                       ;;;;;;;mmMSSSMMMM,   ;Mm;,   '-    ,;M;MMMMMMMSMMMMm;;;;;;;
                                                       ;;;;;;;MMMSSSMMMMMMMm;Mm;;,  ___  ,;SmM;MMMMMMSSMMMM;;;;;;;;
                                                       ;;'";;;MMMSSSSMMMMMM;MMmS;;,  "  ,;SmMM;MMMMMMSSMMMM;;;;;;;;.
                                                       !   ;;;MMMSSSSSMMMMM;MMMmSS;;._.;;SSmMM;MMMMMMSSMMMM;;;;;;;;;
                                                           ;;;;*MSSSSSSMMMP;Mm*"'q;'   `;p*"*M;MMMMMSSSSMMM;;;;;;;;;
                                                           ';;;  ;SS*SSM*M;M;'     `-.        ;;MMMMSSSSSMM;;;;;;;;;,
                                                            ;;;. ;P  `q; qMM.                 ';MMMMSSSSSMp' ';;;;;;;
                                                            ;;;; ',    ; .mm!     \.   `.   /  ;MMM' `qSS'    ';;;;;;
                                                            ';;;       ' mmS';     ;     ,  `. ;'M'   `S       ';;;;;
                                                             `;;.        mS;;`;    ;     ;    ;M,!     '        ';;;;
                                                              ';;       .mS;;, ;   '. o  ;   oMM;                ;;;;
                                                               ';;      MMmS;; `,   ;._.' -_.'MM;                 ;;;
                                                                `;;     MMmS;;; ;   ;      ;  MM;                 ;;;
                                                                  `'.   'MMmS;; `;) ',    .' ,M;'                 ;;;
                                                                     \    '' ''; ;   ;    ;  ;'                   ;;
                                                                      ;        ; `,  ;    ;  ;                   ;;
                                                                               |. ;  ; (. ;  ;      _.-.         ;;
                                                                  .-----..__  /   ;  ;   ;' ;\  _.-" .- `.      ;;
                                                                ;' ___      `*;   `; ';  ;  ; ;'  .-'    :      ;
                                                                ;     """*-.   `.  ;  ;  ;  ; ' ,'      /       |
                                                                ',          `-_    (.--',`--'..'      .'        ',
                                                                  `-_          `*-._'.\\\;||\\)     ,'
                                                                     `"*-._        "*`-ll_ll'l    ,'
                                                                        ,==;*-._           "-.  .'
                                                                     _-'    "*-=`*;-._        ;'
                                                                   ."            ;'  ;"*-.    `
                                                                   ;   ____      ;//'     "-   `,
                                                                   `+   .-/                 ".\\;
                                                                     `*" /                    "'
      

	
		
)";
}

void Decoration::pic_end() {
    cout << R"(
        
                                                                     ,     \    /      ,        
                                                                    / \    )\__/(     / \       
                                                                   /   \  (_\  /_)   /   \      
                                                              ____/_____\__\@  @/___/_____\____ 
                                                             |             |\../|              |
                                                             |              \VV/               |
                                                             |            GAME OVER            |
                                                             |_________________________________|
                                                              |    /\ /      \\       \ /\    | 
                                                              |  /   V        ))       V   \  | 
                                                              |/     `       //        '     \| 
                                                              `              V                '
 )";

}

void Decoration::pic_game(int points) {
    int sz = 100 - points;
    if (sz > 0)
        sz /= 2;
    char pistol[] = "| |||||||||   `------- - '    |          O ";
    char bullet[] = "->";




    cout << R"(
+--^----------,--------,-----,--------^-,)" << endl;

    cout << pistol;
    for (int k = 0; k < sz; k++)
        cout << bullet;







    cout << R"( 
 `+---------------------------^----------|
   `\_,---------,---------,--------------'
     / XXXXXX /'|       /'
    / XXXXXX /  `\    /'
   / XXXXXX /`-------'
  / XXXXXX /
 / XXXXXX /
(________(                
 `------'     
)";
}
        
        
       
