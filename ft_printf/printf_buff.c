// Function to convert a pointer to a base and print the result
int ft_base_add(void *ptr, char *str)
{
	// Variable to hold the converted base string
	char *dest;

	// Loop counter and variables for result, modulo, and remaining value
	size_t i;
	size_t res;
	size_t mod;

	// Initialize loop counter and set res to the integer value of the pointer
	i = 0;
	res = (size_t)ptr;

	// Allocate memory for the destination string
	dest = ft_calloc(sizeof(char), (size_base(res, ft_strlen(str)) + 1));

	// Loop to convert the value to the specified base
	while (res >= (size_t)ft_strlen(str))
	{
		mod = res % (ft_strlen(str));
		dest[i] = str[mod];
		res = res / (ft_strlen(str));
		i++;
	}

	// Add the last character to the destination string
	dest[i] = str[res];
	res = i;

	// Print the converted value in reverse order
	while (i > 0)
	{
		ft_putchar_fd(dest[i], 1);
		i--;
	}

	// Print the first character of the destination string
	ft_putchar_fd(dest[0], 1);

	// Free the allocated memory for the destination string
	free(dest);

	// Return the length of the converted string
	return ((int)res + 1);
}

// Function to print the address of a pointer in hexadecimal format
int ft_adresse(void *ptr)
{
	// Variable to hold the return value
	int i;

	// Initialize the return value
	i = 0;

	// Check if the pointer is NULL
	if (!ptr)
	{
		// Print "(nil)" and return the length
		write(1, "(nil)", 5);
		return (5);
	}

	// Print "0x" prefix for hexadecimal addresses
	ft_putstr_fd("0x", 1);

	// Call the base conversion function for hexadecimal representation
	i = ft_base_add(ptr, "0123456789abcdef");

	// Return the total length of the printed address
	return (i + 2);
}

// Function to zero out a block of memory
void ft_bzero(void *s, size_t n)
{
	// Loop counter and pointer to unsigned char
	size_t i;
	unsigned char *s1;

	// Cast the input pointer to unsigned char
	s1 = (unsigned char *)s;

	// Loop through the memory block and set each byte to zero
	i = 0;
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
}

// Function to allocate memory and zero it out
void *ft_calloc(size_t nmemb, size_t size)
{
	// Variable to hold the destination memory address
	void *dest;

	// Check for zero size or zero number of members
	if (nmemb == 0 || size == 0)
		return (malloc(0));

	// Check for potential overflow in the multiplication
	if (nmemb * size / size != nmemb)
		return (NULL);

	// Allocate memory for the destination with the specified size
	dest = malloc(nmemb * size);

	// Check if memory allocation was successful
	if (!dest)
		return (NULL);

	// Zero out the allocated memory block
	ft_bzero(dest, (nmemb * size));

	// Return the pointer to the allocated and zeroed memory
	return (dest);
}

// Function to count occurrences of a character in a string
int ft_countchar(const char *str, char c)
{
	// Loop counter and variable to store the count
	int i;
	int s;

	// Initialize the count
	s = 0;
	i = 0;

	// Loop through the string and count occurrences of the specified character
	while (str[i])
	{
		if (str[i] == c)
			s++;
		i++;
	}

	// Return the count
	return (s);
}

// Main printf function that handles format specifiers
int ft_printf(const char *str, ...)
{
	// Variable argument list and loop counters
	va_list args;
	int i;
	int res;

	// Initialize variables
	res = 0;
	i = 0;

	// Start variable argument processing
	va_start(args, str);

	// Loop through the format string
	while (str[i])
	{
		// Check for format specifier '%'
		if (str[i] == '%')
		{
			// Move to the next character after '%'
			i++;

			// Add the length of the processed format specifier to the result
			res = res + ft_which_sign(&args, str[i]);

			// Move to the next character after the format specifier
			i++;
		}
		else
		{
			// Print non-format specifier character
			ft_putchar_fd(str[i], 1);

			// Move to the next character
			i++;
		}
	}

	// End variable argument processing
	va_end(args);

	// Return the total length of the printed string
	return (ft_strlen(str) + res - (2 * ft_countchar(str, '%')));
}

// Header file containing function prototypes and necessary includes
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

// Function prototypes
int ft_strlen(const char *str);
int ft_putstr_fd(char *s, int fd);
int ft_putnbr_fd(int n, int fd);
void ft_putendl_fd(char *s, int fd);
int ft_putchar_fd(char c, int fd);
int ft_putnbru_fd(unsigned int n, int fd);
int ft_base(unsigned int n, char *str);
int size_base(int n, int size);
int ft_which_sign(va_list *args, char c);
int ft_adresse(void *ptr);
int ft_base_add(void *ptr, char *str);
int ft_putnbru_base(unsigned int n, int fd, char *base);
int ft_printf(const char *str, ...);
int ft_countchar(const char *str, char c);
int size_unsigned(unsigned int n, unsigned int base);
void *ft_calloc(size_t nmemb, size_t size);
void ft_bzero(void *s, size_t n);

#endif

// Function to print a single character to a specified file descriptor
int ft_putchar_fd(char c, int fd)
{
	// Write the character to the specified file descriptor
	write(fd, &c, 1);

	// Check if the character is '%' and return 3, else return 1
	if (c == '%')
		return (3);
	else
		return (1);
}

// Function to print a string followed by a newline to a specified file descriptor
void ft_putendl_fd(char *s, int fd)
{
	// Print the string to the specified file descriptor
	ft_putstr_fd(s, fd);

	// Print a newline character to the specified file descriptor
	ft_putchar_fd('\n', fd);
}

// Function to print an integer to a specified file descriptor
int ft_putnbr_fd(int n, int fd)
{
	// Variables to store a character and the original value of n
	char c;
	int s;

	// Store the original value of n
	s = n;

	// Check if n is the minimum possible integer value
	if (n == -2147483648)
		// Print the specific string for the minimum integer value and return the length
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		// If n is negative, print '-' and call the function recursively for the positive value
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		// If n has more than one digit, get the last digit, call the function recursively, and print the digit
		c = (n % 10) + '0';
		n /= 10;
		ft_putnbr_fd(n, fd);
		write(fd, &c, 1);
	}
	else
	{
		// If n is a single digit, print it
		c = n + '0';
		write(fd, &c, 1);
	}

	// Return the length of the printed integer
	return (size_base(s, 10));
}

// Function to calculate the number of digits required to represent an unsigned integer in a given base
int size_unsigned(unsigned int n, unsigned int base)
{
	// Variables for loop counter and the result of division
	int i;
	unsigned int div;

	// Initialize loop counter and set div to the value of n
	i = 0;
	div = n;

	// If n is smaller than the base, return 1
	if (div < base)
		return (i + 1);

	// Loop to calculate the number of digits required
	while (div >= base)
	{
		div = div / base;
		i++;
	}

	// Return the total number of digits
	return (i + 1);
}

// Function to print an unsigned integer to a specified file descriptor
int ft_putnbru_fd(unsigned int n, int fd)
{
	// Variables to store a character and the original value of n
	char c;
	unsigned int s;

	// Store the original value of n
	s = n;

	// If n has more than one digit, get the last digit, call the function recursively, and print the digit
	if (n > 9)
	{
		c = (n % 10) + '0';
		n /= 10;
		ft_putnbru_fd(n, fd);
		write(fd, &c, 1);
	}
	else
	{
		// If n is a single digit, print it
		c = n + '0';
		write(fd, &c, 1);
	}

	// Return the number of digits in the printed unsigned integer
	return (size_unsigned(s, 10));
}

// Function to print an unsigned integer in a given base to a specified file descriptor
int ft_putnbru_base(unsigned int n, int fd, char *base)
{
	// Variables to store a character, the length of the base, the index, and the original value of n
	char c;
	unsigned int i;
	unsigned int s;

	// Store the original value of n and the length of the base
	s = n;
	i = (unsigned int)ft_strlen(base);

	// If n is greater than the length of the base - 1, get the last character, call the function recursively, and print the character
	if (n > i - 1)
	{
		c = base[(n % i)];
		n /= i;
		ft_putnbru_base(n, fd, base);
		write(fd, &c, 1);
	}
	else
	{
		// If n is within the range of the base, print the character
		c = base[n];
		write(fd, &c, 1);
	}

	// Return the number of digits in the printed unsigned integer in the specified base
	return (size_unsigned(s, ft_strlen(base)));
}

// Function to print a string to a specified file descriptor
int ft_putstr_fd(char *s, int fd)
{
	// Loop counter
	int i;

	// Initialize loop counter
	i = 0;

	// Check if the string is NULL
	if (!s)
	{
		// Print "(null)" and return the length
		write(1, "(null)", 6);
		return (6);
	}

	// Loop through the string and print each character to the specified file descriptor
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}

	// Return the length of the printed string
	return (ft_strlen(s));
}

// Function to calculate the length of a string
int ft_strlen(const char *str)
{
	// Loop counter
	int i;

	// Initialize loop counter
	i = 0;

	// Loop through the string and count the characters
	while (str[i])
		i++;

	// Return the length of the string
	return (i);
}

// Function to handle individual format specifiers in printf
int ft_which_sign(va_list *args, char c)
{
	// Variable to store the return value
	int i;

	// Initialize return value
	i = 0;

	// Check the format specifier and call the corresponding function
	if (c == 'c')
		i = ft_putchar_fd(va_arg(*args, int), 1);
	if (c == 's')
		i = ft_putstr_fd(va_arg(*args, char *), 1);
	if (c == 'p')
		i = ft_adresse(va_arg(*args, void *));
	if (c == 'd')
		i = ft_putnbr_fd(va_arg(*args, int), 1);
	if (c == 'i')
		i = ft_putnbr_fd(va_arg(*args, int), 1);
	if (c == 'u')
		i = ft_putnbru_fd(va_arg(*args, unsigned int), 1);
	if (c == 'x')
		i = ft_putnbru_base(va_arg(*args, int), 1, "0123456789abcdef");
	if (c == 'X')
		i = ft_putnbru_base(va_arg(*args, int), 1, "0123456789ABCDEF");
	if (c == '%')
		i = ft_putchar_fd('%', 1);

	// Return the length of the printed value
	return (i);
}

// Function to calculate the number of digits required to represent an integer in a given base
int size_base(int n, int base)
{
	// Variables for loop counter, divisor, and original value of n
	int i;
	int div;

	// Initialize loop counter and set div to the value of n
	i = 0;
	div = n;

	// Check if n is the minimum possible integer value
	if (n == -2147483648)
		return (11);

	// If n is negative, set div to its absolute value and increment the loop counter
	if (n < 0)
	{
		div = -n;
		i++;
	}

	// If n is smaller than the base, return 1
	if (div < base)
		return (i + 1);

	// Loop to calculate the number of digits required
	while (div >= base)
	{
		div = div / base;
		i++;
	}

	// Return the total number of digits
	return (i + 1);
}
