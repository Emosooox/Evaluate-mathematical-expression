#include <stdio.h>
#include <math.h>


int parentheses(int *index,char String[]){
    int k[4096];//elimizdeki
    int num_k= 0;
    int up_k[4096] ={0};//yukarı verilen
    // 7 * (3-4) / (7*2)
    // 7 *  k_0  /  k_1
    //k = {-1,14}
    int in = 1;
    char x[4096];
    char y[4096];
    int i = 1;
    int j = 0;
    x[0] = '(';
    while(in != 0)
    {
        x[i] = String[*index + i];
        if(String[*index + i] == '('){
            in++;
        }
        else if(String[*index + i] == ')'){
            in--;
        }
        i++;
    }
    int n = i;
    int *ptr;
    ptr = &i;
    for(i = 1;i < n - 1;i++){
        if(x[i]== '('){
            y[j] = 'k';
            k[num_k] = parentheses(&i,x);
            //printf("%d\n",k[num_k]);
            num_k++;
        }
        else{
            y[j] = x[i];
        }
        j++;
    }
    
    *index = *index + n;
    n = j;





    




    num_k = 0;

    int N[5];
    int nums[4096] = {0};
    int power,sum;
    j = 0;
    for(i = n - 1;i >= 0;i--){
        sum = 0;
        power = 0;
        if(y[i] == 'k'){
            nums[j] = k[num_k];
            num_k++;
            j++;
            continue;
        }
        while((47<y[i]) && (y[i]<58)){
            sum += (int)pow(10.0,(double)power) * (y[i] - 48);
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
    for(i = 0; i < N[1];i++){
        //printf("%d\n",nums[i]);
    }
    
//1+3*(2+2)
    j = 0;
    char symbols[4096] = {' '};
    for(i = 0;i <n;i++){
        if(y[i]==42 || y[i]==43 || y[i]==45 || y[i]==47){
            symbols[j] = y[i];
           // printf("%c\n",symbols[j]);
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
    //printf("%d\n",nums[i]);
    return nums[i];




    












































































}

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

    int k[4096] ={0};//elimizdeki
    int num_k= 0;

    N[0] = i;
    for(i = 0;i < N[0];i++){
        if((46<String[i] && String[i]<58)||(42==String[i])||(43==String[i])||(45==String[i])||(40==String[i])||(41==String[i])){
            String[j] = String[i];
            j++;
        }
    }
    N[0] = j;

    j = 0;
    int *ptr;
    ptr = &i;
    for(i = 0;i < N[0];i++){
        if(String[i]== '('){
            String[j] = 'k';
            k[num_k] = parentheses(&i,String);
            //printf("%d\n",k[num_k]);
            num_k++;
        }
        else{
            String[j] = String[i];
            //printf("%c\n",String[j]);
        }
        j++;
    }
    N[0] = j;


    for(i = 0; i < j;i++){
        printf("String[%d]: %c\n",i,String[i]);
    }



    num_k = 0;
    int nums[4096] = {0};
    int power,sum;
    j = 0;
    for(i = N[0] - 1;i >= 0;i--){
        sum = 0;
        power = 0;
        while((48<String[i]) && (String[i]<58)){
            sum += (int)pow(10.0,(double)power) * (String[i] - 48);
            i--;
            power++;
        }
        if(String[i] == 'k'){
            nums[j] = k[num_k];
            //printf("%d\n",nums[j]);
            num_k++;
            j++;
            i--;
            sum--;
        }
        else if(sum >= 0){
            nums[j] = sum;
            j++;
        }
    }

    printf("num k: %d\n",num_k);
    

    





    N[1] = j;
    char temp;

    for(i = 0;i < (N[1]/2);i++){
        temp = nums[i];
        nums[i] = nums[N[1] - i - 1];
        nums[N[1] - i - 1] = temp;
    }
    for(i = 0; i < j;i++){
        printf("nums[%d]: %d\n",i,nums[i]);
    }
    j = 0;
    char symbols[4096] = {' '};
    for(i = 0;i <N[0];i++){
        if(String[i]==42 || String[i]==43 || String[i]==45 || String[i]==47){
            symbols[j] = String[i];
            j++;
        }
    }
    for(i = 0; i < j;i++){
        printf("symbols[%d]: %c\n",i,symbols[i]);
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