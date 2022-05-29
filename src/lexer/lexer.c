#include <stdio.h>


char	*duble_apostrophe_gap(char *str, int i){
	int		j = i;				// Запоминаем, с какого символа начинаем итерироваться
	char	*tmp, *tmp2, *tmp3;	// Создаём временные буферы для разных частей строки
	
	while(str[++i])			// Итерируемся к закрывающей кавычке или к последнему символу
		if(str[i] == '"')	// Запоминаем найденный символ
			break;			// Выходим из цикла

	
}


void	preparser(char *str){
	int i = -1;

	while(str[++i]){					// Итерируемся по массиву, пока не дойдём до символа
		if(str[i] == '"'){				// " - при нахождении, обрабатываем функцией
			duble_apostrophe_gap(str, i);		// apostrophe_gap
		}
	}
}

int	main(void){
	char    *str = "dfbdfb'dfbdf'd fdb";
	// printf("%s\n", preparser("rgdrbf/sdbdfb/dfbdfbdf/dfbdfbdf"))
}