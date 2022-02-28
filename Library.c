#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int action, task, subtask, passcode, count, systempasscode, systembackup, systemrestore, addcount, removecount, Book_ID, Book_Location, line_number;
    FILE *sys, *sys1, *fp, *fp1, *fpf, *fpf1;
    char type[11], Buffer[500], Book_Name[25], edit, a, b, c, w;
    
    start:
    printf("W E L C O M E  T O  T H E  A N T I G U A  G R A M M A R  S C H O O L  L I B R A R Y  P R O G R A M  2 0 2 2\n");
    printf("What do you wish to do: 1-View || 2-Add Book(s) || 3-Remove Book(s) || 4-Manual Edit || 5-Utility = ");
    scanf("%d", &task);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    
    //setting default passcode 1234
    sys = fopen ("System-Passcode.bin", "rb");
    if(sys==NULL){
    sys = fopen ("System-Passcode.bin", "ab");
    systempasscode= 1234;
    fprintf(sys, "%d", systempasscode);}
    fscanf(sys, "%d", &systempasscode);
    fclose(sys);
    
    //setting default backup interval
    sys1 = fopen ("System-Backup.bin", "rb");
    if(sys1==NULL){
    sys1 = fopen ("System-Backup.bin", "ab");
    systembackup= 10;
    count= 0;
    fprintf(sys1, "%d %d", systembackup, count);
    fclose(sys1);}
    else{
    sys1 = fopen ("System-Backup.bin", "rb");    
    fscanf(sys1, "%d %d", &systembackup, &count);
    fclose(sys1);}
        
        //task 1 where listing of books occurs
        if(task==1){
        printf("\nWhat Books are you looking for? Fiction or Non-Fiction (type exactly as shown). - ");
        scanf("%s", &type[w]);
        line_number = 0;
        
        if(type[w]=='F' || type[w]=='f'){
            
        fp = fopen ("Fiction.txt", "r");
        if(fp==NULL){
        printf("\nSorry for the inconvenience but the Fiction book list is not available for searching at the moment!");
        fclose(fp);}
            
        else{
            
        while ( !feof(fp)){
    	if (fgets(Buffer,500,fp) != NULL){
        if (line_number==0){
        printf("\n%s", Buffer);}
        else{
        printf("%d %s", line_number, Buffer);}
        ++line_number;}}
        fclose(fp);}}
        
        else{                                               
               
        fp = fopen ("Non-Fiction.txt", "r");
        if(fp==NULL){
        printf("\nSorry for the inconvenience but the Non-Fiction book list is not available for searching at the moment!");
        fclose(fp);}
            
        else{
          
        while ( !feof(fp)){
    	if (fgets(Buffer,500,fp) != NULL){
	    if (line_number==0){
        printf("\n%s", Buffer);}
        else{
        printf("%d %s", line_number, Buffer);}
        ++line_number;}}
        fclose(fp);}}}
            
            //task 2 where you can add a book to the management system
            else if (task==2){
            printf("\nEnter passcode ");
            scanf("%d", &passcode);
            if(passcode==systempasscode){
            printf("\nWhich Book List are you editing? Fiction or Non-Fiction (type exactly as shown). - ");
            scanf("%s", &type[w]);
            
            if(type[w]=='F' || type[w]=='f'){

            //Fiction Books addition  
            printf("How much Fiction book(s) do you want to add? ");
            scanf("%d", &addcount);

            fp = fopen("Fiction.txt", "r");
            if(fp==NULL){
            fp = fopen("Fiction.txt", "a");
            fprintf(fp, "\t\t\t\tFiction Book List");
            fclose(fp);}

            for(addcount; addcount!=0; addcount--){

            fp = fopen("Fiction.txt", "a");
            printf("\nBook ID (%d): ", addcount);
            scanf("%d", &Book_ID);
            printf("Name of Book (%d): ", addcount);
            scanf(" %[^\n]s",Book_Name);
            printf("Book Location (%d): ", addcount);
            scanf("%d", &Book_Location);
            fprintf(fp, "\nID: %d, \t\t\tName: %s, \t\t\tLocation: %d", Book_ID, Book_Name, Book_Location);
            fclose(fp);}}   
                
            else{

            //Non-Fiction Books addition   
            printf("How much Non-Fiction book(s) do you want to add? ");
            scanf("%d", &addcount);

            fp = fopen("Non-Fiction.txt", "r");
            if(fp==NULL){
            fp = fopen("Non-Fiction.txt", "a");
            fprintf(fp, "\t\t\t\tNon-Fiction Book List");
            fclose(fp);}

            for(addcount; addcount!=0; addcount--){
            
            fp = fopen("Non-Fiction.txt", "a");
            printf("\nBook ID (%d): ", addcount);
            scanf("%d", &Book_ID);
            printf("Name of Book (%d): ", addcount);
            scanf(" %[^\n]s",Book_Name);
            printf("Book Location (%d): ", addcount);
            scanf("%d", &Book_Location);
            fprintf(fp, "\nID: %d, \t\t\tName: %s, \t\t\tLocation: %d", Book_ID, Book_Name, Book_Location);
            fclose(fp);}}} 
            
            else{
                
            printf("Access has been denied.");}
            }
                //task 3 where you can remove a book from the management system
                else if (task==3){
                printf("\nEnter passcode ");
                scanf("%d", &passcode);
                if(passcode==systempasscode){
                printf("\nWhich Book List are you editing? Fiction or Non-Fiction (type exactly as shown). - ");
                scanf("%s", &type[w]);
                line_number = 0;
                
                if(type[w]=='F' || type[w]=='f'){
                
                //Fiction Books removal
                fp = fopen ("Fiction.txt", "r");
                fclose(fp);
                if(fp==NULL){
                printf("Sorry for the inconvenience but the Fiction book list is not available for editing at the moment!");}
                else{   
                printf("What line do you want to remove from the Fiction Book List (count from search)? ");
                scanf("%d", &removecount);
                removecount = removecount + 1;
                fp = fopen("Fiction.txt","r");
                fp1 = fopen("Fiction 1.txt", "w");
                line_number = 1;
                edit = getc(fp);
                if(edit != EOF) {line_number = 1;}
                while(1){
                if(removecount != line_number)
                putc(edit, fp1);
                edit = getc(fp);
                if(edit == '\n') line_number++;
                if(edit == EOF) break;}
                fclose(fp);
                fclose(fp1);
                remove("Fiction.txt");
                rename("Fiction 1.txt", "Fiction.txt");
                printf("The Book Line has been sucessfully deleted");}}
                
                else{
                
                //Non-Fiction Books removal
                fp = fopen ("Non-Fiction.txt", "r"); 
                fclose(fp);
                if(fp==NULL){
                printf("Sorry for the inconvenience but the Non-Fiction book list is not available for editing at the moment!");}
                else{   
                printf("What line do you want to remove from the Non-Fiction Book List (count from search)? ");
                scanf("%d", &removecount);
                removecount = removecount + 1;
                fp = fopen("Non-Fiction.txt","r");
                fp1 = fopen("Non-Fiction 1.txt", "w");
                edit = getc(fp);
                if(edit != EOF) {line_number = 1;}
                while(1){
                if(removecount != line_number)
                putc(edit, fp1);
                edit = getc(fp);
                if(edit == '\n') line_number++;
                if(edit == EOF) break;}
                fclose(fp);
                fclose(fp1);
                remove("Non-Fiction.txt");
                rename("Non-Fiction 1.txt", "Non-Fiction.txt");
                printf("The Book Line has been sucessfully deleted");}}}
                    
                else{
                    
                printf("Access has been denied.");}}
            
                    //task 4 where books lists can be opened in your on desktop editor for manual editing/viewing
                    else if (task==4){
                    printf("\nEnter passcode ");
                    scanf("%d", &passcode);
                    if(passcode==systempasscode){
                    printf("\nWhich Book List do you wish to view? Fiction or Non-Fiction (type exactly as shown). - ");
                    scanf("%s", &type[w]);
                        
                    if(type[w]=='F' || type[w]=='f'){

                    //Fiction Books manual editing/viewing
                    printf("The Fiction Book list has been opened for manual editing.");   
                    fp = fopen("Fiction.txt", "a");  
                    fclose(fp); 

                    system ("Fiction.txt");}
                        
                    else{

                    //Non-Fiction Books manual editing/viewing
                    printf("The Non-Fiction Book list has been opened for manual editing.");
                    fp = fopen("Non-Fiction.txt", "a");  
                    fclose(fp);

                    system ("Non-Fiction.txt");}}
                        
                    else{
                        
                    printf("Access has been denied.");}}
                        
                        //task 5 where the changing of passcodes, backup intervals and Restoration of book lists occurs
                        else if (task==5){
                        //changing of passcode
                        printf("\nEnter passcode ");
                        scanf("%d", &passcode);
                        if(passcode==systempasscode){
                        printf("\nWhat do you wish to change/alter? \n1-Passcode \n2-Backup int \n3-Restoration \nPlease enter your response - ");
                        scanf("%d", &subtask);
                        
                        if(subtask==1){
                        printf("Enter new passcode - ");
                        scanf("%d", &passcode);
                        sys = fopen ("System-Passcode.bin", "wb+");
                        fprintf(sys, "%d", passcode);
                        fclose(sys);}

                        //changing of backup interval
                        else if(subtask==2){
                        printf("Enter new backup interval ");
                        scanf("%d", &systembackup);
                        count= systembackup - 1;
                        systembackup= 1;
                        sys1 = fopen ("System-Backup.bin", "wb");
                        fprintf(sys1, "%d %d", systembackup, count);
                        fclose(sys1);}

                        //books list restoration from backup
                        else if(subtask==3){
                        printf("\nWhich list do you want to restore \n1-Fiction \n2-Non-Fiction \nPlease enter your response - ");
                        scanf("%d", &systemrestore);
                        if(systemrestore == 1){                                 //Fiction Book list restoration from backup
                        fpf = fopen("Fiction Backup.txt","r");
                        fclose(fpf);
                        if (fpf == NULL){
                        printf("\nthere is no file available for restoration.");}  
                        else{
                        fp = fopen("Fiction.txt","r"); 
                        fpf = fopen("Fiction Backup.txt", "r");
                        fclose(fp);
                        fclose(fpf);
                        remove("Fiction.txt");
                        rename("Fiction Backup.txt", "Fiction.txt");
                        printf("\nThe Fiction Book list has be restored.");}}
                        else if(systemrestore == 2){                            //Non-Fiction Book list restoratio from backup
                        fpf1 = fopen("Non-Fiction Backup.txt","r");
                        fclose(fpf1);
                        if (fpf1 == NULL){  
                        printf("\nThere is no file available for restoration.");}
                        else{
                        fp1 = fopen("Non-Fiction.txt","r"); 
                        fpf1 = fopen("Non-Fiction Backup.txt", "r");
                        fclose(fp1);
                        fclose(fpf1);
                        remove("Non-Fiction.txt");
                        rename("Non-Fiction Backup.txt", "Non-Fiction.txt");
                        printf("\nThe Non-Fiction Book list has be restored.");}}
                        else if(systemrestore != 1||2){
                        printf("The following is not an option.");}}
                        
                        else if(subtask != 1||2||3){
                        printf("The following is not an option.");}}
                        
                        else{
                            
                        printf("Access has been denied.");}}
                         
                            else if (task != 1||2||3||4||5){
                            printf("\nYour Request cannot be fulfilled");}

    //checks to see if the management system has reach the backup counter requirement for backups                      
    sys1 = fopen ("System-Backup.bin", "rb");
    fscanf(sys1, "%d %d", &systembackup, &count);
    fclose(sys1);
    if(systembackup == 0){

    //resets backup counter for the management system once at 0
    sys1 = fopen ("System-Backup.bin", "wb");    
    fscanf(sys1, "%d %d", &systembackup, &count);
    systembackup= count;
    count= 0;
    fprintf(sys1, "%d %d", systembackup, count);
    fclose(sys1);
    
    //creates a copy of the Fiction Book list once reaching the backup counter requirement
    fp = fopen("Fiction.txt","r");
    if (fp != NULL){
    fpf = fopen("Fiction Backup.txt","w");
    c = fgetc(fp);
    while (c != EOF){
    fputc(c, fpf);
    c = fgetc(fp);}
    fclose(fp);
    fclose(fpf);}
    
    //creates a copy of the Fiction Book list once reaching the backup counter requirement
    fp1 = fopen("Non-Fiction.txt","r");
    if (fp1 != NULL){
    fpf1 = fopen("Non-Fiction Backup.txt","w");
    c = fgetc(fp1);
    while (c != EOF){
    fputc(c, fpf1);
    c = fgetc(fp1);}
    fclose(fp1);
    fclose(fpf1);}}

    //adds count to the backup counter each time the management system runs
    sys1 = fopen ("System-Backup.bin", "wb");
    systembackup= --systembackup;
    count= ++count;
    fprintf(sys1, "%d %d", systembackup, count);
    fclose(sys1);

//choice to exit the management system or to go back to the main menu    
printf("\n\nWhat else do you wish to do \n1-Go back To Menu \n2-Exit \n\nResponse - ");
scanf("%d", &action);
if(action == 1){
system("cls");
goto start;}
else{
return 0;}}