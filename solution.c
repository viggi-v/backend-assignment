#include<stdio.h>
#include<math.h>

/*
 * mul returns the product of (count) consecutive numbers before (number)
 * eg mul(a,b) gives a*(a-1)*...*(a-b)
 */
long mul(long number,long count){
    if(count == 1)
        return number;
    return number*mul(number-1,count-1);
}
/*
 * sum_comb returns the sequence (num)C(count)+(num-1)C(count)+...+(num-count+1)C(count)
 */
long sum_comb(long num, long count){
    long sum = 0;
    long multiplier = mul(num,count);
    long i=0;
    for(i = 0; i< count; i++){
        sum+=multiplier;
        multiplier = multiplier*(num-count-i)/(num-i);
    }
    return sum/mul(count,count);
}

void main(){
    /*
     * t = number of test cases
     * n = number
     */
    int t = 1;
    long n,i;
    long answer;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n%2 == 0){
            answer = pow(2,n-1) + mul(n,n/2)/(2*mul(n/2,n/2));
        }
        else
        {
            answer = pow(2,n-1)+mul(n,n/2)/mul(n/2,n/2);
        }
        for(i=1;i<=(n-1)/2;i++){
            answer-=sum_comb(n-1,i);
        }
        printf("%d\n",answer%(int)pow(10,9));
    }
}
