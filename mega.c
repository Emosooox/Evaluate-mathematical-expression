#include <stdio.h>
#include <math.h>



int main(){

    printf("Gir : ");
    int i = 0,j = 0;
    int N[5];
    char c,String[4096];
    while((c = getchar()) != '\n')
    {
        String[i] = c;
        i++;
    }

    N[0] = i;
    for(i = 0;i < N[0];i++){
        if((46<String[i] && String[i]<58)||(42==String[i])||(43==String[i])||(45==String[i])){
            String[j] = String[i];
            j++;
        }
    }
    N[0] = j;

    int nums[4096] = {0};
    int power,sum;
    j = 0;
    for(i = N[0] - 1;i >= 0;i--){
        sum = 0;
        power = 0;
        while((47<String[i]) && (String[i]<58)){
            sum += (int)pow(10.0,(double)power) * (String[i] - 48);
            i--;
            power++;
        }
        if(sum >= 0){
            nums[j] = sum;
            j++;
        }
    }
    N[1] = j;
    char temp;

    for(i = 0;i < (N[1]/2);i++){
        temp = nums[i];
        nums[i] = nums[N[1] - i - 1];
        nums[N[1] - i - 1] = temp;
    }

    j = 0;
    char symbols[4096] = {' '};
    for(i = 0;i <N[0];i++){
        if(String[i]==42 || String[i]==43 || String[i]==45 || String[i]==47){
            symbols[j] = String[i];
            j++;
        }
    }
    N[2] = j;
    j = 0;

    for(i = 0;i < N[1];i++){
        if(symbols[i] == '+' ||symbols[i] == '-')
        {
            nums[j] = nums[i];
            j++;
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
    nums[j] = nums[i-1];
    j++;
    N[3] = j;
    j = 0;
    for(i = 0; i<N[2];i++){
        if(symbols[i]==43)
        {
            symbols[j] = symbols[i];
            j++;
        }
        else if(symbols[i]==45)
        {
            symbols[j] = symbols[i];
            j++;
        }
    }
    N[4] = j;
    sum = 0;
    for(i = 0; i<N[4];i++){
        if(symbols[i]==43)
        {
            nums[i+1] = nums[i] + nums[i+1];
        }
        else if(symbols[i]==45)
        {
            nums[i+1] = nums[i] - nums[i+1];
        }
    }
    printf("Toplam: %d",nums[i]);

    return 0;
}