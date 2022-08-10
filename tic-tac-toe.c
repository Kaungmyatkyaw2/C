#include "stdio.h"
#include "conio.h"
#include "ctype.h"
#include "stdlib.h"
#include "time.h"

char arr[10] = {'0','1','2','3','4','5','6','7','8','9'};



void board();
int markingBoard(int num,char marker);
int winnerChecker();


int main(){


    char mOrc;
    char definder;
    int yourNum = 0;
    int player = 1;
    char markSign;
    int returnOfwinner = 0;




    int cModePlayer = 1;
    char markSign2;
    int yourNum2 = 0;
    int returnOfwinner2 = 0;
    int markerNum2 = 0;
    int markerNum0 = 0;



    modeChoice :


    printf("[M/C]\nM : Multiplayer Mode\nC : Computer Mode\nPress Mode : ");
    scanf("%c",&mOrc);

    definder = toupper(mOrc);


    system("CLS");




    if(definder == 'M'){

        board();

        do {


            player = (player % 2) ? 1 : 2;

            markSign = (player==1) ? '#' : '*';

            MmodeStart :

            printf("Player%d Enter Number : ",player);
            scanf("%d",&yourNum);

            int markerNum = markingBoard(yourNum,markSign);


            if(markerNum == 0){
                printf("Enter Number Valid Move\n");
                goto MmodeStart;
            }


            returnOfwinner = winnerChecker();
            player++;

            system("CLS");

            board();

        }while(returnOfwinner == -1);

        player--;


        if(returnOfwinner == 0){

            printf("**------Player%d WIN------*!",player);

        }else{
            printf("**------Draw------**");
        }








    }else if(definder == 'C'){

        board();


        do {
            cModePlayer = (cModePlayer % 2) ? 1 : 2;
            markSign2 = (cModePlayer == 1) ? '#' : '*';

            if(cModePlayer == 1){

                me :
                printf("Enter Your Number : ");
                scanf("%d",&yourNum2);


                markerNum0 = markingBoard(yourNum2,markSign2);

                if(markerNum0 == 0){
                    printf("Invalid Move\n");
                    goto me;
                }

            }else if(cModePlayer == 2){


                int randomNum = 0;

                computer :

                srand(time(NULL));

                randomNum = (rand() % 9) + 1 ;



                markerNum2 = markingBoard(randomNum,markSign2);

                if(markerNum2 == 0){
                    goto computer;
                }


            }



            returnOfwinner2 = winnerChecker();

            cModePlayer++;

            system("CLS");

            board();


        } while (returnOfwinner2 == -1);

        if(cModePlayer == 2){
            cModePlayer--;
        }


        if(returnOfwinner2==0){



            if(cModePlayer == 1){

                printf("**------You have won the game------**\n");

            }else{
                printf("**------Computer won the game------**\n");
            }



        }else{
            printf("**------Draw------**");

        }









    }else{


        system("ClS");

        printf("\aInvalid Mode!\n");


        goto modeChoice;



    }






    return 0;

}


void board(){


    printf("\t\t*******Welcome To Tic Tac Toe Game********\t\t\t\n\n\n");

    printf("\t.........Player1 is # sign And Player2 is * sign..........\t\t\t\n\n\n");


    printf("     |     |     \n");
    printf(" %c   |  %c  | %c   \n",arr[1],arr[2],arr[3]);
    printf("_____|_____|_____\n");
    printf("     |     |      \n");
    printf(" %c   |  %c  | %c   \n",arr[4],arr[5],arr[6]);
    printf("_____|_____|_____\n");
    printf("     |     |      \n");
    printf(" %c   |  %c  | %c   \n",arr[7],arr[8],arr[9]);
    printf("_____|_____|_____\n");
    printf("     |     |      \n");




}


int markingBoard(int num,char marker){


    char numTochar = num + '0';

    if(num==1 && arr[1]=='1'){
        arr[1] = marker;
    }else if(num == 2 && arr[2]=='2'){
        arr[2]=marker;
    }else if(num == 3 && arr[3]=='3'){
        arr[3]=marker;
    }else if(num == 4 && arr[4]=='4'){
        arr[4]=marker;
    }else if(num == 5 && arr[5]=='5'){
        arr[5]=marker;
    }else if(num == 6 && arr[6]=='6'){
        arr[6]=marker;
    }else if(num == 7 && arr[7]=='7'){
        arr[7]=marker;
    }else if(num == 8 && arr[8]=='8'){
        arr[8]=marker;
    }else if(num == 9 && arr[9]=='9'){
        arr[9]=marker;
    }else if(num > 9){


        return 0;
    }else{


        return 0;
    }


//    switch (num) {
//
//        case 1:
//            if(arr[num] == numTochar){
//
//                arr[num] = marker;
//
//            }else{
//                printf("Please Enter Valid Move\n");
//            }
//            return 0;
//            break;
//
//
//        case 2:
//            if(arr[num] == numTochar){
//
//                arr[num] = marker;
//
//            }
//            return 0;
//            break;
//
//
//
//        case 3:
//            if(arr[num] == numTochar){
//
//                arr[num] = marker;
//
//            }
//            return 0;
//            break;
//
//
//        case 4:
//            if(arr[num] == numTochar){
//
//                arr[num] = marker;
//
//            }
//            return 0;
//            break;
//
//
//
//        case 5:
//            if(arr[num] == numTochar){
//
//                arr[num] = marker;
//
//            }
//            return 0;
//            break;
//
//
//
//        case 6:
//            if(arr[num] == numTochar){
//
//                arr[num] = marker;
//
//            }
//            return 0;
//            break;
//
//
//
//        case 7:
//            if(arr[num] == numTochar){
//
//                arr[num] = marker;
//
//            }
//            return 0;
//            break;
//
//
//        case 8:
//            if(arr[num] == numTochar){
//
//                arr[num] = marker;
//
//            }
//            return 0;
//            break;
//
//
//
//        case 9:
//            if(arr[num] == numTochar){
//
//                arr[num] = marker;
//
//            }
//            return 0;
//            break;
//
//
//
//
//
//        default:
//            printf("Please Enter Valid Move!\n");
//            if(num > 9){
//                printf("Invalid Move");
//            }else{
//                printf("Please move");
//            }
//            return 1;
//            break;
//
//
//    }
//
//
//    if(num > 9){
//        printf("Please Enter Valid Move\n");
//        return 1;
//    }


}


int winnerChecker(){


    if(arr[1] == arr[2] && arr[1] == arr[3]){
        return 0;
    }else if(arr[5] == arr[4] && arr[5] == arr[6]){
        return 0;
    }else if(arr[7] == arr[8] && arr[7] == arr[9]){
        return 0;
    }

    else if(arr[1] == arr[4] && arr[1] == arr[7]){
        return 0;
    }else if(arr[2] == arr[5] && arr[2] == arr[8]){
        return 0;
    }else if(arr[3] == arr[6] && arr[3] == arr[9]){
        return 0;
    }

    else if(arr[1] == arr[5] && arr[1] == arr[9]){
        return 0;
    }else if(arr[3] == arr[5] && arr[3] == arr[7]){
        return 0;
    }

    else if(arr[1]!= '1' && arr[2]!= '2' && arr[3]!= '3' && arr[4]!= '4'&& arr[5]!= '5' && arr[6]!= '6'&& arr[7]!= '7' && arr[8]!= '8' && arr[9]!='9') {
        return 1;
    }


    else{
        return -1;
    }


}
