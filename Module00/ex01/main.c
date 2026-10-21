#include <avr/io.h>

int	main(void)
{
	DDRB |= (1 << PB0); // On met le registre a 1 pour determiner que c'est une sortie
	PORTB |= (1 << PB0); // On allume la led
	while (1)
	{}
	return (0);
}