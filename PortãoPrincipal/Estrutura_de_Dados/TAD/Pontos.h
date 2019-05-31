//Arquivo Pointer.h
typedef struct pointer Pointer;

//Cria um novo ponto
Pointer* NewPointer(float x, float y);

//Libera um ponto
void FreePointer(Pointer* p);

//Acessa valores de x e y de um ponto
void GetValue(Pointer* p, float* x, float* y);

//Atribui valores de x e y a um ponto
void AddValue(Pointer* p, float x, float y);

//Método para caular distância entre dois pontos
float DistanceCalc(Pointer* p1, Pointer* p2);
