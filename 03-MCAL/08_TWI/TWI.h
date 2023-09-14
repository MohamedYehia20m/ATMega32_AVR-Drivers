#ifndef TWI_H_
#define TWI_H_


/************* Master ************/
void TWI_VidMasterInit(void);

void TWI_VidStartCondition(void);

void TWI_VidSendSlaveAddressToWrite(u8 copy_U8Address);

void TWI_VidSendSlaveAddressToRead(u8 copy_U8Address);

void TWI_VidMasterSendDataToSlave( u8 copy_U8Data);

u8 TWI_U8MasterReadDataFromSlave(void);

void TWI_VidStopCondition(void);
/************* slave **************/

void TWI_VidSlaveInit( u8 Copy_U8SlaveAddress);

void TWI_VidSlaveSendDataToMaster( u8 copy_U8SlaveData);

u8 TWI_U8SlaveGetDataFromMaster(void);



#endif
