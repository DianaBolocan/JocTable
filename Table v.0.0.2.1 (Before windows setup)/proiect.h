struct player
{
	char nume[10];
	short linii;
	short partide;
	short zar1;
	short zar2;
	char piesa;
	short eliminate;
};

struct stack
{
	char inf;
	stack *urm;
};
