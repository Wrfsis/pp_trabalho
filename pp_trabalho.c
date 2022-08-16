#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//coeficientes
struct equacao
{
	float a, b, c, d;
};


// calcula altura f(x)
float f(float x, struct equacao e)
{
	return e.a*pow(x,3) + e.b*pow(x,2) + e.c*x + e.d;
}


//calcula area
float area(float altura, float largura) 
{
	return altura*largura;
}


//calcula o modulo
float mod(float valor) 
{
	if(valor<0)
	return -1*valor;
	else
	return valor;
}


//testa o com a constante k
int teste(float anterior, float atual)  
{
	if((mod(anterior-atual))<0.0000001)
		return 0;
	else
		return 1;
}



int main()
{

	struct equacao e ; //coeficientes
	float x, x1, x2; //valores e entrada de intervalo
	float h;//intervalo
	int y; //f(x)
	float K;//constante para encerramento do calculo, precisao
	float cont=1;//controle dos laços
	float S, Santerior, Satual=0; //soma das areas
	
	
	//Entrada de dados
	printf("\n");
	printf("******Calculo da integral da função******\n\n");
	printf("Digite um valor para o coeficiente a: ");
	scanf("%f",&e.a);
	printf("Digite um valor para o coeficiente b: ");
	scanf("%f",&e.b);
	printf("Digite um valor para o coeficiente c: ");
	scanf("%f",&e.c);
	printf("Digite um valor para o coeficiente d: ");
	scanf("%f",&e.d);
	printf("Digite um valor para o primeiro ponto do intervalo, x1: ");
	scanf("%f", &x1);
	printf("Digite um valor para o segundo ponto do intervalo, x2: ");
	scanf("%f", &x2);
	
	
	//verifica se o intervalo e valido
	if(x2<x1) 
	{
		printf("Valores invalidos!!\nDigite outros valores de intervalo");
		system("Pause");
		exit(1);
	}
	
	
	//calculo do intervalo inicial
	h=x2-x1;
		
	
	//calcula a soma da area inicial	
	Santerior = area(mod(f(x2, e)),h); 
	
		
	while((teste(Santerior, Satual))==1)
	{
		Satual=0;
		for(x=x1; x<x2; x=x+h)
		{	
			h = h / 2;
			Satual = Satual + area(mod(f((x+h), e)),h);
			if(teste(Santerior, Satual)==1)
			{
				Santerior=Satual;
			}
				
		}

	}

	printf("\nA soma das areas da integral proposta e igual a: %.2f\n\n", Satual);

	return 0;	
	
}	
		
		
