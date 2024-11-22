int MAX_PRODUCTOS;
#define NOMBRES 50


void ingresardatos(char nombres[MAX_PRODUCTOS][NOMBRES], float productos[MAX_PRODUCTOS][3], float *presuI, float *TiempoMax);
void costos(float productos[MAX_PRODUCTOS][3], float CostoD[MAX_PRODUCTOS]);
void calcularTotales(float productos[MAX_PRODUCTOS][3], float *tiempoT, float *costoT, float costoD[MAX_PRODUCTOS]);
void imprimirdatos(char nombres[MAX_PRODUCTOS][NOMBRES], float productos[MAX_PRODUCTOS][3], float presuI, float TiempoMax, float costoT, float tiempoT);
void editarProducto(char nombres[MAX_PRODUCTOS][NOMBRES], float productos[MAX_PRODUCTOS][3]);
void eliminar(char nombres[MAX_PRODUCTOS][NOMBRES], float productos[MAX_PRODUCTOS][3]);