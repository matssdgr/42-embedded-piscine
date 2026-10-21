#include <avr/io.h>

int main(void)
{
	DDRB |= (1 << PB0); // sortie
	DDRD &= ~(1 << PD2); // entree
	PORTD |= (1 << PD2); // on active SW1
	while (1)
	{
		// Lorsque le bouton est relache (PIND a 1) on eteint la led sinon on l'allume
		if (PIND & (1 << PD2))
			PORTB &= ~(1 << PB0);
		else
			PORTB |= (1 << PB0); 
	}
	return (0);
}