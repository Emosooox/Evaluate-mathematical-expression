#include <stdio.h>
#include <math.h>



int main(){
    //1) String Girilsin
    printf("Gir : ");
    int i = 0,j = 0;
    char c,rawString[4096];
    while((c = getchar()) != '\n')
    {
        rawString[i] = c;
        i++;
    }
    //1) String Girilsin
    //2) Rafine
    int rawLength = i;
    char finalString[4096];
    for(i = 0;i < rawLength;i++){
        if((46<rawString[i] && rawString[i]<58)||(42==rawString[i])||(43==rawString[i])||(45==rawString[i])){
            finalString[j] = rawString[i];
            j++;
        }
    }
    //2) Rafine
    //3) Ters Çevir
    /*char temp;
    //printf("Mid: %d\n",(j/2)+1);
    for(i = 0;i < (j/2)+1;i++){
        temp = finalString[i];
        //printf("index: %d | temp: %c\n",i,temp);
        finalString[i] = finalString[j - i - 1];
        finalString[j - i - 1] = temp;
    }*/
    //3) Ters Çevir
    /*for(i = 0;i < j;i++){
        printf("%c",finalString[i]);
    }*/
   //4) Sayılar arrayini oluştur
    int nums[4096] = {0};
    int k = 0,p,sum;
    for(i = j - 1;i >= 0;i--){
        sum = 0;
        p = 0;
        while((47<finalString[i]) && (finalString[i]<58)){
            //printf("%d | %d\n",(finalString[i] - 48),(int)pow(10.0,(double)p));
            sum += (int)pow(10.0,(double)p) * (finalString[i] - 48);
            i--;
            p++;
        }
        if(sum >= 0){
            nums[k] = sum;
            k++;
        }
    }
    char temp;
    //printf("Mid: %d\n",(j/2)+1);
    for(i = 0;i < (k/2);i++){
        temp = nums[i];
        //printf("index: %d | temp: %c\n",i,temp);
        nums[i] = nums[k - i - 1];
        nums[k - i - 1] = temp;
    }
    /*for(i = 0; i<k;i++){
        printf("%d\n",nums[i]);
    }*/
    //4) Sayılar arrayini oluştur

    //İŞARETLER
    int l = 0;
    char symbols[4096] = {' '};
    for(i = 0;i <j;i++){
        if(finalString[i]==42 || finalString[i]==43 || finalString[i]==45 || finalString[i]==47){
            symbols[l] = finalString[i];
            l++;
        }
    }
    //İŞARETLER
    /*for(i = 0; i<l;i++){
        printf("%c\n",symbols[i]);
    }*/
    //ÇARPMA BÖLME



    int N_x2 = 0;
    int N_y2 = 0;
    int x2[4096] = {0};

    for(i = 0;i < k;i++){
        if(symbols[i] == '+' ||symbols[i] == '-')
        {
            x2[N_x2] = nums[i];
            N_x2++;
        }
        else if(symbols[i] == '*')
        {
            nums[i+1] = nums[i] * nums[i +1];
        }
        else if(symbols[i] == '/')
        {
            nums[i+1] = nums[i] / nums[i +1];
        }
    }
    x2[N_x2] = nums[i-1];
    N_x2++;
    /*for(i = 0;i < N_x2;i++){
        printf("%d\n",x2[i]);
    }*/
    char y2[4096] = {' '};
    for(i = 0; i<l;i++){
        if(symbols[i]==43)
        {
            y2[N_y2] = symbols[i];
            N_y2++;
        }
        else if(symbols[i]==45)
        {
            y2[N_y2] = symbols[i];
            N_y2++;
        }
    }














    //ÇARPMA BÖLME
    //FİNAL
    sum = 0;
    for(i = 0; i<N_y2;i++){
        if(y2[i]==43)
        {
            x2[i+1] = x2[i] + x2[i+1];
        }
        else if(y2[i]==45)
        {
            x2[i+1] = x2[i] - x2[i+1];
        }
    }
    printf("Toplam: %d",x2[i]);
    //FİNAL
    return 0;
}