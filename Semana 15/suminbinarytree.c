#include <stdio.h>

int main(){
    long long int t, n;
    scanf("%lld", &t);

    for(int i = 0; i < t; i++){
        scanf("%lld", &n);
        long long int sum = 0;

        while(n > 0){
            sum += n;
            if(n%2 == 0) n = n/2;
            else if(n%2 != 0) n = (n-1)/2;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
