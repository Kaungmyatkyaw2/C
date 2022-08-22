#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef struct student{
    
    
    char name[30];
    int roll = 0;
    
    struct subject{
        int mark[3];
    }sub;
    
    int total = 0;
    float percent = 0;
    
    
}stu;



void create();
void how();
void append();
int displayRec();
void search();
void update();
void deletes();



int main(){


    
    int definder = 0;

    while (10 == 10){



        puts("\n\n1.CREATE RECORD");
        puts("2.APPEND");
        puts("3.HOW MANY RECORD");
        puts("4.DISPLAY STUDENT RECORD");
        puts("5.SEARCH STUDENT RECORD");
        puts("6.UPDATE STUDENT RECORD");
        puts("7.DELETE STUDENT RECORD");
        puts("0.EXIT\n\n");

        printf(">>>> ");



        scanf("%d",&definder);


        switch (definder) {

            case 0:
                exit(0);
                break;


            case 1:
                create();
                break;



            case 2:
                append();
                break;


            case 3:
                how();
                break;


            case 4:
                displayRec();
                break;


            case 5:
                search();
                break;


            case 6:
                update();
                break;


                case 7:
                    deletes();
                    break;



        }


    }
    
    
    
    return 0;
}




void create(){


    int numOfStu = 0;





    stu *createStu;
    FILE *stuFile;

    stuFile = fopen("allStu.txt","w");

    printf("How many student do you want to record >>>> ");
    scanf("%d",&numOfStu);

    createStu = (stu*)calloc(numOfStu,sizeof(stu));

    for (int i = 0; i < numOfStu; i++) {


        createStu[i].total = 0;
        createStu[i].percent = 0;


        char subName[30] = "Myanmar";

        for (int k = 0; k < i+1; k++) {
            createStu[i].roll = k;
        }

        fflush(stdin);


        printf("\n\nEnter Student Name : ");
        scanf("%s",createStu[i].name);


        for (int j = 0; j < 3; j++) {



            switch (j) {

                case 0:
                    strcpy(subName,"Myanmar");
                    break;

                case 1:
                    strcpy(subName,"English");
                    break;


                case 2:
                    strcpy(subName,"Math");
                    break;

            }


            repeat :

            printf("Enter %s mark >>>>>> ",subName);




            scanf("%d",&createStu[i].sub.mark[j]);

            if(createStu[i].sub.mark[j] > 100){
                printf("\n Mark Must Be 100 or Less than\n");
                goto repeat;
            }


            createStu[i].total += createStu[i].sub.mark[j];





        }


        createStu[i].percent = createStu[i].total / (float)3;




        fwrite(&createStu[i],sizeof(student),1,stuFile);





    }


    free(createStu);

    fclose(stuFile);







}











void append(){




    stu *createStu;

    FILE *stuFile;

    stuFile = fopen("allStu.txt","a");



    createStu = (stu*)malloc(1*sizeof(stu));




        createStu[0].total = 0;
        createStu[0].percent = 0;


        char subName[30] = "Myanmar";

        int lastRoll = displayRec() + 1;

        createStu[0].roll = lastRoll;

        fflush(stdin);


        printf("\n\nEnter Student Name >>> ");
        scanf("%s",createStu[0].name);


        for (int j = 0; j < 3; j++) {



            switch (j) {

                case 0:
                    strcpy(subName,"Myanmar");
                    break;

                case 1:
                    strcpy(subName,"English");
                    break;


                case 2:
                    strcpy(subName,"Math");
                    break;

            }


            repeat:
            printf("Enter %s mark >>>> ",subName);
            scanf("%d",&createStu[0].sub.mark[j]);

            if(createStu[0].sub.mark[j] > 100){
                printf("\n Mark Must Be 100 or Less than\n");
                goto repeat;
            }



            createStu[0].total += createStu[0].sub.mark[j];





        }


        createStu[0].percent = createStu[0].total / (float)3;




        fwrite(&createStu[0],sizeof(student),1,stuFile);


    free(createStu);





    fclose(stuFile);



}





void how(){


    stu test;

    FILE *how;

    how = fopen("allStu.txt","r");


    fseek(how,0,SEEK_END);

   int number = ftell(how) / sizeof(test);

    printf("\n\n\nNumber of Record >>> %d\n\n\n",number);

    fclose(how);



};










int displayRec(){


    stu tempStu;


    FILE *display;

    display = fopen("allStu.txt","r");
    printf("\n\n\n*********************************************************************");
    printf("*********************************************************************\n\n\n");

    printf("%17s%17s%17s%17s%17s%17s%17s\n\n\n","ROLL-NUM","NAME","Myan Mark","Eng Mark","Math Mark","TOTAL","PERCENT");





    while(fread(&tempStu,1,sizeof (tempStu),display)){



        printf("%17d%17s",tempStu.roll,tempStu.name);

        for (int i = 0; i < 3; i++) {

            printf("%17d",tempStu.sub.mark[i]);

        }

        printf("%17d%17.2f\n",tempStu.total,tempStu.percent);




    }


    printf("\n\n\n*********************************************************************");
    printf("*********************************************************************\n\n\n");




    fclose(display);



    return tempStu.roll;




}






void search(){

    stu tempStu;
    int definder = 0;
    int is = 1;


    FILE *display;

    display = fopen("allStu.txt","r");



    printf("\n\nEnter Roll Number >>>> ");
    scanf("%d",&definder);



    while(fread(&tempStu,1,sizeof (tempStu),display)){



        if(definder == tempStu.roll) {

            is = 0;

            printf("%17s%17s%17s%17s%17s%17s%17s\n","ROLL-NUM","NAME","Myan Mark","Eng Mark","Math Mark","TOTAL","PERCENT");


            printf("%17d%17s", tempStu.roll, tempStu.name);

            for (int i = 0; i < 3; i++) {

                printf("%17d", tempStu.sub.mark[i]);

            }

            printf("%17d%17.2f\n", tempStu.total, tempStu.percent);

        }



    }



    if(is != 0){

            printf("\n\nCan't find\n\n");



    }

    fclose(display);


}



void update(){



    stu tempStu;
    int definder = 0;


    FILE *display,*temp;

    int roll = 9;
    int fond = 0;
    int i = 0;




    printf("Enter Roll Number >>>> ");
    scanf("%d",&definder);

    display = fopen("allStu.txt","r");
    temp = fopen("temp.txt","w");





    while(fread(&tempStu,sizeof (student),1,display)){



        if(definder == tempStu.roll) {

            tempStu.total = 0;
            tempStu.percent = 0;

            fond = 1;


            fflush(stdin);

            printf("\n\nEnter Student Name >>>> ");
            scanf("%s",tempStu.name);



            for (i = 0; i < 3; i++) {

                repeat:
                printf("Enter Marks of subject%d : ",i+1);
                scanf("%d", &tempStu.sub.mark[i]);


                if (tempStu.sub.mark[i] > 100){
                    printf("\n\nMark Must Be 100 or Less Than\n\n");
                    goto repeat;
                }



                tempStu.total += tempStu.sub.mark[i];

            }

                tempStu.percent = tempStu.total / (float)3; //typecasting

        }

        fwrite(&tempStu,sizeof(stu),1,temp);



    }





    fclose(display);
    fclose(temp);


    if(fond == 1){

        display = fopen("allStu.txt","w");
        temp = fopen("temp.txt","r");


        while (fread(&tempStu,sizeof(stu),1,temp)){
            fwrite(&tempStu,sizeof (student),1,display);
        }


        fclose(display);
        fclose(temp);



    }else if(fond == 0){


        printf("\nStudent can't found\n");


    }





}







void deletes(){



    stu tempStu;
    int definder = 0;


    FILE *display,*temp;

    int roll = 9;
    int fond = 0;
    int i = 0;




    printf("Enter Roll Number >>>> ");
    scanf("%d",&definder);

    display = fopen("allStu.txt","r");
    temp = fopen("temp.txt","w");





    while(fread(&tempStu,sizeof (student),1,display)){



        if(definder == tempStu.roll) {
                        fond = 1;
        }else{
            fwrite(&tempStu,sizeof(stu),1,temp);

        }




    }





    fclose(display);
    fclose(temp);


    if(fond == 1){

        display = fopen("allStu.txt","w");
        temp = fopen("temp.txt","r");


        while (fread(&tempStu,sizeof(stu),1,temp)){
            fwrite(&tempStu,sizeof (student),1,display);
        }


        fclose(display);
        fclose(temp);



    }else if(fond == 0){


        printf("\nStudent can't found\n");


    }





}
