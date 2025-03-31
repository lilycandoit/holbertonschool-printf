#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - mimic a printf function in C
 * @format: the given string 
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
    {
        return -1;
    }
    va_list args;
    unsigned int count = 0;               
    
    va_start(args, format);
    
    while (*format)                      
    {
        if (*format == '%')              
        {
            format++;                    
            if (*format == '\0')         
            {
                break;
            }
            if (*format == 'c')
            {
                char current_c = va_arg(args, int);       
                putchar(current_c);
                count++;
            } 
            else if (*format == 's')             
            {
                char *str = va_arg(args, char *);        
                
                if (str == NULL)
                    str = "(null)";
                    
                while (*str)                
                {
                    putchar(*str);            
                    count++;  
                    str++;                   
                }
            }
            else if (*format == '%')         
            {
                putchar('%');
                count++;
            }
            else if (*format == 'd' || *format == 'i')          
            {
                int num = va_arg(args, int);
                
                if (num < 0)                                  
                {
                    putchar('-');                            
                    count++;
                    num = -num;                               
                }
                if (num == 0)                                 
                {
                    putchar('0');
                    count++;
                }
                else                                          
                {
                    int digits[10];                           
                    int i = 0;
                                                
                    while (num != 0)                /* this while loop extracts digits in reverse order */              
                    {
                        digits[i++] = num % 10;     /* num % 10 gives the last digit, digits[i++] stores digits and i increments */        
                        num = num / 10;             /* num / 10 removes the last digit */      
                    }
                    int j;
                    
                    for (j = i - 1; j >= 0; j--)    /* this for loop is used to print digits in correct order */
                    {
                        putchar(digits[j] + '0');   /* converts the digit to its corresponding char by adding '0' */     
                        count++;
                    }
                }
            }
            else
            {
                putchar('%');                          
                putchar(*format);                            
                count += 2;                                  
            }
        } 
        else 
        {
            putchar(*format);                              
            count++;
        }
        format++;          
    }    
    va_end(args);         
    return count;      
}
