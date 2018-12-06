#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct CarRecord {//this struct is the default struct givin in the assignmnet page. it hold all of the required defined values 
    int     year;
    char    make[20];
    char    model[40];
    char    type[30];
    float   engineSize;
    char    transmissionType[4];
    char    fuelType;
    float   city;
    float   hwy;
    float   fuelPerYear;
    float   co2;
};
struct Row {//this struct is used for finding the avg for the c Querries 
    int     counter;
    float   city;
    float   hwy;
    float   fuelPerYear;
    float   co2;
};
void cQuery(char type[], char transmissionType[], char fuelType, struct CarRecord data[], int len);//querries all the lines that start wiht c in fullquerries.txt and outputs them in the correct format 
void readQueries(FILE* fp, struct CarRecord data[], int len); // this function sends the querries to either cQuerry or sQuerry depending on if the first letter in the file starts with a c or an s 
void sQuery(char make[], char model[], char transmissionType[], float size, struct CarRecord data[], int len); // querries all the lines that start wiht s in fullquerries.txt and outputs them in the correct format
int readFuelConsumption(FILE* fp, struct CarRecord data[]);// reads the informations from the fuelconsumption.cvs

int main() {//opens all of the nessesary files for reading and writing it also checks if the file are in the correct directory 
    struct CarRecord data[14500];
    FILE *fp = fopen("fuelconsumption.csv", "r");
    if (fp == NULL){
        perror("file not found");
    }
    int totlines = readFuelConsumption(fp, data);
    fp = fopen("fullqueries.txt", "r");
    if (fp == NULL){
        perror("file not found");
    }
    FILE *fap = fopen("report.txt","w");
    fprintf(fap,"");
    fclose(fap);
    readQueries(fp, data, totlines);
    
}
int readFuelConsumption(FILE* fp, struct CarRecord data[]) {//this function reads the information out of the fuelconsumption.csv

    int counter = 0;
    char line[128];//max characters per line from the fuel consumption file 
    
    while(fgets(line, 128, fp)) {
        char *trimstr = strdup(line);
               sscanf(trimstr, "%d,%20[^,],%40[^,],%30[^,],%f,%4[^,],%c,%f,%f,%f,%f", &data[counter].year, data[counter].make, data[counter].model, data[counter].type, &data[counter].engineSize, data[counter].transmissionType, &data[counter].fuelType, &data[counter].city,&data[counter].hwy, &data[counter].fuelPerYear, &data[counter].co2);
        free(trimstr);
        counter++;
    }
    fclose(fp);
    return counter;
}

void readQueries(FILE* fp, struct CarRecord data[], int len ){ //check to see if the querry starts with an s or a c 
    char line[128];
    while(fgets(line, 128, fp)) {
        char *trimstr = strdup(line);
        if (trimstr[0]=='S'){//if it == s it will call the squerry function 
            char    make[20];
            char    model[40];
            char    transmissionType[4];
            float   engineSize;     
            sscanf(trimstr+2,"%20[^;];%40[^;];%30[^;];%f",make, model, transmissionType, &engineSize);
            sQuery(make, model, transmissionType, engineSize, data, len );          
        } else if (trimstr[0]=='C'){// if it ==c it will call the cQuerry function 
            char type[30];
            char transmissionType[4];
            char fuelType;
            sscanf(trimstr+2,"%30[^;];%4[^;];%c",type, transmissionType, &fuelType);
            cQuery(type, transmissionType, fuelType, data, len );
        }  
    }
    
}

void sQuery(char make[], char model[], char transmissionType[], float size, struct CarRecord data[], int len ){// querries all the lines that start wiht s in fullquerries.txt and outputs them in the correct format
    int i;
    int year=2000;
    FILE *out = fopen("report.txt","a");
    fprintf(out, "********************************************************************************\n\n");//this is the table formatting 
    fprintf(out, "Specific Search: %s - %s - %s - %.1f\n\n", make, model, transmissionType, size);
    fprintf(out, " Year | city (L/100km) | highway (L/100km) | fuel consumption/year | CO2 / year \n");
    fprintf(out, "--------------------------------------------------------------------------------\n");
    for (i=0;i<len;i++){
        if ((strcmp(data[i].make, make) == 0) && (strcmp(data[i].model, model) == 0) && (strcmp(data[i].transmissionType, transmissionType)==0) && (data[i].engineSize == size)){
            for (;year<data[i].year;year++){
                fprintf(out, " %d |%15s |%18s |%22s |%11s\n", year, "N/A", "N/A", "N/A", "N/A");//if there is no information for the car it will print N/A
            }    
            fprintf(out, " %d |%15.1f |%18.1f |%22.0f |%11.0f\n", data[i].year, data[i].city, data[i].hwy, data[i].fuelPerYear, data[i].co2);
            year++;         
        }
    }
    for (;year<=2014;year++){
        fprintf(out, " %d |%15s |%18s |%22s |%11s\n", year, "N/A", "N/A", "N/A", "N/A");
    }           
    fprintf(out, "\n");
    fclose(out);
} 
void cQuery(char type[], char transmissionType[], char fuelType, struct CarRecord data[], int len){// querries all the lines that start wiht c in fullquerries.txt and outputs them in the correct format
    int i;
    int year=2000;
    struct Row rows[15];//this struct is used for finding the avg for the c Querries 
    for (i=0;i<15;i++){
        rows[i].counter=0;
        rows[i].city=0;
        rows[i].hwy=0;
        rows[i].fuelPerYear=0;
        rows[i].co2=0;   
    }
    FILE *out = fopen("report.txt","a");
    fprintf(out, "********************************************************************************\n\n");//formatting for the appended output 
    fprintf(out, "Vehicle Class Search: %s - %s - %c \n\n", type, transmissionType, fuelType);
    fprintf(out, " Year | city (L/100km) | highway (L/100km) | fuel consumption/year | CO2 / year \n");
    fprintf(out, "--------------------------------------------------------------------------------\n");
    for (i=0;i<len;i++){
       if ((strcmp(data[i].type, type) == 0) && (strcmp(data[i].transmissionType, transmissionType) == 0) && (data[i].fuelType==fuelType)){
           int a=data[i].year-2000; 
           rows[a].counter++;
           rows[a].city+=data[i].city;
           rows[a].hwy+=data[i].hwy;
           rows[a].fuelPerYear+=data[i].fuelPerYear;
           rows[a].co2+=data[i].co2;        
       }      
    }
    for (i=0;i<15;i++){
          
        if (rows[i].counter > 0)
            fprintf(out, " %d |%15.1f |%18.1f |%22.0f |%11.0f\n", i+2000, rows[i].city/rows[i].counter, rows[i].hwy/rows[i].counter, rows[i].fuelPerYear/rows[i].counter, rows[i].co2/rows[i].counter); 
        else
            fprintf(out, " %d |%15s |%18s |%22s |%11s\n", i+2000, "N/A", "N/A", "N/A", "N/A");
    
    }
    fprintf(out, "\n");
    fclose(out);
    
}




