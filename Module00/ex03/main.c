#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int	etat_prec;
	int	etat_act;

	etat_act = 0;
	etat_prec = 0;
	DDRB |= (1 << PB0);
	DDRD &= ~(1 << PD2);
	PORTD |= (1 << PD2);
	while (1)
	{
		// si le bouton est presse, on passe l'etat a 1
		if (PIND & (1 << PD2))
			etat_act = 0;
		else
			etat_act = 1;
		// si l'etat actuel est different du precedent et que le bouton est presse on inverse l'etat de la led
		if (etat_act != etat_prec)
		{
			_delay_ms(20); // on met un delai de 20 millisecondes pour eviter les rebonds mecaniques
			if (etat_act == 1)
				PORTB ^= (1 << PB0);
		}
		etat_prec = etat_act;
	}
	return (0);
}