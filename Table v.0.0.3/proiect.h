struct player
{
	char nume[10];
	short linii;
	short partide;
	short zar1;
	short zar2;
	short sumazar;
	char piesa;
	short eliminate;
};

struct stack
{
	char inf;
	stack *urm;
	short lungime;
};
