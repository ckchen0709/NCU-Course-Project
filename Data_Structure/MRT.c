#include "MRT.h"

char *names[] = {"淡水","紅樹林","竹圍","關渡","忠義","復興崗","新北投","北投","奇岩","唭哩岸","石牌","明德","芝山","士林","劍潭","圓山","民權西路","雙連","中山","台北車站","台大醫院","中正紀念堂","東門","大安森林公園","大安","信義安和","台北101/世貿","象山","松山","南京三民","台北小巨蛋","南京復興","松江南京","北門","西門","小南門","古亭","台電大樓","公館","萬隆","景美","大坪林","七張","小碧潭","新店區公所","新店","頂埔","永寧","土城","海山","亞東醫院","府中","板橋","新埔","江子翠","龍山寺","善導寺","忠孝新生","忠孝復興","忠孝敦化","國父紀念館","市政府","永春","後山埤","昆陽","南港","南港展覽館","動物園","木柵","萬芳社區","萬芳醫院","辛亥","麟光","六張犁","科技大樓","中山國中","松山機場","大直","劍南路","西湖","港墘","文德","內湖","大湖公園","葫洲","東湖","南港軟體園區","南勢角","景安","永安市場","頂溪","行天宮","中山國小","大橋頭","台北橋","菜寮","三重","先嗇宮","頭前庄","新莊","輔大","丹鳳","迴龍","三重國小","三和國中","徐匯國中","三民高中","蘆洲"};

int main(int argc, const char * argv[]) {
    int i, start = 0, end = 0;
    int pre[STA+1], time[STA+1];
    float d[STA+1];
    FILE    *fp = NULL;
    station *stop = NULL, *stemp = NULL;
    node *ntemp = NULL, *nntemp = NULL;

    printf("If you interest the code of the station, plz read ""README.gm\n\n""");
    
    if((fp=fopen("data.txt","r"))==NULL)    // open file failed
         printf("File open error!!\n");
    else if((stop=readstation(fp))==NULL)
        printf("Read PLA file failed!!\n"); // read input file failed
    else{
        MRT(&start, &end);
        ShortestPath(stop, start, end, d, pre, time);   // find the shortest path by distance
        printf("\n\nFrom %6s to %6s\n", names[start-1], names[end-1]);
        printf("Price : %d NT$\n", FindPrice(d[end]));
        printf("Time  : %d min\n", time[end]);
        PrintPath(end, pre);    // print the path from start to end
    
    }
    /* free memory */
    if(stop){
        for(i=107,stemp=stop+i; i>=0; i--,stemp=stop+i){
            for(ntemp=stemp->next; ntemp; ntemp=nntemp){
                nntemp = ntemp->next;
                free(ntemp);
                ntemp = NULL;
            }
        }
        free(stop);
    }
    return 0;
}
/* read data in adjacency list */
station* readstation(FILE *fp){
    int i, tmp, itmp = 0;
    unsigned int stleng;
    float ftemp;
    station *stemp = NULL, *sstemp = NULL;
    node  *newnode = NULL, *ntemp = NULL;
    char temp[128], temp1[5];
    
    stemp = (station*)malloc(sizeof(station)*STA);
    while ((fgets(temp,128,fp))!=NULL) {
        stleng=(unsigned int)strlen(temp);
        i = 0;
        /* set station */
        if (temp[0]=='.'){
            while (i<stleng && temp[i]!= '\n') {
                for (i=1; i<stleng; i++){
                    if (temp[i]>='0' && temp[i]<='9') {
                        if(temp[i+1]>='0' && temp[i+1]<='9'){
                            if(temp[i+2]>='0' && temp[i+2]<='9'){
                                strncpy(temp1, temp+i, 3);
                                temp1[3] = '\0';
                                itmp = 3;
                            }
                            else{
                                strncpy(temp1, temp+i, 2);
                                temp1[2] = '\0';
                                itmp = 2;
                            }
                        }
                        else{
                             strncpy(temp1, temp+i, 1);
                            temp1[1] = '\0';
                            itmp = 1;
                        }
                        tmp = atoi(temp1);
                        
                        sstemp = stemp+tmp-1;
                        sstemp->index = tmp;
                        break;
                    }
                }
                for (i+=itmp; i<stleng; i++){
                    if (temp[i]>='0' && temp[i]<='9') {
                        if(temp[i+1]>='0' && temp[i+1]<='9'){
                            if(temp[i+2]>='0' && temp[i+2]<='9'){
                                strncpy(temp1, temp+i, 3);
                                temp1[3] = '\0';
                                itmp = 3;
                            }
                            else{
                                strncpy(temp1, temp+i, 2);
                                temp1[2] = '\0';
                                itmp = 2;
                            }
                        }
                        else{
                             strncpy(temp1, temp+i, 1);
                            temp1[1] = '\0';
                            itmp = 1;
                        }
                        
                        tmp = atoi(temp1);
                        
                        sstemp->line = tmp;
                        sstemp->next = NULL;
                        i+=itmp;
                        break;
                    }
                }
            }
        }
        /* set other station which connected */
        else if(temp[0]=='/'){
            while (i<stleng && temp[i]!= '\n') {
                for (i=1; i<stleng; i++){
                    if (temp[i]>='0' && temp[i]<='9') {
                        if(temp[i+1]>='0' && temp[i+1]<='9'){
                            if(temp[i+2]>='0' && temp[i+2]<='9'){
                                strncpy(temp1, temp+i, 3);
                                temp1[3] = '\0';
                                itmp = 3;
                            }
                            else{
                                strncpy(temp1, temp+i, 2);
                                temp1[2] = '\0';
                                itmp = 2;
                            }
                        }
                        else{
                            strncpy(temp1, temp+i, 1);
                            temp1[1] = '\0';
                            itmp = 1;
                        }
                        tmp = atoi(temp1);
                        
                        newnode = (node*)malloc(sizeof(node));
                        newnode->index = tmp;
                        newnode->distance = 0;
                        newnode->time = 0;
                        newnode->next = NULL;
                        
                        if(sstemp->next){
                            ntemp->next = newnode;
                            ntemp = ntemp->next;
                        }
                        else{
                            sstemp->next = newnode;
                            ntemp = newnode;
                        }
                        break;
                    }
                }
                for (i+=itmp; i<stleng; i++){
                    if(temp[i]>='0' && temp[i]<='9'){
                        if(temp[i+2]>='0' && temp[i+2]<='9'){
                            strncpy(temp1, temp+i, 4);
                            temp1[4] = '\0';
                            itmp = 4;
                        }
                        else{
                            strncpy(temp1, temp+i, 3);
                            temp1[3] = '\0';
                            itmp = 3;
                        }
                        ftemp = atof(temp1);
                        newnode->distance = ftemp;
                        break;
                    }
                }
                for (i+=itmp; i<stleng; i++){
                    if(temp[i]>='0' && temp[i]<='9'){
                        strncpy(temp1, temp+i, 1);
                        temp1[1] = '\0';
                        newnode->time = atoi(temp1);
                        i++;
                        break;
                        
                    }
                }
            }
        }
        else{   // unknown options
            printf("Unknown Options!!\n");
            return NULL;
        }
    }
/*  check data
    for(i=0, sstemp=stemp; i<108; i++, sstemp=stemp+i){
        printf("%s\n", names[sstemp->index-1]);
        for(ntemp=sstemp->next; ntemp; ntemp=ntemp->next){
            printf("\t%10s\t%.3f\t%3d\n", names[ntemp->index-1], ntemp->distance, ntemp->time);
        }
    }
 */
    return stemp;
}
/* enter the depart station and arrive station */
void MRT(int *start, int *end){
    int i = 1;
    char temp[5];
    do{
        printf("Enter the start node : ");
        scanf("%s",temp);
        if(strlen(temp) == 1){
            if(temp[0]>='0' && temp[0]<='9'){
                *start = atoi(temp);
                i = 0;
            }
        }
        else if(strlen(temp) == 2){
            if(temp[0]>='0' && temp[0]<='9' && temp[1]>='0' && temp[1]<='9'){
                *start = atoi(temp);
                i = 0;
            }
        }
        else if(strlen(temp) == 3){
            if(temp[0]>='0' && temp[0]<='9' && temp[1]>='0' && temp[1]<='9' && temp[2]>='0' && temp[2]<='9'){
                *start = atoi(temp);
                if(*start<109)
                    i = 0;
            }
        }
        if(i)
            printf("Error input, plz try again!!\n");
    }while(i);
    *start = atoi(temp);
    i = 1;
    do{
        printf("Enter the end node : ");
        scanf("%s",temp);
        
        if(strlen(temp) == 1){
            if(temp[0]>='0' && temp[0]<='9'){
                *end = atoi(temp);
                if(*end!=*start)
                    i = 0;
            }
        }
        else if(strlen(temp) == 2){
            if(temp[0]>='0' && temp[0]<='9' && temp[1]>='0' && temp[1]<='9'){
                *end = atoi(temp);
                if(*end!=*start)
                    i = 0;
            }
        }
        else if(strlen(temp) == 3){
            if(temp[0]>='0' && temp[0]<='9' && temp[1]>='0' && temp[1]<='9' && temp[2]>='0' && temp[2]<='9'){
                *end = atoi(temp);
                if(*end<109 && *end!=*start)
                    i = 0;
            }
        }
        if(i)
            printf("Error input, plz try again!!\n");
    }while(i);
}
/* find the shorest path */
void ShortestPath(station *stop, int start, int end, float d[], int pre[], int time[]){
    int i;
    station *stemp = NULL;
    node *ntemp = NULL;
    quene *qhead = NULL , *qtail = NULL , *qtemp = NULL ;
    
    for(i=0; i<STA+1; i++){
        d[i] = 10000;
        pre[i] = 0;
        time[i] = 0;
    }
    d[start] = 0;
    pre[start] = -1;
    i = start;
    stemp = stop+(i-1);
    
    do{
        for(ntemp=stemp->next; ntemp; ntemp=ntemp->next){
            /* find the shorest path by ading and setting distance from start node to another node */
            if(ntemp->distance + d[stemp->index] < d[ntemp->index]){
                d[ntemp->index] = ntemp->distance + d[stemp->index];
                time[ntemp->index] = ntemp->time + time[stemp->index];
                if(ntemp->index == end){
                    pre[ntemp->index] = stemp->index;
                    /* free memory */
                    for(qtemp=qhead; qtemp; qtemp=qhead){
                        qhead = qtemp->next;
                        free(qtemp);
                    }
                    return;
                }
                /* add data to quene tail */
                if(pre[ntemp->index]!=stemp->index){
                    if(!qhead){
                        qhead = (quene*)malloc(sizeof(quene));
                        qhead->index = ntemp->index;
                        qhead->pre = stemp->index;
                        qhead->next = NULL;
                        qtail = qhead;
                    }
                    else{
                        qtemp = (quene*)malloc(sizeof(quene));
                        qtemp->index = ntemp->index;
                        qtemp->pre = stemp->index;
                        qtemp->next = NULL;
                        qtail->next = qtemp;
                        qtail = qtemp;
                    }
                }
                pre[ntemp->index] = stemp->index;
            }
        }
        /* pop data from quene head */
        i = qhead->index;
        qtemp = qhead->next;
        free(qhead);
        qhead = qtemp;
        
        stemp = stop+(i-1);
    }while(i!=end);
}
/* find the ticket prices*/
int FindPrice(float distance){
    if(distance<5.0)
        return 20;
    else if(distance>31)
        return 65;
    else
        return 5*(int)((distance-2.0)/3)+20;
}
/* print the shorest path */
void PrintPath(int end, int pre[]){
    int i;
    quene *stack_top = NULL , *stack_bot = NULL , *stack_temp = NULL ;
    
    /* add data to stack from end to start */
    for(i=end; pre[i]; i=pre[i]){
        stack_temp = (quene*)malloc(sizeof(quene));
        stack_temp->index = i;
        stack_temp->pre = 0;
        stack_temp->next = NULL;
        if(stack_bot){
            stack_temp->next = stack_top;
            stack_top = stack_temp;
        }
        else{
            stack_top = stack_temp;
            stack_bot = stack_temp;
        }
    }
    /* print station from start to end */
    if(stack_top){
        printf("Start\n");
        for(stack_temp=stack_top; stack_temp; stack_temp=stack_temp->next)
            printf("%6s\n", names[stack_temp->index-1]);
        printf("End\n\n");
    }
    else
        printf("error!!\n");
}
