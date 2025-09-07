#ifndef DRIVER_SPI_H
#define DRIVER_SPI_H
int spi_init(void);
int spi_transfer(const void *tx, void *rx, int len);
#endif
