/*
 * I2C.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: adham
 */

#ifndef I2C_H_
#define I2C_H_


typedef enum{
	TWBR0 = 0,
	TWBR1,
	TWBR2,
	TWBR3,
	TWBR4,
	TWBR5,
	TWBR6,
	TWBR7,


}TWBR_R;

typedef enum{
	TWIE = 0,
	res,
	TWEN,
	TWWC,
	TWSTO,
	TWSTA,
	TWEA,
	TWINT,


}TWCR_R;

typedef enum{
	TWPS0 = 0,
	TWPS1,
	X,
	TWS3,
	TWS4,
	TWS5,
	TWS6,
	TWS7,


}TWSR_R;



#endif /* I2C_H_ */
