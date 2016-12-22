struct player
{
	char nume[10];
	short partide, linii;
	zar zaruri;
	char piesa;
	short eliminate;
};

struct zar{
	short zar1, zar2;
};

struct stiva
{
	char inf;
	stiva *urm;
}stiva *prim;