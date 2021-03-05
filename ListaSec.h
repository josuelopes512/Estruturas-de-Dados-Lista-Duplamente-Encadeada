typedef struct NoDe TNoDe;

TNoDe* criar(int v);
int tamanho(TNoDe *l);
void inserir(TNoDe *l, int v);
void exibe(TNoDe *l);
TNoDe* buscar(TNoDe *l, int v);
void exibeno(TNoDe *l);
void remover(TNoDe *l, int v);
void tornar_circular(TNoDe *no);
