#include<stdio.h>

int gcd(int a, int b){
    return (a%b==0)?b:gcd(b,a%b);
}

int public_key(int totient){
	//e has to be >1
	int e=2;
	while(e<totient){
		if(gcd(e,totient)==1) break;
		else e+=1;
    }
    return e;
}

int extended_gcd(int a, int b, int *x, int *y){
	if (a == 0){
		*x = 0;
		*y = 1;
		return b;
	}

	int _x, _y;
	int gcd_ = extended_gcd(b % a, a, &_x, &_y);

	*x = _y - (b/a) * _x;
	*y = _x;

	return gcd_;
}

int power(int a, int b, int n){
	if(b==1) return a;
	if(b==0) return 1;
	if(b%2==0){
		int aux = power(a,b/2,n)%n;
		return (aux*aux)%n;//!!
	}else{
		return (power(a,b-1,n)*a)%n;
	}
}

int secret_key(int e, int p, int q){
	int d, aux;
	extended_gcd(e,(p-1)*(q-1),&d,&aux);

	return d;
}

int encrypt(int message, int e, int n){
	return power(message,e,n)%n;
}

int decrypt(int encr_mess, int d, int n){
	return power(encr_mess,d,n)%n;
}

int main(){
	int p=3, q=7;//
	int n=p*q;
	int message=1;//
	int totient = (p-1)*(q-1);

	int e = public_key(totient);
	int d = secret_key(e,p,q);

	int m_ = encrypt(message, e, n);
	int ans = decrypt(m_,d,n);

	printf("Message: %d\n",message);
	printf("Encrypted message: %d %d %d\n",m_,d,e);
	printf("Decrypted message: %d\n",ans);
 
    return 0;
}
