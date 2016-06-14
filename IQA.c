#include <stdio.h>
#include <math.h>

int main(void){
	double IQA;
	double CF, Q1;
	double PH, Q2;
	double DBO, Q3;
	double NT, Q4;
	double FT, Q5;
	double TEMP, Q6;
	double TURB, Q7;
	double ST, Q8;
	double OD, Q9;

	printf("Por favor, digite o valor de Coliformes Fecais:\n");
	scanf("%lf", &CF); // Coliformes Fecais

	printf("Por favor, digite o valor do pH:\n");
	scanf("%lf", &PH); // pH

	printf("Por favor, digite o valor da Demanda Bioquímica de Oxigênio(DBO):\n");
	scanf("%lf", &DBO); // DBO

	printf("Por favor, digite o valor de Nitrogênio Total:\n");
	scanf("%lf", &NT); // Nitrogênio Total

	printf("Por favor, digite o valor de Fósforo Total:\n");
	scanf("%lf", &FT); // Fósforo Total

	printf("Por favor, digite o valor da Variação de Temperatura:\n");
	scanf("%lf", &TEMP); // Variação de Temperatura

	printf("Por favor, digite o valor da Turbidez:\n");
	scanf("%lf", &TURB); // Turbidez

	printf("Por favor, digite o valor dos Sólidos Totais:\n");
	scanf("%lf", &ST); // Sólidos Totais

	printf("Por favor, digite o valor do Oxigênio Dissolvido:\n");
	scanf("%lf", &OD); // Oxigênio Dissolvido

	if(CF > pow(10, 5)){
		Q1 = 3.0;
	} else{
		Q1 = (98.03 - 36.45 * log10(CF) + 3.14 * pow(log10(CF), 2) + 0.067 * pow(log10(CF), 3));
	}

	if(PH > 12){
		Q2 = 3.0;
	} else if(PH < 2){
		Q2 = 2.0;
	} else{
		Q2 = (0.05421 * (pow(PH, 1.23 * PH - 0.09873 * (pow(PH, 2)))) + 5.213);
	}

	if(DBO > 30){
		Q3 = 2.0;
	} else{
		Q3 = (102.6 * exp(-0.1101 * DBO));
	}

	if(NT > 100){
		Q4 = 1.0;
	} else{
		Q4 = (98.96 * (pow(NT, -0.2232 + (-0.006457 * NT))));
	}

	if(FT > 10){
		Q5 = 1.0;
	} else{
		Q5 = (213.7 * exp(-1.68 * (pow(FT, 0.3325))));
	}

	if(TEMP <= -5){
		Q6 = 1;
	} else if(TEMP > 15){
		Q6 = 9.0;
	} else{
		Q6 = (1 / (0.0003869 * pow((TEMP + 0.1815), 2) + 0.01081));
	}

	if(TURB > 100){
		Q7 = 5.0;
	} else{
		Q7 = (97.34 * exp(-0.01139 * TURB - 0.04917 * pow(TURB, 0.5)));
	}

	if(ST > 500){
		Q8 = 32.0;
	} else{
		Q8 = (80.26 * exp(-0.00107 * ST + 0.03009 * pow(ST, 0.5)) - 0.1185 * ST);
	}

	if(OD == 140){
		Q9 = 47.0;
	} else{
		Q9 = (100.8 * exp((pow(OD - 106, 2) / -3745)));
	}


	IQA = (pow(Q1, 0.15)) * (pow(Q2, 0.12)) * (pow(Q3, 0.10)) * (pow(Q4, 0.10)) * (pow(Q5, 0.10)) * (pow(Q6, 0.10)) * (pow(Q7, 0.08)) * (pow(Q8, 0.08)) * (pow(Q9, 0.17));
	
	printf("IQA: %lf\n", IQA);
	
	if(IQA >= 80.00 && IQA <= 100.00){
		printf("Qualidade: ÓTIMA\n");
	}

	if(IQA >= 51.00 && IQA < 80.00){
		printf("Qualidade: BOA\n");
	}

	if(IQA >= 37.00 && IQA < 51.00){
		printf("Qualidade: ACEITÁVEL\n");
	}

	if(IQA >= 20.00 && IQA < 37.00){
		printf("Qualidade: RUIM\n");
	}

	if(IQA >= 0.00 && IQA < 20.00){
		printf("Qualidade: Péssima\n");
	}

	return 0;
}
