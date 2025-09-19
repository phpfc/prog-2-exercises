// 1)  Faça uma função que receba uma data como parâmetro 
// e retorne uma nova estrutura com o dia seguinte. 
// O tipo DATA foi criado a partir de uma estrutura que armazena os valores 
// para dia, mês e ano conforme o código a seguir: 

#include<stdio.h>


struct date {
	int day;
	int month;
	int year;
};
typedef struct date DATE;

int is_leap_year(int year) {
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

DATE next_date(DATE currentDate) {
	DATE nextDate = currentDate;

	int daysInMonth[] = {
		0, 31, 28, 31, 30, 31, 30,
			31, 31, 30, 31, 30, 31,
	};

	if (is_leap_year(currentDate.year)) {
		daysInMonth[2] = 29;
	}

	if (currentDate.day < daysInMonth[currentDate.month]) {
		nextDate.day++;
	} else {
		nextDate.day = 1;
		if (currentDate.month == 12) {
			nextDate.month = 1;
			nextDate.year++;
		} else {
			nextDate.month++;
		}
	}


	return nextDate;

}

int main() {
	DATE currentDate;

	printf("Enter a date\n");
	scanf("%d %d %d", &currentDate.day, &currentDate.month, &currentDate.year);
	
	DATE nextDate = next_date(currentDate);
	printf("%d/%d/%d \n", nextDate.day, nextDate.month, nextDate.year);
}