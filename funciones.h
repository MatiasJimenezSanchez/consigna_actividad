#define productos_maximos 5
#define nombres 50

void ingresardatos(char nombresp[productos_maximos][nombres], float productos[productos_maximos][2], float *CantidadMAx, float *tiempoMax);
void calculartotal(float productos[productos_maximos][2], float *tiempoT, float *cantidadT);
void imprimirdatos(char nom[productos_maximos][nombres], float productos[productos_maximos][2], float cantidadMax, float tiempoMax, float tiempot, float cantidad);
void editarProducto(char nom[productos_maximos][nombres], float productos[productos_maximos][2]);
void eliminar(char nom[productos_maximos][nombres], float productos[productos_maximos][2]);
