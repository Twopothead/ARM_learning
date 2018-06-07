#ifdef __cplusplus
 extern "C" {
#include "stm32f10x_usart.h" 	
#endif
int _read(int file, char *data, int len);
int _write(int file, char *data, int len);
int _close(int file);
int _lseek(int file, int ptr, int dir);
int _fstat(int file, struct stat *st);
int _isatty(int file);
#ifdef __cplusplus
}
#endif