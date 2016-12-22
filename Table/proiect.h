struct scor{
    short partide;
    short linii;
};

struct zar{
	short zar1, zar2;
};

struct player{
	char nume[10];
	scor scor;
	zar zaruri;
	char piesa;
	short eliminate;
};

struct stiva{
	char inf;
	stiva *urm;
}stiva *prim;
