#include <stdio.h> 
 
int printfm(const char *format,void * argument);

int printfm(const char *format,void * argument)
{  

  int i,j,k; 
	
    for ( i = 0; format[i] != '\0'; i++) { 
        if (format[i] == '%') { 
            i++; 
  if (format[i] == 'c') {
               
                  char c = (char*)argument;              
                  putchar(c);
			}
  else if (format[i] == 'd') { 
               int d = argument ;
                if (d < 0) { 
                    putchar('-'); 
                    d = -d; 
                } 
                int digit_count = 0;  
                int tmp = d;  
                do {   
                    digit_count++;     
                    tmp /= 10;     
                } while (tmp > 0);     
                for ( j = digit_count - 1; j >= 0; j--) { 
                    int divisor = 1; 
                    for ( k = 0; k < j; k++) { 
                        divisor *= 10; 
                    } 
                    int digit = (d / divisor) % 10;  
                    putchar('0' + digit); 
                } 
            }  else { 
                putchar('?'); 
            } 
        } else { 
            putchar(format[i]); 
        } 
    }}
	




   
int main() { 
    char ch = 'Z'; 
    int num = -434543524; 
    printfm("%c\n\r", ch);
    printfm("%d\n\r", num);
    getch(0);
    return 0; 
}
