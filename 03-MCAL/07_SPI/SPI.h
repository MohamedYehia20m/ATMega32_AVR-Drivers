#ifndef SPI_H_
#define SPI_H_

void SPI_VidMasterInit(void);

void SPI_VidSlaveInit(void);

u8 SPI_U8TransmitRecieve( u8 Copy_U8Data );


void SPI_U8Transmit( u8 Copy_U8Data );

u8 SPI_U8Recieve(void);

#endif
